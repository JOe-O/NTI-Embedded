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
//
//#include "GIE_interface.h"
//#include "GIE_private.h"
//
////#include "ADC.h"
////#include "ADC_config.h"
////#include "ADC_priv.h"
//
//#include "LCD_int.h"
//#include "LCD_Config.h"
//
//#include "spi_config.h"
//#include "spi_init.h"
//#include "SPI_priv.h"
//
//#include "util/delay.h"
//
//u8 recieved_data;
//void receieveISR(void)
//{
//	LCD_voidWriteNumber(recieved_data);
//}
//
//int main(void){
//	DIO_voidSetPinDirection(PORTC,DIO_u8PIN_5,DIO_u8OUTPUT);
//
//	LCD_voidInit();
//	SPI_voidSlaveInit();
//
//	GIE_voidEnable();
//
//	//enable spi interrupt
//	SET_BIT(SPCR,7);
//
//
//	while(1)
//	{
////		u8 received_value = SPI_u8Recieve();
////
////		if(received_value == 1)
////		{
////			LCD_voidWriteString("hi ");
////			DIO_voidSetPinValue(PORTC,DIO_u8PIN_5,DIO_u8HIGH);
////			LCD_voidGoTo(0,0);
////
////		}else
////		{
////			LCD_voidWriteString("bye");
////			DIO_voidSetPinValue(PORTC,DIO_u8PIN_5,DIO_u8LOW);
////			LCD_voidGoTo(0,0);
////		}
//		SPI_u8ReadDataISR(recieved_data,1,receieveISR);
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
//
