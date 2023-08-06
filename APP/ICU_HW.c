/*
 * COUNTER.c
 *
 *  Created on: Aug 4, 2023
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

#include "Timers_int.h"

#include "ICU_int.h"

volatile u16 t1 = 0;
volatile u16 t2 = 0;
volatile u16 t3 = 0;

u8 flag = 0;

void ISR(void)
{

	if(flag == 0)
	{
		t1 = ICR1_REG;
		ICU_voidSenseMode(FALLING);
		flag = 1;
	}
	else if(flag == 1)
	{
		t2 = ICR1_REG;
		ICU_voidSenseMode(RISING);
		flag = 2;
	}
	else if(flag == 2)
	{
		t3 = ICR1_REG;
		ICU_voidSenseMode(FALLING);


		flag = 3;
	}


}


int main(void)
{
	DIO_voidSetPinDirection(PORTB,DIO_u8PIN_3,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(PORTA,DIO_u8PIN_0,DIO_u8OUTPUT);

	ICU_vidSetCallBack(ISR);

	GIE_voidEnable();
	ICU_voidSenseMode(RISING);
	ICU_voidInit();
	LCD_voidInit();



	GPT_vidInit();
	GPT_vidSetCompareValue(63);
	GPT_vidStartTimer();



	u16 Ton = t2-t1;
	u16 Toff = t3-t2;
	u16 DC = ((Ton*100)/(Ton+Toff));

	LCD_voidGoTo(0,0);
	LCD_voidWriteNumber(Ton);//((t2-t1)*100)/(t3-t1)
	LCD_voidGoTo(1,0);
	LCD_voidWriteNumber(1000000/(Ton+Toff));

	while(1)
	{




	}









	return 0;
}
