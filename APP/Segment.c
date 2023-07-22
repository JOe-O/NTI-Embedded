

#include "typedef.h"
#include "DIO_int.h"
#include "ATMEGA32_REGESTERS.h"
#include "Seg.h"
//#define  F_CPU 16000000


#include <util/delay.h>

int main(void)
{
	//DIO_voidSetPinDirection(PORTA,DIO_u8PIN_4,DIO_u8OUTPUT);
	DIO_voidSetPortDirection(PORTD,0xFF);
	DIO_voidSetPortDirection(PORTC,0xFF);


	while(1)
	{



		SEG_voidDisplay(PORTC , COMMON_CATHODE , SEG_5);
		//DIO_voidSetPortValue(PORTC,SEG_5);
		_delay_ms(100);
	}






	return 0;
}
