/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  port.c
 *        \brief  static code for initiation GPIO
 *                static APIs
 *                --
 *
 *      \details
 *
 ***********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 22/8/2022
 **********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "port.h"



/******************************************************************************
* \Syntax          : static Std_ReturnType PIN_SetDirection            (GPIO_PortType Port_ID,
												                        GPIO_ChannelType Channel_ID,
									                                     GPIO_PinDirectionType Direction)


* \Description     :Select direction of pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID >>  pin number
*                    Port_ID    >>  port number
*                    Direction  >>  input | output
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_SetDirection            (GPIO_PortType Port_ID,
												   GPIO_ChannelType Channel_ID,
									               GPIO_PinDirectionType Direction)
{
	if  (  (Port_ID      > PORTF)   |
	       (Channel_ID   > PN7)     |
	       (Direction    > OUTPUT)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (Direction == OUTPUT)
			{
				Set_Pin(GPIOA_DIR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_DIR,Channel_ID);
			}
			break;
		case PORTB:
			if (Direction == OUTPUT)
			{
				Set_Pin(GPIOB_DIR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_DIR,Channel_ID);
			}
			break;
		case PORTC:
			if (Direction == OUTPUT)
			{
				Set_Pin(GPIOC_DIR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_DIR,Channel_ID);
			}
			break;
		case PORTD:
			if (Direction == OUTPUT)
			{
				Set_Pin(GPIOD_DIR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_DIR,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (Direction == OUTPUT)
				{
					Set_Pin(GPIOE_DIR,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_DIR,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (Direction == OUTPUT)
				{
					Set_Pin(GPIOF_DIR,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_DIR,Channel_ID);
				}
			}
			break;
		}
	}
return 0;
}

/*******************************************************************************/
/******************************************************************************
* \Syntax          : static Std_ReturnType PIN_SetDigitalEnable        (GPIO_PortType Port_ID,
												                        GPIO_ChannelType Channel_ID,
											                            GPIO_PinDigitalEnableType DigEn)
* \Description     :set digital enable of pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID >>  pin number
*                    Port_ID    >>  port number
*                    DigEn      >>  set digital enable
* \Parameters (out): None
* \Return value:   : static Std_ReturnType        OK
*                                                 NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_SetDigitalEnable        (GPIO_PortType Port_ID,
												   GPIO_ChannelType Channel_ID,
											       GPIO_PinDigitalEnableType DigEn)
{
	if (  (Port_ID    > PORTF)             |
	     (Channel_ID > PN7)                |
		 (DigEn      > SET_DIGITAL_ENABLE)
	   )
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (DigEn == SET_DIGITAL_ENABLE)
			{
				Set_Pin(GPIOA_DEN,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_DEN,Channel_ID);
			}
			break;
		case PORTB:
			if (DigEn == SET_DIGITAL_ENABLE)
			{
				Set_Pin(GPIOB_DEN,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_DEN,Channel_ID);
			}
			break;
		case PORTC:
			if (DigEn == SET_DIGITAL_ENABLE)
			{
				Set_Pin(GPIOC_DEN,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_DEN,Channel_ID);
			}
			break;
		case PORTD:
			if (DigEn == SET_DIGITAL_ENABLE)
			{
				Set_Pin(GPIOD_DEN,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_DEN,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (DigEn == SET_DIGITAL_ENABLE)
				{
					Set_Pin(GPIOE_DEN,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_DEN,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (DigEn == SET_DIGITAL_ENABLE)
				{
					Set_Pin(GPIOF_DEN,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_DEN,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}

/*******************************************************************************/

/******************************************************************************
* \Syntax          : static Std_ReturnType PIN_SetPullUp               ( GPIO_PortType Port_ID,
													                     GPIO_ChannelType Channel_ID,
											                             GPIO_PinPullUpType PullUp_state)
* \Description     :set  pull up attach of pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    PullUp_state      >>  pull up attach
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_SetPullUp               ( GPIO_PortType Port_ID,
													GPIO_ChannelType Channel_ID,
											        GPIO_PinPullUpType PullUp_state)
{
	if (
		(Port_ID      > PORTF)             |
	    (Channel_ID   > PN7)               |
		(PullUp_state > SET_PULL_UP)
	   )
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (PullUp_state == SET_PULL_UP)
			{
				Set_Pin(GPIOA_PUR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_PUR,Channel_ID);
			}
			break;
		case PORTB:
			if (PullUp_state == SET_PULL_UP)
			{
				Set_Pin(GPIOB_PUR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_PUR,Channel_ID);
			}
		case PORTC:
			if (PullUp_state == SET_PULL_UP)
			{
				Set_Pin(GPIOC_PUR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_PUR,Channel_ID);
			}
			break;
		case PORTD:
			if (PullUp_state == SET_PULL_UP)
			{
				Set_Pin(GPIOD_PUR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_PUR,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (PullUp_state == SET_PULL_UP)
				{
					Set_Pin(GPIOE_PUR,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_PUR,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (PullUp_state == SET_PULL_UP)
				{
					Set_Pin(GPIOF_PUR,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_PUR,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}

/*******************************************************************************/

/******************************************************************************
* \Syntax          :static Std_ReturnType PIN_SetPullDown             (GPIO_PortType Port_ID,
											                    	   GPIO_ChannelType Channel_ID,
										                               GPIO_PinPullDownType PullDown_state)
* \Description     :set  pull down attach of pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    PullUp_state      >>  pull down attach
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_SetPullDown             (GPIO_PortType Port_ID,
												   GPIO_ChannelType Channel_ID,
										           GPIO_PinPullDownType PullDown_state)
{
	if (  (Port_ID        > PORTF)             |
	      (Channel_ID     > PN7)               |
		  (PullDown_state > SET_PULL_DOWN)
	   )
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (PullDown_state == SET_PULL_DOWN)
			{
				Set_Pin(GPIOA_PDR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_PDR,Channel_ID);
			}
			break;
		case PORTB:
			if (PullDown_state == SET_PULL_DOWN)
			{
				Set_Pin(GPIOB_PDR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_PDR,Channel_ID);
			}
			break;
		case PORTC:
			if (PullDown_state == SET_PULL_DOWN)
			{
				Set_Pin(GPIOC_PDR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_PDR,Channel_ID);
			}
			break;
		case PORTD:
			if (PullDown_state == SET_PULL_DOWN)
			{
				Set_Pin(GPIOD_PDR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_PDR,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (PullDown_state == SET_PULL_DOWN)
				{
					Set_Pin(GPIOE_PDR,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_PDR,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (PullDown_state == SET_PULL_DOWN)
				{
					Set_Pin(GPIOF_PDR,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_PDR,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}

/*******************************************************************************/

/******************************************************************************
* \Syntax          : static Std_ReturnType PIN_SetOpenDrain           (GPIO_PortType Port_ID,
											                      	   GPIO_ChannelType Channel_ID,
										                               GPIO_PinOpenDrainType OpenDrain_state)
* \Description     :set  open drain attach of pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    PullUp_state      >>  open drain attach
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_SetOpenDrain           (GPIO_PortType Port_ID,
												  GPIO_ChannelType Channel_ID,
										          GPIO_PinOpenDrainType OpenDrain_state)
{
	if (  (Port_ID         > PORTF)             |
	      (Channel_ID      > PN7)               |
		  (OpenDrain_state > SET_OPEN_DRAIN)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (OpenDrain_state == SET_OPEN_DRAIN)
			{
				Set_Pin(GPIOA_ODR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_ODR,Channel_ID);
			}
			break;
		case PORTB:
			if (OpenDrain_state == SET_OPEN_DRAIN)
			{
				Set_Pin(GPIOB_ODR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_ODR,Channel_ID);
			}
			break;
		case PORTC:
			if (OpenDrain_state == SET_OPEN_DRAIN)
			{
				Set_Pin(GPIOC_ODR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_ODR,Channel_ID);
			}
			break;
		case PORTD:
			if (OpenDrain_state == SET_OPEN_DRAIN)
			{
				Set_Pin(GPIOD_ODR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_ODR,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (OpenDrain_state == SET_OPEN_DRAIN)
				{
					Set_Pin(GPIOE_ODR,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_ODR,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (OpenDrain_state == SET_OPEN_DRAIN)
				{
					Set_Pin(GPIOF_ODR,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_ODR,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}


/******************************************************************************
* \Syntax          : Std_ReturnType PIN_SetSlewRate             (GPIO_ChannelType Channel_ID,
									                             GPIO_PortType Port_ID,
										                         GPIO_PinSlewRateType SlewRate_state);

* \Description     :set  slew rate attach of pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    PullUp_state      >>  slew rate attach
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_SetSlewRate             (GPIO_PortType Port_ID,
												   GPIO_ChannelType Channel_ID,
											       GPIO_PinSlewRateType SlewRate_state)
{
	if (   (Port_ID      > PORTF)             |
	       (Channel_ID   > PN7)               |
		   (SlewRate_state > SET_SLEW_RARE)
	   )
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (SlewRate_state == SET_SLEW_RARE)
			{
				Set_Pin(GPIOA_SLR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_SLR,Channel_ID);
			}
			break;
		case PORTB:
			if (SlewRate_state == SET_SLEW_RARE)
			{
				Set_Pin(GPIOB_SLR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_SLR,Channel_ID);
			}
			break;
		case PORTC:
			if (SlewRate_state == SET_SLEW_RARE)
			{
				Set_Pin(GPIOC_SLR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_SLR,Channel_ID);
			}
			break;
		case PORTD:
			if (SlewRate_state == SET_SLEW_RARE)
			{
				Set_Pin(GPIOD_SLR,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_SLR,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (SlewRate_state == SET_SLEW_RARE)
				{
					Set_Pin(GPIOE_SLR,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_SLR,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (SlewRate_state == SET_SLEW_RARE)
				{
					Set_Pin(GPIOF_SLR,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_SLR,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}



/***************************************************************************************/
/******************************************************************************
* \Syntax          :  Std_ReturnType PIN_MaskInterrupt           ( GPIO_PortType Port_ID,
												                       	GPIO_ChannelType Channel_ID,
										                             	GPIO_InterruptMaskType int_mode)

* \Description     : pin mask interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    int_mode          >>  pin mask interrupt
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
 Std_ReturnType PIN_MaskInterrupt           ( GPIO_PortType Port_ID,
													GPIO_ChannelType Channel_ID,
										         	GPIO_InterruptMaskType int_mode)
{
	if (  (Port_ID      > PORTF)             |
	      (Channel_ID   > PN7)               |
		  (int_mode     > INT_UNMASKED)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (int_mode == INT_UNMASKED)
			{
				Set_Pin(GPIOA_IM,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_IM,Channel_ID);
			}
			break;
		case PORTB:
			if (int_mode == INT_UNMASKED)
			{
				Set_Pin(GPIOB_IM,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_IM,Channel_ID);
			}
			break;
		case PORTC:
			if (int_mode == INT_UNMASKED)
			{
				Set_Pin(GPIOC_IM,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_IM,Channel_ID);
			}
			break;
		case PORTD:
			if (int_mode == INT_UNMASKED)
			{
				Set_Pin(GPIOD_IM,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_IM,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (int_mode == INT_UNMASKED)
				{
					Set_Pin(GPIOE_IM,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_IM,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (int_mode == INT_UNMASKED)
				{
					Set_Pin(GPIOF_IM,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_IM,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}



/***************************************************************************************/
/******************************************************************************
* \Syntax          : Std_ReturnType PIN_SenseInterrupt          (GPIO_PortType Port_ID,
												                       GPIO_ChannelType Channel_ID,
										                               GPIO_InterruptSenseType sense )
* \Description     :set level or edge interrupt sense
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    sense             >>  set level or edge interrupt sense
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
 Std_ReturnType PIN_SenseInterrupt          (GPIO_PortType Port_ID,
												   GPIO_ChannelType Channel_ID,
										           GPIO_InterruptSenseType sense )
{
	if (  (Port_ID      > PORTF)             |
	      (Channel_ID   > PN7)               |
	      (sense        > LEVEL_SENSE)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (sense == LEVEL_SENSE)
			{
				Set_Pin(GPIOA_IS,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_IS,Channel_ID);
			}
			break;
		case PORTB:
			if (sense == LEVEL_SENSE)
			{
				Set_Pin(GPIOB_IS,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_IS,Channel_ID);
			}
			break;
		case PORTC:
			if (sense == LEVEL_SENSE)
			{
				Set_Pin(GPIOC_IS,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_IS,Channel_ID);
			}
			break;
		case PORTD:
			if (sense == LEVEL_SENSE)
			{
				Set_Pin(GPIOD_IS,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_IS,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (sense == LEVEL_SENSE)
				{
					Set_Pin(GPIOE_IS,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_IS,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (sense == LEVEL_SENSE)
				{
					Set_Pin(GPIOF_IS,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_IS,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}



/***************************************************************************************/

/******************************************************************************
* \Syntax           Std_ReturnType PIN_BothInterrupt           ( GPIO_PortType Port_ID,
													                   GPIO_ChannelType Channel_ID,
										         	                   GPIO_InterruptBothType both_mode )
* \Description     :set both edges or not
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    both_mode         >>  set both edges or not
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
 Std_ReturnType PIN_BothInterrupt                 ( GPIO_PortType Port_ID,
													GPIO_ChannelType Channel_ID,
										         	GPIO_InterruptBothType both_mode )
{
	if (  (Port_ID      > PORTF)             |
	      (Channel_ID   > PN7)               |
	      (both_mode    > BOTH_EDGES)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (both_mode == BOTH_EDGES)
			{
				Set_Pin(GPIOA_IBE ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_IBE ,Channel_ID);
			}
			break;
		case PORTB:
			if (both_mode == BOTH_EDGES)
			{
				Set_Pin(GPIOB_IBE ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_IBE ,Channel_ID);
			}
			break;
		case PORTC:
			if (both_mode == BOTH_EDGES)
			{
				Set_Pin(GPIOC_IBE ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_IBE ,Channel_ID);
			}
			break;
		case PORTD:
			if (both_mode == BOTH_EDGES)
			{
				Set_Pin(GPIOD_IBE ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_IBE ,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (both_mode == BOTH_EDGES)
				{
					Set_Pin(GPIOE_IBE ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_IBE ,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (both_mode == BOTH_EDGES)
				{
					Set_Pin(GPIOF_IBE ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_IBE ,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}


/***************************************************************************************/

/******************************************************************************
* \Syntax        Std_ReturnType PIN_EventInterrupt          ( GPIO_PortType Port_ID,
										                  	  GPIO_ChannelType Channel_ID,
										                      GPIO_InterruptEventType trigger_state )
* \Description     :set trigger state raising-high or falling-low
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    trigger_state     >>  set trigger state raising-high or falling-low
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
Std_ReturnType PIN_EventInterrupt          ( GPIO_PortType Port_ID,
											 GPIO_ChannelType Channel_ID,
										     GPIO_InterruptEventType trigger_state )
{
	if (  (Port_ID       > PORTF)             |
	      (Channel_ID    > PN7)               |
		  (trigger_state > RAISING_HIGH)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (trigger_state == RAISING_HIGH)
			{
				Set_Pin(GPIOA_IEV  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_IEV  ,Channel_ID);
			}
			break;
		case PORTB:
			if (trigger_state == RAISING_HIGH)
			{
				Set_Pin(GPIOB_IEV  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_IEV  ,Channel_ID);
			}
			break;
		case PORTC:
			if (trigger_state == RAISING_HIGH)
			{
				Set_Pin(GPIOC_IEV  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_IEV  ,Channel_ID);
			}
			break;
		case PORTD:
			if (trigger_state == RAISING_HIGH)
			{
				Set_Pin(GPIOD_IEV  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_IEV  ,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (trigger_state == RAISING_HIGH)
				{
					Set_Pin(GPIOE_IEV  ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_IEV  ,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (trigger_state == RAISING_HIGH)
				{
					Set_Pin(GPIOF_IEV  ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_IEV  ,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}


/***************************************************************************************/

/******************************************************************************
* \Syntax        Std_ReturnType PIN_MaskedStatusInterrupt          (GPIO_PortType     Port_ID,
												                   GPIO_ChannelType  Channel_ID)
* \Description     :Read masked status interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
 Std_ReturnType PIN_MaskedStatusInterrupt          (GPIO_PortType     Port_ID,
												    GPIO_ChannelType  Channel_ID)

{
	if (   (Port_ID       > PORTF) |
	       (Channel_ID    > PN7)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
				return Read_Pin(GPIOA_MIS  ,Channel_ID);

		case PORTB:
				return Read_Pin(GPIOB_MIS  ,Channel_ID);

		case PORTC:
				return Read_Pin(GPIOC_MIS  ,Channel_ID);

		case PORTD:
				return Read_Pin(GPIOD_MIS  ,Channel_ID);

		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				return Read_Pin(GPIOE_MIS  ,Channel_ID);
			}

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				return Read_Pin(GPIOF_MIS  ,Channel_ID);
			}
		}
	}
	return 0;
}


/******************************************************************************
* \Syntax         Std_ReturnType PIN_RawStatusInterrupt      (GPIO_PortType Port_ID,
										                  	 GPIO_ChannelType Channel_ID )
* \Description     :Read masked status interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
 Std_ReturnType PIN_RawStatusInterrupt      (GPIO_PortType Port_ID,
											 GPIO_ChannelType Channel_ID )
{
	if ( (Port_ID       > PORTF) |
	     (Channel_ID    > PN7)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
				return Read_Pin(GPIOA_RIS  ,Channel_ID);

		case PORTB:
				return Read_Pin(GPIOB_RIS  ,Channel_ID);

		case PORTC:
				return Read_Pin(GPIOC_RIS  ,Channel_ID);

		case PORTD:
				return Read_Pin(GPIOD_RIS  ,Channel_ID);

		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				return Read_Pin(GPIOE_RIS  ,Channel_ID);
			}

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				return Read_Pin(GPIOF_RIS  ,Channel_ID);
			}
		}
	}
	return 0;
}


/***************************************************************************************/

/******************************************************************************
* \Syntax        Std_ReturnType PIN_ClearInterrupt          ( GPIO_PortType    Port_ID,
											                  GPIO_ChannelType Channel_ID )
* \Description     :clear interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
 Std_ReturnType PIN_ClearInterrupt          ( GPIO_PortType    Port_ID,
											  GPIO_ChannelType Channel_ID )
{
	if (  (Port_ID       > PORTF) |
	      (Channel_ID    > PN7)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
				Set_Pin(GPIOA_ICR   ,Channel_ID);
				break;

		case PORTB:
				Set_Pin(GPIOB_ICR   ,Channel_ID);
				break;

		case PORTC:
				Set_Pin(GPIOC_ICR   ,Channel_ID);
				break;

		case PORTD:
				Set_Pin(GPIOD_ICR   ,Channel_ID);
				break;

		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				Set_Pin(GPIOE_ICR   ,Channel_ID);
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				Set_Pin(GPIOF_ICR   ,Channel_ID);
			}
			break;
		}
	}
	return 0 ;
}


/***************************************************************************************/


/******************************************************************************
* \Syntax           Std_ReturnType PIN_Lock                     (GPIO_PortType Port_ID,
										                       GPIO_LockType lock_state);
* \Description     :unlock protected pins
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID         >>  pin number
*                    lock_state         >>  lock status
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
 Std_ReturnType     PIN_Lock                     (GPIO_PortType Port_ID,
											      GPIO_LockType lock_state)
{
	if ( lock_state    >  UNLOCKED )

	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (lock_state == UNLOCKED)
			{
				GPIOA_LOCK = 0x4C4F434B;
			}
			else
			{
				GPIOA_LOCK = 0;
			}
			break;
		case PORTB:
			if (lock_state == UNLOCKED)
			{
				GPIOB_LOCK = 0x4C4F434B;
			}
			else
			{
				GPIOB_LOCK = 0;
			}
			break;
		case PORTC:
			if (lock_state == UNLOCKED)
			{
				GPIOC_LOCK = 0x4C4F434B;
			}
			else
			{
				GPIOC_LOCK = 0;
			}
			break;
		case PORTD:
			if (lock_state == UNLOCKED)
			{
				GPIOD_LOCK = 0x4C4F434B;
			}
			else
			{
				GPIOD_LOCK = 0;
			}
			break;
		case PORTE:

			if (lock_state == UNLOCKED)
			{
				GPIOE_LOCK = 0x4C4F434B;
			}
			else
			{
				GPIOE_LOCK = 0;
			}
			break;
		case PORTF:
			if (lock_state == UNLOCKED)
			{
				GPIOF_LOCK = 0x4C4F434B;
			}
			else
			{
				GPIOF_LOCK = 0;
			}
			break;
		}
	}
	return 0;
}

/******************************************************************************
* \Syntax       Std_ReturnType PIN_Commit                   (GPIO_PortType Port_ID,
											                 GPIO_ChannelType Channel_ID);
* \Description     :PIN commit for unlocking
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
 Std_ReturnType PIN_Commit                   (GPIO_PortType Port_ID,
											 GPIO_ChannelType Channel_ID)
{
	if ((Port_ID       > PORTF) |
	    (Channel_ID    > PN7)
	   )
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
				Set_Pin(GPIOA_CR   ,Channel_ID);
				break;

		case PORTB:
				Set_Pin(GPIOB_CR   ,Channel_ID);
				break;

		case PORTC:
				Set_Pin(GPIOC_CR   ,Channel_ID);
				break;

		case PORTD:
				Set_Pin(GPIOD_CR   ,Channel_ID);
				break;

		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				Set_Pin(GPIOE_CR   ,Channel_ID);
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				Set_Pin(GPIOF_CR   ,Channel_ID);
			}
			break;
		}
	}
	return 0;
}

/******************************************************************************
* \Syntax         static Std_ReturnType PIN_PortControl             (GPIO_PortType Port_ID,
												   GPIO_ChannelType Channel_ID,
										           GPIO_PortControlType function )


* \Description     :selects the specific peripheral signal for each GPIO pin when using the alternate function mode
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    function          >>  specific peripheral signal
* \Parameters (out): None
* \Return value:   : static Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_PortControl             (GPIO_PortType Port_ID,
												   GPIO_ChannelType Channel_ID,
										           GPIO_PortControlType function )
{
	if (  (Port_ID       > PORTF)             |
	      (Channel_ID    > PN7)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			GPIOA_PCTL |= (function << (Channel_ID * 4));
			break;

		case PORTB:
			GPIOB_PCTL |= (function << (Channel_ID * 4));
			break;

		case PORTC:
			GPIOC_PCTL |= (function << (Channel_ID * 4));
			break;

		case PORTD:
			GPIOD_PCTL |= (function << (Channel_ID * 4));
			break;

		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				GPIOE_PCTL |= (function << (Channel_ID * 4));
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				GPIOF_PCTL |= (function << (Channel_ID * 4));
			}
			break;
		}
	}
	return 0;
}

/******************************************************************************
* \Syntax         static Std_ReturnType PIN_ADCControl              (GPIO_PortType Port_ID,
											                    	 GPIO_ChannelType Channel_ID,
											                         GPIO_ADCControlType state )
* \Description     : used to configure a GPIO pin as a source for the ADC trigger.
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    state             >>  set or reset
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_ADCControl              (GPIO_PortType Port_ID,
												   GPIO_ChannelType Channel_ID,
											       GPIO_ADCControlType state )
{
	if (    (Port_ID       > PORTF)             |
	        (Channel_ID    > PN7)               |
		   (state         > EN_ADC_TRI)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (state == EN_ADC_TRI)
			{
				Set_Pin(GPIOA_ADCCTL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_ADCCTL  ,Channel_ID);
			}
			break;
		case PORTB:
			if (state == EN_ADC_TRI)
			{
				Set_Pin(GPIOB_ADCCTL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_ADCCTL  ,Channel_ID);
			}
			break;
		case PORTC:
			if (state == EN_ADC_TRI)
			{
				Set_Pin(GPIOC_ADCCTL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_ADCCTL  ,Channel_ID);
			}
			break;
		case PORTD:
			if (state == EN_ADC_TRI)
			{
				Set_Pin(GPIOD_ADCCTL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_ADCCTL  ,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (state == EN_ADC_TRI)
				{
					Set_Pin(GPIOE_ADCCTL  ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_ADCCTL  ,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (state == EN_ADC_TRI)
				{
					Set_Pin(GPIOF_ADCCTL  ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_ADCCTL  ,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}


/***************************************************************************************/
/******************************************************************************
* \Syntax         Std_ReturnType PIN_DMAControl              ( GPIO_PortType Port_ID,
*                                                              GPIO_ChannelType Channel_ID,
 										                       GPIO_DMAControlType state )
* \Description     :used to configure a GPIO pin as a source for the DMA trigger.
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    state             >>  set or not
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_DMAControl              ( GPIO_PortType Port_ID,
													GPIO_ChannelType Channel_ID,
											        GPIO_DMAControlType state )
{
	if ( (Port_ID       > PORTF)             |
	     (Channel_ID    > PN7)               |
		 (state         > EN_DMA_TRI)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (state == EN_DMA_TRI)
			{
				Set_Pin(GPIOA_DMACTL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_DMACTL  ,Channel_ID);
			}
			break;
		case PORTB:
			if (state == EN_DMA_TRI)
			{
				Set_Pin(GPIOB_DMACTL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_DMACTL  ,Channel_ID);
			}
			break;
		case PORTC:
			if (state == EN_DMA_TRI)
			{
				Set_Pin(GPIOC_DMACTL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_DMACTL  ,Channel_ID);
			}
			break;
		case PORTD:
			if (state == EN_DMA_TRI)
			{
				Set_Pin(GPIOD_DMACTL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_DMACTL  ,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (state == EN_DMA_TRI)
				{
					Set_Pin(GPIOE_DMACTL  ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_DMACTL  ,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (state == EN_DMA_TRI)
				{
					Set_Pin(GPIOF_DMACTL  ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_DMACTL  ,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}


/***************************************************************************************/
/******************************************************************************
* \Syntax         static Std_ReturnType PIN_AnalogMode              ( GPIO_PortType Port_ID,
											                	   	GPIO_ChannelType Channel_ID,
										         	                  GPIO_AnalogType state )

* \Description     :     This register is only valid for ports and pins that can be used as ADC AINx inputs.
                         If any pin is to be used as an ADC input, the appropriate bit in GPIOAMSEL must be
                         set to disable the analog isolation circuit
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    PullUp_state      >>  slew rate attach
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_AnalogMode              ( GPIO_PortType Port_ID,
													GPIO_ChannelType Channel_ID,
										         	GPIO_AnalogType state )
{
	if ( (Port_ID       > PORTF)             |
	     (Channel_ID    > PN7)               |
	     (state         > SET_ANALOG)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (state == SET_ANALOG)
			{
				Set_Pin(GPIOA_AMSEL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_AMSEL  ,Channel_ID);
			}
			break;
		case PORTB:
			if (state == SET_ANALOG)
			{
				Set_Pin(GPIOB_AMSEL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_AMSEL  ,Channel_ID);
			}
			break;
		case PORTC:
			if (state == SET_ANALOG)
			{
				Set_Pin(GPIOC_AMSEL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_AMSEL  ,Channel_ID);
			}
			break;
		case PORTD:
			if (state == SET_ANALOG)
			{
				Set_Pin(GPIOD_AMSEL  ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_AMSEL  ,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (state == SET_ANALOG)
				{
					Set_Pin(GPIOE_AMSEL  ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_AMSEL  ,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (state == SET_ANALOG)
				{
					Set_Pin(GPIOF_AMSEL  ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_AMSEL  ,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}

/******************************************************************************
* \Syntax        static Std_ReturnType PIN_AlternativeFunction     (GPIO_PortType Port_ID,
												                    GPIO_ChannelType Channel_ID,
											                        GPIO_AlternativeFunctionType state )
{
* \Description     :Setting a bit in this register configures the
                    corresponding GPIO line to be controlled by an associated peripheral
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    state             >>  set or not
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_AlternativeFunction     (GPIO_PortType Port_ID,
												   GPIO_ChannelType Channel_ID,
											       GPIO_AlternativeFunctionType state )
{
	if (  (Port_ID       > PORTF)             |
	      (Channel_ID    > PN7)               |
	      (state         > SET_ALTERNATIVE)
		)
	{
		return NOT_OK ;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (state == SET_ALTERNATIVE)
			{
				Set_Pin(GPIOA_AFSEL   ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOA_AFSEL   ,Channel_ID);
			}
			break;
		case PORTB:
			if (state == SET_ALTERNATIVE)
			{
				Set_Pin(GPIOB_AFSEL   ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOB_AFSEL   ,Channel_ID);
			}
			break;
		case PORTC:
			if (state == SET_ALTERNATIVE)
			{
				Set_Pin(GPIOC_AFSEL   ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOC_AFSEL   ,Channel_ID);
			}
			break;
		case PORTD:
			if (state == SET_ALTERNATIVE)
			{
				Set_Pin(GPIOD_AFSEL   ,Channel_ID);
			}
			else
			{
				Clear_Pin(GPIOD_AFSEL   ,Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (state == SET_ALTERNATIVE)
				{
					Set_Pin(GPIOE_AFSEL   ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOE_AFSEL   ,Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (state == SET_ALTERNATIVE)
				{
					Set_Pin(GPIOF_AFSEL   ,Channel_ID);
				}
				else
				{
					Clear_Pin(GPIOF_AFSEL   ,Channel_ID);
				}
			}
			break;
		}
	}
	return 0;
}

/*************************************************************************************/
/******************************************************************************
* \Syntax        static Std_ReturnType PIN_CurrentDrive            ( GPIO_PortType Port_ID,
												                     GPIO_ChannelType Channel_ID,
											                         GPIO_PinOutputCurrentType drive )
* \Description     :drive control
*                   By default, all GPIO pins have 2-mA drive.
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID        >>  pin number
*                    Port_ID           >>  port number
*                    drive             >>  current value
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/
static Std_ReturnType PIN_CurrentDrive            ( GPIO_PortType Port_ID,
													GPIO_ChannelType Channel_ID,
											        GPIO_PinOutputCurrentType drive )
{
	if ((Port_ID > PORTF) | (Channel_ID > PN7) | (drive > CURRENT_8MA))
	{
		return NOT_OK;
	}
	else
	{
		switch (Port_ID)
		{
		case PORTA:
			if (drive == CURRENT_2MA)
			{
				Set_Pin(GPIOA_DR2R, Channel_ID);
			}
			else if (drive == CURRENT_4MA)
			{
				Set_Pin(GPIOA_DR4R, Channel_ID);
			}
			else
			{
				Set_Pin(GPIOA_DR8R, Channel_ID);
			}
			break;
		case PORTB:
			if (drive == CURRENT_2MA)
			{
				Set_Pin(GPIOB_DR2R, Channel_ID);
			}
			else if (drive == CURRENT_4MA)
			{
				Set_Pin(GPIOB_DR4R, Channel_ID);
			}
			else
			{
				Set_Pin(GPIOB_DR8R, Channel_ID);
			}
			break;
		case PORTC:
			if (drive == CURRENT_2MA)
			{
				Set_Pin(GPIOC_DR2R, Channel_ID);
			}
			else if (drive == CURRENT_4MA)
			{
				Set_Pin(GPIOC_DR4R, Channel_ID);
			}
			else
			{
				Set_Pin(GPIOC_DR8R, Channel_ID);
			}
			break;
		case PORTD:
			if (drive == CURRENT_2MA)
			{
				Set_Pin(GPIOC_DR2R, Channel_ID);
			}
			else if (drive == CURRENT_4MA)
			{
				Set_Pin(GPIOC_DR4R, Channel_ID);
			}
			else
			{
				Set_Pin(GPIOC_DR8R, Channel_ID);
			}
			break;
		case PORTE:
			if (Channel_ID > PN5)
			{
				return NOT_OK;
			}
			else
			{
				if (drive == CURRENT_2MA)
				{
					Set_Pin(GPIOE_DR2R, Channel_ID);
				}
				else if (drive == CURRENT_4MA)
				{
					Set_Pin(GPIOE_DR4R, Channel_ID);
				}
				else
				{
					Set_Pin(GPIOE_DR8R, Channel_ID);
				}
			}
			break;

		case PORTF:
			if (Channel_ID > PN4)
			{
				return NOT_OK;
			}
			else
			{
				if (drive == CURRENT_2MA)
				{
					Set_Pin(GPIOF_DR2R, Channel_ID);
				}
				else if (drive == CURRENT_4MA)
				{
					Set_Pin(GPIOF_DR4R, Channel_ID);
				}
				else
				{
					Set_Pin(GPIOF_DR8R, Channel_ID);
				}
			}
			break;
		}
	}
return 0;
}

/******************************************************************************
* \Syntax        Std_ReturnType  GPIO_Init (const GPIO_ConfigType *Port_ConfigPtr);

* \Description     :init GPIO Pins
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Port_ConfigPtr >> pointer to configuration array
* \Parameters (out): None
* \Return value:   : Std_ReturnType        OK
*                                          NOT_OK =-1
*******************************************************************************/

 Std_ReturnType GPIO_Init(const GPIO_ConfigType *Port_ConfigPtr)
{

	uint8_t i;
	for (i = 0; i < PIN_NUMBERS; i++)
	{
		if (Port_ConfigPtr[i].PinState == NON_CONFIGURED_PIN)
		{
		} /* do nothing */
		else
		{
/**************************************SET CLOCK **************************************************/

			switch (Port_ConfigPtr[i].PortType)
			{
			case PORTA:
				Enable_Peripheral_Clock(2, 0);
				break;
			case PORTB:
				Enable_Peripheral_Clock(2, 1);
				break;
			case PORTC:
				Enable_Peripheral_Clock(2, 2);
				break;
			case PORTD:
				Enable_Peripheral_Clock(2, 3);
				break;
			case PORTE:
				Enable_Peripheral_Clock(2, 4);
				break;
			case PORTF:
				Enable_Peripheral_Clock(2, 5);
				break;
			default: /*do nothing */
				break;
			}
/**************************************SET MODE**************************************************/
			switch (Port_ConfigPtr[i].PinMode)
			{
			case MODE_DIO:
				break;
			case MODE_ADC:
				PIN_ADCControl(Port_ConfigPtr[i].PortType,
							   Port_ConfigPtr[i].ChannelType,
								 EN_ADC_TRI);
				break;
			case MODE_DMA:
				PIN_DMAControl(Port_ConfigPtr[i].PortType,
							   Port_ConfigPtr[i].ChannelType,
								 EN_DMA_TRI);
				break;
			default:
				return NOT_OK;
			}
/**************************************SET DIRECTION**************************************************/

			switch (Port_ConfigPtr[i].PinDirection)
			{
			case INPUT:
				PIN_SetDirection(Port_ConfigPtr[i].PortType,
								 Port_ConfigPtr[i].ChannelType,
									INPUT);
				break;
			case OUTPUT:
				PIN_SetDirection(Port_ConfigPtr[i].PortType,
								 Port_ConfigPtr[i].ChannelType,
								 OUTPUT);
				break;
			default: /*do nothing*/
				break;
			}
/**************************************SET INTERNAL ATTACH *********************************************/

			switch (Port_ConfigPtr[i].PinIntrnalAttach)
			{
			case PULL_UP_ATTACH:
				PIN_SetPullUp(Port_ConfigPtr[i].PortType,
							  Port_ConfigPtr[i].ChannelType,
							    SET_PULL_UP);
				break;
			case PULL_DOWN_ATTACH:
				PIN_SetPullDown(Port_ConfigPtr[i].PortType,
								Port_ConfigPtr[i].ChannelType,
							    SET_PULL_DOWN);
				break;
			case OPEN_DRAIN_ATTACH:
				PIN_SetOpenDrain(Port_ConfigPtr[i].PortType,
								 Port_ConfigPtr[i].ChannelType,
								 SET_OPEN_DRAIN);
			case SLEW_RATE__ATTACH:
				PIN_SetSlewRate(Port_ConfigPtr[i].PortType,
								Port_ConfigPtr[i].ChannelType,
								 SET_SLEW_RARE);
				break;
			case NON_CONFIGUERED_ATTACH :
				break;               /*do nothing */
			default: /*do nothing */
				break;
			}
/**************************************SET PIN INITIAL LEVEL******************************************/

			switch (Port_ConfigPtr[i].PinLevel)
			{
			case PIN_LOW:
				DIO_WriteChannel(Port_ConfigPtr[i].PortType,
								 Port_ConfigPtr[i].ChannelType,
								 PIN_LOW);
				break;
			case PIN_HIGH:
				DIO_WriteChannel(Port_ConfigPtr[i].PortType,
								 Port_ConfigPtr[i].ChannelType,
								 PIN_HIGH);
				break;
			case NON_CONFIGURED:
				break;
			default: /*do nothing*/
				break;
			}
/**************************************SET CURRENT DRIVE ******************************************/
			switch (Port_ConfigPtr[i].PinOutputCurrent)
			{
			case CURRENT_2MA:
				PIN_CurrentDrive(Port_ConfigPtr[i].PortType,
								 Port_ConfigPtr[i].ChannelType,
								CURRENT_2MA);
				break;
			case CURRENT_4MA:
				PIN_CurrentDrive(Port_ConfigPtr[i].PortType,
								 Port_ConfigPtr[i].ChannelType,
								CURRENT_4MA);
				break;
			case CURRENT_8MA:
				PIN_CurrentDrive(Port_ConfigPtr[i].PortType,
									Port_ConfigPtr[i].ChannelType, CURRENT_8MA);

			default: /*do nothing */
				break;
			}
/******************************************************8******************************************/
/**************************************SET DIGITAL ENABLE ******************************************/
			switch (Port_ConfigPtr[i].PinDigitalStatus)
			{
			case RESET_DIGITAL_ENABLE:
				PIN_SetDigitalEnable(Port_ConfigPtr[i].PortType,
									Port_ConfigPtr[i].ChannelType, RESET_DIGITAL_ENABLE);
				break;
			case SET_DIGITAL_ENABLE:
				PIN_SetDigitalEnable(Port_ConfigPtr[i].PortType,
									Port_ConfigPtr[i].ChannelType, SET_DIGITAL_ENABLE);
				break;
			default: /*do nothing */
				break;
			}
			/******************************************************8******************************************/

		}
	}
	return 0;
}


