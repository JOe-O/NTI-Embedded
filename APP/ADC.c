/*
 * ADC.c
 *
 *  Created on: Jul 29, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "DIO_int.h"
#include "bitMath.h"
#include "ATMEGA32_REGESTERS.h"
#include "EXTI0_private.h"
#include "EXTI0_interface.h"
#include "EXTI0_config.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "ADC.h"
#include "ADC_config.h"
#include "ADC_priv.h"
#include "LCD_int.h"
#include "LCD_Config.h"

#include "util/delay.h"


u16 ADC_u16Read(void)
{
	u16 value = 0;
	ADC_voidStartConversion();

	while(!GET_BIT(ADCSRA,4));
	value = ADC_u16_ADCL_REG;
	SET_BIT(ADCSRA,4);
	return value;
}


int main(void)
{
	DIO_voidSetPinDirection(PORTA,DIO_u8PIN_1,DIO_u8INPUT);
	DIO_voidSetPinDirection(PORTA,DIO_u8PIN_2,DIO_u8OUTPUT);
	ADC_voidInit();
	ADC_voidEnable();
	LCD_voidInit();
	u16 value = 0;
	u16 temp = 0;
	LCD_voidWriteString("ADC Value: ");
	LCD_voidGoTo(1,0);
	LCD_voidWriteString("Temp Value: ");

	while(1)
	{
		//value = ADC_u16ReadADCInMV();
		value = ADC_u8ReadADC(ADC_u16Read);
		value = ((u16)((((u32)value)*5000)/1024));
		temp = value/10;


		LCD_voidGoTo(0,11);
		LCD_voidWriteNumber(value);
		LCD_voidWriteString("   ");
		LCD_voidGoTo(1,12);
		LCD_voidWriteNumber(temp);
		LCD_voidWriteString("   ");
		_delay_ms(100);

		if(value > 2500)//2.5 volts
		{
			DIO_voidSetPinValue(PORTA,DIO_u8PIN_2,DIO_u8LOW);
		}else
		{
			DIO_voidSetPinValue(PORTA,DIO_u8PIN_2,DIO_u8HIGH);
		}

	}





	return 0;
}
