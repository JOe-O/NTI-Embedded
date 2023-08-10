///*
// * I2C.c
// *
// *  Created on: Aug 7, 2023
// *      Author: JOe
// */
//
//
//
//#include "typedef.h"
//#include "DIO_int.h"
//#include "bitMath.h"
//#include "ATMEGA32_REGESTERS.h"
//
//#include "EXTI0_private.h"
//#include "EXTI0_interface.h"
//#include "EXTI0_config.h"
//
//#include "GIE_interface.h"
//#include "GIE_private.h"
//
//
//#include "LCD_int.h"
//#include "LCD_Config.h"
//
//#include "Timers_int.h"
//
//#include "I2C_int.h"
//
//#include "util/delay.h"
//
//int main(void){
//
//	DIO_voidSetPinDirection(PORTC,DIO_u8PIN_0,DIO_u8OUTPUT);
//	DIO_voidSetPinDirection(PORTC,DIO_u8PIN_1,DIO_u8OUTPUT);
//	DIO_voidSetPinDirection(PORTC,DIO_u8PIN_2,DIO_u8OUTPUT);
//
//	LCD_voidInit();
//	I2C_vidInit(1);
//
//	I2C_vidSendStart();
//	if(I2C_u8CheckStatus(TW_START) == 1){
//		LCD_voidWriteString("M start");
//		_delay_ms(1000);
//	}
//	I2C_vidSendSLA(2,WRITE);
//	if(I2C_u8CheckStatus(TW_MT_SLA_ACK) == 1){
//			LCD_voidGoTo(1,0);
//			LCD_voidWriteString("slave address sent");
//			LCD_voidWriteString("    ");
//			_delay_ms(1000);
//		}
//	I2C_vidSendData(3);
//	if(I2C_u8CheckStatus(TW_MT_DATA_ACK) == 1){
//		LCD_voidGoTo(0,0);
//		LCD_voidWriteString("M data ack");
//		LCD_voidWriteString("    ");
//		_delay_ms(1000);
//	}
//	_delay_ms(2000);
//	while(1)
//	{
//
//
//
//
//	}
//
//	return 0;
//}
