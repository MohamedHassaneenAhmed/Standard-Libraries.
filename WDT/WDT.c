/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  WDT.c
 *        \brief >> WDT
 *
 *      \details
 *
 *
 *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 1/9/2022
**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "WDT.h"
#include "SysCtr.h"

 /**********************************************************************************************************************
   * FUNCTION IMPLEMENTATION
 *********************************************************************************************************************/
 /******************************************************************************
  * \Syntax          : void WDT1_Init (const WDT_ConfigType * ConfigPtr);


  * \Description     : init of watch dog timer
  *
  * \Sync\Async      : Synchronous
  * \Reentrancy      : Reentrant
  * \Parameters (in) : *ConfigPtr --> pointer to structure of WDT configuration
  * \Parameters (out): None
  * \Return value:   : None
  *******************************************************************************/

 void WDT_Init (const WDT_ConfigType * ConfigPtr)
 {
	 if (ConfigPtr  == NULL_PTR)
	 {
	 } /* do nothing */
	 else
	 {
		 Enable_Peripheral_Clock (WATCHDOG ,1 );            /* enable clock */

		 WATCHDOG1_LOAD = ((ConfigPtr->initial_Timeout * 1000) / CPU_F);                 /*set initial value in ticks*/

		 while (!Read_Pin(WATCHDOG1_CTL,31));                        /* WAIT TO MAKE SURE PREVIOUS OPERATION IS DONE */

		 switch(ConfigPtr->reset_type)                                /*select reset enability */
		 {
		case WDT_RESET_DISABLE:
			Clear_Pin(WATCHDOG1_CTL, 1);
			break;
		case WDT_RESET_ENABLE:
			Set_Pin(WATCHDOG1_CTL, 1);
			break;
		 }

		while (!Read_Pin(WATCHDOG1_CTL, 31));                     /* WAIT TO MAKE SURE PREVIOUS OPERATION IS DONE */


		switch (ConfigPtr->interrupt_type)
		{
		case WDT_INTERRUPT_STD:
			Clear_Pin(WATCHDOG1_CTL, 2);
			break;
		case WDT_INTERRUPT_NMI:
			Set_Pin(WATCHDOG1_CTL, 2);
			break;
		}

		while (!Read_Pin(WATCHDOG1_CTL, 31));                   /* WAIT TO MAKE SURE PREVIOUS OPERATION IS DONE */

		Set_Pin(WATCHDOG1_CTL, 0);                                          /**Watchdog Interrupt Enable**/
	}
}

 /******************************************************************************
  * \Syntax          : void WDT_ISR (void)



  * \Description     :callback of watch dog timer
  *
  * \Sync\Async      : Synchronous
  * \Reentrancy      : Reentrant
  * \Parameters (in) : None
  * \Parameters (out): None
  * \Return value:   : None
  *******************************************************************************/

void WDT1_ISR (void)
{
	/* A write of any value to this register clears the Watchdog interrupt and
	   reloads the 32-bit counter from the WDTLOAD register. */
	Set_Pin(WATCHDOG1_ICR, 2);
	/*callback function to ISR implementation function */
	if (WDT_ConficObject.callback_function != NULL_PTR)
	{
		WDT_ConficObject.callback_function();
	}
}

/******************************************************************************
 * \Syntax          : void WDT_SetTriggerConditin (uint16_t Timeout);


 * \Description     :reload trigger timeout value of watch dog timer
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Timeout --> timeout value in milli second
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void WDT_SetTriggerConditin(uint16_t Timeout)
{
	/*# millisecond = # * 1000/CPU_F*/
	WATCHDOG1_LOAD = ((Timeout * 1000) / CPU_F);

	/* WAIT TO MAKE SURE PREVIOUS OPERATION IS DONE */
	while (!Read_Pin(WATCHDOG1_CTL, 31))
		;

}











/**********************************************************************************************************************
 *  END OF FILE: WDT.c
 *********************************************************************************************************************/
