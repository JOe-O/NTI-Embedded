/*
 * LightDimmer.c
 *
 *  Created on: Aug 5, 2023
 *      Author: JOe
 */

#include "typedef.h"
#include "DIO_int.h"
#include "bitMath.h"
#include "ATMEGA32_REGESTERS.h"



#include "ADC.h"
#include "ADC_config.h"
#include "ADC_priv.h"

#include "LCD_int.h"
#include "LCD_Config.h"

#include "PWM_int.h"

#include "util/delay.h"


int main(void){
	DIO_voidSetPinDirection(PORTD,DIO_u8PIN_5,DIO_u8OUTPUT);

	//ADC_voidInit();

	PWM_vidPwmInit(TIMER_1);

	PWM_vidSetPwmDutyCycle(TIMER_1,50);
	PWM_StartTimer(TIMER_1);



	while(1)
	{

	}


	return 0;
}
