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
//u16 ADC_u16Read(void)
//{
//	u16 value = 0;
//	ADC_voidStartConversion();
//
//	while(!GET_BIT(ADCSRA,4));
//	value = ADC_u16_ADCL_REG;
//	SET_BIT(ADCSRA,4);
//	return value;
//}
//
//
//
//
//int main(void){
//	DIO_voidSetPinDirection(PORTD,DIO_u8PIN_5,DIO_u8OUTPUT);
//	DIO_voidSetPinDirection(PORTA,DIO_u8PIN_1,DIO_u8INPUT);
//
//	ADC_voidInit();
//	ADC_voidEnable();
//
//	LCD_voidInit();
//	u16 value = 0;
//	//LCD_voidWriteString("ADC Value: ");
//	PWM_vidPwmInit(TIMER_1);
//	PWM_StartTimer(TIMER_1);
//	PWM_vidSetPwmDutyCycle(TIMER_1,0);
//	LCD_voidWriteString("DC: ");
//
//	while(1)
//	{
//		value = ADC_u8ReadADC(ADC_u16Read);
//		value = ((u16)((((u32)value)*5)/1023)) + 5;
//
//		LCD_voidGoTo(0,4);
//		LCD_voidWriteNumber(value);
//		LCD_voidWriteString("   ");
//		PWM_vidSetPwmDutyCycle(TIMER_1,value);
//
//
//
//	}
//
//
//	return 0;
//}
