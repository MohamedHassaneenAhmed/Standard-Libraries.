
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: Port.h
 *       Module:  GPIO
 *
 *  Description:  static code for initiation GPIO
 *                static APIs
 *                --
 ************************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 22/8/2022
 **********************************************************************************************************************/

#ifndef GPIO_PORT_PORT_H_
#define GPIO_PORT_PORT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"GPIO_Types.h"
#include"GPIO_Reg.h"
#include"DIO.h"
#include"Macros.h"
#include"SysCtr.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define PIN_NUMBERS 43
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
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
										         	GPIO_InterruptMaskType int_mode);
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
										           GPIO_InterruptSenseType sense );
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
										         	GPIO_InterruptBothType both_mode );
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
										     GPIO_InterruptEventType trigger_state );

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
												    GPIO_ChannelType  Channel_ID);
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
											 GPIO_ChannelType Channel_ID );

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
											  GPIO_ChannelType Channel_ID );

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
											      GPIO_LockType lock_state);
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
											 GPIO_ChannelType Channel_ID);

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
Std_ReturnType  GPIO_Init (const GPIO_ConfigType *Port_ConfigPtr);


#endif /* GPIO_PORT_PORT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
