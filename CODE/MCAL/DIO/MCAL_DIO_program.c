#include "../../STD_HEADERS/STD_TYPES.h"
#include "../../STD_HEADERS/BITMATH.h"


#include "../../MCU/Atmega32_REGS.h"

#include "MCAL_DIO_interface.h"
#include "MCAL_DIO_privite.h"

  volatile u8* DIO_REG [4][3]={ {&REG_DDRA,&REG_PORTA,&REG_PINA},
  {&REG_DDRB,&REG_PORTB,&REG_PINB},
  {&REG_DDRC,&REG_PORTC,&REG_PINC},
  {&REG_DDRD,&REG_PORTD,&REG_PIND}
  };
							   
 extern const DIO_PINSTUTES_et PINXSTUTES [PIN_NUMBERS];

 void MCAL_DIO_SetPinDirection(DIO_PINS_et Pinx,DIO_PINSTUTES_et stutes)
{   u8 Pin;
	DIO_PORTS_et Port;
	Port=Pinx/8;
	Pin =Pinx%8;
	switch (stutes)
	{
		case OUTPUTT :
		SET_BIT(*DIO_REG[Port][DDR],Pin);
		CLEAR_BIT(*DIO_REG[Port][PORT],Pin);
		break;
		case INPFREE :
		CLEAR_BIT(*DIO_REG[Port][DDR],Pin);
		CLEAR_BIT(*DIO_REG[Port][PORT],Pin);
		break;
		case INPPULLUP :
		CLEAR_BIT(*DIO_REG[Port][DDR],Pin);
		SET_BIT(*DIO_REG[Port][PORT],Pin);
		break;
		default:
		/*ERROR*/
		break;
	}
	
}

void MCAL_DIO_INIT (void)
{
	DIO_PINS_et Pinx;
	for (Pinx=PINA0;Pinx<PIN_NUMBERS;Pinx++)
	{
		MCAL_DIO_SetPinDirection(Pinx,PINXSTUTES[Pinx]);
	}
}

void MCAL_DIO_WRITEPIN(DIO_PINS_et Pinx,DIO_PINLEVEl_et PinxLevel)
{
	u8 Pin;
	DIO_PORTS_et Port;
	Port=Pinx/8;
	Pin =Pinx%8;
	if (PinxLevel==HIGH)
	{
		SET_BIT(*DIO_REG[Port][PORT],Pin);
	}
	else if(PinxLevel==LOW)
	{
		CLEAR_BIT(*DIO_REG[Port][PORT],Pin);
	}
}

DIO_PINLEVEl_et MCAL_DIO_READPIN (DIO_PINS_et Pinx) 
{
	u8 Pin;
	DIO_PORTS_et Port;
	Port=Pinx/8;
	Pin =Pinx%8;
	return READ_BIT(*DIO_REG[Port][PIN],Pin);
}



void MCAL_DIO_TOGGLEPIN (DIO_PINS_et Pinx) 
{
	u8 Pin;
	DIO_PORTS_et Port;
	Port=Pinx/8;
	Pin =Pinx%8;
	TOGGLE_BIT(*DIO_REG[Port][PORT],Pin);	
}
 
 void MCAL_DIO_WRITEPORT (DIO_PORTS_et Portx,u8 PortxLevel) 
      {
      	*DIO_REG[Portx][PORT]=PortxLevel;
      }
   
 u8 MCAL_DIO_READPORT (DIO_PORTS_et Portx) 
 {
	return *DIO_REG[Portx][PIN]; 
 }