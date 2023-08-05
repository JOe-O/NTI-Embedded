/*
 * PWM_int.h
 *
 *  Created on: Aug 5, 2023
 *      Author: JOe
 */

#ifndef MCAL_AVR_PWM_DRIVER_PWM_INT_H_
#define MCAL_AVR_PWM_DRIVER_PWM_INT_H_


#define TIMER_0   0
#define TIMER_1   1
#define TIMER_2   2

//CLOCK SOURCES
#define PWM_CS0_STOPPED            0x00
#define PWM_CS0_INT_0              0x01
#define PWM_CS0_INT_8              0x02
#define PWM_CS0_INT_64             0x03
#define PWM_CS0_INT_256            0x04
#define PWM_CS0_INT_1024           0x05
#define PWM_CS0_EXT_FALLING_EDGE   0x06
#define PWM_CS0_EXT_RISING_EDGE    0x07

#define PWM_CS1_STOPPED            0x00
#define PWM_CS1_INT_0              0x01
#define PWM_CS1_INT_8              0x02
#define PWM_CS1_INT_64             0x03
#define PWM_CS1_INT_256            0x04
#define PWM_CS1_INT_1024           0x05
#define PWM_CS1_EXT_FALLING_EDGE   0x06
#define PWM_CS1_EXT_RISING_EDGE    0x07

#define PWM_CS_CLEAR_MASK          ~(0x07)


#define PWM_CS0_MODE               PWM_CS0_INT_256
#define PWM_CS1_MODE               PWM_CS1_INT_8
#define PWM_ICR1_VALUE             (u16)20000 			//ticks correspoding to the 8 prescale (every prescale needs a calculation)



void PWM_vidPwmInit(u8 Copy_TimerNo);

void PWM_vidSetPwmDutyCycle(u8 Copy_TimerNo,u32 Copy_DC);

void PWM_StartTimer(u8 Copy_TimerNo);

void PWM_StopTimer(u8 Copy_TimerNo);




#endif /* MCAL_AVR_PWM_DRIVER_PWM_INT_H_ */
