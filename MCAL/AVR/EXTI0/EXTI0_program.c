#include "typedef.h"
#include "bitMath.h"
#include "ATMEGA32_REGESTERS.h"

#include "EXTI0_interface.h"
#include "EXTI0_private.h"
#include "EXTI0_config.h"

#ifndef NULL
#define NULL   ((void *) 0)
#endif

void EXTI0_voidInit(void)
{
	//setting mode on interrupt 1 as rising edge
	#if SENSE_MODE == EXTI0_RISING
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	#elif SENSE_MODE == EXTI0_FALLING
		SET_BIT(MCUCR,3);
		CLR_BIT(MCUCR,2);
	#elif SENSE_MODE == EXTI0_LOW
		CLR_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	#elif SENSE_MODE == EXTI0_IOC
		SET_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	#endif

	//disabling interupt 1
	CLR_BIT(GICR,7);

	//clearning interupt 1 flag
	SET_BIT(GIFR,7);


}
void EXTI0_voidEnable(void)
{
	//enabling interupt 1
	SET_BIT(GICR,7);
}
void EXTI0_voidDisable(void)
{
	//disabling interupt 1
	CLR_BIT(GICR,7);

	//clearning interupt 1 flag
	SET_BIT(GIFR,7);
}

void (*ext_pf)(void) = NULL;

void __vector_2(void)
{
	ext_pf();

}


void EXTI_SetCallBack(void (*pf)(void))
{
	ext_pf = pf;

}
