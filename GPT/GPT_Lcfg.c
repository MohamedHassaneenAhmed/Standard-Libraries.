/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT_Lcfh.c
 *
 *
 *        \brief --- dynamic code for user configuration
 *      \details
 *
 *
 *********************************************************************************************************************
 *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 24/8/2022

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include"GPT_types.h"
#include"STD_Types.h"
#include"Compiler.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

extern void System_Tick_handler(void);

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define GPT_PREDEF_TIMER_1US_16BIT       DISABLE
#define GPT_PREDEF_TIMER_1US_24BIT       DISABLE
#define GPT_PREDEF_TIMER_1US_32BIT       ENABLE
#define GPT_PREDEF_TIMER_100US_32BIT     DISABLE


#if (GPT_PREDEF_TIMER_1US_16BIT == ENABLE )
#define PREDEF_TARGET_VALUE 0xFFFFFF
#endif

#if (GPT_PREDEF_TIMER_1US_24BIT == ENABLE )
#define PREDEF_TARGET_VALUE 0xFFFFFFFF
#endif

#if (GPT_PREDEF_TIMER_1US_32BIT == ENABLE )
#define PREDEF_TARGET_VALUE 0xFFFFFFFF
#endif

#if (GPT_PREDEF_TIMER_100US_32BIT == ENABLE )
#define PREDEF_TARGET_VALUE 0xFFFFFFFFFFFF
#endif


GPT_ConfigType GPT_LinkConfig[12]=
{
 {TIMERA0,GPT_DISABLE,F_16,0xFFFF,15999,GPT_MODE_PERIODIC,NULL_PTR},
 {TIMERA1,GPT_ENABLE,F_16,0xFFFF,15999,GPT_MODE_PERIODIC,&System_Tick_handler},
 {TIMERA2,GPT_DISABLE,F_16,0,0,NON_CONFIGURED_MODE,NULL_PTR},
 {TIMERA3,GPT_DISABLE,F_16,0,0,NON_CONFIGURED_MODE,NULL_PTR},
 {TIMERA4,GPT_DISABLE,F_16,0,0,NON_CONFIGURED_MODE,NULL_PTR},
 {TIMERA5,GPT_DISABLE,F_16,0,0,NON_CONFIGURED_MODE,NULL_PTR},
 {WTIMERA0,GPT_DISABLE,F_16,PREDEF_TARGET_VALUE,15999,GPT_MODE_PERIODIC,NULL_PTR},          /* PREDEF TIMER = WTIMERA0 */
 {WTIMERA1,GPT_DISABLE,F_16,0,0,NON_CONFIGURED_MODE,NULL_PTR},
 {WTIMERA2,GPT_DISABLE,F_16,0,0,NON_CONFIGURED_MODE,NULL_PTR},
 {WTIMERA3,GPT_DISABLE,F_16,0,0,NON_CONFIGURED_MODE,NULL_PTR},
 {WTIMERA4,GPT_DISABLE,F_16,0,0,NON_CONFIGURED_MODE,NULL_PTR},
 {WTIMERA5,GPT_DISABLE,F_16,0,0,NON_CONFIGURED_MODE,NULL_PTR},
};

