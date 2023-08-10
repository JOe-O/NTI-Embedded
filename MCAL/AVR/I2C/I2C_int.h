/*
 * I2C_int.h
 *
 *  Created on: Aug 7, 2023
 *      Author: JOe
 */

#ifndef MCAL_AVR_I2C_I2C_INT_H_
#define MCAL_AVR_I2C_I2C_INT_H_



/* MASTER TRANSMITTER MODE*/
#define TW_START         			0x08
#define TW_REP_START     			0x10
#define TW_MT_SLA_ACK    			0x18
#define TW_MT_SLA_NOT_ACK   		0x20
#define TW_MT_DATA_ACK   			0x28
#define TW_MT_DATA_NOT_ACK  		0x30
#define TW_MASTER_ARB_LOST   		0x38

/* MASTER RECIEVER MODE (SHARED WITH SOME OF THE ONES IN TRANSMITTER MODE)*/
#define TW_MR_SLA_ACK    			0x40
#define TW_MR_SLA_NOT_ACK   		0x48
#define TW_MR_DATA_ACK   			0x50
#define TW_MR_DATA_NOT_ACK  		0x58

/*SLAVE RECIEVER MODE*/
#define TW_SR_SLA_ACK				0x60
#define TW_SLAVE_ARB_LOST			0x68
#define TW_SR_GENERAL_ACK			0x70
#define TW_SR_ARB_GENERAL			0x78
#define TW_SR_DATA_ACK				0x80
#define TW_SR_DATA_NOT_ACK			0x88


#define READ	 	1
#define WRITE		0

#define TRUE        1
#define FALSE       0


#define ACK         0
#define NACK        1


void I2C_vidInit(u8 Copy_u8SLA);
void I2C_vidSendStart(void);
void I2C_vidSendStop(void);
void I2C_vidSendSLA(u8 Copy_u8SLA);
void I2C_vidSendData(u8 Copy_u8Data);
u8 I2C_vidRecieveData(u8 Copy_u8AckMode);
u8 I2C_u8CheckStatus(u8 Copy_u8ExpectedStatus);






#endif /* MCAL_AVR_I2C_I2C_INT_H_ */
