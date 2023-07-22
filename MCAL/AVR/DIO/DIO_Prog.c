/*
 * DIO_Prog.c
 *
 *  Created on: Jul 21, 2023
 *      Author: ART
 */
#include "typedef.h"
#include "bitMath.h"
#include "ATMEGA32_REGESTERS.h"

#include "DIO_int.h"


u8 DIO_u8GetPinValue(u8 Copy_PortX,u8 Copy_PinX)
{
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)))
	{
		switch(Copy_PortX)
		{
		case PORTA:
			return GET_BIT(PINA_REG,Copy_PinX);
			break;
		case PORTB:
			return GET_BIT(PINB_REG,Copy_PinX);
			break;
		case PORTC:
			return GET_BIT(PINC_REG,Copy_PinX);
			break;
		case PORTD:
			return GET_BIT(PIND_REG,Copy_PinX);
			break;
		}
	}
	return 0xFF;
}


void DIO_voidSetPinValue(u8 Copy_PortX, u8 Copy_PinX, u8 Copy_Value)
{
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)) \
			&& ((Copy_Value == DIO_u8HIGH)|| (Copy_Value == DIO_u8LOW)))
	{
		if(Copy_Value == DIO_u8HIGH)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				SET_BIT(PORTA_REG,Copy_PinX);
				break;
			case PORTB:
				SET_BIT(PORTB_REG,Copy_PinX);
				break;
			case PORTC:
				SET_BIT(PORTC_REG,Copy_PinX);
				break;
			case PORTD:
				SET_BIT(PORTD_REG,Copy_PinX);
				break;
			}
		}else if(Copy_Value == DIO_u8LOW)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				CLR_BIT(PORTA_REG,Copy_PinX);
				break;
			case PORTB:
				CLR_BIT(PORTB_REG,Copy_PinX);
				break;
			case PORTC:
				CLR_BIT(PORTC_REG,Copy_PinX);
				break;
			case PORTD:
				CLR_BIT(PORTD_REG,Copy_PinX);
				break;
			}
		}
	}
}


void DIO_voidSetPinDirection(u8 Copy_PortX,u8 Copy_PinX,u8 Copy_Direction)
{
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)) && ((Copy_PinX >= DIO_u8PIN_0) && (Copy_PinX <= DIO_u8PIN_7)) \
			&& ((Copy_Direction == DIO_u8INPUT)|| (Copy_Direction == DIO_u8OUTPUT)))
	{
		if(Copy_Direction == DIO_u8INPUT)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				CLR_BIT(DDRA_REG,Copy_PinX);
				break;
			case PORTB:
				CLR_BIT(DDRB_REG,Copy_PinX);
				break;
			case PORTC:
				CLR_BIT(DDRC_REG,Copy_PinX);
				break;
			case PORTD:
				CLR_BIT(DDRD_REG,Copy_PinX);
				break;
			}
		}else if(Copy_Direction == DIO_u8OUTPUT)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				SET_BIT(DDRA_REG,Copy_PinX);
				break;
			case PORTB:
				SET_BIT(DDRB_REG,Copy_PinX);
				break;
			case PORTC:
				SET_BIT(DDRC_REG,Copy_PinX);
				break;
			case PORTD:
				SET_BIT(DDRD_REG,Copy_PinX);
				break;
			}
		}else
		{
			/*do nothing*/
		}

	}
}

void DIO_voidSetPortDirection(u8 Copy_PortX, u8 Copy_Direction)
{
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)))
	{
		switch(Copy_PortX)
		{
		case PORTA:
			DDRA_REG = Copy_Direction;
			break;
		case PORTB:
			DDRB_REG = Copy_Direction;
			break;
		case PORTC:
			DDRC_REG = Copy_Direction;
			break;
		case PORTD:
			DDRD_REG = Copy_Direction;
			break;
		}

	}else
	{
		/*do nothing*/
	}
}



void DIO_voidSetPortValue(u8 Copy_PortX, u8 Copy_value)
{
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)))
	{
		switch(Copy_PortX)
		{
		case PORTA:
			PORTA_REG = Copy_value;
			break;
		case PORTB:
			PORTB_REG = Copy_value;
			break;
		case PORTC:
			PORTC_REG = Copy_value;
			break;
		case PORTD:
			PORTD_REG = Copy_value;
			break;
		}

	}else
	{
		/*do nothing*/
	}
}


void DIO_voidTogglePinValue(u8 Copy_PortX, u8 Copy_PinX)
{
	if(((Copy_PortX >= PORTA) && (Copy_PortX <= PORTD)))
	{
		if(Copy_PinX == DIO_u8PIN_0)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				TGL_BIT(PORTA_REG,Copy_PinX);
				break;
			case PORTB:
				TGL_BIT(PORTB_REG,Copy_PinX);
				break;
			case PORTC:
				TGL_BIT(PORTC_REG,Copy_PinX);
				break;
			case PORTD:
				TGL_BIT(PORTD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_PinX == DIO_u8PIN_1)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				TGL_BIT(PORTA_REG,Copy_PinX);
				break;
			case PORTB:
				TGL_BIT(PORTB_REG,Copy_PinX);
				break;
			case PORTC:
				TGL_BIT(PORTC_REG,Copy_PinX);
				break;
			case PORTD:
				TGL_BIT(PORTD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_PinX == DIO_u8PIN_2)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				TGL_BIT(PORTA_REG,Copy_PinX);
				break;
			case PORTB:
				TGL_BIT(PORTB_REG,Copy_PinX);
				break;
			case PORTC:
				TGL_BIT(PORTC_REG,Copy_PinX);
				break;
			case PORTD:
				TGL_BIT(PORTD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_PinX == DIO_u8PIN_3)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				TGL_BIT(PORTA_REG,Copy_PinX);
				break;
			case PORTB:
				TGL_BIT(PORTB_REG,Copy_PinX);
				break;
			case PORTC:
				TGL_BIT(PORTC_REG,Copy_PinX);
				break;
			case PORTD:
				TGL_BIT(PORTD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_PinX == DIO_u8PIN_4)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				TGL_BIT(PORTA_REG,Copy_PinX);
				break;
			case PORTB:
				TGL_BIT(PORTB_REG,Copy_PinX);
				break;
			case PORTC:
				TGL_BIT(PORTC_REG,Copy_PinX);
				break;
			case PORTD:
				TGL_BIT(PORTD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_PinX == DIO_u8PIN_5)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				TGL_BIT(PORTA_REG,Copy_PinX);
				break;
			case PORTB:
				TGL_BIT(PORTB_REG,Copy_PinX);
				break;
			case PORTC:
				TGL_BIT(PORTC_REG,Copy_PinX);
				break;
			case PORTD:
				TGL_BIT(PORTD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_PinX == DIO_u8PIN_6)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				TGL_BIT(PORTA_REG,Copy_PinX);
				break;
			case PORTB:
				TGL_BIT(PORTB_REG,Copy_PinX);
				break;
			case PORTC:
				TGL_BIT(PORTC_REG,Copy_PinX);
				break;
			case PORTD:
				TGL_BIT(PORTD_REG,Copy_PinX);
				break;
			}
		}
		else if(Copy_PinX == DIO_u8PIN_7)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				TGL_BIT(PORTA_REG,Copy_PinX);
				break;
			case PORTB:
				TGL_BIT(PORTB_REG,Copy_PinX);
				break;
			case PORTC:
				TGL_BIT(PORTC_REG,Copy_PinX);
				break;
			case PORTD:
				TGL_BIT(PORTD_REG,Copy_PinX);
				break;
			}
		}
	}
}

