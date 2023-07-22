//
//
//#include "typedef.h"
//#include "DIO_int.h"
//#include "ATMEGA32_REGESTERS.h"
////#define  F_CPU 16000000
//
//
//#include <util/delay.h>
//
//int main(void)
//{
//	DIO_voidSetPinDirection(PORTA,DIO_u8PIN_4,DIO_u8OUTPUT);
//	DIO_voidSetPortDirection(PORTC,0xFF);
//
//	int numbers[10] = {
//			0b00111111, //0
//			0b00000110, //1
//			0b01011011, //2
//			0b01001111, //3
//			0b01100110, //4
//			0b01101101, //5
//			0b01111101, //6
//			0b00000111, //7
//			0b01111111, //8
//			0b01100111  //9
//
//	};
//
//	while(1)
//	{
////		DIO_voidSetPinValue(PORTA,DIO_u8PIN_4,DIO_u8HIGH);
////		_delay_ms(200);
////		DIO_voidSetPinValue(PORTA,DIO_u8PIN_4,DIO_u8LOW);
////		_delay_ms(200);
//		for(u8 i = 0 ; i < 10 ; i++)
//		{
//			DIO_voidSetPortValue(PORTC,numbers[i]);
//			_delay_ms(500);
//		}
//	}
//
//
//
//
//
//
//	return 0;
//}
