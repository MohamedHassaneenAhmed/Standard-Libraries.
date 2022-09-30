
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  NVIC.h
 *       Module:  NVIC
 *
 *  Description: --- Enable peripheral interrupt
 *               --- Disable peripheral interrupt
 *                --- Set Priority of Peripheral interrupt
 *
 *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 15/8/2022
**********************************************************************************************************************/
#ifndef NVIC_NVIC_H_
#define NVIC_NVIC_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "NVIC_Types.h"
#include "Macros.h"
#include "Compiler.h"
#include "STD_Types.h"
#include "NVIC_Reg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define INTERRUPT_NUMBERS  78


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : uint8_t  NVIC_Enable_IRQ( uint8_t U8Peripheral_Name);
* \Description     : Enable peripheral interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : U8Peripheral_Name  name of peripheral that i want to enable
* \Parameters (out): None
* \Return value:   : Std_ReturnType         E_OK
*                                           E_NOT_OK
*******************************************************************************/
/* enter interrupt number that exists in vector table*/
Std_ReturnType NVIC_Enable_IRQ (uint8_t U8Peripheral_Name);


/******************************************************************************
* \Syntax          : uint8_t  NVIC_Disable_IRQ( uint8_t U8Peripheral_Name);
* \Description     : Disable peripheral interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : U8Peripheral_Name  name of peripheral that i want to disnable
* \Parameters (out): None
* \Return value:   : uint8_t         E_OK
*                                    E_NOT_OK
*******************************************************************************/
Std_ReturnType  NVIC_Disable_IRQ( uint8_t U8Peripheral_Name);


/******************************************************************************
* \Syntax          : uint8_t  NVIC_Priority_IRQ( uint32_t *U8Ptr_NVIC_PRI_Reg,
							                     NVIC_IntType  U8Peripheral_Name,
							                     uint8_t  U8Level_Priority
							                   );
* \Description     : set priority of peripheral interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : uint8_t *U8Ptr_NVIC_PRI_Reg,  --> Array contains all PRI registers
					 uint8_t  U8Peripheral_Name,   --> name of peripheral that i want to set priority
					 uint8_t  U8Level_Priority     --> level of priority
* \Parameters (out): None
* \Return value:   : uint8_t         E_OK
*                                    E_NOT_OK
*******************************************************************************/

Std_ReturnType  NVIC_Priority_IRQ( uint32_t *NVIC_PRI_Reg_Addresses[],
								   uint8_t  U8Peripheral_Name,
							       uint8_t  U8Level_Priority
						         );


/**********************************************************************************************************************/
#endif /* NVIC_NVIC_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
