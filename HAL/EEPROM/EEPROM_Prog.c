/*
 * EEPROM_Prog.c
 *
 *  Created on: Aug 10, 2023
 *      Author: JOe
 */

#include "typedef.h"
#include "bitMath.h"
#include "DIO_int.h"
#include "ATMEGA32_REGESTERS.h"

#include "I2C_int.h"
#include "LCD_Config.h"
#include "LCD_int.h"

#include "EEPROM_int.h"


void EEPROM_voidInit() //same initialization as I2C
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
	//		TWAR_REG.Whole_Register = Copy_u8SLA<<1;
	//		TWAR_REG.Bits.BIT_0 = 0;

	//generate acknowledge pulse: On
	//TWI interrupt: off
	TWCR_REG.Bits.BIT_6 = 1;
	TWCR_REG.Bits.BIT_0 = 0;
}

void EEPROM_voidWriteByte(u8 Copy_u8Data,u16 Copy_u16Location)
{
	u8 SLA = 0xA0 | (CHIP_ENABLE << 3);
	SLA |= ((Copy_u16Location >> 7) & 0x06);
	I2C_vidSendStart();
	if(I2C_u8CheckStatus(TW_START) == TRUE)
	{
		I2C_vidSendSLA(SLA);
		if(I2C_u8CheckStatus(TW_MT_SLA_ACK) == TRUE)
		{
			I2C_vidSendData((u8)Copy_u16Location);
			if(I2C_u8CheckStatus(TW_MT_DATA_ACK) == TRUE)
			{
				I2C_vidSendData(Copy_u8Data);
				if(I2C_u8CheckStatus(TW_MT_DATA_ACK) == TRUE)
				{
					I2C_vidSendStop();
				}
			}
		}
	}
}

u8 EEPROM_voidReadByte(u16 Copy_u16Location)
{
	u8 SLA = 0xA0 | (CHIP_ENABLE << 3);
	SLA |= (Copy_u16Location >> 7) & 0x06;
	u8 local_data;
	I2C_vidSendStart();
	if(I2C_u8CheckStatus(TW_START) == TRUE)
	{
		I2C_vidSendSLA(SLA);
		if(I2C_u8CheckStatus(TW_MT_SLA_ACK) == TRUE)
		{
			I2C_vidSendData((u8)Copy_u16Location);
			if(I2C_u8CheckStatus(TW_MT_DATA_ACK) == TRUE)
			{
				I2C_vidSendStart();
				if(I2C_u8CheckStatus(TW_REP_START) == TRUE)
				{
					I2C_vidSendSLA(SLA | 0x01);
					if(I2C_u8CheckStatus(TW_MR_SLA_ACK) == TRUE)
					{
						local_data = I2C_vidRecieveData(NACK);
						if(I2C_u8CheckStatus(TW_MR_DATA_NOT_ACK) == TRUE)
						{
							I2C_vidSendStop();
						}
					}
				}
			}
		}
	}
	return local_data;
}
