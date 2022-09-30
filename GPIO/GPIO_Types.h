
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Types.h
 *       Module:  GPIO
 *
 *  Description:  GPIO Types file includes all types i need of GPIO driver
 *
*********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 20/8/2022
 **********************************************************************************************************************/
#ifndef GPIO_GPIO_TYPES_H_
#define GPIO_GPIO_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"STD_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*******************************/
typedef enum
{
	NON_CONFIGURED_PIN=0,
	CONFIGURED_PIN
}GPIO_PinConfigStateType;

typedef enum
{
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
} GPIO_PortType;
/*******************************/
typedef enum
{
	PN0 = 0,
	PN1,
	PN2,
	PN3,
	PN4,
	PN5,
	PN6,
	PN7
} GPIO_ChannelType;
/*******************************/
typedef enum
{
	INPUT,
	OUTPUT,
	NON_CONFIGUERED_DIRECTION
} GPIO_PinDirectionType;

/*******************************/
typedef enum
{
	MODE_DIO = 0,
	MODE_ADC,
	MODE_DMA
} GPIO_PinModeType;
/*******************************/
typedef enum
{
	PULL_UP_ATTACH = 0,
	PULL_DOWN_ATTACH,
	OPEN_DRAIN_ATTACH,
	SLEW_RATE__ATTACH,
	NON_CONFIGUERED_ATTACH
} GPIO_PinIntrnalAttachType;
/*******************************/
typedef enum
{
	PIN_LOW = 0,
	PIN_HIGH,
	NON_CONFIGURED
} GPIO_PinLevelType;
/*******************************/
typedef enum
{
	CURRENT_2MA = 0,
	CURRENT_4MA,
	CURRENT_8MA
} GPIO_PinOutputCurrentType;
/*******************************/

typedef enum
{
	RESET_DIGITAL_ENABLE=0,
	SET_DIGITAL_ENABLE
} GPIO_PinDigitalEnableType;


/*************************************************************************
 * Description : structure for configuration
 *                1- port type :-
 *                     >> PORTA
	                   >> PORTB
	                   >> PORTC
	                   >> PORTD
	                   >> PORTE
	                   >> PORTF
 *                2- pin type :-
 *                     >> PN0
	                   >> PN1
	                   >> PN2
	                   >> PN3
	                   >> PN4
	                   >> PN5
	                   >> PN6
	                   >> PN7
	              3- pin state :-
 *                     >> CONFIGURED_PIN
	                   >> NON_CONFIGURED_PIN
	              4- pin mode :-
 *                     >> MODE_DIO
	                   >> MODE_ADC
	                   >> MODE_DMA
 *                5- pin direction :-
 *                     >> INPUT
	                   >> OUTPUT
	              6- pin internal attach :-
	                   >> PULL_UP_ATTACH
	                   >> PULL_DOWN_ATTACH
                	   >> OPEN_DRAIN_ATTACH
	                   >> SLEW_RATE__ATTACH
 *                7- pin level :-
 *                     >> PIN_LOW
	                   >> PIN_HIGH
 *                8- pin output current :-
 *                     >> CURRENT_2MA = 0,
	                   >> CURRENT_4MA,
	                   >> CURRENT_8MA
	              9- DIGITAL ENABLE
	                   >> RESET_DIGITAL_ENABLE
	                   >> SET_DIGITAL_ENABLE
 **************************************************************************/
typedef struct
{
	GPIO_PortType                PortType;
	GPIO_ChannelType             ChannelType;
	GPIO_PinConfigStateType      PinState;
	GPIO_PinModeType             PinMode;
	GPIO_PinDirectionType        PinDirection;
	GPIO_PinIntrnalAttachType    PinIntrnalAttach;
	GPIO_PinLevelType            PinLevel;
	GPIO_PinOutputCurrentType    PinOutputCurrent;
	GPIO_PinDigitalEnableType    PinDigitalStatus;
}GPIO_ConfigType;

typedef uint8_t GPIO_LevelChannelType;
typedef uint8_t GPIO_LevelPortType;

/**********************************************************************************************/

/*********************** INTERNAL ATTACH TYPES *********************************/
typedef enum
{
	RESET_PULL_UP=0,
	SET_PULL_UP
} GPIO_PinPullUpType;

typedef enum
{
	RESET_PULL_DOEN=0,
	SET_PULL_DOWN
} GPIO_PinPullDownType;

typedef enum
{
	RESET_OPEN_DRAIN=0,
	SET_OPEN_DRAIN
} GPIO_PinOpenDrainType;

typedef enum
{
	RESET_SLEW_RATE=0,
	SET_SLEW_RARE
} GPIO_PinSlewRateType;

/***********************INTERRUPT TYPES *********************************/

typedef enum
{
	INT_MASKED=0,
	INT_UNMASKED
} GPIO_InterruptMaskType;

typedef enum
{
	EDGE_SENSE=0,
	LEVEL_SENSE
} GPIO_InterruptSenseType;


typedef enum
{
	EVENT_CONTROL=0,
	BOTH_EDGES
} GPIO_InterruptBothType;

typedef enum
{
	FALLING_LOW=0,
	RAISING_HIGH
} GPIO_InterruptEventType;

/***************************************************************************/
typedef enum
{
	LOCKED=0,
	UNLOCKED
} GPIO_LockType;


/***********************CONTROL REGISTERS TYPES********************/
typedef uint8_t  GPIO_PortControlType;

typedef enum
{
	DIS_ADC_TRI=0,
	EN_ADC_TRI
} GPIO_ADCControlType;

typedef enum
{
	DIS_DMA_TRI=0,
	EN_DMA_TRI
} GPIO_DMAControlType;

/******************************************************************/

typedef enum
{
	RESET_ANALOG=0,
	SET_ANALOG
} GPIO_AnalogType;

typedef enum
{
	RESET_ALTERNATIVE=0,
	SET_ALTERNATIVE
} GPIO_AlternativeFunctionType;


/*******************************************************************************************************************/
#endif /* GPIO_GPIO_TYPES_H_ */
/**********************************************************************************************************************
 *  END OF FILE: GPIO_Types.h
 *********************************************************************************************************************/

