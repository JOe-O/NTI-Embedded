/*
 * UART.c
 *
 *  Created on: Jul 31, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "DIO_int.h"
#include "bitMath.h"
#include "ATMEGA32_REGESTERS.h"
#include "EXTI0_private.h"
#include "EXTI0_interface.h"
#include "EXTI0_config.h"

#include "GIE_interface.h"
#include "GIE_private.h"

#include "ADC.h"
#include "ADC_config.h"
#include "ADC_priv.h"

#include "LCD_int.h"
#include "LCD_Config.h"

#include "uart_config.h"
#include "uart_int.h"
#include "uart_priv.h"


#include "util/delay.h"


int main(void)
{

	USART_Init();
	LCD_voidInit();

	u8 data;

	while(1)
	{
		data = USART_Receive();
		USART_Transmit(data);
		LCD_voidWriteData(data);

	}






	return 0;
}
