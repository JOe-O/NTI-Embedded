
#include "typedef.h"
#include "bitMath.h"
#include "DIO_int.h"
#include "ATMEGA32_REGESTERS.h"

#include "ICU_int.h"

void (*ext_pf_icu)(void) = '\0';

void ICU_voidInit()
{
	ICR1_REG = 0;
	//enable icu interrupt
	TIMSK_REG.Bits.BIT_5 = 1;

	//normal mode
	TCCR1A_REG.Bits.BIT_0 = 0;
	TCCR1A_REG.Bits.BIT_1 = 0;
	TCCR1B_REG.Bits.BIT_3 = 0;
	TCCR1B_REG.Bits.BIT_4 = 0;


	//prescaler of 8
	TCCR1B_REG.Bits.BIT_0 = 0;
	TCCR1B_REG.Bits.BIT_1 = 1;
	TCCR1B_REG.Bits.BIT_2 = 0;

}


void ICU_voidSenseMode(u8 Copy_Mode)
{
	switch(Copy_Mode)
	{
	case RISING:
		//rising edge capture
		TCCR1B_REG.Bits.BIT_6 = 1;
		break;
	case FALLING:
		//falling edge capture
		TCCR1B_REG.Bits.BIT_6 = 0;
	}


}

void ICU_vidSetCallBack(void (*pf)(void))
{
	ext_pf_icu = pf;
}

void __vector_6(void)
{
	ext_pf_icu();

}


