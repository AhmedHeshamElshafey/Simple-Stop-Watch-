/*
 * SEVENSEGMANT_interface.h
 *
 * Created: 20/09/2024 02:30:51 ص
 *  Author: LENOVO
 */ 


#ifndef SEVENSEGMANT_INTERFACE_H_
#define SEVENSEGMANT_INTERFACE_H_


typedef enum {
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	A,
	B, 
	C,
	D,
	E,
	F
	}SEVENSEGMANT_HEXNUMBER_et;
	
void HAL_SEVENSEGMANT_Init (void);
void HAL_SEVENSEGMANT_WriteNumber (u8 NUMBER);






#endif /* SEVENSEGMANT_INTERFACE_H_ */