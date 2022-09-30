/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT.h
 *       Module:  GPT
 *
 *  Description:  ---  static code for GPT Modules
 *               ---  generic APIs implementation for GPT
 *               ---  Callback functions for each module
 *
 *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 24/8/2022
**********************************************************************************************************************/

#ifndef GPT_GPT_H_
#define GPT_GPT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"Macros.h"
#include"GPT_Types.h"
#include"GPT_Reg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define GPT_MODULESNUMBERS 12



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
 * \Syntax          : Std_ReturnType GPT_Init(const GPT_ConfigType * ConfigPtr)

 * \Description     : initiation of GPT module
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : * ConfigPtr  >>  pointer to configuration structure
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType        OK = 0
 *
 *                                          NOT_OK =-1
 *******************************************************************************/

Std_ReturnType GPT_Init (const GPT_ConfigType *ConfigPtr);

/******************************************************************************
* \Syntax          : void GPT_StartTimer (GPT_ChannelAType Channel, GPT_ValueType target_value)

* \Description     : start timer and set the target value
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel          >> module number
*                    target_value    >>  port target_value
* \Parameters (out): None
* \Return value:   : None
 *******************************************************************************/
void GPT_StartTimer (GPT_ChannelAType Channel, GPT_ValueType target_value);
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
void GPT_StopTimer (GPT_ChannelAType Channel);

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
void GPT_EnableNotification (GPT_ChannelAType Channel);

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
void GPT_DisableNotification (GPT_ChannelAType Channel);



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

GPT_ValueType GPT_GetTimeElapsed (GPT_ChannelAType Channel);
/******************************************************************************
* \Syntax          : GPT_ValueType GPT_GetTimeElapsed (GPT_ChannelAType Channel)


* \Description     : determine the remaining time of timer to reach the target with handling the required frequency
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Channel >>  module number
* \Parameters (out): None
* \Return value:   : GPT_ValueType         remaining  time
*                                          NOT_OK =-1
 *******************************************************************************/
GPT_ValueType GPT_GetTimeRemaining (GPT_ChannelAType Channel);
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
Std_ReturnType GPT_GetPredefTimerValue(GPT_PredefTimerType TimerType, uint32_t* TimueValuePtr);


/************************************************************************************************************************/

#endif /* GPT_GPT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/


