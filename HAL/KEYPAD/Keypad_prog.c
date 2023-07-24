/*
 * Keypad_prog.c
 *
 *  Created on: Jul 24, 2023
 *      Author: JOe
 */


#include "typedef.h"
#include "bitMath.h"
#include "ATMEGA32_REGESTERS.h"
#include "DIO_int.h"
#include <util/delay.h>
#include "LCD_int.h"
#include "LCD_Config.h"
#include "Keypad_int.h"


u8 Keypad_matrix[2][4] =
{
		{ROW_1,ROW_2,ROW_3,ROW_4},
		{COL_1,COL_2,COL_3,COL_4}
};

u8 Keypad_Layout[4][4] =
{
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'#','0','=','+'}
};


u8 Keypad_u8GetKey()
{
	u8 iRow,jCol;

	for(iRow = 0 ; iRow < 4 ; iRow++)
	{
		DIO_voidSetPinValue(KEYPAD_PORT,Keypad_matrix[0][iRow],DIO_u8LOW);

		for(jCol = 0 ; jCol < 4 ; jCol++)
		{
			if(DIO_u8GetPinValue(KEYPAD_PORT,Keypad_matrix[1][jCol]) == DIO_u8LOW)
			{
				while(DIO_u8GetPinValue(KEYPAD_PORT,Keypad_matrix[1][jCol]) == DIO_u8LOW); //to prevent debouncing we use a while loop guard to make sure it stays as is as long as the button is pressed

				return Keypad_Layout[iRow][jCol];
			}
		}
		DIO_voidSetPinValue(KEYPAD_PORT,Keypad_matrix[0][iRow],DIO_u8HIGH);
	}
	return NOT_PRESSED;
}


void Keypad_voidInit()
{
	//setting the rows as output
	DIO_voidSetPinDirection(KEYPAD_PORT,ROW_1,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,ROW_2,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,ROW_3,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,ROW_4,DIO_u8OUTPUT);

	//setting the columns as input
	DIO_voidSetPinDirection(KEYPAD_PORT,COL_1,DIO_u8INPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,COL_2,DIO_u8INPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,COL_3,DIO_u8INPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,COL_4,DIO_u8INPUT);

	//outputting 1 on the rows
	DIO_voidSetPinValue(KEYPAD_PORT,ROW_1,DIO_u8HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,ROW_2,DIO_u8HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,ROW_3,DIO_u8HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,ROW_4,DIO_u8HIGH);

	//setting the input pull up on column buttons
	DIO_voidSetPinValue(KEYPAD_PORT,COL_1,DIO_u8HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,COL_2,DIO_u8HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,COL_3,DIO_u8HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,COL_4,DIO_u8HIGH);
}

