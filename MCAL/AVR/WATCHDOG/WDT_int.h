/*
 * WDT_int.h
 *
 *  Created on: Aug 5, 2023
 *      Author: ART
 */

#ifndef MCAL_AVR_WATCHDOG_WDT_INT_H_
#define MCAL_AVR_WATCHDOG_WDT_INT_H_


#define WDG_TIME_OUT	WDG_TIME_OUT_21_S



void WDG_On(void);

void WDG_Off(void);

void WDG_Refresh(void);

#endif /* MCAL_AVR_WATCHDOG_WDT_INT_H_ */
