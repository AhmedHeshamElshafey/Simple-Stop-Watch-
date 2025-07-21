
#include "../../STD_HEADERS/BITMATH.h"
#include "../../STD_HEADERS/STD_TYPES.h"

#include "../../MCU/Atmega32_REGS.h"

#include "../../MCAL/DIO/MCAL_DIO_interface.h"
#include "../../MCAL/DIO/MCAL_DIO_privite.h"

#include "SEVENSEGMANT_privite.h"
#include "SEVENSEGMANT_interface.h"


extern const SEVENSEGMANT_Settings_et SEVENSEGMANT_Settings[SEVENSEGAMNT_SETTINGS];
extern const DIO_PINS_et SEVENSEGMANT_Pins[NORMAL_SEVENSEGAMNT_PINS];
const u8 COMMONCATHODE_SEVENSEGMANT_NUMBER [HEXNUMBERS]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

 void HAL_SEVENSEGMANT_sendData(u8 NUMBER)
{
	u8 pinx=0;
	u8 PinsNumber=0;
	
	if ((SEVENSEGMANT_Settings[SEVENSEGAMNT_MOOD]==CommonAnode_Normal_7Segment)||(SEVENSEGMANT_Settings[SEVENSEGAMNT_MOOD]==CommonCathode_Normal_7Segment))
	{
		PinsNumber=NORMAL_SEVENSEGAMNT_PINS-1;
	}
	else if (SEVENSEGMANT_Settings[SEVENSEGAMNT_MOOD]==Bcd_7Segment)
	{
		PinsNumber=BCD_SEVENSEGAMNT_PINS-1;
	}
	
	for (pinx=0;pinx<PinsNumber;pinx++)
	{
		
		if ((NUMBER>>pinx)&1)
		{
			MCAL_DIO_WRITEPIN(SEVENSEGMANT_Pins[pinx],HIGH);
		}
		else
		{
			MCAL_DIO_WRITEPIN(SEVENSEGMANT_Pins[pinx],LOW);
		}
	}
	
}

void HAL_SEVENSEGMANT_Init (void)
{
	u8 pinx=0;
	u8 PinsNumber=0;
		
	if ((SEVENSEGMANT_Settings[SEVENSEGAMNT_MOOD]==CommonAnode_Normal_7Segment)||(SEVENSEGMANT_Settings[SEVENSEGAMNT_MOOD]==CommonCathode_Normal_7Segment))
	{
		PinsNumber=NORMAL_SEVENSEGAMNT_PINS-1;
	}
	else if (SEVENSEGMANT_Settings[SEVENSEGAMNT_MOOD]==Bcd_7Segment)
	{
		PinsNumber=BCD_SEVENSEGAMNT_PINS-1;
	}
	
	for (pinx=0;pinx<PinsNumber;pinx++)
	{
		MCAL_DIO_SetPinDirection(SEVENSEGMANT_Pins[pinx],OUTPUTT);
	} 
	
	if (SEVENSEGMANT_Settings[SEVENSEGAMNT_COMMON_PIN_CONNECTION]==CONNECTED)
	{
	      MCAL_DIO_SetPinDirection(SEVENSEGMANT_Pins[COMMON_PIN],OUTPUTT);	
	}
	
}

void HAL_SEVENSEGMANT_WriteNumber (u8 NUMBER)
{
	if (SEVENSEGMANT_Settings[SEVENSEGAMNT_MOOD]==CommonAnode_Normal_7Segment)
	{
		HAL_SEVENSEGMANT_sendData(~COMMONCATHODE_SEVENSEGMANT_NUMBER[NUMBER]);	
	}
	else if (SEVENSEGMANT_Settings[SEVENSEGAMNT_MOOD]==CommonCathode_Normal_7Segment)
	{
		HAL_SEVENSEGMANT_sendData(COMMONCATHODE_SEVENSEGMANT_NUMBER[NUMBER]);	
	}
	else
	{
		HAL_SEVENSEGMANT_sendData(NUMBER);
	}
	
}



