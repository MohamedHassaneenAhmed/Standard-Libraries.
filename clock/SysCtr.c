/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysCtr.c
 *        \brief ---  Peripheral Clock Gating Control
 *               --- control of system clocl by PLL
 *
 *      \details
 *
 *
 *********************************************************************************************************************
 *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 18/8/2022

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SysCtr.h"


/******************************************************************************
* \Syntax          : uint8_t Enable_Peripheral_Clock (uint8_t U8Peripheral_Name , uint8_t U8Peripheral_Channel )
* \Description     : Peripheral Clock Gating Control
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : U8Peripheral_Name        >>>  Name of peripheral that i want to set clock enable
*                    U8Peripheral_Channel     >>>  select peripheral channel
* \Parameters (out): None
* \Return value:   : Std_ReturnType  OK
*                                    NOT_OK
*******************************************************************************/
Std_ReturnType Enable_Peripheral_Clock (uint8_t U8Peripheral_Name , uint8_t U8Peripheral_Channel )
{
 if (U8Peripheral_Name > 15)
 {
	 return NOT_OK;
 }
 else
 {
	 switch (U8Peripheral_Name)
	 {
	 case WATCHDOG :
		 if  (U8Peripheral_Channel > 1)
		 {
			 return NOT_OK;
		 }
		 else
		 {
			 Set_Pin(SYSCTL_RCGCWD,U8Peripheral_Channel);
		 }
		 break;
	 case TIMER :
	 		 if  (U8Peripheral_Channel > 5)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCTIMER,U8Peripheral_Channel);
	 		 }
			 break;

	 case GPIO :
	 		 if (U8Peripheral_Channel > 5)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCGPIO,U8Peripheral_Channel);
	 		 }
			 break;

	 case DMA :
	 		 if (U8Peripheral_Channel > 0)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCDMA,U8Peripheral_Channel);
	 		 }
			 break;

	 case HIB :
	 		 if (U8Peripheral_Channel > 0)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCHIB,U8Peripheral_Channel);
	 		 }
			 break;

	 case UART :
	 		 if (U8Peripheral_Channel > 7)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCUART,U8Peripheral_Channel);
	 		 }
			 break;

	 case SSI :
	 		 if (U8Peripheral_Channel > 3)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCSSI,U8Peripheral_Channel);
	 		 }
			 break;

	 case I2C :
	 		 if (U8Peripheral_Channel > 3)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCI2C,U8Peripheral_Channel);
	 		 }
			 break;

	 case USB :
	 		 if (U8Peripheral_Channel > 0)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCUSB,U8Peripheral_Channel);
	 		 }
			 break;

	 case CAN :
	 		 if (U8Peripheral_Channel > 1)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCCAN,U8Peripheral_Channel);
	 		 }
			 break;

	 case ADC :
	 		 if (U8Peripheral_Channel > 1)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCADC,U8Peripheral_Channel);
	 		 }
			 break;

	 case ACMP :
	 		 if (U8Peripheral_Channel > 0)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCACMP,U8Peripheral_Channel);
	 		 }
			 break;

	 case PWM :
	 		 if (U8Peripheral_Channel > 1)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCPWM,U8Peripheral_Channel);
	 		 }
			 break;

	 case QEI :
	 		 if (U8Peripheral_Channel > 1)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCQEI,U8Peripheral_Channel);
	 		 }
			 break;

	 case EEPROM :
	 		 if (U8Peripheral_Channel > 0)
	 		 {
	 			 return NOT_OK;
	 		 }
	 		 else
	 		 {
	 			 Set_Pin(SYSCTL_RCGCEEPROM,U8Peripheral_Channel);
			}
			 break;

		case WTIMER:
			if (U8Peripheral_Channel > 5)
			{
				return NOT_OK;
			}
			else
			{
				Set_Pin(SYSCTL_RCGCWTIMER, U8Peripheral_Channel);
			}
			 break;

		}
	}
	return OK;

}
/******************************************************************************
* \Syntax          : uint8_t Clock_PLL_init (uint8_t U8Div_number);

* \Description     :  PLL setting -- clock control
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : U8Div_number        >>> 400 MHZ PLL / U8Div_number to select clock value
*
* \Parameters (out): None
* \Return value:   : Std_ReturnType  OK
*                                    NOT_OK
*******************************************************************************/
Std_ReturnType Clock_PLL_Setting (uint8_t U8Div_number)
{
	if (U8Div_number < 2)
	{
		 return NOT_OK;
	}
	else
	{
	SYSCTL_RCC2_R |= 0x80000000;                        /* Enable USERCC2 in RCC2*/
	SYSCTL_RCC2_R |= 0x00000800;                        /*BYPASS PLL While initialization */
	SYSCTL_RCC_R = (SYSCTL_RCC_R & ~0x000007C0)         /* clear XTAL 6-10 BITS */
			         +  0x00000540;                     /* Configuration for 16 Mhz*/
	SYSCTL_RCC2_R &= ~0x00000070;                       /* Configuration for main oscillator*/
	SYSCTL_RCC2_R &= ~0x00002000;                       /* activate PLL by clearing PWRDN*/
	SYSCTL_RCC2_R |= 0x40000000;                        /* use 400 mhz PLL*/
	SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000)       /*clear system clock divider*/
			         + ((U8Div_number - 1 )<<22);       /* Configuration for (400/U8Div_number) Mhz */
	while(SYSCTL_RIS_R & 0x00000040 == 0 ){} ;          /* wait for PLLRIS bit */
	SYSCTL_RCC2_R &= ~0x00000800;                       /* enable use PLL by clearing bypass*/
	}
	return OK;
}



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
