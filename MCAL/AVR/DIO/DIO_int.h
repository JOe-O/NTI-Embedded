/*
 * DIO_int.h
 *
 *  Created on: Jul 21, 2023
 *      Author: ART
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define PORTA				1
#define PORTB				2
#define PORTC				3
#define PORTD				4


#define DIO_u8PIN_0			0
#define DIO_u8PIN_1			1
#define DIO_u8PIN_2			2
#define DIO_u8PIN_3			3
#define DIO_u8PIN_4			4
#define DIO_u8PIN_5			5
#define DIO_u8PIN_6			6
#define DIO_u8PIN_7			7



#define DIO_u8INPUT			0
#define DIO_u8OUTPUT		1


#define DIO_u8HIGH			1
#define DIO_u8LOW			0


/*getting the value of pin X*/
u8 DIO_u8GetPinValue(u8 Copy_PortX,u8 Copy_PinX);

/*setting a value for pin X at port X*/
void DIO_voidSetPinValue(u8 Copy_PortX, u8 Copy_PinX, u8 Copy_Value);

//setting whether the pin is output or input
void DIO_voidSetPinDirection(u8 Copy_PortX,u8 Copy_PinX,u8 Copy_Direction);

/*setting whether the port is output or input*/
void DIO_voidSetPortDirection(u8 Copy_PortX, u8 Copy_Direction);

/*setting the value of the whole port either HIGH or LOW*/
void DIO_voidSetPortValue(u8 Copy_PortX, u8 Copy_value);

/*Toggling between HIGH or LOW on a specific pin*/
void DIO_voidTogglePinValue(u8 Copy_PortX, u8 Copy_PinX);

#endif /* DIO_INT_H_ */
