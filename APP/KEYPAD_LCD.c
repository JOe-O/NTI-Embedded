///*
// * LCD.c
// *
// *  Created on: Jul 23, 2023
// *      Author: ART
// */
//
//#include "typedef.h"
//#include "DIO_int.h"
//#include "ATMEGA32_REGESTERS.h"
//#include "LCD_int.h"
//#include "LCD_Config.h"
//#include "Keypad_int.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <util/delay.h>
//
//u8 num1[10],num2[10];
//int main(void)
//{
//	LCD_voidInit();
//	u8 KeyVal;
//	Keypad_voidInit();
//	//LCD_voidSendCommand(0x80);
//	DIO_voidSetPinDirection(PORTC,DIO_u8PIN_2,DIO_u8OUTPUT);
//	DIO_voidSetPinDirection(PORTC,DIO_u8PIN_0,DIO_u8OUTPUT);
//	DIO_voidSetPinValue(PORTC,DIO_u8PIN_0,DIO_u8LOW);
//
//	//LCD_voidWriteString("hi");
//
//	while(1)
//	{
//		DIO_voidSetPinValue(PORTC,DIO_u8PIN_2,DIO_u8HIGH);
//		_delay_ms(500);
//		DIO_voidSetPinValue(PORTC,DIO_u8PIN_2,DIO_u8LOW);
//		_delay_ms(500);
//
////		KeyVal= Keypad_u8GetKey();
////		if(KeyVal != NOT_PRESSED)
////		{
////				LCD_voidWriteData(KeyVal);
////		}
//	}
//
//
//	return 0;
//}
