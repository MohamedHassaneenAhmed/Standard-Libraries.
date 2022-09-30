
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
 *        \brief  configuration of each pin
 *                user interfacing
 *
 *      \details
 *
 **********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 22/8/2022
 **********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_Types.h"
#include "GPIO_Types.h"
#include "port.h"
/*************************************************************************
 * Description :Array of structures for configuration of pins (43) during link time
 *
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
	                   >> NON_CONFIGUERED_DIRECTION
	              6- pin internal attach :-
	                   >> PULL_UP_ATTACH
	                   >> PULL_DOWN_ATTACH
                	   >> OPEN_DRAIN_ATTACH
	                   >> SLEW_RATE__ATTACH
	                   >> NON_CONFIGUERED_ATTACH
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
GPIO_ConfigType PORT_ConfigType [PIN_NUMBERS] =
{
    {PORTA,                                         /* 1- port type */
	 PN0,                                           /* 2- pin type */
	 NON_CONFIGURED_PIN,                            /* 3- pin state */
	 MODE_DIO,                                      /* 4- pin mode  */
	 NON_CONFIGUERED_DIRECTION,                     /* 5- pin direction */
	 NON_CONFIGUERED_ATTACH,                        /* 6- pin internal attach */
	 PIN_LOW,                                       /* 7- pin level  */
	 CURRENT_2MA,                                   /* 8- pin output current  */
	 SET_DIGITAL_ENABLE                             /* 9- DIGITAL ENABLE       */
    },                                                /* PORTA-PIN0*/

		{ PORTA, PN1, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTA-PIN1*/

		{ PORTA, PN2, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTA-PIN2*/

		{ PORTA, PN3, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTA-PIN3*/

		{ PORTA, PN4, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTA-PIN4*/

		{ PORTA, PN5, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTA-PIN5*/

		{ PORTA, PN6, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTA-PIN6*/

		{ PORTA, PN7, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTA-PIN7*/

/****************************************************************************************************/

		{ PORTB, PN0, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTB-PIN0*/

		{ PORTB, PN1, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTB-PIN1*/

		{ PORTB, PN2, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTB-PIN2*/

		{ PORTB, PN3, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTB-PIN3*/

		{ PORTB, PN4, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTB-PIN4*/

		{ PORTB, PN5, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTB-PIN5*/

		{ PORTB, PN6, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTB-PIN6*/

		{ PORTB, PN7, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTB-PIN7*/

/****************************************************************************************************/


		{ PORTC, PN0, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTC-PIN0*/

		{ PORTC, PN1, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTC-PIN1*/

		{ PORTC, PN2, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTC-PIN2*/

		{ PORTC, PN3, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTC-PIN3*/

		{ PORTC, PN4, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTC-PIN4*/

		{ PORTC, PN5, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTC-PIN5*/

		{ PORTC, PN6, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTC-PIN6*/

		{ PORTC, PN7, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTC-PIN7*/

/****************************************************************************************************/


		{ PORTD, PN0, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTD-PIN0*/

		{ PORTD, PN1, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTD-PIN1*/

		{ PORTD, PN2, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTD-PIN2*/

		{ PORTD, PN3, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTD-PIN3*/

		{ PORTD, PN4, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTD-PIN4*/

		{ PORTD, PN5, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTD-PIN5*/

		{ PORTD, PN6, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTD-PIN6*/

		{ PORTD, PN7, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTD-PIN7*/

/****************************************************************************************************/


		{ PORTE, PN0, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTE-PIN0*/

		{ PORTE, PN1, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTE-PIN1*/

		{ PORTE, PN2, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTE-PIN2*/

		{ PORTE, PN3, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTE-PIN3*/

		{ PORTE, PN4, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTE-PIN4*/

		{ PORTE, PN5, NON_CONFIGURED_PIN, MODE_DIO, NON_CONFIGUERED_DIRECTION,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTE-PIN5*/

/****************************************************************************************************/


		{ PORTF, PN0, CONFIGURED_PIN, MODE_DIO, INPUT,
		  PULL_UP_ATTACH, NON_CONFIGURED, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTF-PIN0*/

		{ PORTF, PN1, CONFIGURED_PIN, MODE_DIO, OUTPUT, NON_CONFIGUERED_ATTACH,
		  PIN_LOW, CURRENT_2MA,SET_DIGITAL_ENABLE}, /* PORTF-PIN1*/

		{ PORTF, PN2, CONFIGURED_PIN, MODE_DIO, OUTPUT, NON_CONFIGUERED_ATTACH,
		  PIN_LOW, CURRENT_2MA,SET_DIGITAL_ENABLE }, /* PORTF-PIN2*/

		{ PORTF, PN3, CONFIGURED_PIN, MODE_DIO, OUTPUT,
			NON_CONFIGUERED_ATTACH, PIN_LOW, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTF-PIN3*/

		{ PORTF, PN4, CONFIGURED_PIN, MODE_DIO, INPUT,
		  PULL_UP_ATTACH, NON_CONFIGURED, CURRENT_2MA, SET_DIGITAL_ENABLE }, /* PORTF-PIN4*/
};
/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
