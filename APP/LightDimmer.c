///*
// * LightDimmer.c
// *
// *  Created on: Aug 5, 2023
// *      Author: JOe
// */
//
//#include "typedef.h"
//#include "DIO_int.h"
//#include "bitMath.h"
//#include "ATMEGA32_REGESTERS.h"
//
//
//
//#include "ADC.h"
//#include "ADC_config.h"
//#include "ADC_priv.h"
//
//#include "LCD_int.h"
//#include "LCD_Config.h"
//
//#include "PWM_int.h"
//
//#include "util/delay.h"
//
//
//int main(void){
//	DIO_voidSetPinDirection(PORTD,DIO_u8PIN_5,DIO_u8OUTPUT);
//
//	LCD_voidInit();
//
//	PWM_vidPwmInit(TIMER_1);
//
//	PWM_StartTimer(TIMER_1);
//
//	LCD_voidWriteString("Duty Cycle: ");
//
//
//	while(1)
//	{
//
//		for(int i = 0 ; i <= 100 ; i++)
//		{
//			PWM_vidSetPwmDutyCycle(TIMER_1,i);
//			LCD_voidGoTo(0,12);
//			LCD_voidWriteNumber(i);
//			LCD_voidWriteString("   ");
//			_delay_ms(10);
//
//		}
//		for(int i = 100 ; i >= 0 ; i--)
//		{
//			PWM_vidSetPwmDutyCycle(TIMER_1,i);
//			LCD_voidGoTo(0,12);
//			LCD_voidWriteNumber(i);
//			LCD_voidWriteString("   ");
//			_delay_ms(10);
//
//		}
//
//
//	}
//
//
//	return 0;
//}
