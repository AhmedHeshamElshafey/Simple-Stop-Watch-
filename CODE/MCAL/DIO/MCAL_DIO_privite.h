/*
 * MCAL_DIO_privite.h
 *
 * Created: 18/09/2024 05:29:37 م
 *  Author: LENOVO
 */ 


#ifndef MCAL_DIO_PRIVITE_H_
#define MCAL_DIO_PRIVITE_H_

#include "MCAL_DIO_interface.h"

#define DDR   0
#define PORT  1
#define PIN   2

typedef enum {
	OUTPUTT,
	INPFREE,
	INPPULLUP
	}DIO_PINSTUTES_et;
	
 void MCAL_DIO_SetPinDirection(DIO_PINS_et Pinx,DIO_PINSTUTES_et stutes);




#endif /* MCAL_DIO_PRIVITE_H_ */