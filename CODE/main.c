
#include "STD_HEADERS/STD_TYPES.h"
#include "STD_HEADERS/BITMATH.h"

#include "MCU/Atmega32_REGS.h"
#include "MCAL/DIO/MCAL_DIO_interface.h"
#include "HAL/SEVEN_SEGMENT/SEVENSEGMANT_interface.h"
 #define F_CPU 8000000
 #include "util/delay.h"
 
#define SEVENSEGMANT_1    PINB0
#define SEVENSEGMANT_2    PINB1 
#define POUSE_RESUME_PB   PINB6
#define RESET_PB          PINB7
#define CONFG_PB          PINB5
#define DIGIT1LED         PINB3
#define DIGIT2LED         PINB4

u8 New_Time=30, Time=30, FLAGOFPB1=0,FLAGOFPB2=0,PRESSEDFLAG_CONFG_PB=0,SECONDPRESSFLAG_CONFG_PB=0,PRESSEDFLAG_RESET_PB=0,PRESSEDFLAG_POUSE_RESUME_PB=0,EDIT_FLAG=0,SECONDPRESSFLAG_POUSE_RESUME_PB=0;

void Desplay_Number (u8 Number)
{
	u8 digit0,digit1;
	digit0=Number%10;
	digit1=Number/10;
	MCAL_DIO_WRITEPIN(SEVENSEGMANT_2,HIGH);
	HAL_SEVENSEGMANT_WriteNumber(digit0);
	_delay_ms(3);
	MCAL_DIO_WRITEPIN(SEVENSEGMANT_2,LOW);
	MCAL_DIO_WRITEPIN(SEVENSEGMANT_1,HIGH);
	HAL_SEVENSEGMANT_WriteNumber(digit1);
	_delay_ms(3);
	MCAL_DIO_WRITEPIN(SEVENSEGMANT_1,LOW);
}

void pouse_resume_PB_PRESSED (void)
{
	if (MCAL_DIO_READPIN(POUSE_RESUME_PB)==LOW)
	{
		if (SECONDPRESSFLAG_POUSE_RESUME_PB==0)
		{
		FLAGOFPB1++;
		MCAL_DIO_WRITEPIN(DIGIT1LED,HIGH);
		MCAL_DIO_WRITEPIN(DIGIT2LED,HIGH);
		SECONDPRESSFLAG_POUSE_RESUME_PB++;
		}
		
	}
	else
	{
		SECONDPRESSFLAG_POUSE_RESUME_PB=0;
	}
	
		if (FLAGOFPB1==2)
		{
		FLAGOFPB1=0;
		MCAL_DIO_WRITEPIN(DIGIT1LED,LOW);
		MCAL_DIO_WRITEPIN(DIGIT2LED,LOW);
	
		}
	
	
}

void confgration_PB_PRESSED (void)
{
	u8 SelectedDigit=0;
	u8 RESET_PB_Counts=0;
	u8 POUSE_RESUME_Counts=0;
	if (MCAL_DIO_READPIN(CONFG_PB)==LOW)
	{
			
		if (PRESSEDFLAG_CONFG_PB==0)
		{
			FLAGOFPB2++;
			while (FLAGOFPB2<3)
			{
			
			if (FLAGOFPB2==1)
			{
				MCAL_DIO_WRITEPIN(DIGIT1LED,HIGH);
				SelectedDigit=1;
					
			}
			else if (FLAGOFPB2==2)
			{
				MCAL_DIO_WRITEPIN(DIGIT1LED,LOW);
				MCAL_DIO_WRITEPIN(DIGIT2LED,HIGH);
				SelectedDigit=2;
					
			}
			while (EDIT_FLAG==0)
			{
				 RESET_PB_Counts=0;
				 POUSE_RESUME_Counts=0;
			if (MCAL_DIO_READPIN(CONFG_PB)==LOW)
			{
				if (SECONDPRESSFLAG_CONFG_PB==1)
				{
				FLAGOFPB2++;
				SECONDPRESSFLAG_CONFG_PB=0;
				EDIT_FLAG=1;
				
				}
				
			}
			else
			{
				SECONDPRESSFLAG_CONFG_PB=1;
			}
			
			if (MCAL_DIO_READPIN(RESET_PB)==LOW)
			{
				if (PRESSEDFLAG_RESET_PB==0)
				{
					RESET_PB_Counts++;
					PRESSEDFLAG_RESET_PB++;
				}
			}
			else
			{
				PRESSEDFLAG_RESET_PB=0;
			}
			
			if (MCAL_DIO_READPIN(POUSE_RESUME_PB)==LOW)
			{
				if (PRESSEDFLAG_POUSE_RESUME_PB==0)
				{
					POUSE_RESUME_Counts++;
					PRESSEDFLAG_POUSE_RESUME_PB++;
				}
			}
			else
			{
				PRESSEDFLAG_POUSE_RESUME_PB=0;
			}
			
			if (SelectedDigit==1)
			{
				New_Time=Time+POUSE_RESUME_Counts-RESET_PB_Counts;
				
			}
			else if (SelectedDigit==2)
			{
				New_Time=Time+((POUSE_RESUME_Counts-RESET_PB_Counts)*10);
			}
			Time=New_Time;
			Desplay_Number (Time);
			}
			EDIT_FLAG=0;
			
			}
			PRESSEDFLAG_CONFG_PB=1;
			FLAGOFPB2=0;
			MCAL_DIO_WRITEPIN(DIGIT2LED,LOW);
		}
			
	}
	else
	{
		PRESSEDFLAG_CONFG_PB=0;
	}
	
}

	
void Reset_PB_PRESSED (void)
{
	if (MCAL_DIO_READPIN(RESET_PB)==LOW)
	{
		Time=New_Time;
	}
	
} 
void ALARM (void)
{
	
	MCAL_DIO_TOGGLEPIN (DIGIT1LED);
	MCAL_DIO_TOGGLEPIN (DIGIT2LED);
	
}
int main(void)
{
   MCAL_DIO_INIT();
   HAL_SEVENSEGMANT_Init();
    while (1) 
    {
		if (Time!=0)
		{
			
		for (u16 Iteration=0;Iteration<160;Iteration++)
		{
			Desplay_Number (Time);
	        pouse_resume_PB_PRESSED();
			Reset_PB_PRESSED();
			confgration_PB_PRESSED();
		}
		if (FLAGOFPB1==0)
		{
		Time--;
		}
		}
		else
		{
			for (u16 Iteration=0;Iteration<12;Iteration++)
			{
				Desplay_Number (Time);
				Reset_PB_PRESSED();
				confgration_PB_PRESSED();
			}
			ALARM();

			
		}
		
    }
		

}

