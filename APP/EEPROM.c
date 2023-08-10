/*
 * I2C.c
 *
 *  Created on: Aug 7, 2023
 *      Author: JOe
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


#include "LCD_int.h"
#include "LCD_Config.h"

#include "Timers_int.h"

#include "I2C_int.h"
#include "EEPROM_int.h"
#include "util/delay.h"

int main(void){

	DIO_voidSetPinDirection(PORTC,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(PORTC,DIO_u8PIN_1,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(PORTC,DIO_u8PIN_2,DIO_u8OUTPUT);

	LCD_voidInit();
	//I2C_vidInit(1);
	EEPROM_voidInit();
	u8 data = 0;

	EEPROM_voidWriteByte(200,512);

	_delay_ms(10);


	data = EEPROM_voidReadByte(512);
	LCD_voidWriteString("The Value = ");
	LCD_voidGoTo(0,12);
	LCD_voidWriteNumber(data);


	while(1)
	{




	}

	return 0;
}
