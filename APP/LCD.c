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

#include <util/delay.h>

int main(void)
{
	LCD_voidInit();

	//LCD_voidSendCommand(0x80);
	LCD_voidGoTo(0,3);
	while(1)
	{

//		LCD_voidWriteData('G');
//		_delay_ms(200);
//		LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);


		LCD_voidWriteData('T');
		LCD_voidWriteString("Hello");
		_delay_ms(200);
		LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);

	}










	return 0;
}
