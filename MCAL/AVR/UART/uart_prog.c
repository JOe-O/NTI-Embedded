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

