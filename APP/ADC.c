/*
 * ADC.c
 *
 *  Created on: Jul 29, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "DIO_int.h"
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
int main(void)
{
	DIO_voidSetPinDirection(PORTA,DIO_u8PIN_1,DIO_u8INPUT);
	ADC_voidInit();
	ADC_voidEnable();
	LCD_voidInit();
	u16 value = 0;
	while(1)
	{
		value = ADC_u16ReadADCInMV();
		LCD_voidWriteNumber(value);
		_delay_ms(150);
		LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);




	}





	return 0;
}
