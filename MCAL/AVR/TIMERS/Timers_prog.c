/*
 * Timers_prog.c
 *
 *  Created on: Aug 4, 2023
 *      Author: ART
 */
#include "typedef.h"
#include "bitMath.h"
#include "DIO_int.h"
#include "ATMEGA32_REGESTERS.h"

#include "Timers_int.h"

void (*ext_pf_timer)(void) = '\0';
void (*ext_pf_ctc)(void) = '\0';

void GPT_vidInit()
{

#if GPT_MODE == NORMAL_MODE
//	//NORMAL MODE
	CLR_BIT(TCCR0_REG,3);
	CLR_BIT(TCCR0_REG,6);
#elif GPT_MODE == CTC
	//CTC MODE
	//SET_BIT(TCCR0_REG,3);
	TCCR0_REG.Bits.BIT_3 = 1;
	//CLR_BIT(TCCR0_REG,6);
	TCCR0_REG.Bits.BIT_6 = 0;
#elif GPT_MODE == PHASE_CORRECT
	//PHASE CORRECT MODE
	CLR_BIT(TCCR0_REG,3);
	SET_BIT(TCCR0_REG,6);
#elif GPT_MODE == FAST_PWM
	//PHASE CORRECT MODE
	SET_BIT(TCCR0_REG,3);
	SET_BIT(TCCR0_REG,6);

#endif



	//CLR_BIT(TCCR0_REG,5);
	TCCR0_REG.Bits.BIT_5 = 0;
	//SET_BIT(TCCR0_REG,4);
	TCCR0_REG.Bits.BIT_4 = 1;


}

void GPT_vidSetCompareValue(u8 Copy_Value)
{
	OCR0_REG.Whole_Register = Copy_Value;
}

void GPT_vidStartTimer(){

	#if CLK_MODE == GPT_DIV_BY_8

		//CLR_BIT(TCCR0_REG,0);
		TCCR0_REG.Bits.BIT_0 = 0;
		//SET_BIT(TCCR0_REG,1);
		TCCR0_REG.Bits.BIT_1 = 1;
		//CLR_BIT(TCCR0_REG,2);
		TCCR0_REG.Bits.BIT_2 = 0;
	#elif CLK_MODE == GPT_NO_CLK

		CLR_BIT(TCCR0_REG,0);
		CLR_BIT(TCCR0_REG,1);
		CLR_BIT(TCCR0_REG,2);
	#elif CLK_MODE == GPT_DIV_BY_1

		SET_BIT(TCCR0_REG,0);
		CLR_BIT(TCCR0_REG,1);
		CLR_BIT(TCCR0_REG,2);
	#elif CLK_MODE == GPT_DIV_BY_64

		SET_BIT(TCCR0_REG,0);
		SET_BIT(TCCR0_REG,1);
		CLR_BIT(TCCR0_REG,2);
	#elif CLK_MODE == GPT_DIV_BY_256

		CLR_BIT(TCCR0_REG,0);
		CLR_BIT(TCCR0_REG,1);
		SET_BIT(TCCR0_REG,2);
	#elif CLK_MODE == GPT_DIV_BY_1024

		SET_BIT(TCCR0_REG,0);
		CLR_BIT(TCCR0_REG,1);
		SET_BIT(TCCR0_REG,2);
	#elif CLK_MODE == GPT_RISING_EDGE

		SET_BIT(TCCR0_REG,0);
		SET_BIT(TCCR0_REG,1);
		SET_BIT(TCCR0_REG,2);
	#elif CLK_MODE == GPT_FALLING_EDGE

		CLR_BIT(TCCR0_REG,0);
		SET_BIT(TCCR0_REG,1);
		SET_BIT(TCCR0_REG,2);
	#endif

#if OC0_MODE == OC0_DISCONNECTED
		CLR_BIT(TCCR0_REG,4);
		CLR_BIT(TCCR0_REG,5);

#elif OC0_MODE == OC0_TGL
		//SET_BIT(TCCR0_REG,4);
		TCCR0_REG.Bits.BIT_4 = 1;
		//CLR_BIT(TCCR0_REG,5);
		TCCR0_REG.Bits.BIT_5 = 0;

#elif OC0_MODE == OC0_CLEAR
		CLR_BIT(TCCR0_REG,4);
		SET_BIT(TCCR0_REG,5);

#elif OC0_MODE == OC0_SET
		SET_BIT(TCCR0_REG,4);
		SET_BIT(TCCR0_REG,5);

#endif
}

void GPT_vidOverflowInterruptEn()
{
	//enable overflow interrupt
	//SET_BIT(TIMSK_REG,0);
	TIMSK_REG.Bits.BIT_0 = 1;

}
void GPT_vidCompareMatchInterruptEn()
{
	//enable compare match interrupt
	//SET_BIT(TIMSK_REG,1);
	TIMSK_REG.Bits.BIT_1 = 1;
}


u16 delay_s(u16 Copy_Time)
{
	u8 OCR_Value = OCR0_REG.Whole_Register;
	u16 OVFS = (Copy_Time*1000000UL)/OCR_Value; //Number of overflows needed

	return OVFS;

}



void GPT_vidSetCallBack(void (*pf)(void))
{
	ext_pf_timer = pf;
}

void __vector_11(void)
{
	ext_pf_timer();

}

void __vector_10(void)
{
	ext_pf_ctc();

}
void GPT_vidSetCallBackCTC(void (*pf)(void))
{
	ext_pf_ctc = pf;
}

