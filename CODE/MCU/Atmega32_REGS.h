/*
 * Atmega32_REGS.h
 *
 * Created: 18/09/2024 05:21:55 م
 *  Author: LENOVO
 */ 


#ifndef ATMEGA32_REGS_H_
#define ATMEGA32_REGS_H_

#include "../STD_HEADERS/STD_TYPES.h"
#include "Atmega32_BasedAddress.h"

/********************************************************** DIO REG ******************************************************/

#define REG_DDRA    (*(volatile u8*) DDRA_BASEDADDRESS)
#define REG_PORTA   (*(volatile u8*) PORTA_BASEDADDRESS)
#define REG_PINA    (*(volatile u8*) PINA_BASEDADDRESS)

#define REG_DDRB    (*(volatile u8*) DDRB_BASEDADDRESS)
#define REG_PORTB   (*(volatile u8*) PORTB_BASEDADDRESS)
#define REG_PINB    (*(volatile u8*) PINB_BASEDADDRESS)

#define REG_DDRC    (*(volatile u8*) DDRC_BASEDADDRESS)
#define REG_PORTC   (*(volatile u8*) PORTC_BASEDADDRESS)
#define REG_PINC    (*(volatile u8*) PINC_BASEDADDRESS)

#define REG_DDRD    (*(volatile u8*) DDRD_BASEDADDRESS)
#define REG_PORTD   (*(volatile u8*) PORTD_BASEDADDRESS)
#define REG_PIND    (*(volatile u8*) PIND_BASEDADDRESS)

/************************************************************************************************************************/

#endif /* ATMEGA32_REGS_H_ */