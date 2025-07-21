
#include "../../HAL/SEVEN_SEGMENT/SEVENSEGMANT_privite.h"
#include "../../MCAL/DIO/MCAL_DIO_interface.h"





	
/*
		MOOD OPTION :                                              COMMON PIN MOOD OPTIONS :
		
		CommonAnode_Normal_7Segment,                               CONNECTED
	    CommonCathode_Normal_7Segment,                             NOTCONNECTED
		Bcd_7Segment

*/


		
 const SEVENSEGMANT_Settings_et SEVENSEGMANT_Settings[SEVENSEGAMNT_SETTINGS]= {
	
	 CommonAnode_Normal_7Segment,            /* MOOD OF SEVEN SEGMANT*/
	 CONNECTED                                 /* COMMON PIN MOOD      */
};

 const DIO_PINS_et SEVENSEGMANT_Pins[NORMAL_SEVENSEGAMNT_PINS]= {
	PINA0,          // NORMAL SEVEN SEGMANT PIN 1  AND BCD SEVEN SEGMANT PIN 1 
	PINA1,          // NORMAL SEVEN SEGMANT PIN 2  AND BCD SEVEN SEGMANT PIN 2
	PINA2,          // NORMAL SEVEN SEGMANT PIN 3  AND BCD SEVEN SEGMANT PIN 3
	PINA3,          // NORMAL SEVEN SEGMANT PIN 4  AND BCD SEVEN SEGMANT PIN 4
	PINA4,          // NORMAL SEVEN SEGMANT PIN 5
	PINA5,          // NORMAL SEVEN SEGMANT PIN 6
	PINA6,          // NORMAL SEVEN SEGMANT PIN 7
	PINB0           // COMMON PIN IF NOT CONNECTION I MAKE THIS PIN NOT IN MIND BUT U MUST COMPLETE ARRAY
};

