
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Reg.h
 *       Module:  GPIO
 *
 *  Description:  GPIO Registers
 *                Using Bit Masking feature in Data register in ARM CORTEXM-4 to avoid
 *                Raed-Modify-write technique and all functions are reentrant.
 *
 *********************************************************************************************************************/
#ifndef GPIO_GPIO_REG_H_
#define GPIO_GPIO_REG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_Types.h"

/*********************************************************************************************************************
 * BIT BANDING MACROS
 * *******************************************************************************************************************/
/*Define base address of peripheral bit-band*/

#define BITBAND_PERI_BASE 0x40000000

/*  Define base address of peripheral alias band */
#define ALIAS_PERI_BASE 0x42000000

/*   Convert PERI address to alias region */
#define BITBAND_PERI(reg_address, bit_number) ((ALIAS_PERI_BASE + \
                (reg_address - BITBAND_PERI_BASE) * 32 + (bit_number * 4)))

/*********************************************************************************************************************
 * DATA PORT BASE REGISTERS
 * *******************************************************************************************************************/
#define GPIOA_DATA  0x400043FC
#define GPIOB_DATA  0x400053FC
#define GPIOC_DATA  0x400063FC
#define GPIOD_DATA  0x400073FC
#define GPIOE_DATA  0x400243FC
#define GPIOF_DATA  0x400253FC




//*****************************************************************************
//
// GPIO registers (PORTA)
//
//*****************************************************************************
#define GPIOA_DATA_BITS  ((volatile uint32_t *)0x40004000)
#define GPIOA_DATA_PORT  (*((volatile uint32_t *)0x400043FC))

                 /* DATA REG BIT MASKING */
//#define GPIOA_DATA_PN0   (*((volatile uint32_t *)0x40004004))
//#define GPIOA_DATA_PN1   (*((volatile uint32_t *)0x40004008))
//#define GPIOA_DATA_PN2   (*((volatile uint32_t *)0x40004010))
//#define GPIOA_DATA_PN3   (*((volatile uint32_t *)0x40004020))
//#define GPIOA_DATA_PN4   (*((volatile uint32_t *)0x40004040))
//#define GPIOA_DATA_PN5   (*((volatile uint32_t *)0x40004080))
//#define GPIOA_DATA_PN6   (*((volatile uint32_t *)0x40004100))
//#define GPIOA_DATA_PN7   (*((volatile uint32_t *)0x40004200))
/*--------------------------------------------------------------*/
#define GPIOA_DIR        (*((volatile uint32_t *)0x40004400))
#define GPIOA_IS         (*((volatile uint32_t *)0x40004404))
#define GPIOA_IBE        (*((volatile uint32_t *)0x40004408))
#define GPIOA_IEV        (*((volatile uint32_t *)0x4000440C))
#define GPIOA_IM         (*((volatile uint32_t *)0x40004410))
#define GPIOA_RIS        (*((volatile uint32_t *)0x40004414))
#define GPIOA_MIS        (*((volatile uint32_t *)0x40004418))
#define GPIOA_ICR        (*((volatile uint32_t *)0x4000441C))
#define GPIOA_AFSEL      (*((volatile uint32_t *)0x40004420))
#define GPIOA_DR2R       (*((volatile uint32_t *)0x40004500))
#define GPIOA_DR4R       (*((volatile uint32_t *)0x40004504))
#define GPIOA_DR8R       (*((volatile uint32_t *)0x40004508))
#define GPIOA_ODR        (*((volatile uint32_t *)0x4000450C))
#define GPIOA_PUR        (*((volatile uint32_t *)0x40004510))
#define GPIOA_PDR        (*((volatile uint32_t *)0x40004514))
#define GPIOA_SLR        (*((volatile uint32_t *)0x40004518))
#define GPIOA_DEN        (*((volatile uint32_t *)0x4000451C))
#define GPIOA_LOCK       (*((volatile uint32_t *)0x40004520))
#define GPIOA_CR         (*((volatile uint32_t *)0x40004524))
#define GPIOA_AMSEL      (*((volatile uint32_t *)0x40004528))
#define GPIOA_PCTL       (*((volatile uint32_t *)0x4000452C))
#define GPIOA_ADCCTL     (*((volatile uint32_t *)0x40004530))
#define GPIOA_DMACTL     (*((volatile uint32_t *)0x40004534))

//*****************************************************************************
//
// GPIO registers (PORTB)
//
//*****************************************************************************
#define GPIOB_DATA_BITS  ((volatile uint32_t *)0x40005000)
#define GPIOB_DATA_PORT  (*((volatile uint32_t *)0x400053FC))
                   /* DATA REG BIT MASKING */
//#define GPIOB_DATA_PN0   (*((volatile uint32_t *)0x40005004))
//#define GPIOB_DATA_PN1   (*((volatile uint32_t *)0x40005008))
//#define GPIOB_DATA_PN2   (*((volatile uint32_t *)0x40005010))
//#define GPIOB_DATA_PN3   (*((volatile uint32_t *)0x40005020))
//#define GPIOB_DATA_PN4   (*((volatile uint32_t *)0x40005040))
//#define GPIOB_DATA_PN5   (*((volatile uint32_t *)0x40005080))
//#define GPIOB_DATA_PN6   (*((volatile uint32_t *)0x40005100))
//#define GPIOB_DATA_PN7   (*((volatile uint32_t *)0x40005200))
/*--------------------------------------------------------------*/
#define GPIOB_DIR        (*((volatile uint32_t *)0x40005400))
#define GPIOB_IS         (*((volatile uint32_t *)0x40005404))
#define GPIOB_IBE        (*((volatile uint32_t *)0x40005408))
#define GPIOB_IEV        (*((volatile uint32_t *)0x4000540C))
#define GPIOB_IM         (*((volatile uint32_t *)0x40005410))
#define GPIOB_RIS        (*((volatile uint32_t *)0x40005414))
#define GPIOB_MIS        (*((volatile uint32_t *)0x40005418))
#define GPIOB_ICR        (*((volatile uint32_t *)0x4000541C))
#define GPIOB_AFSEL      (*((volatile uint32_t *)0x40005420))
#define GPIOB_DR2R       (*((volatile uint32_t *)0x40005500))
#define GPIOB_DR4R       (*((volatile uint32_t *)0x40005504))
#define GPIOB_DR8R       (*((volatile uint32_t *)0x40005508))
#define GPIOB_ODR        (*((volatile uint32_t *)0x4000550C))
#define GPIOB_PUR        (*((volatile uint32_t *)0x40005510))
#define GPIOB_PDR        (*((volatile uint32_t *)0x40005514))
#define GPIOB_SLR        (*((volatile uint32_t *)0x40005518))
#define GPIOB_DEN        (*((volatile uint32_t *)0x4000551C))
#define GPIOB_LOCK       (*((volatile uint32_t *)0x40005520))
#define GPIOB_CR         (*((volatile uint32_t *)0x40005524))
#define GPIOB_AMSEL      (*((volatile uint32_t *)0x40005528))
#define GPIOB_PCTL       (*((volatile uint32_t *)0x4000552C))
#define GPIOB_ADCCTL     (*((volatile uint32_t *)0x40005530))
#define GPIOB_DMACTL     (*((volatile uint32_t *)0x40005534))

//*****************************************************************************
//
// GPIO registers (PORTC)
//
//*****************************************************************************
#define GPIOC_DATA_BITS  ((volatile uint32_t *)0x40006000)
#define GPIOC_DATA_PORT  (*((volatile uint32_t *)0x400063FC))
                   /* DATA REG BIT MASKING */
//#define GPIOC_DATA_PN0   (*((volatile uint32_t *)0x40006004))
//#define GPIOC_DATA_PN1   (*((volatile uint32_t *)0x40006008))
//#define GPIOC_DATA_PN2   (*((volatile uint32_t *)0x40006010))
//#define GPIOC_DATA_PN3   (*((volatile uint32_t *)0x40006020))
//#define GPIOC_DATA_PN4   (*((volatile uint32_t *)0x40006040))
//#define GPIOC_DATA_PN5   (*((volatile uint32_t *)0x40006080))
//#define GPIOC_DATA_PN6   (*((volatile uint32_t *)0x40006100))
//#define GPIOC_DATA_PN7   (*((volatile uint32_t *)0x40006200))
/*--------------------------------------------------------------*/
#define GPIOC_DIR        (*((volatile uint32_t *)0x40006400))
#define GPIOC_IS         (*((volatile uint32_t *)0x40006404))
#define GPIOC_IBE        (*((volatile uint32_t *)0x40006408))
#define GPIOC_IEV        (*((volatile uint32_t *)0x4000640C))
#define GPIOC_IM         (*((volatile uint32_t *)0x40006410))
#define GPIOC_RIS        (*((volatile uint32_t *)0x40006414))
#define GPIOC_MIS        (*((volatile uint32_t *)0x40006418))
#define GPIOC_ICR        (*((volatile uint32_t *)0x4000641C))
#define GPIOC_AFSEL      (*((volatile uint32_t *)0x40006420))
#define GPIOC_DR2R       (*((volatile uint32_t *)0x40006500))
#define GPIOC_DR4R       (*((volatile uint32_t *)0x40006504))
#define GPIOC_DR8R       (*((volatile uint32_t *)0x40006508))
#define GPIOC_ODR        (*((volatile uint32_t *)0x4000650C))
#define GPIOC_PUR        (*((volatile uint32_t *)0x40006510))
#define GPIOC_PDR        (*((volatile uint32_t *)0x40006514))
#define GPIOC_SLR        (*((volatile uint32_t *)0x40006518))
#define GPIOC_DEN        (*((volatile uint32_t *)0x4000651C))
#define GPIOC_LOCK       (*((volatile uint32_t *)0x40006520))
#define GPIOC_CR         (*((volatile uint32_t *)0x40006524))
#define GPIOC_AMSEL      (*((volatile uint32_t *)0x40006528))
#define GPIOC_PCTL       (*((volatile uint32_t *)0x4000652C))
#define GPIOC_ADCCTL     (*((volatile uint32_t *)0x40006530))
#define GPIOC_DMACTL     (*((volatile uint32_t *)0x40006534))

//*****************************************************************************
//
// GPIO registers (PORTD)
//
//*****************************************************************************
#define GPIOD_DATA_BITS  ((volatile uint32_t *)0x40007000)
#define GPIOD_DATA_PORT  (*((volatile uint32_t *)0x400073FC))
                /* DATA REG BIT MASKING */
//#define GPIOD_DATA_PN0   (*((volatile uint32_t *)0x40007004))
//#define GPIOD_DATA_PN1   (*((volatile uint32_t *)0x40007008))
//#define GPIOD_DATA_PN2   (*((volatile uint32_t *)0x40007010))
//#define GPIOD_DATA_PN3   (*((volatile uint32_t *)0x40007020))
//#define GPIOD_DATA_PN4   (*((volatile uint32_t *)0x40007040))
//#define GPIOD_DATA_PN5   (*((volatile uint32_t *)0x40007080))
//#define GPIOD_DATA_PN6   (*((volatile uint32_t *)0x40007100))
//#define GPIOD_DATA_PN7   (*((volatile uint32_t *)0x40007200))
/*--------------------------------------------------------------*/
#define GPIOD_DIR        (*((volatile uint32_t *)0x40007400))
#define GPIOD_IS         (*((volatile uint32_t *)0x40007404))
#define GPIOD_IBE        (*((volatile uint32_t *)0x40007408))
#define GPIOD_IEV        (*((volatile uint32_t *)0x4000740C))
#define GPIOD_IM         (*((volatile uint32_t *)0x40007410))
#define GPIOD_RIS        (*((volatile uint32_t *)0x40007414))
#define GPIOD_MIS        (*((volatile uint32_t *)0x40007418))
#define GPIOD_ICR        (*((volatile uint32_t *)0x4000741C))
#define GPIOD_AFSEL      (*((volatile uint32_t *)0x40007420))
#define GPIOD_DR2R       (*((volatile uint32_t *)0x40007500))
#define GPIOD_DR4R       (*((volatile uint32_t *)0x40007504))
#define GPIOD_DR8R       (*((volatile uint32_t *)0x40007508))
#define GPIOD_ODR        (*((volatile uint32_t *)0x4000750C))
#define GPIOD_PUR        (*((volatile uint32_t *)0x40007510))
#define GPIOD_PDR        (*((volatile uint32_t *)0x40007514))
#define GPIOD_SLR        (*((volatile uint32_t *)0x40007518))
#define GPIOD_DEN        (*((volatile uint32_t *)0x4000751C))
#define GPIOD_LOCK       (*((volatile uint32_t *)0x40007520))
#define GPIOD_CR         (*((volatile uint32_t *)0x40007524))
#define GPIOD_AMSEL      (*((volatile uint32_t *)0x40007528))
#define GPIOD_PCTL       (*((volatile uint32_t *)0x4000752C))
#define GPIOD_ADCCTL     (*((volatile uint32_t *)0x40007530))
#define GPIOD_DMACTL     (*((volatile uint32_t *)0x40007534))

//*****************************************************************************
//
// GPIO registers (PORTE)
//
//*****************************************************************************
#define GPIOE_DATA_BITS  ((volatile uint32_t *)0x40024000)
#define GPIOE_DATA_PORT  (*((volatile uint32_t *)0x400243FC))
                  /* DATA REG BIT MASKING */
//#define GPIOE_DATA_PN0   (*((volatile uint32_t *)0x40024004))
//#define GPIOE_DATA_PN1   (*((volatile uint32_t *)0x40024008))
//#define GPIOE_DATA_PN2   (*((volatile uint32_t *)0x40024010))
//#define GPIOE_DATA_PN3   (*((volatile uint32_t *)0x40024020))
//#define GPIOE_DATA_PN4   (*((volatile uint32_t *)0x40024040))
//#define GPIOE_DATA_PN5   (*((volatile uint32_t *)0x40024080))
/*--------------------------------------------------------------*/
#define GPIOE_DIR        (*((volatile uint32_t *)0x40024400))
#define GPIOE_IS         (*((volatile uint32_t *)0x40024404))
#define GPIOE_IBE        (*((volatile uint32_t *)0x40024408))
#define GPIOE_IEV        (*((volatile uint32_t *)0x4002440C))
#define GPIOE_IM         (*((volatile uint32_t *)0x40024410))
#define GPIOE_RIS        (*((volatile uint32_t *)0x40024414))
#define GPIOE_MIS        (*((volatile uint32_t *)0x40024418))
#define GPIOE_ICR        (*((volatile uint32_t *)0x4002441C))
#define GPIOE_AFSEL      (*((volatile uint32_t *)0x40024420))
#define GPIOE_DR2R       (*((volatile uint32_t *)0x40024500))
#define GPIOE_DR4R       (*((volatile uint32_t *)0x40024504))
#define GPIOE_DR8R       (*((volatile uint32_t *)0x40024508))
#define GPIOE_ODR        (*((volatile uint32_t *)0x4002450C))
#define GPIOE_PUR        (*((volatile uint32_t *)0x40024510))
#define GPIOE_PDR        (*((volatile uint32_t *)0x40024514))
#define GPIOE_SLR        (*((volatile uint32_t *)0x40024518))
#define GPIOE_DEN        (*((volatile uint32_t *)0x4002451C))
#define GPIOE_LOCK       (*((volatile uint32_t *)0x40024520))
#define GPIOE_CR         (*((volatile uint32_t *)0x40024524))
#define GPIOE_AMSEL      (*((volatile uint32_t *)0x40024528))
#define GPIOE_PCTL       (*((volatile uint32_t *)0x4002452C))
#define GPIOE_ADCCTL     (*((volatile uint32_t *)0x40024530))
#define GPIOE_DMACTL     (*((volatile uint32_t *)0x40024534))

//*****************************************************************************
//
// GPIO registers (PORTF)
//
//*****************************************************************************
#define GPIOF_DATA_BITS  ((volatile uint32_t *)0x40025000)
#define GPIOF_DATA_PORT  (*((volatile uint32_t *)0x400253FC))
                  /* DATA REG BIT MASKING */
//#define GPIOF_DATA_PN0   (*((volatile uint32_t *)0x40025004))
//#define GPIOF_DATA_PN1   (*((volatile uint32_t *)0x40025008))
//#define GPIOF_DATA_PN2   (*((volatile uint32_t *)0x40025010))
//#define GPIOF_DATA_PN3   (*((volatile uint32_t *)0x40025020))
//#define GPIOF_DATA_PN4   (*((volatile uint32_t *)0x40025040))
/*--------------------------------------------------------------*/
#define GPIOF_DIR        (*((volatile uint32_t *)0x40025400))
#define GPIOF_IS         (*((volatile uint32_t *)0x40025404))
#define GPIOF_IBE        (*((volatile uint32_t *)0x40025408))
#define GPIOF_IEV        (*((volatile uint32_t *)0x4002540C))
#define GPIOF_IM         (*((volatile uint32_t *)0x40025410))
#define GPIOF_RIS        (*((volatile uint32_t *)0x40025414))
#define GPIOF_MIS        (*((volatile uint32_t *)0x40025418))
#define GPIOF_ICR        (*((volatile uint32_t *)0x4002541C))
#define GPIOF_AFSEL      (*((volatile uint32_t *)0x40025420))
#define GPIOF_DR2R       (*((volatile uint32_t *)0x40025500))
#define GPIOF_DR4R       (*((volatile uint32_t *)0x40025504))
#define GPIOF_DR8R       (*((volatile uint32_t *)0x40025508))
#define GPIOF_ODR        (*((volatile uint32_t *)0x4002550C))
#define GPIOF_PUR        (*((volatile uint32_t *)0x40025510))
#define GPIOF_PDR        (*((volatile uint32_t *)0x40025514))
#define GPIOF_SLR        (*((volatile uint32_t *)0x40025518))
#define GPIOF_DEN        (*((volatile uint32_t *)0x4002551C))
#define GPIOF_LOCK       (*((volatile uint32_t *)0x40025520))
#define GPIOF_CR         (*((volatile uint32_t *)0x40025524))
#define GPIOF_AMSEL      (*((volatile uint32_t *)0x40025528))
#define GPIOF_PCTL       (*((volatile uint32_t *)0x4002552C))
#define GPIOF_ADCCTL     (*((volatile uint32_t *)0x40025530))
#define GPIOF_DMACTL     (*((volatile uint32_t *)0x40025534))

//#define PF1                    (*((volatile uint32_t *)BITBAND_PERI(0x40025000,1)))

/****************************************************************************************************/


#endif /* GPIO_GPIO_REG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
