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
	SET_BIT(TCCR0_REG,3);
	CLR_BIT(TCCR0_REG,6);
#elif GPT_MODE == PHASE_CORRECT
	//PHASE CORRECT MODE
	CLR_BIT(TCCR0_REG,3);
	SET_BIT(TCCR0_REG,6);
#elif GPT_MODE == FAST_PWM
	//PHASE CORRECT MODE
	SET_BIT(TCCR0_REG,3);
	SET_BIT(TCCR0_REG,6);

#endif

#if CLK_MODE == RISING_EDGE
//	//CLK on Rising edge
//	SET_BIT(TCCR0_REG,0);
//	SET_BIT(TCCR0_REG,1);
//	SET_BIT(TCCR0_REG,2);
#endif

CLR_BIT(TCCR0_REG,5);
SET_BIT(TCCR0_REG,4);

OCR0_REG = 200;
}

void GPT_vidStartTimer(){

	//8 prescaler
	CLR_BIT(TCCR0_REG,0);
	SET_BIT(TCCR0_REG,1);
	CLR_BIT(TCCR0_REG,2);


	//enable overflow interrupt
	//SET_BIT(TIMSK_REG,0);

	//enable compare match interrupt
	SET_BIT(TIMSK_REG,1);


}

u16 delay_s(u16 Copy_Time)
{
	u8 OCR_Value = OCR0_REG;
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

