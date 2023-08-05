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
//#include "Timers_int.h"
//
//volatile u16 Number_of_OVFS;
//
//
//void ISR(void)
//{
//	static u16 counter = 0;
//	static u8 flag = 0;
//	counter++;
//	if(counter == 3906)
//	{
//		//LCD_voidWriteString("hi");
//
//		TGL_BIT(PORTA_REG,2);
////		if(flag == 1)
////		{
////			DIO_voidSetPinValue(PORTA,DIO_u8PIN_2,DIO_u8HIGH);
////			flag = 0;
////		} else
////		{
////			DIO_voidSetPinValue(PORTA,DIO_u8PIN_2,DIO_u8LOW);
////			flag = 1;
////		}
//
//
//
//
//		counter = 0;
//	}
//
//}
//void ISR_CTC(void)
//{
//	static u16 counter = 0;
//	static u8 flag = 0;
//	counter++;
//	if(counter == Number_of_OVFS)
//	{
//		//LCD_voidWriteString("hi");
//
//		TGL_BIT(PORTA_REG,2);
////		if(flag == 1)
////		{
////			DIO_voidSetPinValue(PORTA,DIO_u8PIN_2,DIO_u8HIGH);
////			flag = 0;
////		} else
////		{
////			DIO_voidSetPinValue(PORTA,DIO_u8PIN_2,DIO_u8LOW);
////			flag = 1;
////		}
//
//		counter = 0;
//	}
//
//}
//
//
//
//int main(void)
//{
//	DIO_voidSetPinDirection(PORTB,DIO_u8PIN_0,DIO_u8INPUT);
//	DIO_voidSetPinDirection(PORTA,DIO_u8PIN_2,DIO_u8OUTPUT);
//	DIO_voidSetPinDirection(PORTB,DIO_u8PIN_3,DIO_u8OUTPUT);
//	DIO_voidSetPinValue(PORTB,DIO_u8PIN_0,DIO_u8LOW);
//	DIO_voidSetPinValue(PORTA,DIO_u8PIN_2,DIO_u8LOW);
//
//	//GPT_vidSetCallBack(ISR);
//
//	LCD_voidWriteNumber(Number_of_OVFS);
//	GPT_vidSetCallBackCTC(ISR_CTC);
//	GIE_voidEnable();
//	LCD_voidInit();
//	GPT_vidInit();
//	GPT_vidSetCompareValue(200);
//	GPT_vidStartTimer();
//
//	Number_of_OVFS = delay_s(1);
//
//
////TCNT0_REG = 250;
////	u8 counter = 0;
////	u16 value = 0;
//
//	while(1)
//	{
////		 value = TCNT0_REG + (counter * 255);
////
////		if(TCNT0_REG == 255){
////			TCNT0_REG = 0;
////			counter++;
////
////		}
////		LCD_voidWriteString("    ");
////		LCD_voidGoTo(0,0);
////		LCD_voidWriteNumber(value);
//
//
//
//
//
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
