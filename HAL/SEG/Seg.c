/*
 * Seg.c
 *
 *  Created on: Jul 22, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "DIO_int.h"
#include "Seg.h"
#include "bitMath.h"
#include "ATMEGA32_REGESTERS.h"



void SEG_voidDisplay(u8 Copy_PortX,u8 Copy_Mode,u8 Copy_Digit)
{
	if( ((Copy_PortX > 0) && (Copy_PortX <5))  && (Copy_Mode < 2))
	{
		if(Copy_Mode == COMMON_CATHODE)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				DIO_voidSetPortValue(PORTA, Copy_Digit);
				break;
			case PORTB:
				DIO_voidSetPortValue(PORTB, Copy_Digit);
				break;
			case PORTC:
				DIO_voidSetPortValue(PORTC, Copy_Digit);
				break;
			case PORTD:
				DIO_voidSetPortValue(PORTD, Copy_Digit);
				break;
			}
		}else if(Copy_Mode == COMMON_ANODE)
		{
			switch(Copy_PortX)
			{
			case PORTA:
				DIO_voidSetPortValue(PORTA, ~Copy_Digit);
				break;
			case PORTB:
				DIO_voidSetPortValue(PORTB, ~Copy_Digit);
				break;
			case PORTC:
				DIO_voidSetPortValue(PORTC, ~Copy_Digit);
				break;
			case PORTD:
				DIO_voidSetPortValue(PORTD, ~Copy_Digit);
				break;
			}
		}
	}
}








