///*
// * COUNTER.c
// *
// *  Created on: Aug 4, 2023
// *      Author: ART
// */
//
//#include "typedef.h"
//#include "DIO_int.h"
//#include "bitMath.h"
//#include "ATMEGA32_REGESTERS.h"
//#include "EXTI0_private.h"
//#include "EXTI0_interface.h"
//#include "EXTI0_config.h"
//
//#include "GIE_interface.h"
//#include "GIE_private.h"
//
//#include "ADC.h"
//#include "ADC_config.h"
//#include "ADC_priv.h"
//
//#include "LCD_int.h"
//#include "LCD_Config.h"
//
//#include "WDT_int.h"
//#include "util/delay.h"
//
//int main(void)
//{
//
//	DIO_voidSetPinDirection(PORTA,DIO_u8PIN_0,DIO_u8OUTPUT);
//	DIO_voidSetPinValue(PORTA,DIO_u8PIN_0,DIO_u8LOW);
//	_delay_ms(2000);
//
//	WDG_On();
//	DIO_voidSetPinValue(PORTA,DIO_u8PIN_0,DIO_u8HIGH);
//	_delay_ms(3000);
//
//	WDG_Off();
//
//
//
//
//
//	while(1)
//	{
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
