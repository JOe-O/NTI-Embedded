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
#if ADC_PRESCALLER == DIVID_BY_128
	//setting prescalar to 128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

#elif ADC_PRESCALLER == DIVID_BY_64
	//setting prescalar to 64
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif ADC_PRESCALLER == DIVID_BY_32
	//setting prescalar to 32
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#endif

#if VOLTAGE_REFERENCE == AVCC
	//reference voltage as AVCC with external capacitor
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

#elif VOLTAGE_REFERENCE == AREF
	CLR_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

#elif VOLTAGE_REFERENCE == RESERVED
	CLR_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#elif VOLTAGE_REFERENCE == INTERNAL
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#endif

#if ADJUSTMENT == RIGHT_ADJUSTMENT
	//right adjusted
	CLR_BIT(ADMUX,5);

#elif ADJUSTMENT == LEFT_ADJUSTMENT
	//right adjusted
	SET_BIT(ADMUX,5);
#endif

#if ADC_CHANNEL_NUMBER == DIO_U8_PIN_1
	//setting adc channel as ADC1
	SET_BIT(ADMUX,0);		//1
	CLR_BIT(ADMUX,1);		//2
	CLR_BIT(ADMUX,2);		//4
	CLR_BIT(ADMUX,3);		//8
	CLR_BIT(ADMUX,4);		//16

#elif ADC_CHANNEL_NUMBER == DIO_U8_PIN_0
	//setting adc channel as ADC0
	CLR_BIT(ADMUX,0);       //1
	CLR_BIT(ADMUX,1);       //2
	CLR_BIT(ADMUX,2);       //4
	CLR_BIT(ADMUX,3);       //8
	CLR_BIT(ADMUX,4);       //16

#elif ADC_CHANNEL_NUMBER == DIO_U8_PIN_2
	//setting adc channel as ADC2
	CLR_BIT(ADMUX,0);       //1
	SET_BIT(ADMUX,1);       //2
	CLR_BIT(ADMUX,2);       //4
	CLR_BIT(ADMUX,3);       //8
	CLR_BIT(ADMUX,4);       //16
#elif ADC_CHANNEL_NUMBER == DIO_U8_PIN_3
	//setting adc channel as ADC2
	SET_BIT(ADMUX,0);       //1
	SET_BIT(ADMUX,1);       //2
	CLR_BIT(ADMUX,2);       //4
	CLR_BIT(ADMUX,3);       //8
	CLR_BIT(ADMUX,4);       //16
#elif ADC_CHANNEL_NUMBER == DIO_U8_PIN_4
	//setting adc channel as ADC2
	CLR_BIT(ADMUX,0);       //1
	CLR_BIT(ADMUX,1);       //2
	SET_BIT(ADMUX,2);       //4
	CLR_BIT(ADMUX,3);       //8
	CLR_BIT(ADMUX,4);       //16
#elif ADC_CHANNEL_NUMBER == DIO_U8_PIN_5
	//setting adc channel as ADC2
	SET_BIT(ADMUX,0);       //1
	CLR_BIT(ADMUX,1);       //2
	SET_BIT(ADMUX,2);       //4
	CLR_BIT(ADMUX,3);       //8
	CLR_BIT(ADMUX,4);       //16
#elif ADC_CHANNEL_NUMBER == DIO_U8_PIN_6
	//setting adc channel as ADC2
	CLR_BIT(ADMUX,0);       //1
	SET_BIT(ADMUX,1);       //2
	SET_BIT(ADMUX,2);       //4
	CLR_BIT(ADMUX,3);       //8
	CLR_BIT(ADMUX,4);       //16
#elif ADC_CHANNEL_NUMBER == DIO_U8_PIN_7
	//setting adc channel as ADC2
	SET_BIT(ADMUX,0);       //1
	SET_BIT(ADMUX,1);       //2
	SET_BIT(ADMUX,2);       //4
	CLR_BIT(ADMUX,3);       //8
	CLR_BIT(ADMUX,4);       //16
#endif

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
u16 (*ext_pf2)(void) = '\0';

u16 ADC_u8ReadADC(u16 (*pf)(void))//pf addresscpy
{
	ext_pf2 = pf;
	return ext_pf2();
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


