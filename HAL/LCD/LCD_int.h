/*
 * LCD_int.h
 *
 *  Created on: Jul 23, 2023
 *      Author: ART
 */

#ifndef LCD_LCD_INT_H_
#define LCD_LCD_INT_H_


#define LCD_u8CLEAR_DISPLAY				0x01
#define LCD_u8RETURN_HOME				0X02




void LCD_voidWriteString(u8 * Copy_Text);

void LCD_voidWriteData(u8 Copy_Data);

void LCD_voidSendCommand(u8 Copy_Command);

void LCD_voidInit();

void LCD_voidGoTo(u8 Copy_Row, u8 Copy_Column);

void LCD_voidWriteNumber(u32 Copy_Number);


#endif /* LCD_LCD_INT_H_ */
