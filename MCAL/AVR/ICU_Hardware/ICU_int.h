/*
 * ICU_int.h
 *
 *  Created on: Aug 6, 2023
 *      Author: ART
 */

#ifndef MCAL_AVR_ICU_HARDWARE_ICU_INT_H_
#define MCAL_AVR_ICU_HARDWARE_ICU_INT_H_


#define RISING 			1
#define FALLING			0



void ICU_voidInit();

void ICU_voidSenseMode(u8 Copy_Mode);

void ICU_vidSetCallBack(void (*pf)(void));


void __vector_6(void) __attribute__((signal , used));








#endif /* MCAL_AVR_ICU_HARDWARE_ICU_INT_H_ */
