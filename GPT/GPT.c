
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT.c
 *        \brief ---  static code for GPT Modules
 *               ---  generic APIs implementation for GPT
 *               ---  Callback functions for each module
 *
 *      \details
 *
 *
 *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 24/8/2022
**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include"GPT.h"
#include"SysCtr.h"
#include"NVIC.h"
#include"GPT_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* Array of structures contains GPT Modules configuration */
extern GPT_ConfigType GPT_LinkConfig[GPT_MODULESNUMBERS];


/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/* Look up table includes :
 *                              1- offset of each timer
 *                              3- vector table number of each timer
 *                              3- max counts of each timer                            */

GPT_InfoListType Timer_Info_List[GPT_MODULESNUMBERS]=
{
   {TIMER0_OFFSET,    NVIC_TIMER0A_16_32, 0xFFFF      ,GPT_TIMER , GPT_8BIT_PRESCALE},
   {TIMER1_OFFSET,    NVIC_TIMER1A_16_32, 0xFFFF      ,GPT_TIMER , GPT_8BIT_PRESCALE},
   {TIMER2_OFFSET,    NVIC_TIMER2A_16_32, 0xFFFF      ,GPT_TIMER , GPT_8BIT_PRESCALE},
   {TIMER3_OFFSET,    NVIC_TIMER3A_16_32, 0xFFFF      ,GPT_TIMER , GPT_8BIT_PRESCALE},
   {TIMER4_OFFSET,    NVIC_Timer4A_16_32, 0xFFFF      ,GPT_TIMER , GPT_8BIT_PRESCALE},
   {TIMER5_OFFSET,    NVIC_Timer5A_16_32, 0xFFFF      ,GPT_TIMER , GPT_8BIT_PRESCALE},
   {WTIMER0_OFFSET,   NVIC_Timer0A_32_64, 0xFFFFFFFF,GPT_WTIMER , GPT_16BIT_PRESCALE},
   {WTIMER1_OFFSET,   NVIC_Timer1A_32_64,0xFFFFFFFF,GPT_WTIMER , GPT_16BIT_PRESCALE},
   {WTIMER2_OFFSET,   NVIC_Timer2A_32_64, 0xFFFFFFFF,GPT_WTIMER , GPT_16BIT_PRESCALE},
   {WTIMER3_OFFSET,   NVIC_Timer3A_32_64, 0xFFFFFFFF,GPT_WTIMER , GPT_16BIT_PRESCALE},
   {WTIMER4_OFFSET,   NVIC_Timer4A_32_64, 0xFFFFFFFF,GPT_WTIMER , GPT_16BIT_PRESCALE},
   {WTIMER5_OFFSET,   NVIC_Timer5A_32_64, 0xFFFFFFFF,GPT_WTIMER , GPT_16BIT_PRESCALE}
};


/******************************************************************************
 * \Syntax          : Std_ReturnType GPT_Init(const GPT_ConfigType * ConfigPtr)

 * \Description     : initiation of GPT module
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : * ConfigPtr  >>  pointer to configuration structure
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType        OK = 0
 *                                          NOT_OK =-1
 *******************************************************************************/
Std_ReturnType GPT_Init(const GPT_ConfigType * ConfigPtr)
{
	uint8_t i;
	GPT_MaxTickValueType max_ticks;
	for (i = 0; i < GPT_MODULESNUMBERS; i++)
	{
		if (ConfigPtr[i].Enablitiy == GPT_DISABLE)
		{
		} /* do nothing*/
		else
		{

			/*determine number of counts to select suitable timer */
			max_ticks = ConfigPtr[i].Max_Tick_Numbers;

			/* enable clock */
			max_ticks = max_ticks * CPU_F / ConfigPtr[i].Frequency_MHZ;

			/*check if capacity of timer contains the number of counts or not */
			if (max_ticks > Timer_Info_List[i].counts)
			{
				return NOT_OK;
			}
			else
			{
				/* enable timer module clock */
				Enable_Peripheral_Clock(Timer_Info_List[i].clock, i % 6);

				/* disable module during configuration */
				Clear_Pin(
						(*((volatile uint32_t *)(Base_TIMER_CTL + Timer_Info_List[i].offest))),
						0);

				/*** All timers 16_32 configure to 16 bit    ***/
				/*** All timers 32_64 configure to 32 bit    ***/
				Set_Pin((*((volatile uint32_t *)(Base_TIMER_CFG + Timer_Info_List[i].offest))),
						2);

				/*set mode one shot / periodic  */
				Set_Pin((*((volatile uint32_t *)(Base_TIMER_TAMR + Timer_Info_List[i].offest))),
						ConfigPtr[i].Mode);

				/*Set full pre-scale of each module */
			Set_Pin((*((volatile uint32_t *)(Base_TIMER_TAPR + Timer_Info_List[i].offest))),
					Timer_Info_List[i].prescale);

				/* clear interrupt */
				Set_Pin((*((volatile uint32_t *)(Base_TIMER_ICR + Timer_Info_List[i].offest))),
						0);

				/* enable interrupt of module */
				Set_Pin((*((volatile uint32_t *)(Base_TIMER_IMR + Timer_Info_List[i].offest))),
						0);

				/* TIMER TRIGGER */
				Set_Pin((*((volatile uint32_t *)(Base_TIMER_CTL + Timer_Info_List[i].offest))),
						5);

				/* enable NVIC of module */
				 NVIC_Enable_IRQ(Timer_Info_List[i].vector_number);

			}
		}

	}
	if (ConfigPtr[WTIMERA0].Enablitiy == GPT_DISABLE)
	{
	} /* do nothing*/
	else
	{
		/* load target value = number of counts*/
		WTIMER0_TAILR = GPT_LinkConfig[WTIMERA0].Target_Value * 16
				/ GPT_LinkConfig[WTIMERA0].Frequency_MHZ;

		/* enable predefine timer == wtimera0 */
		Set_Pin(WTIMER0_CTL, 0);

	}

return 0;
}


/******************************************************************************
* \Syntax          : void GPT_StartTimer (GPT_ChannelAType channel, GPT_ValueType target_value)

* \Description     : start timer and set the target value
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : channel          >> module number
*                    target_value    >>  port target_value
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

	void GPT_StartTimer(GPT_ChannelAType Channel, GPT_ValueType target_value)
{
	/* clear interrupt */
	Set_Pin((*((volatile uint32_t *)(Base_TIMER_ICR + Timer_Info_List[Channel].offest))),
			0);

	/* load target value = number of counts*/
	(*((volatile uint32_t*) (Base_TIMER_TAILR + Timer_Info_List[Channel].offest))) =
			target_value * 16 / GPT_LinkConfig[Channel].Frequency_MHZ;

	/* Enable module */
	Set_Pin((*((volatile uint32_t *)(Base_TIMER_CTL + Timer_Info_List[Channel].offest))),
				0);

	}




/******************************************************************************
* \Syntax          : void GPT_StopTimer (GPT_ChannelAType Channel)

* \Description     : stop timer
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel    >> module number
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_StopTimer (GPT_ChannelAType Channel)
{
	/* disable module */
	Clear_Pin((*((volatile uint32_t *)(Base_TIMER_CTL + Timer_Info_List[Channel].offest))),
					0);
}

/******************************************************************************
* \Syntax          : void GPT_EnableNotification(GPT_ChannelAType Channel)


* \Description     : enable interrupt of module and NVIC
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel       >>  module number
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_EnableNotification(GPT_ChannelAType Channel)
{
	/* enable interrupt of module */
	Set_Pin((*((volatile uint32_t *)(Base_TIMER_IMR + Timer_Info_List[Channel].offest))),
			0);

	/* enable NVIC of module */
	 NVIC_Enable_IRQ(Timer_Info_List[Channel].vector_number);

}


/******************************************************************************
* \Syntax          : void GPT_DisableNotification (GPT_ChannelAType Channel)



* \Description     :disable interrupt of module and NVIC
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel       >>  module number
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_DisableNotification (GPT_ChannelAType Channel)
{
	/* disable interrupt of module */
  	Clear_Pin((*((volatile uint32_t *)(Base_TIMER_IMR + Timer_Info_List[Channel].offest))),
				0);

	/* disable NVIC of module */
		NVIC_Disable_IRQ(Timer_Info_List[Channel].vector_number);

}

/******************************************************************************
* \Syntax          : GPT_ValueType GPT_GetTimeElapsed (GPT_ChannelAType Channel)


* \Description     : determine the instant time of timer with handling the required frequency
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel >>  module number
* \Parameters (out): None
* \Return value:   : GPT_ValueType         elapesed  time
*                                          NOT_OK =-1
 *******************************************************************************/

GPT_ValueType GPT_GetTimeElapsed (GPT_ChannelAType Channel)
{
	uint32_t return_value;
	switch(GPT_LinkConfig[Channel].Frequency_MHZ)
	{
	case F_1:
		return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) >> 4;
		break;
	case F_2:
		return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) >> 3;
		break;
	case F_4:
		return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) >> 2;
		break;
	case F_8:
		return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) >> 1;
		break;
	case F_16:
		return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) ;
		break;
	case F_32:
		return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) << 1;
		break;
	case F_48:
		return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) << 2;
		break;
	case F_64:
		return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) << 3;
		break;
	case F_80:
		return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) << 4;
		break;
	}
	return (return_value / CPU_F );

}

/******************************************************************************
* \Syntax          : GPT_ValueType GPT_GetTimeRemaining (GPT_ChannelAType Channel)


* \Description     : determine the remaining time of timer to reach the target with handling the required frequency
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel >>  module number
* \Parameters (out): None
* \Return value:   : GPT_ValueType         remaining  time
*                                          NOT_OK =-1
 *******************************************************************************/

GPT_ValueType GPT_GetTimeRemaining(GPT_ChannelAType Channel)
{

	uint32_t rem_return_value;
	uint32_t rem_target_value;
	switch (GPT_LinkConfig[Channel].Frequency_MHZ)
	{
	case F_1:
		rem_return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) >> 4;
		rem_target_value = GPT_LinkConfig[Channel].Target_Value>> 4;

		break;
	case F_2:
		rem_return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) >> 3;
		rem_target_value = GPT_LinkConfig[Channel].Target_Value >> 3;

		break;
	case F_4:
		rem_return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) >> 2;
		rem_target_value = GPT_LinkConfig[Channel].Target_Value >> 2;

		break;
	case F_8:
		rem_return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) >> 1;
		rem_target_value = GPT_LinkConfig[Channel].Target_Value>> 1;

		break;
	case F_16:
		rem_return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest)));
		rem_target_value = GPT_LinkConfig[Channel].Target_Value;

		break;
	case F_32:
		rem_return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) << 1;
		rem_target_value = GPT_LinkConfig[Channel].Target_Value<< 1;

		break;
	case F_48:
		rem_return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) << 2;
		rem_target_value = GPT_LinkConfig[Channel].Target_Value<< 2;

		break;
	case F_64:
		rem_return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) << 3;
		rem_target_value = GPT_LinkConfig[Channel].Target_Value << 3;

		break;
	case F_80:
		rem_return_value = (*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[Channel].offest))) << 4;
		rem_target_value = GPT_LinkConfig[Channel].Target_Value<< 4;

		break;
	}
	return ((rem_target_value - rem_return_value )/CPU_F );
}

/******************************************************************************
* \Syntax          : Std_ReturnType GPT_GetPredefTimerValue(GPT_PredefTimerType TimerType,
									                     	uint32_t *TimueValuePtr)


* \Description     : determine the instant time of PREDEF timer with handling the required frequency and resolution.
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : TimerType      >>  determine type of timer :
*                                             GPT_PREDEF_TIMER_1US_16BIT=0,
	                                          GPT_PREDEF_TIMER_1US_24BIT,
	                                          GPT_PREDEF_TIMER_1US_32BIT,
	                                         GPT_PREDEF_TIMER_100US_32BIT,
	                *TimueValuePtr  >>   pointer to get time
* \Parameters (out): None
* \Return value:   : GPT_ValueType         remaining  time
*                                          NOT_OK =-1
 *******************************************************************************/

Std_ReturnType GPT_GetPredefTimerValue(GPT_PredefTimerType TimerType,
										uint32_t *TimueValuePtr)
{
	uint64_t return_value;
	if (TimueValuePtr == NULL_PTR)
	{
		return NOT_OK;
	}
	else
	{

	switch (GPT_LinkConfig[WTIMERA0].Frequency_MHZ)
	{
	case F_1:
		return_value = ((*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[WTIMERA0].offest)))
				+ ((*((volatile uint32_t*) (Base_TIMER_TAPV
						+ Timer_Info_List[WTIMERA0].offest)))
						<<0xFFFFFFFF)) << 4;
	case F_2:
		return_value = ((*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[WTIMERA0].offest)))
				+ ((*((volatile uint32_t*) (Base_TIMER_TAPV
						+ Timer_Info_List[WTIMERA0].offest)))
						<<0xFFFFFFFF)) << 3;

		break;
	case F_4:
		return_value = ((*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[WTIMERA0].offest)))
				+ ((*((volatile uint32_t*) (Base_TIMER_TAPV
						+ Timer_Info_List[WTIMERA0].offest)))
						<<0xFFFFFFFF)) << 2;

		break;
	case F_8:
		return_value = ((*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[WTIMERA0].offest)))
				+ ((*((volatile uint32_t*) (Base_TIMER_TAPV
						+ Timer_Info_List[WTIMERA0].offest)))
						<<0xFFFFFFFF)) << 1;

		break;
	case F_16:
		return_value = ((*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[WTIMERA0].offest)))
				+ ((*((volatile uint32_t*) (Base_TIMER_TAPV
						+ Timer_Info_List[WTIMERA0].offest)))
						<<0xFFFFFFFF));

		break;
	case F_32:
		return_value = ((*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[WTIMERA0].offest)))
				+ ((*((volatile uint32_t*) (Base_TIMER_TAPV
						+ Timer_Info_List[WTIMERA0].offest)))
						<<0xFFFFFFFF))>> 1;
		break;
	case F_48:
		return_value = ((*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[WTIMERA0].offest)))
				+ ((*((volatile uint32_t*) (Base_TIMER_TAPV
						+ Timer_Info_List[WTIMERA0].offest)))
						<<0xFFFFFFFF)) >> 2;

		break;
	case F_64:
		return_value = ((*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[WTIMERA0].offest)))
				+ ((*((volatile uint32_t*) (Base_TIMER_TAPV
						+ Timer_Info_List[WTIMERA0].offest)))
						<<0xFFFFFFFF))>> 3;
		break;
	case F_80:
		return_value = ((*((volatile uint32_t*) (Base_TIMER_TAV
				+ Timer_Info_List[WTIMERA0].offest)))
				+ ((*((volatile uint32_t*) (Base_TIMER_TAPV
						+ Timer_Info_List[WTIMERA0].offest)))
						<<0xFFFFFFFF)) >> 4;
		break;

	}
		switch (TimerType)
		{
		case GPT_PREDEF_TIMER_1US_16BIT:
			*TimueValuePtr = ((return_value & 0xFFFFFF)       >> 4);
			break;
		case GPT_PREDEF_TIMER_1US_24BIT:
			*TimueValuePtr = ((return_value & 0xFFFFFFFF)     >> 4);
			break;
		case GPT_PREDEF_TIMER_1US_32BIT:
			*TimueValuePtr = ((return_value & 0xFFFFFFFFFF)   >> 4);
			break;

		case GPT_PREDEF_TIMER_100US_32BIT:
			*TimueValuePtr = ((return_value & 0xFFFFFFFFFFFF) >> 6);
		break;
	}
	}
	return 0;
}
/******************************************************************************
* \Syntax          :void GPT_TimerA0_Handler (void)


* \Description     : ISR For timerA0 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_TimerA0_Handler (void)
{


	if(GPT_LinkConfig[TIMERA0].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[TIMERA0].GPT_Callback();
	}

}

/******************************************************************************
* \Syntax          : void GPT_TimerA1_Handler (void)

* \Description     : ISR For timerA1 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_TimerA1_Handler (void)
{


	if(GPT_LinkConfig[TIMERA1].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[TIMERA1].GPT_Callback();
	}

}
/******************************************************************************
* \Syntax          : void GPT_TimerA1_Handler (void)

* \Description     : ISR For timerA2 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_TimerA2_Handler (void)
{


	if(GPT_LinkConfig[TIMERA2].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[TIMERA2].GPT_Callback();
	}

}
/******************************************************************************
* \Syntax          : void GPT_TimerA3_Handler (void)

* \Description     : ISR For timerA3 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_TimerA3_Handler (void)
{


	if(GPT_LinkConfig[TIMERA3].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[TIMERA3].GPT_Callback();
	}

}
/******************************************************************************
* \Syntax          : void GPT_TimerA4_Handler (void)

* \Description     : ISR For timerA4 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_TimerA4_Handler (void)
{


	if(GPT_LinkConfig[TIMERA4].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[TIMERA4].GPT_Callback();
	}

}
/******************************************************************************
* \Syntax          : void GPT_TimerA5_Handler (void)

* \Description     : ISR For timerA5 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_TimerA5_Handler (void)
{


	if(GPT_LinkConfig[TIMERA5].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[TIMERA5].GPT_Callback();
	}

}
/******************************************************************************
* \Syntax          : void GPT_WTimerA0_Handler (void)

* \Description     : ISR For WtimerA0 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_WTimerA0_Handler (void)
{


	if(GPT_LinkConfig[WTIMERA0].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[WTIMERA0].GPT_Callback();
	}

}

/******************************************************************************
* \Syntax          : void GPT_WTimerA1_Handler (void)

* \Description     : ISR For WtimerA1 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_WTimerA1_Handler (void)
{


	if(GPT_LinkConfig[WTIMERA1].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[WTIMERA1].GPT_Callback();
	}

}
/******************************************************************************
* \Syntax          : void GPT_WTimerA2_Handler (void)

* \Description     : ISR For WtimerA2 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_WTimerA2_Handler (void)
{


	if(GPT_LinkConfig[WTIMERA2].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[WTIMERA2].GPT_Callback();
	}

}
/******************************************************************************
* \Syntax          : void GPT_WTimerA3_Handler (void)

* \Description     : ISR For WtimerA3 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_WTimerA3_Handler (void)
{


	if(GPT_LinkConfig[WTIMERA3].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[WTIMERA3].GPT_Callback();
	}

}
/******************************************************************************
* \Syntax          : void GPT_WTimerA4_Handler (void)

* \Description     : ISR For WtimerA4 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_WTimerA4_Handler (void)
{


	if(GPT_LinkConfig[WTIMERA4].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[WTIMERA4].GPT_Callback();
	}

}

/******************************************************************************
* \Syntax          : void GPT_WTimerA5_Handler (void)

* \Description     : ISR For WtimerA5 includes callback function to ISR implementation
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/

void GPT_WTimerA5_Handler (void)
{


	if(GPT_LinkConfig[WTIMERA5].GPT_Callback!= NULL_PTR)
	{
		GPT_LinkConfig[WTIMERA5].GPT_Callback();
	}

}

/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/
