#ifndef		EXTI0_INTERFACE_H
#define		EXTI0_INTERFACE_H

#define		EXTI0_FALLING			0
#define		EXTI0_RISING			1
#define		EXTI0_IOC				2
#define		EXTI0_LOW				3


void EXTI0_voidInit(void);
void EXTI0_voidEnable(void);
void EXTI0_voidDisable(void);

void EXTI_SetCallBack(void (*pf)(void));


#endif
