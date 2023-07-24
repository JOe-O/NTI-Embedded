/*
 * Keypad_int.h
 *
 *  Created on: Jul 24, 2023
 *      Author: JOe
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_


#define KEYPAD_PORT				PORTB

#define ROW_1					DIO_u8PIN_0
#define ROW_2					DIO_u8PIN_1
#define ROW_3					DIO_u8PIN_2
#define ROW_4					DIO_u8PIN_3

#define COL_1					DIO_u8PIN_4
#define COL_2					DIO_u8PIN_5
#define COL_3					DIO_u8PIN_6
#define COL_4					DIO_u8PIN_7


#define NOT_PRESSED				0

//getting the pressed keys on the keypad
u8 Keypad_u8GetKey();

//Initialization of the input/output pins for the keypad
void Keypad_voidInit();


#endif /* KEYPAD_INT_H_ */
