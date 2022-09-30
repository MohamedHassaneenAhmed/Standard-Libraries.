
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysCtr.h
 *       Module:  clock
 *
 *  Description:  ---  Peripheral Clock Gating Control
 *                --- control of system clocl by PLL
 *
 ********************************************************************************************************************* *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 18/8/2022
**********************************************************************************************************************/
#ifndef CLOCK_SYSCTR_H_
#define CLOCK_SYSCTR_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_Types.h"
#include "SysCtr_Reg.h"
#include "SysCtr_Types.h"
#include "NVIC_Types.h"
#include "Macros.h"
#include  "Compiler.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CPU_F  16

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
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
Std_ReturnType Enable_Peripheral_Clock (uint8_t U8Peripheral_Name , uint8_t U8Peripheral_Channel );

/******************************************************************************
* \Syntax          : Std_ReturnType Clock_PLL_init (uint8_t U8Div_number);

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
Std_ReturnType Clock_PLL_init (uint8_t U8Div_number);

/*********************************************************************************************************************/
#endif /* CLOCK_SYSCTR_H_ */

/**********************************************************************************************************************
 *  END OF FILE: SysCtr.h
 *********************************************************************************************************************/
