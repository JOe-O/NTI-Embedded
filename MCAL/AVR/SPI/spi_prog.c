#include "typedef.h"
#include "bitMath.h"
#include "DIO_int.h"
#include "spi_init.h"
#include "SPI_priv.h"
#include "spi_config.h"


void (*CallBack) (void) = '\0';



//void SPI_voidSetCallBack( void (*PtrToFunc) (void) )
//{
//	CallBack = PtrToFunc;
//}

u8 * SPI_buffer;
u8 SPI_Buffer_size;
u8 SPI_Index = 0;
u8 busy_flag = 0;

void __vector_12(void) __attribute__((signal , used));
void __vector_12(void)
{
	//CallBack();
	SPI_buffer[SPI_Index] = SPDR;
	SPI_Index++;
	if(SPI_Index == SPI_Buffer_size)
	{
		SPI_Buffer_size = 0;
		SPI_Index = 0;
		busy_flag = 0;
		CallBack();

	}
	else
	{
		SPDR = SPI_buffer[SPI_Index];
	}

}

u8 SPI_voidSendDataISR(u8 data,u8 buffer_size, void (*pf)(void))
{
	if(busy_flag == 1){
		return 1; //error
	}else{
		busy_flag = 1;
		SPI_buffer = data;
		SPI_Buffer_size = buffer_size;
		CallBack = pf;
		SPDR = SPI_buffer;

	}
	//SPDR = *data;
	return 0;

}

//u8 SPI_u8ReadDataISR(void)
//{
//
//}

u8 SPI_u8ReadDataISR(u8 * data,u8 buffer_size, void (*pf)(void))
{
	if(busy_flag == 1){
		return 1; //error
	}else{
		busy_flag = 1;
		SPI_buffer = data;
		SPI_Buffer_size = buffer_size;
		CallBack = pf;
		//SPDR = SPI_buffer[SPI_Index];
	}
	//SPDR = *data;
	return 0;
}


u8 SPI_u8Transfer(u8 Copy_Data)
{
	//clearing the SPDR register
	SPDR = 0;
	//setting the register to our transfer data
	SPDR = Copy_Data;
	while(GET_BIT(SPSR,7) == 0);
}

u8 SPI_u8Recieve(void){

	u8 Local_u8Result; //making a variable to return in our received data
	while(GET_BIT(SPSR,7) == 0); //while the transfer is in progress nothing will happen until it finishes
	Local_u8Result = SPDR; //storing the data in our SPDR register in our local variable
	CLR_BIT(SPSR,7); //setting our flag to 0 again

	return Local_u8Result; //returning our data

}


void SPI_voidMasterInit(void)
{
	//setting MOSI of Master microcontroller as output
	DIO_voidSetPinDirection(PORTB,DIO_u8PIN_5,DIO_u8OUTPUT);
	//setting SCK as output
	DIO_voidSetPinDirection(PORTB,DIO_u8PIN_7,DIO_u8OUTPUT);

	//Enable SPI
	SET_BIT(SPCR,6);

	//Set Data Order to MSF(Most Significant Figure)
	CLR_BIT(SPCR,5);

	//Enable Master
	SET_BIT(SPCR,4);

	//Select Clock Polarity "Rising is the Leading Edge"
	CLR_BIT(SPCR,3);

	//Select The Clock Phase "Setup/Write on the Leading Edge"
	SET_BIT(SPCR,2);

	// Select the Clock Frequency as Fosc/128
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	CLR_BIT(SPSR,0);

}

void SPI_voidSlaveInit(void)
{
	//setting MISO on slave microcontroller as output
	DIO_voidSetPinDirection(PORTB,DIO_u8PIN_6,DIO_u8OUTPUT);

	//Enable SPI
	SET_BIT(SPCR,6);

	//Set Data Order to MSF(Most Significant Figure)
	CLR_BIT(SPCR,5);

	//Enable Slave
	CLR_BIT(SPCR,4);

	//Select Clock Polarity "Rising is the Leading Edge"
	CLR_BIT(SPCR,3);

	//Select The Clock Phase "Setup on the Leading Edge"
	SET_BIT(SPCR,2);

	// Select the Clock Frequency as Fosc/128
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
}

