/*
 * WDT.c
 *
 *  Created on: Aug 5, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "bitMath.h"
#include "DIO_int.h"
#include "ATMEGA32_REGESTERS.h"

#include "WDT_int.h"
#include "WTD_Priv.h"


void WDG_On(void)
{
	//ENABLE WATCHDOG
	SET_BIT(WDTCR,3);

#if WDG_TIME_OUT == WDG_TIME_OUT_163_MS
	CLR_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);

#elif WDG_TIME_OUT == WDG_TIME_OUT_325_MS
	SET_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);

#elif WDG_TIME_OUT == WDG_TIME_OUT_65_MS
	CLR_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);
#elif WDG_TIME_OUT == WDG_TIME_OUT_1_S
	CLR_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
#elif WDG_TIME_OUT == WDG_TIME_OUT_21_S
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
#elif WDG_TIME_OUT == WDG_TIME_OUT_13_S
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	CLR_BIT(WDTCR,2);
#elif WDG_TIME_OUT == WDG_TIME_OUT_26_S
	CLR_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
#elif WDG_TIME_OUT == WDG_TIME_OUT_52_S
	SET_BIT(WDTCR,0);
	CLR_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);

#endif

}

void WDG_Off(void)
{
	WDTCR = 0xFF;

	WDTCR = 0x00;


}

void WDG_Refresh(void)
{
	asm("WDR");
}
