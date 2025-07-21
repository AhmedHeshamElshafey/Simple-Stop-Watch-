/*
 * SEVENSEGMANT_privite.h
 *
 * Created: 20/09/2024 02:31:47 ص
 *  Author: LENOVO
 */ 

#include "../../STD_HEADERS/STD_TYPES.h"
#include "../../MCAL/DIO/MCAL_DIO_interface.h"


#ifndef SEVENSEGMANT_PRIVITE_H_
#define SEVENSEGMANT_PRIVITE_H_

#define NORMAL_SEVENSEGAMNT_PINS           8
#define BCD_SEVENSEGAMNT_PINS              5
#define SEVENSEGAMNT_SETTINGS              2
#define SEVENSEGAMNT_MOOD                  0
#define SEVENSEGAMNT_COMMON_PIN_CONNECTION 1
#define COMMON_PIN                         7 
#define HEXNUMBERS                         16
#define DECIMALNUMBERS                     10




typedef enum {
	CommonAnode_Normal_7Segment,            // SEVENSEGMANT MOOD
	CommonCathode_Normal_7Segment,          // SEVENSEGMANT MOOD
	Bcd_7Segment,                           // SEVENSEGMANT MOOD
	CONNECTED,                              //COMMON PIN CONNECTION
	NOTCONNECTED                            //COMMON PIN CONNECTION
}SEVENSEGMANT_Settings_et;

   
 void HAL_SEVENSEGMANT_sendData(u8 NUMBER);


#endif /* SEVENSEGMANT_PRIVITE_H_ */