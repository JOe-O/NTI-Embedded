///*
// * SPI_MASTER.c
// *
// *  Created on: Aug 3, 2023
// *      Author: JOe
// */
//
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
////#include "ADC.h"
////#include "ADC_config.h"
////#include "ADC_priv.h"
////
////#include "LCD_int.h"
////#include "LCD_Config.h"
//
//#include "spi_config.h"
//#include "spi_init.h"
//#include "SPI_priv.h"
//
//#include "util/delay.h"
//
//void sentISR(void)
//{
//
//	DIO_voidSetPinValue(PORTD,DIO_u8PIN_0,DIO_u8HIGH);
//	_delay_ms(500);
//	DIO_voidSetPinValue(PORTD,DIO_u8PIN_0,DIO_u8LOW);
//	_delay_ms(500);
//}
//
//int main(void){
//
//	DIO_voidSetPinDirection(PORTD,DIO_u8PIN_0,DIO_u8OUTPUT);
//
//	SPI_voidMasterInit();
//	GIE_voidEnable();
//
//	//enable spi interrupt
//	SET_BIT(SPCR,7);
//
//	u8 data = 5;
//
//	while(1)
//	{
////		SPI_u8Transfer(1);
////		_delay_ms(500);
////		SPI_u8Transfer(0);
////		_delay_ms(500);
//
//		SPI_voidSendDataISR(data,1,sentISR);
//
//
//
//
//	}
//
//
//	return 0;
//}
//
