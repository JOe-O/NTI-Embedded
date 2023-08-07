/*
 * I2C_prog.c
 *
 *  Created on: Aug 7, 2023
 *      Author: JOe
 */




#include "typedef.h"
#include "bitMath.h"
#include "DIO_int.h"
#include "ATMEGA32_REGESTERS.h"

#include "I2C_int.h"

void I2C_vidInit(u8 Copy_u8SLA)
{
	//TWI initialization
	//Bit rate: 100 kHz for 16MHz cpu clock
	TWBR_REG.Whole_Register = 2;
	//setting prescaler to 1
	TWSR_REG.Whole_Register &= 0xFC;
	//enable TWI
	TWCR_REG.Bits.BIT_2 = 1;

	//Two wire bus slave address: 0x01
	//general call recognition: off
	TWAR_REG.Whole_Register = Copy_u8SLA<<1;
	TWAR_REG.Bits.BIT_0 = 0;

	//generate acknowledge pulse: On
	//TWI interrupt: off
	TWCR_REG.Bits.BIT_6 = 1;
	TWCR_REG.Bits.BIT_0 = 0;





}
void I2C_vidSendStart(void)
{
	//sending start condition by first clearing the TWINT flag
	//and setting the start condition and making sure that the acknowledge bit is set
	TWCR_REG.Whole_Register = (1<<7) | (1<<5) | (1<<2);

	while(TWCR_REG.Bits.BIT_7 == 0);


}
void I2C_vidSendStop(void)
{
	//sending stop condition by first clearing the TWINT flag
	//and setting the start condition and making sure that the acknowledge bit is set
	TWCR_REG.Whole_Register = (1<<7) | (1<<4) | (1<<2);


}
void I2C_vidSendSLA(u8 Copy_u8SLA,u8 R_W)
{
	//put data on TWI Register
	TWDR_REG.Whole_Register = Copy_u8SLA<<1;
	TWDR_REG.Bits.BIT_0 =R_W;
	//send data
	TWCR_REG.Whole_Register = (1<<7) | (1<<2);

	//wait for TWINT flag set in TWCR Register
	while(TWCR_REG.Bits.BIT_7 == 0);


}
void I2C_vidSendData(u8 Copy_u8Data)
{
	//put data on TWI Register
	TWDR_REG.Whole_Register = Copy_u8Data;

	//send data
	TWCR_REG.Whole_Register = (1<<7) | (1<<2);

	//wait for TWINT flag set in TWCR Register
	while(TWCR_REG.Bits.BIT_7 == 0);


}
u8 I2C_vidRecieveData(u8 Copy_u8AckMode)
{
	TWCR_REG.Whole_Register = (1<<7) | (1 << 2);
	TWCR_REG.Bits.BIT_6 = (~Copy_u8AckMode);
	while(TWCR_REG.Bits.BIT_7 == 0);
	return TWDR_REG.Whole_Register;


}
u8 I2C_u8CheckStatus(u8 Copy_u8ExpectedStatus)
{

	u8 localStatus = FALSE;

	if(Copy_u8ExpectedStatus == (TWSR_REG.Whole_Register & 0xF8))
	{
		localStatus = TRUE;
	}
	else
	{
		localStatus = FALSE;
	}
	return localStatus;

}
