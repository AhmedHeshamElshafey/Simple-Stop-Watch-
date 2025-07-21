#ifndef MCAL_DIO_INTERFACE_H_
#define MCAL_DIO_INTERFACE_H_

#include "../../STD_HEADERS/STD_TYPES.h"

typedef enum {
	PortA,
	PortB,
	PortC,
	PortD
	}DIO_PORTS_et;

typedef enum {
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	PIN_NUMBERS,
	}DIO_PINS_et;
	
typedef enum {
	LOW,
	HIGH
	}DIO_PINLEVEl_et;	


/*********************************************************FUNCATIONS*********************************************/

void MCAL_DIO_INIT (void);

void MCAL_DIO_WRITEPIN(DIO_PINS_et Pinx,DIO_PINLEVEl_et PinxLevel);

DIO_PINLEVEl_et MCAL_DIO_READPIN (DIO_PINS_et Pinx) ;

void MCAL_DIO_TOGGLEPIN (DIO_PINS_et Pinx) ;

void MCAL_DIO_WRITEPORT (DIO_PORTS_et Portx,u8 PortxLevel) ;

u8 MCAL_DIO_READPORT (DIO_PORTS_et Portx) ;

#endif /* MCAL_DIO_INTERFACE_H_ */