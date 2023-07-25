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
	u8 character[]=
	{
			0x0E,
			0x0A,
			0x0E,
			0x14,
			0x1F,
			0x05,
			0x04,
			0x04
	};
	u8 character2[]=
	{
			0x0E,
			0x0A,
			0x0E,
			0x05,
			0x1F,
			0x14,
			0x04,
			0x04
	};
	//LCD_voidSendCommand(0x80);
u8 i = 0;
	while(1)
	{

		//		LCD_voidWriteData('G');
		//		_delay_ms(200);
		//		LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);

		//LCD_voidGoTo(3,3);


		//		LCD_voidWriteData('T');
		//		LCD_voidWriteString((u8 *)"Hello");
		//		_delay_ms(200);
		//		LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);

		//LCD_voidWriteNumber(505500);

//		LCD_voidSendCommand(0x40);//first cgram address
//
//		for(int i = 0 ; i < 8 ; i++)
//		{
//			LCD_voidWriteData(character[i]);
//		}
//
//		LCD_voidSendCommand(0x80); // first address in ddram for viewing the character
//
//		LCD_voidWriteData(0); //corresponds to 0x00 address to display the character
//		_delay_ms(200);
//		LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
//
//		//LCD_voidSendCommand(LCD_u8RETURN_HOME);
//
//		LCD_voidGoTo(0,i);
//
//		LCD_voidSendCommand(0x40);//first cgram address
//
//		for(int i = 0 ; i < 8 ; i++)
//		{
//			LCD_voidWriteData(character2[i]);
//		}
//
//		LCD_voidSendCommand(0x80); // first address in ddram for viewing the character
//
//		LCD_voidWriteData(0); //corresponds to 0x00 address to display the character
//		_delay_ms(200);
//		LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
//
//		LCD_voidSendCommand(LCD_u8RETURN_HOME);
//
//		i++;




	}










	return 0;
}
