/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: SysCtr_Reg.h
 *       Module:  clock
 *
 *  Description:  --- registers mapping of clock module
 *
 ********************************************************************************************************************* *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 18/8/2022
**********************************************************************************************************************/
#ifndef MCAL_CLOCK_SYSCTR_REG_H_
#define MCAL_CLOCK_SYSCTR_REG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_Types.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* Memory-mapped peripheral registers */

#define SYSCTL_RCGCWD         (*((volatile uint32_t *)0x400FE600))
#define SYSCTL_RCGCTIMER      (*((volatile uint32_t *)0x400FE604))
#define SYSCTL_RCGCGPIO       (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_RCGCDMA        (*((volatile uint32_t *)0x400FE60C))
#define SYSCTL_RCGCHIB        (*((volatile uint32_t *)0x400FE614))
#define SYSCTL_RCGCUART       (*((volatile uint32_t *)0x400FE618))
#define SYSCTL_RCGCSSI        (*((volatile uint32_t *)0x400FE61C))
#define SYSCTL_RCGCI2C        (*((volatile uint32_t *)0x400FE620))
#define SYSCTL_RCGCUSB        (*((volatile uint32_t *)0x400FE628))
#define SYSCTL_RCGCCAN        (*((volatile uint32_t *)0x400FE634))
#define SYSCTL_RCGCADC        (*((volatile uint32_t *)0x400FE638))
#define SYSCTL_RCGCACMP       (*((volatile uint32_t *)0x400FE63C))
#define SYSCTL_RCGCPWM        (*((volatile uint32_t *)0x400FE640))
#define SYSCTL_RCGCQEI        (*((volatile uint32_t *)0x400FE644))
#define SYSCTL_RCGCEEPROM     (*((volatile uint32_t *)0x400FE658))
#define SYSCTL_RCGCWTIMER     (*((volatile uint32_t *)0x400FE65C))

#define SYSCTL_RCC_R            (*((volatile uint32_t *)0x400FE060))
#define SYSCTL_RCC2_R           (*((volatile uint32_t *)0x400FE070))
#define SYSCTL_RIS_R            (*((volatile uint32_t *)0x400FE050))
/*************************************************************************************************************************/
#endif /* MCAL_CLOCK_SYSCTR_REG_H_ */
/**********************************************************************************************************************
 *  END OF FILE: SysCtr_Reg.h
 *********************************************************************************************************************/
