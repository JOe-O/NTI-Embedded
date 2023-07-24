/*
 * LCD.c
 *
 *  Created on: Jul 23, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "DIO_int.h"
#include "ATMEGA32_REGESTERS.h"
#include "LCD_int.h"
#include "LCD_Config.h"
#include "Keypad_int.h"

#include <util/delay.h>

int main(void)
{
	LCD_voidInit();
	u8 KeyVal;
	Keypad_voidInit();
	//LCD_voidSendCommand(0x80);

	while(1)
	{

		KeyVal= Keypad_u8GetKey();
		if(KeyVal != NOT_PRESSED)
		{
			LCD_voidWriteData(KeyVal);
		}

	}










	return 0;
}
