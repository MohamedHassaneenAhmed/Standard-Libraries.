/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT.h
 *       Module:  GPT
 *
 *  Description:  ---  Header file includes all registers mapping of GPT driver
 *                ---  has two types of mapping
 *                    >> each register of each module
 *                    >> base of timer0 module and offsets
 *
 *********************************************************************************************************************
 *** NAME: Mohamed Hassaneen Ahmed
 *** DATE: 24/8/2022
**********************************************************************************************************************/
#ifndef GPT_GPT_REG_H_
#define GPT_GPT_REG_H_

//*****************************************************************************
//
// Timer registers (TIMER0)
//
//*****************************************************************************

#define TIMER0_CFG            (*((volatile uint32_t *)0x40030000))
#define TIMER0_TAMR           (*((volatile uint32_t *)0x40030004))
#define TIMER0_TBMR           (*((volatile uint32_t *)0x40030008))
#define TIMER0_CTL            (*((volatile uint32_t *)0x4003000C))
#define TIMER0_SYNC           (*((volatile uint32_t *)0x40030010))
#define TIMER0_IMR            (*((volatile uint32_t *)0x40030018))
#define TIMER0_RIS            (*((volatile uint32_t *)0x4003001C))
#define TIMER0_MIS            (*((volatile uint32_t *)0x40030020))
#define TIMER0_ICR            (*((volatile uint32_t *)0x40030024))
#define TIMER0_TAILR          (*((volatile uint32_t *)0x40030028))
#define TIMER0_TBILR          (*((volatile uint32_t *)0x4003002C))
#define TIMER0_TAMATCHR       (*((volatile uint32_t *)0x40030030))
#define TIMER0_TBMATCHR       (*((volatile uint32_t *)0x40030034))
#define TIMER0_TAPR           (*((volatile uint32_t *)0x40030038))
#define TIMER0_TBPR           (*((volatile uint32_t *)0x4003003C))
#define TIMER0_TAPMR          (*((volatile uint32_t *)0x40030040))
#define TIMER0_TBPMR          (*((volatile uint32_t *)0x40030044))
#define TIMER0_TAR            (*((volatile uint32_t *)0x40030048))
#define TIMER0_TBR            (*((volatile uint32_t *)0x4003004C))
#define TIMER0_TAV            (*((volatile uint32_t *)0x40030050))
#define TIMER0_TBV            (*((volatile uint32_t *)0x40030054))
#define TIMER0_RTCPD          (*((volatile uint32_t *)0x40030058))
#define TIMER0_TAPS           (*((volatile uint32_t *)0x4003005C))
#define TIMER0_TBPS           (*((volatile uint32_t *)0x40030060))
#define TIMER0_TAPV           (*((volatile uint32_t *)0x40030064))
#define TIMER0_TBPV           (*((volatile uint32_t *)0x40030068))
#define TIMER0_PP             (*((volatile uint32_t *)0x40030FC0))

//*****************************************************************************
//
// Timer registers (TIMER1)
//
//*****************************************************************************
#define TIMER1_CFG            (*((volatile uint32_t *)0x40031000))
#define TIMER1_TAMR           (*((volatile uint32_t *)0x40031004))
#define TIMER1_TBMR           (*((volatile uint32_t *)0x40031008))
#define TIMER1_CTL            (*((volatile uint32_t *)0x4003100C))
#define TIMER1_SYNC           (*((volatile uint32_t *)0x40031010))
#define TIMER1_IMR            (*((volatile uint32_t *)0x40031018))
#define TIMER1_RIS            (*((volatile uint32_t *)0x4003101C))
#define TIMER1_MIS            (*((volatile uint32_t *)0x40031020))
#define TIMER1_ICR            (*((volatile uint32_t *)0x40031024))
#define TIMER1_TAILR          (*((volatile uint32_t *)0x40031028))
#define TIMER1_TBILR          (*((volatile uint32_t *)0x4003102C))
#define TIMER1_TAMATCHR       (*((volatile uint32_t *)0x40031030))
#define TIMER1_TBMATCHR       (*((volatile uint32_t *)0x40031034))
#define TIMER1_TAPR           (*((volatile uint32_t *)0x40031038))
#define TIMER1_TBPR           (*((volatile uint32_t *)0x4003103C))
#define TIMER1_TAPMR          (*((volatile uint32_t *)0x40031040))
#define TIMER1_TBPMR          (*((volatile uint32_t *)0x40031044))
#define TIMER1_TAR            (*((volatile uint32_t *)0x40031048))
#define TIMER1_TBR            (*((volatile uint32_t *)0x4003104C))
#define TIMER1_TAV            (*((volatile uint32_t *)0x40031050))
#define TIMER1_TBV            (*((volatile uint32_t *)0x40031054))
#define TIMER1_RTCPD          (*((volatile uint32_t *)0x40031058))
#define TIMER1_TAPS           (*((volatile uint32_t *)0x4003105C))
#define TIMER1_TBPS           (*((volatile uint32_t *)0x40031060))
#define TIMER1_TAPV           (*((volatile uint32_t *)0x40031064))
#define TIMER1_TBPV           (*((volatile uint32_t *)0x40031068))
#define TIMER1_PP             (*((volatile uint32_t *)0x40031FC0))

//*****************************************************************************
//
// Timer registers (TIMER2)
//
//*****************************************************************************
#define TIMER2_CFG            (*((volatile uint32_t *)0x40032000))
#define TIMER2_TAMR           (*((volatile uint32_t *)0x40032004))
#define TIMER2_TBMR           (*((volatile uint32_t *)0x40032008))
#define TIMER2_CTL            (*((volatile uint32_t *)0x4003200C))
#define TIMER2_SYNC           (*((volatile uint32_t *)0x40032010))
#define TIMER2_IMR            (*((volatile uint32_t *)0x40032018))
#define TIMER2_RIS            (*((volatile uint32_t *)0x4003201C))
#define TIMER2_MIS            (*((volatile uint32_t *)0x40032020))
#define TIMER2_ICR            (*((volatile uint32_t *)0x40032024))
#define TIMER2_TAILR          (*((volatile uint32_t *)0x40032028))
#define TIMER2_TBILR          (*((volatile uint32_t *)0x4003202C))
#define TIMER2_TAMATCHR       (*((volatile uint32_t *)0x40032030))
#define TIMER2_TBMATCHR       (*((volatile uint32_t *)0x40032034))
#define TIMER2_TAPR           (*((volatile uint32_t *)0x40032038))
#define TIMER2_TBPR           (*((volatile uint32_t *)0x4003203C))
#define TIMER2_TAPMR          (*((volatile uint32_t *)0x40032040))
#define TIMER2_TBPMR          (*((volatile uint32_t *)0x40032044))
#define TIMER2_TAR            (*((volatile uint32_t *)0x40032048))
#define TIMER2_TBR            (*((volatile uint32_t *)0x4003204C))
#define TIMER2_TAV            (*((volatile uint32_t *)0x40032050))
#define TIMER2_TBV            (*((volatile uint32_t *)0x40032054))
#define TIMER2_RTCPD          (*((volatile uint32_t *)0x40032058))
#define TIMER2_TAPS           (*((volatile uint32_t *)0x4003205C))
#define TIMER2_TBPS           (*((volatile uint32_t *)0x40032060))
#define TIMER2_TAPV           (*((volatile uint32_t *)0x40032064))
#define TIMER2_TBPV           (*((volatile uint32_t *)0x40032068))
#define TIMER2_PP             (*((volatile uint32_t *)0x40032FC0))

//*****************************************************************************
//
// Timer registers (TIMER3)
//
//*****************************************************************************
#define TIMER3_CFG            (*((volatile uint32_t *)0x40033000))
#define TIMER3_TAMR           (*((volatile uint32_t *)0x40033004))
#define TIMER3_TBMR           (*((volatile uint32_t *)0x40033008))
#define TIMER3_CTL            (*((volatile uint32_t *)0x4003300C))
#define TIMER3_SYNC           (*((volatile uint32_t *)0x40033010))
#define TIMER3_IMR            (*((volatile uint32_t *)0x40033018))
#define TIMER3_RIS            (*((volatile uint32_t *)0x4003301C))
#define TIMER3_MIS            (*((volatile uint32_t *)0x40033020))
#define TIMER3_ICR            (*((volatile uint32_t *)0x40033024))
#define TIMER3_TAILR          (*((volatile uint32_t *)0x40033028))
#define TIMER3_TBILR          (*((volatile uint32_t *)0x4003302C))
#define TIMER3_TAMATCHR       (*((volatile uint32_t *)0x40033030))
#define TIMER3_TBMATCHR       (*((volatile uint32_t *)0x40033034))
#define TIMER3_TAPR           (*((volatile uint32_t *)0x40033038))
#define TIMER3_TBPR           (*((volatile uint32_t *)0x4003303C))
#define TIMER3_TAPMR          (*((volatile uint32_t *)0x40033040))
#define TIMER3_TBPMR          (*((volatile uint32_t *)0x40033044))
#define TIMER3_TAR            (*((volatile uint32_t *)0x40033048))
#define TIMER3_TBR            (*((volatile uint32_t *)0x4003304C))
#define TIMER3_TAV            (*((volatile uint32_t *)0x40033050))
#define TIMER3_TBV            (*((volatile uint32_t *)0x40033054))
#define TIMER3_RTCPD          (*((volatile uint32_t *)0x40033058))
#define TIMER3_TAPS           (*((volatile uint32_t *)0x4003305C))
#define TIMER3_TBPS           (*((volatile uint32_t *)0x40033060))
#define TIMER3_TAPV           (*((volatile uint32_t *)0x40033064))
#define TIMER3_TBPV           (*((volatile uint32_t *)0x40033068))
#define TIMER3_PP             (*((volatile uint32_t *)0x40033FC0))

//*****************************************************************************
//
// Timer registers (TIMER4)
//
//*****************************************************************************
#define TIMER4_CFG            (*((volatile uint32_t *)0x40034000))
#define TIMER4_TAMR           (*((volatile uint32_t *)0x40034004))
#define TIMER4_TBMR           (*((volatile uint32_t *)0x40034008))
#define TIMER4_CTL            (*((volatile uint32_t *)0x4003400C))
#define TIMER4_SYNC           (*((volatile uint32_t *)0x40034010))
#define TIMER4_IMR            (*((volatile uint32_t *)0x40034018))
#define TIMER4_RIS            (*((volatile uint32_t *)0x4003401C))
#define TIMER4_MIS            (*((volatile uint32_t *)0x40034020))
#define TIMER4_ICR            (*((volatile uint32_t *)0x40034024))
#define TIMER4_TAILR          (*((volatile uint32_t *)0x40034028))
#define TIMER4_TBILR          (*((volatile uint32_t *)0x4003402C))
#define TIMER4_TAMATCHR       (*((volatile uint32_t *)0x40034030))
#define TIMER4_TBMATCHR       (*((volatile uint32_t *)0x40034034))
#define TIMER4_TAPR           (*((volatile uint32_t *)0x40034038))
#define TIMER4_TBPR           (*((volatile uint32_t *)0x4003403C))
#define TIMER4_TAPMR          (*((volatile uint32_t *)0x40034040))
#define TIMER4_TBPMR          (*((volatile uint32_t *)0x40034044))
#define TIMER4_TAR            (*((volatile uint32_t *)0x40034048))
#define TIMER4_TBR            (*((volatile uint32_t *)0x4003404C))
#define TIMER4_TAV            (*((volatile uint32_t *)0x40034050))
#define TIMER4_TBV            (*((volatile uint32_t *)0x40034054))
#define TIMER4_RTCPD          (*((volatile uint32_t *)0x40034058))
#define TIMER4_TAPS           (*((volatile uint32_t *)0x4003405C))
#define TIMER4_TBPS           (*((volatile uint32_t *)0x40034060))
#define TIMER4_TAPV           (*((volatile uint32_t *)0x40034064))
#define TIMER4_TBPV           (*((volatile uint32_t *)0x40034068))
#define TIMER4_PP             (*((volatile uint32_t *)0x40034FC0))

//*****************************************************************************
//
// Timer registers (TIMER5)
//
//*****************************************************************************
#define TIMER5_CFG            (*((volatile uint32_t *)0x40035000))
#define TIMER5_TAMR           (*((volatile uint32_t *)0x40035004))
#define TIMER5_TBMR           (*((volatile uint32_t *)0x40035008))
#define TIMER5_CTL            (*((volatile uint32_t *)0x4003500C))
#define TIMER5_SYNC           (*((volatile uint32_t *)0x40035010))
#define TIMER5_IMR            (*((volatile uint32_t *)0x40035018))
#define TIMER5_RIS            (*((volatile uint32_t *)0x4003501C))
#define TIMER5_MIS            (*((volatile uint32_t *)0x40035020))
#define TIMER5_ICR            (*((volatile uint32_t *)0x40035024))
#define TIMER5_TAILR          (*((volatile uint32_t *)0x40035028))
#define TIMER5_TBILR          (*((volatile uint32_t *)0x4003502C))
#define TIMER5_TAMATCHR       (*((volatile uint32_t *)0x40035030))
#define TIMER5_TBMATCHR       (*((volatile uint32_t *)0x40035034))
#define TIMER5_TAPR           (*((volatile uint32_t *)0x40035038))
#define TIMER5_TBPR           (*((volatile uint32_t *)0x4003503C))
#define TIMER5_TAPMR          (*((volatile uint32_t *)0x40035040))
#define TIMER5_TBPMR          (*((volatile uint32_t *)0x40035044))
#define TIMER5_TAR            (*((volatile uint32_t *)0x40035048))
#define TIMER5_TBR            (*((volatile uint32_t *)0x4003504C))
#define TIMER5_TAV            (*((volatile uint32_t *)0x40035050))
#define TIMER5_TBV            (*((volatile uint32_t *)0x40035054))
#define TIMER5_RTCPD          (*((volatile uint32_t *)0x40035058))
#define TIMER5_TAPS           (*((volatile uint32_t *)0x4003505C))
#define TIMER5_TBPS           (*((volatile uint32_t *)0x40035060))
#define TIMER5_TAPV           (*((volatile uint32_t *)0x40035064))
#define TIMER5_TBPV           (*((volatile uint32_t *)0x40035068))
#define TIMER5_PP             (*((volatile uint32_t *)0x40035FC0))

//*****************************************************************************
//
// Timer registers (WTIMER0)
//
//*****************************************************************************
#define WTIMER0_CFG           (*((volatile uint32_t *)0x40036000))
#define WTIMER0_TAMR          (*((volatile uint32_t *)0x40036004))
#define WTIMER0_TBMR          (*((volatile uint32_t *)0x40036008))
#define WTIMER0_CTL           (*((volatile uint32_t *)0x4003600C))
#define WTIMER0_SYNC          (*((volatile uint32_t *)0x40036010))
#define WTIMER0_IMR           (*((volatile uint32_t *)0x40036018))
#define WTIMER0_RIS           (*((volatile uint32_t *)0x4003601C))
#define WTIMER0_MIS           (*((volatile uint32_t *)0x40036020))
#define WTIMER0_ICR           (*((volatile uint32_t *)0x40036024))
#define WTIMER0_TAILR         (*((volatile uint32_t *)0x40036028))
#define WTIMER0_TBILR         (*((volatile uint32_t *)0x4003602C))
#define WTIMER0_TAMATCHR      (*((volatile uint32_t *)0x40036030))
#define WTIMER0_TBMATCHR      (*((volatile uint32_t *)0x40036034))
#define WTIMER0_TAPR          (*((volatile uint32_t *)0x40036038))
#define WTIMER0_TBPR          (*((volatile uint32_t *)0x4003603C))
#define WTIMER0_TAPMR         (*((volatile uint32_t *)0x40036040))
#define WTIMER0_TBPMR         (*((volatile uint32_t *)0x40036044))
#define WTIMER0_TAR           (*((volatile uint32_t *)0x40036048))
#define WTIMER0_TBR           (*((volatile uint32_t *)0x4003604C))
#define WTIMER0_TAV           (*((volatile uint32_t *)0x40036050))
#define WTIMER0_TBV           (*((volatile uint32_t *)0x40036054))
#define WTIMER0_RTCPD         (*((volatile uint32_t *)0x40036058))
#define WTIMER0_TAPS          (*((volatile uint32_t *)0x4003605C))
#define WTIMER0_TBPS          (*((volatile uint32_t *)0x40036060))
#define WTIMER0_TAPV          (*((volatile uint32_t *)0x40036064))
#define WTIMER0_TBPV          (*((volatile uint32_t *)0x40036068))
#define WTIMER0_PP            (*((volatile uint32_t *)0x40036FC0))

//*****************************************************************************
//
// Timer registers (WTIMER1)
//
//*****************************************************************************
#define WTIMER1_CFG           (*((volatile uint32_t *)0x40037000))
#define WTIMER1_TAMR          (*((volatile uint32_t *)0x40037004))
#define WTIMER1_TBMR          (*((volatile uint32_t *)0x40037008))
#define WTIMER1_CTL           (*((volatile uint32_t *)0x4003700C))
#define WTIMER1_SYNC          (*((volatile uint32_t *)0x40037010))
#define WTIMER1_IMR           (*((volatile uint32_t *)0x40037018))
#define WTIMER1_RIS           (*((volatile uint32_t *)0x4003701C))
#define WTIMER1_MIS           (*((volatile uint32_t *)0x40037020))
#define WTIMER1_ICR           (*((volatile uint32_t *)0x40037024))
#define WTIMER1_TAILR         (*((volatile uint32_t *)0x40037028))
#define WTIMER1_TBILR         (*((volatile uint32_t *)0x4003702C))
#define WTIMER1_TAMATCHR      (*((volatile uint32_t *)0x40037030))
#define WTIMER1_TBMATCHR      (*((volatile uint32_t *)0x40037034))
#define WTIMER1_TAPR          (*((volatile uint32_t *)0x40037038))
#define WTIMER1_TBPR          (*((volatile uint32_t *)0x4003703C))
#define WTIMER1_TAPMR         (*((volatile uint32_t *)0x40037040))
#define WTIMER1_TBPMR         (*((volatile uint32_t *)0x40037044))
#define WTIMER1_TAR           (*((volatile uint32_t *)0x40037048))
#define WTIMER1_TBR           (*((volatile uint32_t *)0x4003704C))
#define WTIMER1_TAV           (*((volatile uint32_t *)0x40037050))
#define WTIMER1_TBV           (*((volatile uint32_t *)0x40037054))
#define WTIMER1_RTCPD         (*((volatile uint32_t *)0x40037058))
#define WTIMER1_TAPS          (*((volatile uint32_t *)0x4003705C))
#define WTIMER1_TBPS          (*((volatile uint32_t *)0x40037060))
#define WTIMER1_TAPV          (*((volatile uint32_t *)0x40037064))
#define WTIMER1_TBPV          (*((volatile uint32_t *)0x40037068))
#define WTIMER1_PP            (*((volatile uint32_t *)0x40037FC0))
//*****************************************************************************
//
// Timer registers (WTIMER2)
//
//*****************************************************************************
#define WTIMER2_CFG           (*((volatile uint32_t *)0x4004C000))
#define WTIMER2_TAMR          (*((volatile uint32_t *)0x4004C004))
#define WTIMER2_TBMR          (*((volatile uint32_t *)0x4004C008))
#define WTIMER2_CTL           (*((volatile uint32_t *)0x4004C00C))
#define WTIMER2_SYNC          (*((volatile uint32_t *)0x4004C010))
#define WTIMER2_IMR           (*((volatile uint32_t *)0x4004C018))
#define WTIMER2_RIS           (*((volatile uint32_t *)0x4004C01C))
#define WTIMER2_MIS           (*((volatile uint32_t *)0x4004C020))
#define WTIMER2_ICR           (*((volatile uint32_t *)0x4004C024))
#define WTIMER2_TAILR         (*((volatile uint32_t *)0x4004C028))
#define WTIMER2_TBILR         (*((volatile uint32_t *)0x4004C02C))
#define WTIMER2_TAMATCHR      (*((volatile uint32_t *)0x4004C030))
#define WTIMER2_TBMATCHR      (*((volatile uint32_t *)0x4004C034))
#define WTIMER2_TAPR          (*((volatile uint32_t *)0x4004C038))
#define WTIMER2_TBPR          (*((volatile uint32_t *)0x4004C03C))
#define WTIMER2_TAPMR         (*((volatile uint32_t *)0x4004C040))
#define WTIMER2_TBPMR         (*((volatile uint32_t *)0x4004C044))
#define WTIMER2_TAR           (*((volatile uint32_t *)0x4004C048))
#define WTIMER2_TBR           (*((volatile uint32_t *)0x4004C04C))
#define WTIMER2_TAV           (*((volatile uint32_t *)0x4004C050))
#define WTIMER2_TBV           (*((volatile uint32_t *)0x4004C054))
#define WTIMER2_RTCPD         (*((volatile uint32_t *)0x4004C058))
#define WTIMER2_TAPS          (*((volatile uint32_t *)0x4004C05C))
#define WTIMER2_TBPS          (*((volatile uint32_t *)0x4004C060))
#define WTIMER2_TAPV          (*((volatile uint32_t *)0x4004C064))
#define WTIMER2_TBPV          (*((volatile uint32_t *)0x4004C068))
#define WTIMER2_PP            (*((volatile uint32_t *)0x4004CFC0))

//*****************************************************************************
//
// Timer registers (WTIMER3)
//
//*****************************************************************************
#define WTIMER3_CFG           (*((volatile uint32_t *)0x4004D000))
#define WTIMER3_TAMR          (*((volatile uint32_t *)0x4004D004))
#define WTIMER3_TBMR          (*((volatile uint32_t *)0x4004D008))
#define WTIMER3_CTL           (*((volatile uint32_t *)0x4004D00C))
#define WTIMER3_SYNC          (*((volatile uint32_t *)0x4004D010))
#define WTIMER3_IMR           (*((volatile uint32_t *)0x4004D018))
#define WTIMER3_RIS           (*((volatile uint32_t *)0x4004D01C))
#define WTIMER3_MIS           (*((volatile uint32_t *)0x4004D020))
#define WTIMER3_ICR           (*((volatile uint32_t *)0x4004D024))
#define WTIMER3_TAILR         (*((volatile uint32_t *)0x4004D028))
#define WTIMER3_TBILR         (*((volatile uint32_t *)0x4004D02C))
#define WTIMER3_TAMATCHR      (*((volatile uint32_t *)0x4004D030))
#define WTIMER3_TBMATCHR      (*((volatile uint32_t *)0x4004D034))
#define WTIMER3_TAPR          (*((volatile uint32_t *)0x4004D038))
#define WTIMER3_TBPR          (*((volatile uint32_t *)0x4004D03C))
#define WTIMER3_TAPMR         (*((volatile uint32_t *)0x4004D040))
#define WTIMER3_TBPMR         (*((volatile uint32_t *)0x4004D044))
#define WTIMER3_TAR           (*((volatile uint32_t *)0x4004D048))
#define WTIMER3_TBR           (*((volatile uint32_t *)0x4004D04C))
#define WTIMER3_TAV           (*((volatile uint32_t *)0x4004D050))
#define WTIMER3_TBV           (*((volatile uint32_t *)0x4004D054))
#define WTIMER3_RTCPD         (*((volatile uint32_t *)0x4004D058))
#define WTIMER3_TAPS          (*((volatile uint32_t *)0x4004D05C))
#define WTIMER3_TBPS          (*((volatile uint32_t *)0x4004D060))
#define WTIMER3_TAPV          (*((volatile uint32_t *)0x4004D064))
#define WTIMER3_TBPV          (*((volatile uint32_t *)0x4004D068))
#define WTIMER3_PP            (*((volatile uint32_t *)0x4004DFC0))

//*****************************************************************************
//
// Timer registers (WTIMER4)
//
//*****************************************************************************
#define WTIMER4_CFG           (*((volatile uint32_t *)0x4004E000))
#define WTIMER4_TAMR          (*((volatile uint32_t *)0x4004E004))
#define WTIMER4_TBMR          (*((volatile uint32_t *)0x4004E008))
#define WTIMER4_CTL           (*((volatile uint32_t *)0x4004E00C))
#define WTIMER4_SYNC          (*((volatile uint32_t *)0x4004E010))
#define WTIMER4_IMR           (*((volatile uint32_t *)0x4004E018))
#define WTIMER4_RIS           (*((volatile uint32_t *)0x4004E01C))
#define WTIMER4_MIS           (*((volatile uint32_t *)0x4004E020))
#define WTIMER4_ICR           (*((volatile uint32_t *)0x4004E024))
#define WTIMER4_TAILR         (*((volatile uint32_t *)0x4004E028))
#define WTIMER4_TBILR         (*((volatile uint32_t *)0x4004E02C))
#define WTIMER4_TAMATCHR      (*((volatile uint32_t *)0x4004E030))
#define WTIMER4_TBMATCHR      (*((volatile uint32_t *)0x4004E034))
#define WTIMER4_TAPR          (*((volatile uint32_t *)0x4004E038))
#define WTIMER4_TBPR          (*((volatile uint32_t *)0x4004E03C))
#define WTIMER4_TAPMR         (*((volatile uint32_t *)0x4004E040))
#define WTIMER4_TBPMR         (*((volatile uint32_t *)0x4004E044))
#define WTIMER4_TAR           (*((volatile uint32_t *)0x4004E048))
#define WTIMER4_TBR           (*((volatile uint32_t *)0x4004E04C))
#define WTIMER4_TAV           (*((volatile uint32_t *)0x4004E050))
#define WTIMER4_TBV           (*((volatile uint32_t *)0x4004E054))
#define WTIMER4_RTCPD         (*((volatile uint32_t *)0x4004E058))
#define WTIMER4_TAPS          (*((volatile uint32_t *)0x4004E05C))
#define WTIMER4_TBPS          (*((volatile uint32_t *)0x4004E060))
#define WTIMER4_TAPV          (*((volatile uint32_t *)0x4004E064))
#define WTIMER4_TBPV          (*((volatile uint32_t *)0x4004E068))
#define WTIMER4_PP            (*((volatile uint32_t *)0x4004EFC0))

//*****************************************************************************
//
// Timer registers (WTIMER5)
//
//*****************************************************************************
#define WTIMER5_CFG           (*((volatile uint32_t *)0x4004F000))
#define WTIMER5_TAMR          (*((volatile uint32_t *)0x4004F004))
#define WTIMER5_TBMR          (*((volatile uint32_t *)0x4004F008))
#define WTIMER5_CTL           (*((volatile uint32_t *)0x4004F00C))
#define WTIMER5_SYNC          (*((volatile uint32_t *)0x4004F010))
#define WTIMER5_IMR           (*((volatile uint32_t *)0x4004F018))
#define WTIMER5_RIS           (*((volatile uint32_t *)0x4004F01C))
#define WTIMER5_MIS           (*((volatile uint32_t *)0x4004F020))
#define WTIMER5_ICR           (*((volatile uint32_t *)0x4004F024))
#define WTIMER5_TAILR         (*((volatile uint32_t *)0x4004F028))
#define WTIMER5_TBILR         (*((volatile uint32_t *)0x4004F02C))
#define WTIMER5_TAMATCHR      (*((volatile uint32_t *)0x4004F030))
#define WTIMER5_TBMATCHR      (*((volatile uint32_t *)0x4004F034))
#define WTIMER5_TAPR          (*((volatile uint32_t *)0x4004F038))
#define WTIMER5_TBPR          (*((volatile uint32_t *)0x4004F03C))
#define WTIMER5_TAPMR         (*((volatile uint32_t *)0x4004F040))
#define WTIMER5_TBPMR         (*((volatile uint32_t *)0x4004F044))
#define WTIMER5_TAR           (*((volatile uint32_t *)0x4004F048))
#define WTIMER5_TBR           (*((volatile uint32_t *)0x4004F04C))
#define WTIMER5_TAV           (*((volatile uint32_t *)0x4004F050))
#define WTIMER5_TBV           (*((volatile uint32_t *)0x4004F054))
#define WTIMER5_RTCPD         (*((volatile uint32_t *)0x4004F058))
#define WTIMER5_TAPS          (*((volatile uint32_t *)0x4004F05C))
#define WTIMER5_TBPS          (*((volatile uint32_t *)0x4004F060))
#define WTIMER5_TAPV          (*((volatile uint32_t *)0x4004F064))
#define WTIMER5_TBPV          (*((volatile uint32_t *)0x4004F068))
#define WTIMER5_PP            (*((volatile uint32_t *)0x4004FFC0))

/************************************************************************************************/
#define Base_TIMER_CFG            0x40030000
#define Base_TIMER_TAMR           0x40030004
#define Base_TIMER_TBMR           0x40030008
#define Base_TIMER_CTL            0x4003000C
#define Base_TIMER_SYNC           0x40030010
#define Base_TIMER_IMR            0x40030018
#define Base_TIMER_RIS            0x4003001C
#define Base_TIMER_MIS            0x40030020
#define Base_TIMER_ICR            0x40030024
#define Base_TIMER_TAILR          0x40030028
#define Base_TIMER_TBILR          0x4003002C
#define Base_TIMER_TAMATCHR       0x40030030
#define Base_TIMER_TBMATCHR       0x40030034
#define Base_TIMER_TAPR           0x40030038
#define Base_TIMER_TBPR           0x4003003C
#define Base_TIMER_TAPMR          0x40030040
#define Base_TIMER_TBPMR          0x40030044
#define Base_TIMER_TAR            0x40030048
#define Base_TIMER_TBR            0x4003004C
#define Base_TIMER_TAV            0x40030050
#define Base_TIMER_TBV            0x40030054
#define Base_TIMER_RTCPD          0x40030058
#define Base_TIMER_TAPS           0x4003005C
#define Base_TIMER_TBPS           0x40030060
#define Base_TIMER_TAPV           0x40030064
#define Base_TIMER_TBPV           0x40030068
#define Base_TIMER_PP             0x40030FC0


#define TIMER0_OFFSET  0
#define TIMER1_OFFSET  0x1000
#define TIMER2_OFFSET  0x2000
#define TIMER3_OFFSET  0x3000
#define TIMER4_OFFSET  0x4000
#define TIMER5_OFFSET  0x5000
#define WTIMER0_OFFSET 0x6000
#define WTIMER1_OFFSET 0x7000
#define WTIMER2_OFFSET 0x1C000
#define WTIMER3_OFFSET 0x1D000
#define WTIMER4_OFFSET 0x1E000
#define WTIMER5_OFFSET 0x1F000


#endif /* GPT_GPT_REG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Reg.h
 *********************************************************************************************************************/
