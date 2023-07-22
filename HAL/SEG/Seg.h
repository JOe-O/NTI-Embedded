/*
 * Seg.h
 *
 *  Created on: Jul 22, 2023
 *      Author: ART
 */

#ifndef HAL_7SEGMENT_SEG_H_
#define HAL_7SEGMENT_SEG_H_

#define COMMON_CATHODE			0
#define COMMON_ANODE			1

#define SEG_0					((u8)0b00111111)
#define SEG_1					((u8)0b00000110)
#define SEG_2					((u8)0b01011011)
#define SEG_3					((u8)0b01001111)
#define SEG_4					((u8)0b01100110)
#define SEG_5					((u8)0b01101101)
#define SEG_6					((u8)0b01111101)
#define SEG_7					((u8)0b00000111)
#define SEG_8					((u8)0b01111111)
#define SEG_9					((u8)0b01100111)

void SEG_voidDisplay(u8 Copy_PortX,u8 Copy_Mode,u8 Copy_Digit);



#endif /* HAL_7SEGMENT_SEG_H_ */
