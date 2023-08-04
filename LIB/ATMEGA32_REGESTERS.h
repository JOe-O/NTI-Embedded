/*
 * ATMEGA32_REGESTERS.h
 *
 *  Created on: Jul 21, 2023
 *      Author: ART
 */

#ifndef ATMEGA32_REGESTERS_H_
#define ATMEGA32_REGESTERS_H_

/*DIO A*/
#define PORTA_REG		*((volatile u8*)(0x3B))
#define DDRA_REG		*((volatile u8*)(0x3A))
#define PINA_REG        *((volatile u8*)(0x39))

/*DIO B*/
#define PORTB_REG       *((volatile u8*)(0x38))
#define DDRB_REG		*((volatile u8*)(0x37))
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
#define TCCR0_REG    (*((volatile u8*)(0x53)))
#define TCNT0_REG    (*((volatile u8*)(0x52)))
#define OCR0_REG     (*((volatile u8*)(0x5C)))
#define TIMSK_REG    (*((volatile u8*)(0x59)))

#endif /* ATMEGA32_REGESTERS_H_ */
