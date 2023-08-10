/*
 * EEPROM_int.h
 *
 *  Created on: Aug 10, 2023
 *      Author: JOe
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_


#define CHIP_ENABLE   1


void EEPROM_voidInit();

void EEPROM_voidWriteByte(u8 Copy_u8Data,u16 Copy_u16Location);

u8 EEPROM_voidReadByte(u16 Copy_u16Location);







#endif /* EEPROM_INT_H_ */
