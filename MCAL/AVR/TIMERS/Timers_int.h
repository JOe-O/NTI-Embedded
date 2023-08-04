/*
 * Timers_int.h
 *
 *  Created on: Aug 4, 2023
 *      Author: ART
 */

#ifndef MCAL_AVR_TIMERS_TIMERS_INT_H_
#define MCAL_AVR_TIMERS_TIMERS_INT_H_

#define NORMAL_MODE				1
#define CTC						2
#define PHASE_CORRECT			3
#define FAST_PWM				4

#define RISING_EDGE				1
#define FALLING_EDGE			2


#define GPT_MODE		CTC
#define CLK_MODE		RISING_EDGE






void GPT_vidInit();
void GPT_vidStartTimer();

void GPT_vidSetCallBack(void (*pf)(void));
void GPT_vidSetCallBackCTC(void (*pf)(void));

u16 delay_s(u16 Copy_Time);

void __vector_11(void) __attribute__((signal , used));
void __vector_10(void) __attribute__((signal , used));





#endif /* MCAL_AVR_TIMERS_TIMERS_INT_H_ */
