/*
 * I2C_int.h
 *
 *  Created on: Aug 7, 2023
 *      Author: JOe
 */

#ifndef MCAL_AVR_I2C_I2C_INT_H_
#define MCAL_AVR_I2C_I2C_INT_H_




#define TW_MASTER_ARB_LOST   		0x38
#define TW_START         			0x08
#define TW_REP_START     			0x10
#define TW_MT_SLA_ACK    			0x18
#define TW_MT_DATA_ACK   			0x28
#define TW_MR_DATA_NOT_ACK  		0x58
#define TW_MR_SLA_NOT_ACK   		0x48
#define TW_MT_SLA_NOT_ACK   		0x20
#define TW_MT_DATA_NOT_ACK  		0x30
#define TW_MR_DATA_ACK   			0x50
#define TW_MR_SLA_ACK    			0x40


#define READ	 	1
#define WRITE		0

#define TRUE        1
#define FALSE       0


#define ACK         0
#define NACK        1


void I2C_vidInit(void);
void I2C_vidSendStart(void);
void I2C_vidSendStop(void);
void I2C_vidSendSLA(u8 Copy_u8SLA,u8 R_W);
void I2C_vidSendData(u8 Copy_u8Data);
u8 I2C_vidRecieveData(u8 Copy_u8AckMode);
u8 I2C_u8CheckStatus(u8 Copy_u8ExpectedStatus);






#endif /* MCAL_AVR_I2C_I2C_INT_H_ */
