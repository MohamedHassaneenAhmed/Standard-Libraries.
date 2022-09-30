/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Macros.h
 *  Module:  	  Macros
 *
 *  Description:  Header file for macros
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Hassaneen
 *	Date:		  15/8/2022
 *********************************************************************************************************************/

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define Set_Pin(reg,pin_num)        (reg |=(1<<pin_num))                /* Set pin_num */

#define Clear_Pin(reg,pin_num)      (reg &=(~(1<<pin_num)))            /* Clear pin_num */

#define Toggle_Pin(reg,pin_num)     (reg ^=(1<<pin_num))               /* Toggle pin_num */

#define Pin_Is_Set(reg,pin_num)     ( reg & (1<<pin_num) )             /* check if pin_num is set */

#define Pin_Is_Clear(reg,pin_num)   (!(reg & (1<<pin_num)) )           /* check if pin_num is clear */

#define Read_Pin(reg,pin_num)      (( reg >> pin_num )& 0x1 )         /* Read pin_num */

#define Set_Offset (base , offset)    (*((volatile uint32_t *) base + offset))

#endif   /* COMMON_MACROS_H_ */
