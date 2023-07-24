/*
 * LCD_Driver.c
 *
 *  Created on: Jul 23, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "bitMath.h"
#include "ATMEGA32_REGESTERS.h"
#include "DIO_int.h"
#include <util/delay.h>
#include "LCD_int.h"
#include "LCD_Config.h"
#include <string.h>

#include <stdio.h>

void LCD_voidWriteData(u8 Copy_Data)
{
	if(LCD_MODE == MODE_8)
	{
		//resetting RS/RW pins
	DIO_voidSetPinValue(CONTROL_PORT,RS_PIN,DIO_u8HIGH); 		// RS = 0 for instruction and 1 for data
	DIO_voidSetPinValue(CONTROL_PORT,RW_PIN,DIO_u8LOW); 		// RW = 0 for writing data and 1 for reading data
	DIO_voidSetPortValue(DATA_PORT,Copy_Data);		  			// sending the command

	DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8HIGH);		// switching on the Enable pin
	_delay_ms(2);
	DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8LOW);			// switching off the Enable pin
	_delay_ms(2);

	}else if(LCD_MODE == MODE_4)
	{
		DIO_voidSetPinValue(CONTROL_PORT,RS_PIN,DIO_u8HIGH); 		// RS = 0 for instruction and 1 for data
		DIO_voidSetPinValue(CONTROL_PORT,RW_PIN,DIO_u8LOW); 		// RW = 0 for writing data and 1 for reading data
		//DIO_voidSetPortValue(DATA_PORT,Copy_Data);		  			// sending the command

		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_4,GET_BIT(Copy_Data,4));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_5,GET_BIT(Copy_Data,5));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_6,GET_BIT(Copy_Data,6));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_7,GET_BIT(Copy_Data,7));

		DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8HIGH);		// switching on the Enable pin
		_delay_ms(2);
		DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8LOW);			// switching off the Enable pin
		_delay_ms(2);

		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_4,GET_BIT(Copy_Data,0));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_5,GET_BIT(Copy_Data,1));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_6,GET_BIT(Copy_Data,2));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_7,GET_BIT(Copy_Data,3));

		DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8HIGH);		// switching on the Enable pin
		_delay_ms(2);
		DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8LOW);			// switching off the Enable pin
		_delay_ms(2);
	}

}

void LCD_voidSendCommand(u8 Copy_Command)
{
	if(LCD_MODE == MODE_8)
	{
	//resetting RS/RW pins
	DIO_voidSetPinValue(CONTROL_PORT,RS_PIN,DIO_u8LOW); 		// RS = 0 for instruction and 1 for data
	DIO_voidSetPinValue(CONTROL_PORT,RW_PIN,DIO_u8LOW); 		// RW = 0 for writing data and 1 for reading data
	DIO_voidSetPortValue(DATA_PORT,Copy_Command);		  		// sending the command

	DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8HIGH);		// switching on the Enable pin
	_delay_ms(2);
	DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8LOW);			// switching off the Enable pin
	_delay_ms(2);
	}else if(LCD_MODE == MODE_4)
	{
		//resetting RS/RW pins
		DIO_voidSetPinValue(CONTROL_PORT,RS_PIN,DIO_u8LOW); 		// RS = 0 for instruction and 1 for data
		DIO_voidSetPinValue(CONTROL_PORT,RW_PIN,DIO_u8LOW); 		// RW = 0 for writing data and 1 for reading data
		//DIO_voidSetPortValue(DATA_PORT,Copy_Command);		  		// sending the command

		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_4,GET_BIT(Copy_Command,4));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_5,GET_BIT(Copy_Command,5));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_6,GET_BIT(Copy_Command,6));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_7,GET_BIT(Copy_Command,7));


		DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8HIGH);		// switching on the Enable pin
		_delay_ms(2);
		DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8LOW);			// switching off the Enable pin
		_delay_ms(2);

		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_4,GET_BIT(Copy_Command,0));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_5,GET_BIT(Copy_Command,1));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_6,GET_BIT(Copy_Command,2));
		DIO_voidSetPinValue(DATA_PORT,DIO_u8PIN_7,GET_BIT(Copy_Command,3));

		DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8HIGH);		// switching on the Enable pin
		_delay_ms(2);
		DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8LOW);			// switching off the Enable pin
		_delay_ms(2);
	}

}


void LCD_voidInit()
{
	if(LCD_MODE == MODE_8)
	{
		DIO_voidSetPinDirection(CONTROL_PORT,RS_PIN,DIO_u8OUTPUT); 			//initializing RS_PIN as output
		DIO_voidSetPinDirection(CONTROL_PORT,RW_PIN,DIO_u8OUTPUT); 			//initializing RW_PIN as output
		DIO_voidSetPinDirection(CONTROL_PORT,EN_PIN,DIO_u8OUTPUT); 			//initializing EN_PIN as output
		DIO_voidSetPortDirection(DATA_PORT,DIO_u8OUTPUT);		   			//initializing the whole selected data port as output

		_delay_ms(30);
		LCD_voidSendCommand(0b00111000);  	 	  //Function Set Register initialization
		_delay_ms(39);
		LCD_voidSendCommand(0b00001111); 		  //Display ON/OFF Control
		_delay_ms(39);
		LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY); //Display Clear
		_delay_ms(1.53);
		LCD_voidSendCommand(0b00000110);		  //Entry Mode Set
		_delay_ms(5);

	}else if (LCD_MODE == MODE_4)
	{

		DIO_voidSetPinDirection(CONTROL_PORT,RS_PIN,DIO_u8OUTPUT); 			//initializing RS_PIN as output
		DIO_voidSetPinDirection(CONTROL_PORT,RW_PIN,DIO_u8OUTPUT); 			//initializing RW_PIN as output
		DIO_voidSetPinDirection(CONTROL_PORT,EN_PIN,DIO_u8OUTPUT); 			//initializing EN_PIN as output
		DIO_voidSetPortDirection(DATA_PORT,DIO_u8OUTPUT);		   			//initializing the whole selected data port as output

//		_delay_ms(30);
//		LCD_voidSendCommand(0b00101000);  	 	  //Function Set Register initialization
//		LCD_voidSendCommand(0b00101000);
//		LCD_voidSendCommand(0b11101000);
//		_delay_ms(39);
//		LCD_voidSendCommand(0b00001111); 		  //Display ON/OFF Control
//		LCD_voidSendCommand(0b11111111);
//		_delay_ms(39);
//		LCD_voidSendCommand(0b00000000); //Display Clear
//		LCD_voidSendCommand(0b00011111);
//		_delay_ms(1.53);
//		LCD_voidSendCommand(0b00000110);		  //Entry Mode Set
//		LCD_voidSendCommand(0b01101111);
//		_delay_ms(5);
		//DIO_voidSetPinValue(CONTROL_PORT,EN_PIN,DIO_u8LOW);

		_delay_ms(100);

		LCD_voidSendCommand(0x02);
		_delay_ms(1);
		LCD_voidSendCommand(0x28);
		_delay_ms(1);
		LCD_voidSendCommand(0x0C);
		_delay_ms(1);
		LCD_voidSendCommand(0x01);
		_delay_ms(1);
		LCD_voidSendCommand(0x06);
		_delay_ms(1);

	}


}

void LCD_voidWriteString(u8 * Copy_Text)
{
	for(int i = 0 ; Copy_Text[i] != '\0' ; i++)
	{
		LCD_voidWriteData(Copy_Text[i]);

	}

}

void LCD_voidGoTo(u8 Copy_Row, u8 Copy_Column)
{
	if((Copy_Column >= 0) && (Copy_Column <= 15))
	{
		switch(Copy_Row)
		{
		case 0:
			LCD_voidSendCommand((0x80)+Copy_Column);
			break;
		case 1:
			LCD_voidSendCommand((0xC0)+Copy_Column);
			break;
		case 2:
			LCD_voidSendCommand((0x90)+Copy_Column);
			break;
		case 3:
			LCD_voidSendCommand((0xD0)+Copy_Column);
			break;
		default:
			//wrong row entry
			break;

		}
	}

}


void LCD_voidWriteNumber(u32 Copy_Number)
{
    u8 output[50];

    sprintf(output, "%lu", Copy_Number); // Use %lu for unsigned long (u32)

    LCD_voidWriteString(output);

    memset(output, '\0', sizeof(output));
}

