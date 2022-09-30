/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  WDT.h
 *       Module:  WDT
 *
 *  Description:  <Write File DESCRIPTION here>
 **********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 1/9/2022
 *********************************************************************************************************************/
#ifndef WDT_WDT_H_
#define WDT_WDT_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "WDT_Types.h"
#include "Compiler.h"
#include "WDT_Reg.h"
#include "Macros.h"

/**********************************************************************************************************************
   * FUNCTION PROTOTYPES
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
void WDT_Init (const WDT_ConfigType * ConfigPtr);

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
void WDT1_ISR (void);

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

void WDT_SetTriggerConditin (uint16_t Timeout);

/***********************************************************************************************************/
#endif /* WDT_WDT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: WDT.h
 *********************************************************************************************************************/
