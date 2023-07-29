///*
// * LED_Interrupt.c
// *
// *  Created on: Jul 28, 2023
// *      Author: ART
// */
//
//#include "typedef.h"
//#include "DIO_int.h"
//#include "ATMEGA32_REGESTERS.h"
//#include "EXTI0_private.h"
//#include "EXTI0_interface.h"
//#include "EXTI0_config.h"
//#include "GIE_interface.h"
//#include "GIE_private.h"
//
//
//
//#include <util/delay.h>
//
//void ISR(void)
//{
//	DIO_voidSetPinValue(PORTC,DIO_u8PIN_2,DIO_u8HIGH);
//	_delay_ms(500);
//	DIO_voidSetPinValue(PORTC,DIO_u8PIN_2,DIO_u8LOW);
//	_delay_ms(500);
//
//}
//
//int main(void)
//{
//	DIO_voidSetPinDirection(PORTD, DIO_u8PIN_3, DIO_u8INPUT);
//	DIO_voidSetPinValue(PORTD, DIO_u8PIN_3, DIO_u8HIGH);
//	DIO_voidSetPinDirection(PORTC, DIO_u8PIN_2, DIO_u8OUTPUT);
//
//	EXTI_SetCallBack(ISR);
//
//	GIE_voidEnable();
//
//	EXTI0_voidInit();
//	EXTI0_voidEnable();
//
//
//
//	while(1)
//	{//test
////		if(DIO_u8GetPinValue(PORTD,DIO_u8PIN_3) == DIO_u8LOW)
////		{
////			DIO_voidSetPinValue(PORTC,DIO_u8PIN_2,DIO_u8HIGH);
////
////		}else{
////			DIO_voidSetPinValue(PORTC,DIO_u8PIN_2,DIO_u8LOW);
////		}
//
//
//
//
//	}
//
//
//
//
//
//
//
//
//
//	return 0;
//}
//
//
//
