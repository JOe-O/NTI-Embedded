/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "typedef.h"
#include "bitMath.h"
#include "ATMEGA32_REGESTERS.h"
/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "uart_int.h"
#include "uart_config.h"
#include "uart_priv.h"


/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize USART     */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/


void USART_Init( )
{
	//frame format to 8 data
		SET_BIT(UCSRC,1);
		SET_BIT(UCSRC,7);
		CLR_BIT(UCSRC,6);
		SET_BIT(UCSRC,2);
		CLR_BIT(UCSRB,2);

		//1 bit stop
		CLR_BIT(UCSRC,3);

		//disabling parity
		CLR_BIT(UCSRC,4);
		CLR_BIT(UCSRC,5);

//setting the baud rate to 9600 for 8Mhz micro controller
		UBRRH = 0;
		UBRRL = 51;

		//enabling rx and tx
		SET_BIT(UCSRB,3);
		SET_BIT(UCSRB,4);


}



/****************************************************************/
/* Description    : This function used to Send Data				*/ 
/*																*/
/*					Inputs : u8 data				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
void USART_Transmit( u8 data )
{
	while(GET_BIT(UCSRA,5) == 0);
		UDR = data;

}

void (*ext_pf_TX)(void) = '\0';

void __vector_15(void)
{
	ext_pf_TX();

}

void USART_TXSetCallBack(void (*pf)(void))
{
	ext_pf_TX = pf;


}

u8 index_TX = 0;

void USART_INTTransmit( u8 * data )
{
	//enabling tx complete interrupt enable
	SET_BIT(UCSRB,6);

	//while(GET_BIT(UCSRA,5) == 0);
	UDR = data[index_TX];
	index_TX++;

}



/****************************************************************/
/* Description    : This function used to Receive Data			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u8			 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
u8 USART_Receive( )
{
	u8 Local_u8Result;
	while(GET_BIT(UCSRA,7) == 0);
	Local_u8Result = UDR;
	CLR_BIT(UCSRA,7);
	return Local_u8Result;
}
void USART_INTReceive()
{
	//enabling rx complete interrupt enable
	SET_BIT(UCSRB,7);


}

void (*ext_pf_RX)(void) = '\0';

void __vector_13(void)
{
	ext_pf_RX();

}


void USART_RXSetCallBack(void (*pf)(void))
{
	ext_pf_RX = pf;
}
