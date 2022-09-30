/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  NVIC_LCfg.c
 *        \brief  includes array of pointers to priority addresses
 *
 *      \details
 *
 *
*********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 15/8/2022
**********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NVIC.h"
/**********************************************************************************************************************
*  Array of NVIC configurations
*********************************************************************************************************************/
 volatile uint32_t* NVIC_PRI_Reg[]=
			 {
			  &NVIC_PRI0,         /*Interrupt 0-3 Priority (PRI0)*/
			  &NVIC_PRI1,         /*Interrupt 4-7 Priority (PRI1)*/
			  &NVIC_PRI2,         /*Interrupt 8-11 Priority (PRI2)*/
			  &NVIC_PRI3,         /*Interrupt 12-15 Priority (PRI3)*/
			  &NVIC_PRI4,         /*Interrupt 16-19 Priority (PRI4) */
			  &NVIC_PRI5,         /*Interrupt 20-23 Priority (PRI5) */
			  &NVIC_PRI6,         /*Interrupt 24-27 Priority (PRI6) */
			  &NVIC_PRI7,         /*Interrupt 28-31 Priority (PRI7)*/
			  &NVIC_PRI8,         /*Interrupt 32-35 Priority (PRI8) */
			  &NVIC_PRI9,         /* Interrupt 36-39 Priority (PRI9)*/
			  &NVIC_PRI10,        /*Interrupt 40-43 Priority (PRI10)*/
			  &NVIC_PRI11,        /*Interrupt 44-47 Priority (PRI11) */
			  &NVIC_PRI12,        /*Interrupt 48-51 Priority (PRI12)*/
			  &NVIC_PRI13,        /*Interrupt 52-55 Priority (PRI13)*/
			  &NVIC_PRI14,        /*Interrupt 56-59 Priority (PRI14)*/
			  &NVIC_PRI15,        /*Interrupt 60-63 Priority (PRI15)*/
			  &NVIC_PRI16,        /*Interrupt 64-67 Priority (PRI16)*/
			  &NVIC_PRI17,        /*Interrupt 68-71 Priority (PRI17)*/
			  &NVIC_PRI18,        /*Interrupt 72-75 Priority (PRI18)*/
			  &NVIC_PRI19,        /*Interrupt 76-79 Priority (PRI19)*/
			  &NVIC_PRI20,        /*Interrupt 80-83 Priority (PRI20)*/
			  &NVIC_PRI21,        /*Interrupt 84-87 Priority (PRI21)*/
			  &NVIC_PRI22,        /*Interrupt 88-91 Priority (PRI22)*/
			  &NVIC_PRI23,        /*Interrupt 92-95 Priority (PRI23)*/
			  &NVIC_PRI24,        /*Interrupt 96-99 Priority (PRI24)*/
			  &NVIC_PRI25,        /*Interrupt 100-103 Priority (PRI25)*/
			  &NVIC_PRI26,        /*Interrupt 104-107 Priority (PRI26)*/
			  &NVIC_PRI27,        /*Interrupt 108-111 Priority (PRI27)*/
			  &NVIC_PRI28,        /*Interrupt 112-115 Priority (PRI28)*/
			  &NVIC_PRI29,        /*Interrupt 116-119 Priority (PRI29)*/
			  &NVIC_PRI30,        /*Interrupt 120-123 Priority (PRI30)*/
			  &NVIC_PRI31,        /*Interrupt 124-127 Priority (PRI31)*/
			  &NVIC_PRI32,        /*Interrupt 128-131 Priority (PRI32)*/
			  &NVIC_PRI33,        /*Interrupt 132-135 Priority (PRI33)*/
			  &NVIC_PRI34         /*Interrupt 136-138 Priority (PRI34)*/
			 };

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
