/*
 * Timers_int.h
 *
 *  Created on: Aug 4, 2023
 *      Author: ART
 */

#ifndef MCAL_AVR_TIMERS_TIMERS_INT_H_
#define MCAL_AVR_TIMERS_TIMERS_INT_H_

#define NORMAL_MODE					1
#define CTC							2
#define PHASE_CORRECT				3
#define FAST_PWM					4


#define GPT_NO_CLK					0
#define GPT_DIV_BY_1				1
#define GPT_DIV_BY_8				2
#define GPT_DIV_BY_64				3
#define GPT_DIV_BY_256				4
#define GPT_DIV_BY_1024				5
#define GPT_RISING_EDGE				6
#define GPT_FALLING_EDGE			7

#define OC0_DISCONNECTED			0
#define OC0_TGL						1
#define OC0_CLEAR					2
#define OC0_SET						3




#define GPT_MODE		CTC
#define CLK_MODE		GPT_DIV_BY_8
#define OC0_MODE		OC0_TGL




void GPT_vidInit();
void GPT_vidStartTimer();
void GPT_vidOverflowInterruptEn();
void GPT_vidCompareMatchInterruptEn();
void GPT_vidSetCompareValue(u8 Copy_Value);

void GPT_vidSetCallBack(void (*pf)(void));
void GPT_vidSetCallBackCTC(void (*pf)(void));

u16 delay_s(u16 Copy_Time);

void __vector_11(void) __attribute__((signal , used));
void __vector_10(void) __attribute__((signal , used));



#endif /* MCAL_AVR_TIMERS_TIMERS_INT_H_ */
