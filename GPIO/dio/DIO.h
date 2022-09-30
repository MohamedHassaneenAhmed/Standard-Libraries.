/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  DIO
 *
 *  Description:   -- APIs for :
 *                        - read & write & toggle pin
 *                        - read & write port
 *
*********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 20/8/2022
 *********************************************************************************************************************/
#ifndef GPIO_DIO_DIO_H_
#define GPIO_DIO_DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include"GPIO_Reg.h"
#include"GPIO_Types.h"
/**********************************************************************************************************************
 * CONFIGURATION MACROS
 *********************************************************************************************************************/
#define BIT_BANDING       0       /*Set 1 for bit banding
                                          0 for bit masking
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : DIO_LevelChannelType DIO_ReadChannel (DIO_ChannelType Channel_ID,
*                                                          DIO_PortType Port_ID);

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
GPIO_LevelChannelType DIO_ReadChannel (GPIO_PortType Port_ID,GPIO_ChannelType Channel_ID);


/******************************************************************************
* \Syntax          : Std_ReturnType DIO_WriteChannel (DIO_ChannelType Channel_ID,
*                                           DIO_PortType Port_ID,
*                                           DIO_LevelChannelType Level_Value);


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
								 GPIO_LevelChannelType Level_Value);

/******************************************************************************
* \Syntax          : void      DIO_FlipChannel      (DIO_ChannelType Channel_ID,
*                                                    DIO_PortType Port_ID);

* \Description     : Toggle pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel_ID >>  pin number
*                    Port_ID    >>  port number
* \Parameters (out): None
* \Return value:   : None
*
*******************************************************************************/
void DIO_FlipChannel (GPIO_PortType Port_ID,GPIO_ChannelType Channel_ID);

/******************************************************************************
* \Syntax          : DIO_LevelPortType DIO_ReadPort (DIO_PortType Port_ID);


* \Description     : read port
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Port_ID    >>  port number
*
* \Parameters (out): None
* \Return value:   : DIO_LevelPortType   port_reading_value
*                                        NOT_OK
*
*******************************************************************************/

GPIO_LevelPortType DIO_ReadPort (GPIO_PortType Port_ID);


/******************************************************************************
	* \Syntax          : Std_ReturnType DIO_WritePort (DIO_PortType Port_ID,
	*                                                  DIO_LevelPortType Level_Value);

	* \Description     : Write port
	*
	* \Sync\Async      : Synchronous
	* \Reentrancy      : Reentrant
	* \Parameters (in) : Port_ID     >>  port number
	*                    Level_Value >>  port value
	* \Parameters (out): None
	* \Return value:   : DIO_LevelPortType   port_reading_value
	*                                        NOT_OK
	*
	*******************************************************************************/
Std_ReturnType DIO_WritePort (GPIO_PortType Port_ID,GPIO_LevelPortType Level_Value);

/*****************************************************************************************************/

#endif /* GPIO_DIO_DIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
