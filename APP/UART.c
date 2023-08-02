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

u8 string[10] = "hhhh lol";
u8 index = 0;
u8 data;
void ISR_TX(void)
{
	//LCD_voidWriteData("done");
	if(string[index] != '\0')
	{
		//USART_INTTransmit(string[index]);
		LCD_voidWriteData(string[index]);
		USART_INTTransmit(string);
		index++;
	}

}
void ISR_RX(void)
{
	//LCD_voidWriteString("hi");
	u8 local = 0;

	local = UDR;

	USART_Transmit(local);

	LCD_voidWriteData(local);


}


int main(void)
{
	GIE_voidEnable();
	USART_Init();
	LCD_voidInit();

	USART_INTReceive();


	//USART_TXSetCallBack(ISR_TX);
	USART_RXSetCallBack(ISR_RX);
	//USART_INTTransmit(string);




	while(1)
	{

		//data = USART_Receive();
		//USART_Transmit(data);
		//LCD_voidWriteData(data);

//		data = USART_Receive();
//		USART_Transmit(data);
//		LCD_voidWriteData(data);

	}






	return 0;
}
