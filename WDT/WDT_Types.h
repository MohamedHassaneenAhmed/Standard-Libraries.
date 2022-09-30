/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:   WDT_Types.h
 *       Module:   WDT
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************
*********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 29/8/2022
**********************************************************************************************************************/
#ifndef WDT_WDT_TYPES_H_
#define WDT_WDT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_Types.h"


typedef enum
{
	WDT_INTERRUPT_STD,
	WDT_INTERRUPT_NMI
}WDT_InterruptType;

typedef enum
{
	WDT_RESET_DISABLE,
	WDT_RESET_ENABLE
}WDT_ResetType;


typedef struct
{
	WDT_InterruptType interrupt_type;
	WDT_ResetType     reset_type;
	uint32_t          initial_Timeout;
	uint32_t          max_timeout;
	void (*callback_function)(void);
}WDT_ConfigType;

#endif /* WDT_WDT_TYPES_H_ */
