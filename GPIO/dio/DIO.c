
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  -- APIs for :
 *                        - read & write & toggle pin
 *                        - read & write port
 *
 *      \details
 *
 *

*********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 20/8/2022
**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "DIO.h"
#include "Macros.h"



///******************************************************************************
//* \Syntax          : GPIO_LevelChannelType DIO_ReadChannel (GPIO_ChannelType Channel_ID,
//*                                                           GPIO_PortType Port_ID)
//
//* \Description     : Read pin
//*
//* \Sync\Async      : Synchronous
//* \Reentrancy      : Reentrant
//* \Parameters (in) : Channel_ID >>  pin number
//*                    Port_ID    >>  port number
//* \Parameters (out): None
//* \Return value:   : DIO_LevelChannelType  High=1
//*                                          Low =0
//*                                          NOT_OK =-1
//*******************************************************************************/
//GPIO_LevelChannelType DIO_ReadChannel (GPIO_PortType Port_ID,
//									   GPIO_ChannelType Channel_ID)
//{
//	switch (Port_ID)
//	{
//	case PORTA:
//		switch (Channel_ID)
//		{
//		case PN0:
//			return GPIOA_DATA_PN0;
//		case PN1:
//			return GPIOA_DATA_PN1;
//		case PN2:
//			return GPIOA_DATA_PN2;
//		case PN3:
//			return GPIOA_DATA_PN3;
//		case PN4:
//			return GPIOA_DATA_PN4;
//		case PN5:
//			return GPIOA_DATA_PN5;
//		case PN6:
//			return GPIOA_DATA_PN6;
//		case PN7:
//			return GPIOA_DATA_PN7;
//		}
//	case PORTB:
//		switch (Channel_ID)
//		{
//		case PN0:
//			return GPIOB_DATA_PN0;
//		case PN1:
//			return GPIOB_DATA_PN1;
//		case PN2:
//			return GPIOB_DATA_PN2;
//		case PN3:
//			return GPIOB_DATA_PN3;
//		case PN4:
//			return GPIOB_DATA_PN4;
//		case PN5:
//			return GPIOB_DATA_PN5;
//		case PN6:
//			return GPIOB_DATA_PN6;
//		case PN7:
//			return GPIOB_DATA_PN7;
//
//		}
//	case PORTC:
//		switch (Channel_ID)
//		{
//		case PN0:
//			return GPIOC_DATA_PN0;
//		case PN1:
//			return GPIOC_DATA_PN1;
//		case PN2:
//			return GPIOC_DATA_PN2;
//		case PN3:
//			return GPIOC_DATA_PN3;
//		case PN4:
//			return GPIOC_DATA_PN4;
//		case PN5:
//			return GPIOC_DATA_PN5;
//		case PN6:
//			return GPIOC_DATA_PN6;
//		case PN7:
//			return GPIOC_DATA_PN7;
//
//		}
//	case PORTD:
//		switch (Channel_ID)
//		{
//		case PN0:
//			return GPIOD_DATA_PN0;
//		case PN1:
//			return GPIOD_DATA_PN1;
//		case PN2:
//			return GPIOD_DATA_PN2;
//		case PN3:
//			return GPIOD_DATA_PN3;
//		case PN4:
//			return GPIOD_DATA_PN4;
//		case PN5:
//			return GPIOD_DATA_PN5;
//		case PN6:
//			return GPIOD_DATA_PN6;
//		case PN7:
//			return GPIOD_DATA_PN7;
//		}
//	case PORTE:
//		switch (Channel_ID)
//		{
//		case PN0:
//			return GPIOE_DATA_PN0;
//		case PN1:
//			return GPIOE_DATA_PN1;
//		case PN2:
//			return GPIOE_DATA_PN2;
//		case PN3:
//			return GPIOE_DATA_PN3;
//		case PN4:
//			return GPIOE_DATA_PN4;
//		case PN5:
//			return GPIOE_DATA_PN5;
//		}
//	case PORTF:
//		switch (Channel_ID)
//		{
//		case PN0:
//			return GPIOF_DATA_PN0;
//		case PN1:
//			return GPIOF_DATA_PN1;
//		case PN2:
//			return GPIOF_DATA_PN2;
//		case PN3:
//			return GPIOF_DATA_PN3;
//		case PN4:
//			return GPIOF_DATA_PN4;
//
//		}
//	}
//
//}
/******************************************************************************
* \Syntax          : GPIO_LevelChannelType DIO_ReadChannel (GPIO_ChannelType Channel_ID,
*                                                           GPIO_PortType Port_ID)

* \Description     : Read pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID >>  pin number
*                    Port_ID    >>  port number
* \Parameters (out): None
* \Return value:   : DIO_LevelChannelType  High=1
*                                          Low =0
*                                          NOT_OK =-1
*******************************************************************************/
GPIO_LevelChannelType DIO_ReadChannel (GPIO_PortType Port_ID,
									   GPIO_ChannelType Channel_ID)
{
#if (BIT_BANDING == 1 )
	uint8_t read_value;
		switch (Port_ID)
		{
		case PORTA:
			read_value = *((volatile uint32_t *)(BITBAND_PERI(GPIOA_DATA, Channel_ID)));
			break;
		case PORTB:
			read_value = *((volatile uint32_t *)(BITBAND_PERI(GPIOB_DATA, Channel_ID)));
			break;
		case PORTC:
			read_value = *((volatile uint32_t *)(BITBAND_PERI(GPIOC_DATA, Channel_ID)));
			break;
		case PORTD:
			read_value = *((volatile uint32_t *)(BITBAND_PERI(GPIOD_DATA, Channel_ID)));
			break;
		case PORTE:
			read_value = *((volatile uint32_t *)(BITBAND_PERI(GPIOE_DATA, Channel_ID)));
			break;
		case PORTF:
			read_value = *((volatile uint32_t *)(BITBAND_PERI(GPIOF_DATA, Channel_ID)));
			break;
		}
		return read_value;
#else
	uint8_t read_value;
	switch (Port_ID)
	{
	case PORTA:
		read_value = Read_Pin(GPIOA_DATA_PORT,Channel_ID);
		break;
	case PORTB:
		read_value = Read_Pin(GPIOB_DATA_PORT,Channel_ID);
		break;
	case PORTC:
		read_value = Read_Pin(GPIOC_DATA_PORT,Channel_ID);
		break;
	case PORTD:
		read_value = Read_Pin(GPIOD_DATA_PORT,Channel_ID);
		break;
	case PORTE:
		read_value = Read_Pin(GPIOE_DATA_PORT,Channel_ID);
		break;
	case PORTF:
		read_value = Read_Pin(GPIOF_DATA_PORT,Channel_ID);
		break;
	}
	return read_value;
#endif
}


///******************************************************************************
//* \Syntax          :Std_ReturnType DIO_WriteChannel (GPIO_ChannelType Channel_ID,
//								                     GPIO_PortType Port_ID,
//								                     GPIO_LevelChannelType Level_Value);
//
//
//* \Description     : set pin level high or low
//*
//* \Sync\Async      : Synchronous
//* \Reentrancy      : Reentrant
//* \Parameters (in) : Channel_ID >>  pin number
//*                    Port_ID    >>  port number
//*                    Level_Value>>  pin state
//* \Parameters (out): None
//* \Return value:   : Std_ReturnType      OK
//*                                        NOT_OK
//*
//*******************************************************************************/
//Std_ReturnType DIO_WriteChannel (GPIO_PortType Port_ID,
//								 GPIO_ChannelType Channel_ID,
//								 GPIO_LevelChannelType Level_Value)
//
//
//{
//	switch (Port_ID)
//	{
//	case PORTA:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOA_DATA_PN0 =Level_Value;
//		case PN1:
//			 GPIOA_DATA_PN1=Level_Value;
//		case PN2:
//			 GPIOA_DATA_PN2=Level_Value;
//		case PN3:
//			 GPIOA_DATA_PN3=Level_Value;
//		case PN4:
//			 GPIOA_DATA_PN4=Level_Value;
//		case PN5:
//			 GPIOA_DATA_PN5=Level_Value;
//		case PN6:
//			 GPIOA_DATA_PN6=Level_Value;
//		case PN7:
//			 GPIOA_DATA_PN7=Level_Value;
//		default:
//			return NOT_OK;
//		}
//	case PORTB:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOB_DATA_PN0=Level_Value;
//		case PN1:
//			 GPIOB_DATA_PN1=Level_Value;
//		case PN2:
//			 GPIOB_DATA_PN2=Level_Value;
//		case PN3:
//			 GPIOB_DATA_PN3=Level_Value;
//		case PN4:
//			 GPIOB_DATA_PN4=Level_Value;
//		case PN5:
//			 GPIOB_DATA_PN5=Level_Value;
//		case PN6:
//			 GPIOB_DATA_PN6=Level_Value;
//		case PN7:
//			 GPIOB_DATA_PN7=Level_Value;
//		default:
//			return NOT_OK;
//		}
//	case PORTC:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOC_DATA_PN0=Level_Value;
//		case PN1:
//			 GPIOC_DATA_PN1=Level_Value;
//		case PN2:
//			 GPIOC_DATA_PN2=Level_Value;
//		case PN3:
//			 GPIOC_DATA_PN3=Level_Value;
//		case PN4:
//			 GPIOC_DATA_PN4=Level_Value;
//		case PN5:
//			 GPIOC_DATA_PN5=Level_Value;
//		case PN6:
//			 GPIOC_DATA_PN6=Level_Value;
//		case PN7:
//			 GPIOC_DATA_PN7=Level_Value;
//		default:
//			return NOT_OK;
//		}
//	case PORTD:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOD_DATA_PN0=Level_Value;
//		case PN1:
//			 GPIOD_DATA_PN1=Level_Value;
//		case PN2:
//			 GPIOD_DATA_PN2=Level_Value;
//		case PN3:
//			 GPIOD_DATA_PN3=Level_Value;
//		case PN4:
//			 GPIOD_DATA_PN4=Level_Value;
//		case PN5:
//			 GPIOD_DATA_PN5=Level_Value;
//		case PN6:
//			 GPIOD_DATA_PN6=Level_Value;
//		case PN7:
//			 GPIOD_DATA_PN7=Level_Value;
//		default:
//			return NOT_OK;
//		}
//	case PORTE:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOE_DATA_PN0=Level_Value;
//		case PN1:
//			 GPIOE_DATA_PN1=Level_Value;
//		case PN2:
//			 GPIOE_DATA_PN2=Level_Value;
//		case PN3:
//			 GPIOE_DATA_PN3=Level_Value;
//		case PN4:
//			 GPIOE_DATA_PN4=Level_Value;
//		case PN5:
//			 GPIOE_DATA_PN5=Level_Value;
//		default:
//			return NOT_OK;
//		}
//	case PORTF:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOF_DATA_PN0=Level_Value;
//		case PN1:
//			 GPIOF_DATA_PN1=Level_Value;
//		case PN2:
//			 GPIOF_DATA_PN2=Level_Value;
//		case PN3:
//			 GPIOF_DATA_PN3=Level_Value;
//		case PN4:
//			 GPIOF_DATA_PN4=Level_Value;
//		default:
//			return NOT_OK;
//		}
//	default:
//		return NOT_OK;
//	}
//
//}
//

/******************************************************************************
* \Syntax          :Std_ReturnType DIO_WriteChannel (GPIO_ChannelType Channel_ID,
								                     GPIO_PortType Port_ID,
								                     GPIO_LevelChannelType Level_Value);


* \Description     : set pin level high or low
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID >>  pin number
*                    Port_ID    >>  port number
*                    Level_Value>>  pin state
* \Parameters (out): None
* \Return value:   : Std_ReturnType      OK
*                                        NOT_OK
*
*******************************************************************************/
Std_ReturnType DIO_WriteChannel (GPIO_PortType Port_ID,
								 GPIO_ChannelType Channel_ID,
								 GPIO_LevelChannelType Level_Value)
{
#if (BIT_BANDING == 1 )
		switch (Port_ID)
		{
		case PORTA:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOA_DATA, Channel_ID)))=Level_Value ;
			break;
		case PORTB:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOB_DATA, Channel_ID)))=Level_Value ;
			break;
		case PORTC:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOC_DATA, Channel_ID)))=Level_Value ;
			break;
		case PORTD:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOD_DATA, Channel_ID)))=Level_Value ;
			break;
		case PORTE:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOE_DATA, Channel_ID)))=Level_Value ;
			break;
		case PORTF:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOF_DATA, Channel_ID)))= Level_Value ;
			break;
		}
#else
	switch (Port_ID)
	{
	case PORTA:
		switch (Level_Value)
		{
		case 0:
			Clear_Pin(GPIOA_DATA_PORT, Channel_ID);
			break;
		case 1:
			Set_Pin(GPIOA_DATA_PORT, Channel_ID);
			break;
		}
		break;
	case PORTB:
		switch (Level_Value)
		{
		case 0:
			Clear_Pin(GPIOB_DATA_PORT, Channel_ID);
			break;
		case 1:
			Set_Pin(GPIOB_DATA_PORT, Channel_ID);
			break;
		}
		break;
	case PORTC:
		switch (Level_Value)
		{
		case 0:
			Clear_Pin(GPIOC_DATA_PORT, Channel_ID);
			break;
		case 1:
			Set_Pin(GPIOC_DATA_PORT, Channel_ID);
			break;
		}
		break;
	case PORTD:
		switch (Level_Value)
		{
		case 0:
			Clear_Pin(GPIOD_DATA_PORT, Channel_ID);
			break;
		case 1:
			Set_Pin(GPIOD_DATA_PORT, Channel_ID);
			break;
		}
		break;
	case PORTE:
		switch (Level_Value)
		{
		case 0:
			Clear_Pin(GPIOE_DATA_PORT, Channel_ID);
			break;
		case 1:
			Set_Pin(GPIOE_DATA_PORT, Channel_ID);
			break;
		}
		break;
	case PORTF:
		switch (Level_Value)
		{
		case 0:
			Clear_Pin(GPIOF_DATA_PORT, Channel_ID);
			break;
		case 1:
			Set_Pin(GPIOF_DATA_PORT, Channel_ID);
			break;
		}
		break;
	}
#endif
}


///******************************************************************************
//* \Syntax          :Std_ReturnType DIO_FlipChannel (GPIO_ChannelType Channel_ID,
//*                                                   GPIO_PortType Port_ID);
//
//* \Description     : Toggle pin
//*
//* \Sync\Async      : Synchronous
//* \Reentrancy      : Reentrant
//* \Parameters (in) : Channel_ID >>  pin number
//*                    Port_ID    >>  port number
//* \Parameters (out): None
//* \Return value:   : Std_ReturnType      OK
//*                                        NOT_OK
//*
//*******************************************************************************/
//Std_ReturnType DIO_FlipChannel (GPIO_PortType Port_ID,GPIO_ChannelType Channel_ID)
//{
//	switch (Port_ID)
//	{
//	case PORTA:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOA_DATA_PN0  ^=  1 ;
//		case PN1:
//			 GPIOA_DATA_PN1 ^=  1 ;
//		case PN2:
//			 GPIOA_DATA_PN2 ^=  1 ;
//		case PN3:
//			 GPIOA_DATA_PN3 ^=  1 ;
//		case PN4:
//			 GPIOA_DATA_PN4 ^=  1 ;
//		case PN5:
//			 GPIOA_DATA_PN5 ^=  1 ;
//		case PN6:
//			 GPIOA_DATA_PN6 ^=  1 ;
//		case PN7:
//			 GPIOA_DATA_PN7 ^=  1 ;
//		default:
//			return NOT_OK;
//		}
//	case PORTB:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOB_DATA_PN0 ^=  1 ;
//		case PN1:
//			 GPIOB_DATA_PN1 ^=  1 ;
//		case PN2:
//			 GPIOB_DATA_PN2 ^=  1 ;
//		case PN3:
//			 GPIOB_DATA_PN3 ^=  1 ;
//		case PN4:
//			 GPIOB_DATA_PN4 ^=  1 ;
//		case PN5:
//			 GPIOB_DATA_PN5 ^=  1 ;
//		case PN6:
//			 GPIOB_DATA_PN6 ^=  1 ;
//		case PN7:
//			 GPIOB_DATA_PN7 ^=  1 ;
//		default:
//			return NOT_OK;
//		}
//	case PORTC:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOC_DATA_PN0 ^=  1 ;
//		case PN1:
//			 GPIOC_DATA_PN1 ^=  1 ;
//		case PN2:
//			 GPIOC_DATA_PN2 ^=  1 ;
//		case PN3:
//			 GPIOC_DATA_PN3 ^=  1 ;
//		case PN4:
//			 GPIOC_DATA_PN4 ^=  1 ;
//		case PN5:
//			 GPIOC_DATA_PN5 ^=  1 ;
//		case PN6:
//			 GPIOC_DATA_PN6 ^=  1 ;
//		case PN7:
//			 GPIOC_DATA_PN7 ^=  1 ;
//		default:
//			return NOT_OK;
//		}
//	case PORTD:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOD_DATA_PN0 ^=  1 ;
//		case PN1:
//			 GPIOD_DATA_PN1 ^=  1 ;
//		case PN2:
//			 GPIOD_DATA_PN2 ^=  1 ;
//		case PN3:
//			 GPIOD_DATA_PN3 ^=  1 ;
//		case PN4:
//			 GPIOD_DATA_PN4 ^=  1 ;
//		case PN5:
//			 GPIOD_DATA_PN5 ^=  1 ;
//		case PN6:
//			 GPIOD_DATA_PN6 ^=  1 ;
//		case PN7:
//			 GPIOD_DATA_PN7 ^=  1 ;
//		default:
//			return NOT_OK;
//		}
//	case PORTE:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOE_DATA_PN0 ^=  1 ;
//		case PN1:
//			 GPIOE_DATA_PN1 ^=  1 ;
//		case PN2:
//			 GPIOE_DATA_PN2 ^=  1 ;
//		case PN3:
//			 GPIOE_DATA_PN3 ^=  1 ;
//		case PN4:
//			 GPIOE_DATA_PN4 ^=  1 ;
//		case PN5:
//			 GPIOE_DATA_PN5 ^=  1 ;
//		default:
//			return NOT_OK;
//		}
//	case PORTF:
//		switch (Channel_ID)
//		{
//		case PN0:
//			 GPIOF_DATA_PN0 ^=  1 ;
//		case PN1:
//			 GPIOF_DATA_PN1 ^=  1 ;
//		case PN2:
//			 GPIOF_DATA_PN2 ^=  1 ;
//		case PN3:
//			 GPIOF_DATA_PN3 ^=  1 ;
//		case PN4:
//			 GPIOF_DATA_PN4 ^=  1 ;
//		default:
//			return NOT_OK;
//		}
//	default:
//		return NOT_OK;
//	}
//
//}

	/******************************************************************************
	* \Syntax          :Std_ReturnType DIO_FlipChannel (GPIO_ChannelType Channel_ID,
	*                                                   GPIO_PortType Port_ID);

	* \Description     : Toggle pin
	*
	* \Sync\Async      : Synchronous
	* \Reentrancy      : Reentrant
	* \Parameters (in) : Channel_ID >>  pin number
	*                    Port_ID    >>  port number
	* \Parameters (out): None
	* \Return value:   : Std_ReturnType      OK
	*                                        NOT_OK
	*
	*******************************************************************************/
void DIO_FlipChannel(GPIO_PortType Port_ID, GPIO_ChannelType Channel_ID)
{
#if (BIT_BANDING == 1 )
		switch (Port_ID)
		{
		case PORTA:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOA_DATA, Channel_ID))) ^= 1 ;
			break;
		case PORTB:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOB_DATA, Channel_ID))) ^= 1 ;
			break;
		case PORTC:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOC_DATA, Channel_ID))) ^= 1 ;
			break;
		case PORTD:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOD_DATA, Channel_ID))) ^= 1 ;
			break;
		case PORTE:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOE_DATA, Channel_ID))) ^= 1 ;
			break;
		case PORTF:
			 *((volatile uint32_t *)(BITBAND_PERI(GPIOF_DATA, Channel_ID))) ^= 1 ;
			break;
		}
#else


	switch (Port_ID)
	{
	case PORTA:
		Toggle_Pin(GPIOA_DATA_PORT, Channel_ID);
		break;
	case PORTB:
		Toggle_Pin(GPIOB_DATA_PORT, Channel_ID);
		break;
	case PORTC:
		Toggle_Pin(GPIOC_DATA_PORT, Channel_ID);
		break;
	case PORTD:
		Toggle_Pin(GPIOD_DATA_PORT, Channel_ID);
		break;
	case PORTE:
		Toggle_Pin(GPIOE_DATA_PORT, Channel_ID);
		break;
	case PORTF:
		Toggle_Pin(GPIOF_DATA_PORT, Channel_ID);
		break;
	}
#endif
}

/******************************************************************************
* \Syntax          : GPIO_LevelPortType DIO_ReadPort (GPIO_PortType Port_ID)


* \Description     : read port
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Port_ID    >>  port number
*
* \Parameters (out): None
* \Return value:   : GPIO_LevelPortType   port_reading_value
*                                          NOT_OK
*
*******************************************************************************/
GPIO_LevelPortType DIO_ReadPort (GPIO_PortType Port_ID)
{
	switch (Port_ID)
	{
	case PORTA:
		return GPIOA_DATA_PORT;
	case PORTB:
		return GPIOB_DATA_PORT;
	case PORTC:
		return GPIOC_DATA_PORT;
	case PORTD:
		return GPIOD_DATA_PORT;
	case PORTE:
		return GPIOE_DATA_PORT;
	case PORTF:
		return GPIOF_DATA_PORT;

	}
}

	/******************************************************************************
	* \Syntax          : Std_ReturnType DIO_WritePort (GPIO_PortType Port_ID,
	*                                                  GPIO_LevelPortType Level_Value)

	* \Description     : Write port
	*
	* \Sync\Async      : Synchronous
	* \Reentrancy      : Reentrant
	* \Parameters (in) : Port_ID     >>  port number
	*                    Level_Value >>  port value
	* \Parameters (out): None
	* \Return value:   : Std_ReturnType       OK
	*                                        NOT_OK
	*
	*******************************************************************************/
Std_ReturnType DIO_WritePort (GPIO_PortType Port_ID,GPIO_LevelPortType Level_Value)
	{
		switch (Port_ID)
		{
		case PORTA:
			GPIOA_DATA_PORT = Level_Value;
		case PORTB:
			GPIOB_DATA_PORT = Level_Value;
		case PORTC:
			GPIOC_DATA_PORT = Level_Value;
		case PORTD:
			GPIOD_DATA_PORT = Level_Value;
		case PORTE:
			GPIOE_DATA_PORT = Level_Value;
		case PORTF:
			GPIOF_DATA_PORT = Level_Value;
		default:
			return NOT_OK;
		}

	}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/


