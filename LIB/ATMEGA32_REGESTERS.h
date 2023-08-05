/*
 * ATMEGA32_REGESTERS.h
 *
 *  Created on: Jul 21, 2023
 *      Author: ART
 */

#ifndef ATMEGA32_REGESTERS_H_
#define ATMEGA32_REGESTERS_H_

typedef union{
	struct{
		u8 BIT_0: 1;
		u8 BIT_1: 1;
		u8 BIT_2: 1;
		u8 BIT_3: 1;
		u8 BIT_4: 1;
		u8 BIT_5: 1;
		u8 BIT_6: 1;
		u8 BIT_7: 1;

	}Bits;
	u8 Whole_Register;
}tuniReg;






/*DIO A*/
#define PORTA_REG	*((volatile u8*)(0x3B))
#define DDRA_REG	*((volatile u8*)(0x3A))
#define PINA_REG        *((volatile u8*)(0x39))

/*DIO B*/
#define PORTB_REG       *((volatile u8*)(0x38))
#define DDRB_REG	*((volatile u8*)(0x37))
#define PINB_REG        *((volatile u8*)(0x36))

/*DIO C*/
#define PORTC_REG       *((volatile u8*)(0x35))
#define DDRC_REG        *((volatile u8*)(0x34))
#define PINC_REG        *((volatile u8*)(0x33))


/*DIO D*/
#define PORTD_REG       *((volatile u8*)(0x32))
#define DDRD_REG        *((volatile u8*)(0x31))
#define PIND_REG        *((volatile u8*)(0x30))

//TIMER REGISTERS
#define TCCR0_REG    (*((volatile tuniReg*)(0x53)))
#define TCNT0_REG    (*((volatile tuniReg*)(0x52)))
#define OCR0_REG     (*((volatile tuniReg*)(0x5C)))
#define TIMSK_REG    (*((volatile tuniReg*)(0x59)))



//PWM REGISTERS
#define TCCR1A_REG       (*((volatile tuniReg*)(0x4F)))
#define TCCR1B_REG       (*((volatile tuniReg*)(0x4E)))
#define TCNT1_REG        (*((volatile u16*)(0x4C)))
#define OCR1A_REG        (*((volatile u16*)(0x4A)))
#define OCR1B_REG        (*((volatile u16*)(0x48)))
#define ICR1_REG         (*((volatile u16*)(0x46)))

#endif /* ATMEGA32_REGESTERS_H_ */
