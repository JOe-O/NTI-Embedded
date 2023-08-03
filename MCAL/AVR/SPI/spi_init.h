#ifndef SPI_INT_H_
#define SPI_INT_H_

#define DUMMY 0xFF

void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

u8 SPI_u8Transfer(u8 Copy_Data);

u8 SPI_u8Recieve(void);

void SPI_voidSetCallBack( void (*PtrToFunc) (void) );

u8 SPI_u8ReadDataISR(u8 * data,u8 buffer_size, void (*pf)(void));

u8 SPI_voidSendDataISR(u8 data,u8 buffer_size, void (*pf)(void));


#endif /* SPI_INT_H_ */
