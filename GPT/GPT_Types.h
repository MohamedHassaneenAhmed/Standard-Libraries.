/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT_Typed.h
 *       Module:  GPT
 *
 *  Description:  ---  Header file includes all types of GPT driver
 *
 *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 24/8/2022
**********************************************************************************************************************/
#ifndef GPT_GPT_TYPES_H_
#define GPT_GPT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"STD_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* numeric type for timer channels */
typedef enum
{
	TIMERA0=0,
	TIMERA1,
	TIMERA2,
	TIMERA3,
	TIMERA4,
	TIMERA5,
	WTIMERA0,
	WTIMERA1,
	WTIMERA2,
	WTIMERA3,
	WTIMERA4,
	WTIMERA5
}GPT_ChannelAType;


/* type to set or read target value */
typedef uint32_t GPT_ValueType;


/* type to select max number of ticks*/
typedef uint64_t GPT_MaxTickValueType;


/* type to select frequency in MHZ  */
typedef enum
{
	F_1  = 1,
	F_2  = 2,
	F_4  = 4,
	F_8  = 8,
	F_16 = 16,
	F_32 = 32,
	F_48 = 48,
	F_64 = 64,
	F_80 = 80
}GPT_ChannelTickFrequencyType;



/* Type to select the mode of timer 0-  one shot
 *                                  1-  periodic
 *                                  2-  non configure                         */
typedef enum
{
	GPT_MODE_ONESHOT=0,
	GPT_MODE_PERIODIC,
	NON_CONFIGURED_MODE
}GPT_ModeType;


/* this type for predefine timer which the user select the desired mode */
typedef enum
{
	GPT_PREDEF_TIMER_1US_16BIT=0,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT,
	NON_CONFIGURED_PREDEF
}GPT_PredefTimerType;


/* type to select the status of timer enable or disable */
typedef enum
{
	GPT_DISABLE=0,
	GPT_ENABLE
}GPT_EnableType;


/* Structure for configuration  */
typedef struct
{
	GPT_ChannelAType                Channel_ID;
	GPT_EnableType                  Enablitiy;
	GPT_ChannelTickFrequencyType    Frequency_MHZ;
	GPT_MaxTickValueType            Max_Tick_Numbers;
	GPT_ValueType                   Target_Value;
	GPT_ModeType                    Mode;
	void (*GPT_Callback)(void);
}GPT_ConfigType;


/* type of look up table includes :
 *                              1- offset of each timer
 *                              3- vector table number of each timer
 *                              3- max counts of each timer                            */

typedef uint32_t GPT_OffsetType;


typedef uint64_t GPT_MaxCountsType;


typedef uint8_t  GPT_NvicNumberType;

/* type to set clock */
typedef enum
{
	GPT_TIMER  =1,
	GPT_WTIMER =15
}GPT_ClockType;

/* type to pre-scale */
typedef enum
{
	GPT_8BIT_PRESCALE  =0xFF,
	GPT_16BIT_PRESCALE =0xFFFF
}GPT_PrescaleType;


typedef struct
{
	GPT_OffsetType               offest;
	GPT_NvicNumberType           vector_number;
	GPT_MaxCountsType            counts;
	GPT_ClockType                clock;
	GPT_PrescaleType             prescale;
}GPT_InfoListType;


#endif /* GPT_GPT_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Types.h
 *********************************************************************************************************************/
