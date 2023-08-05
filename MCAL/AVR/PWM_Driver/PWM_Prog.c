/*
 * PWM_Prog.c
 *
 *  Created on: Aug 5, 2023
 *      Author: JOe
 */


#include "typedef.h"
#include "bitMath.h"
#include "DIO_int.h"
#include "ATMEGA32_REGESTERS.h"

#include "PWM_int.h"





void PWM_vidPwmInit(u8 Copy_TimerNo)
{
	switch(Copy_TimerNo)
	{
	case TIMER_0:
		TCCR0_REG.Bits.BIT_3 = 1;
		TCCR0_REG.Bits.BIT_6 = 1;
		break;
	case TIMER_1:
		//compare output mode, fast pwm clear OC1A/OC1B on compare match
		TCCR1A_REG.Bits.BIT_7 = 1;
		TCCR1A_REG.Bits.BIT_6 = 0;
		TCCR1A_REG.Bits.BIT_4 = 0;
		TCCR1A_REG.Bits.BIT_5 = 0;
		//setting the mode as fast pwm with a TOP of ICR1
		TCCR1A_REG.Bits.BIT_0 = 0;
		TCCR1A_REG.Bits.BIT_1 = 1;
		TCCR1B_REG.Bits.BIT_3 = 1;
		TCCR1B_REG.Bits.BIT_4 = 1;
		//setting the ICR1 register with a calculated value
		ICR1_REG = PWM_ICR1_VALUE;
		break;


	}




}


void PWM_vidSetPwmDutyCycle(u8 Copy_TimerNo,u32 Copy_DC)
{
	switch(Copy_TimerNo){
	case TIMER_0:

		OCR0_REG.Whole_Register = (u8)(((f32)Copy_DC * ((f32)256))/100);
		break;
	case TIMER_1:

		OCR1A_REG = (u16)(((f32)Copy_DC * ((f32)PWM_ICR1_VALUE))/100);
		break;

	}
}

void PWM_StartTimer(u8 Copy_TimerNo)
{
	switch(Copy_TimerNo){
	case TIMER_0:
		TCCR0_REG.Whole_Register &= PWM_CS_CLEAR_MASK;
		TCCR0_REG.Whole_Register |= PWM_CS0_MODE;
		break;
	case TIMER_1:
		TCCR1B_REG.Whole_Register &= PWM_CS_CLEAR_MASK;
		TCCR1B_REG.Whole_Register |= PWM_CS1_MODE;
		break;
	}
}
void PWM_StopTimer(u8 Copy_TimerNo)
{
	switch(Copy_TimerNo){
	case TIMER_0:

		TCCR0_REG.Whole_Register &= 0xf8;
		break;
	case TIMER_1:

		TCCR1B_REG.Whole_Register &= 0xf8;
		break;

	}

}
