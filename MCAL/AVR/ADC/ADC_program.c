/*
 * ADC_program.c
 *
 *  Created on: Jul 29, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "bitMath.h"
#include "ATMEGA32_REGESTERS.h"
#include "ADC.h"
#include "ADC_config.h"
#include "ADC_priv.h"


void ADC_voidInit (void)
{
	//disable adc
	CLR_BIT(ADCSRA,7);

	//disable auto trigger
	CLR_BIT(ADCSRA,5);

	//disable interrupt flag
	SET_BIT(ADCSRA,4);

	//clearning adc interrupt enable
	CLR_BIT(ADCSRA,3);

	//setting prescalar to 128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

	//reference voltage as AVCC with external capacitor
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

	//right adjusted
	CLR_BIT(ADMUX,5);

	//setting adc channel as ADC1
	SET_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);



}



void ADC_voidEnable()
{
	//enable adc
	SET_BIT(ADCSRA,7);
}


void ADC_voidInterrputEnable()
{
	//enable interrupt flag
	CLR_BIT(ADCSRA,4);
}



void ADC_voidDisable()
{
	//disable adc
	CLR_BIT(ADCSRA,7);
}


u8 ADC_u8ReadADC(pf addresscpy)
{

}


void ADC_voidStartConversion()
{
	SET_BIT(ADCSRA,6);
}


void ADC_voidAutoTrigger()
{
	//enable auto trigger
	SET_BIT(ADCSRA,5);
}


u16 ADC_u16ReadADCInMV()
{

u16 value = 0;
ADC_voidStartConversion();

while(!GET_BIT(ADCSRA,4));
value = ADC_u16_ADCL_REG;
SET_BIT(ADCSRA,4);
return value;

}


