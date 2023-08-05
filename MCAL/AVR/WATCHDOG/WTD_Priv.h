/*
 * WTD_Priv.h
 *
 *  Created on: Aug 5, 2023
 *      Author: ART
 */

#ifndef MCAL_AVR_WATCHDOG_WTD_PRIV_H_
#define MCAL_AVR_WATCHDOG_WTD_PRIV_H_


#define WDTCR  	  (*((volatile u8* )0x41))


#define WDG_TIME_OUT_163_MS  1
#define WDG_TIME_OUT_325_MS  5
#define WDG_TIME_OUT_65_MS   7
#define WDG_TIME_OUT_13_S    9
#define WDG_TIME_OUT_26_S    11
#define WDG_TIME_OUT_52_S    14
#define WDG_TIME_OUT_1_S     20
#define WDG_TIME_OUT_21_S    25


#endif /* MCAL_AVR_WATCHDOG_WTD_PRIV_H_ */
