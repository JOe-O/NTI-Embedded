/*
 * LCD.c
 *
 *  Created on: Jul 23, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "DIO_int.h"
#include "ATMEGA32_REGESTERS.h"
#include "LCD_int.h"
#include "LCD_Config.h"

#include <util/delay.h>


#define DELAY			2000


// Function to handle text wrapping to the next row
void LCD_voidPrintWithWrapping(u8 *text, u8 Copy_ROWS) {
	u8 currentRow = 0;
	for (u8 i = 0; text[i] != '\0'; i++) {
		// Check if we reached the end of the current row
		if (i > 0 && i % 16 == 0) {
			currentRow++; // Move to the next row
			LCD_voidGoTo(currentRow, 0); // Set the cursor to the beginning of the next row
		}
		// Check if we reached the end of the LCD rows
		if (currentRow >= Copy_ROWS) {
			break; // Exit the loop if all rows are used
		}
		LCD_voidWriteData(text[i]);
	}
}

int main(void) {
	// Initialize LCD
	LCD_voidInit();

	// Define custom characters for animations
	u8 heroWalk1[] = {
			0x0E,
			0x04,
			0x0E,
			0x15,
			0x04,
			0x0A,
			0x0A,
			0x0A

	};
	u8 heroWalk2[] = {
			0x0E,
			0x15,
			0x0E,
			0x04,
			0x04,
			0x0A,
			0x11,
			0x11
	};
	u8 heroWave1[] = {
			0x0E,
			0x05,
			0x05,
			0x0E,
			0x14,
			0x0E,
			0x0A,
			0x0A
	};
	u8 heroWave2[] = {
			0x0E,
			0x06,
			0x05,
			0x0E,
			0x14,
			0x0E,
			0x0A,
			0x0A
	};
	u8 bounce1[] = {
			0x0E,
			0x04,
			0x04,
			0x0E,
			0x15,
			0x0E,
			0x0A,
			0x0A
	};
	u8 bounce2[] = {
			0x0E,
			0x04,
			0x15,
			0x0E,
			0x04,
			0x0E,
			0x0A,
			0x11
	};

	u8 funky1[] = {
			0x0E,
			  0x05,
			  0x06,
			  0x0C,
			  0x14,
			  0x06,
			  0x0A,
			  0x12
		};
	u8 funky2[] = {
			0x0E,
			  0x14,
			  0x0C,
			  0x06,
			  0x05,
			  0x0C,
			  0x0A,
			  0x09
			};




	// Save custom characters in CGRAM
	LCD_voidCustomChar(0, heroWalk1);
	LCD_voidCustomChar(1, heroWalk2);
	LCD_voidCustomChar(2, heroWave1);
	LCD_voidCustomChar(3, heroWave2);
	LCD_voidCustomChar(4, bounce1);
	LCD_voidCustomChar(5, bounce2);
	LCD_voidCustomChar(6, funky1);
	LCD_voidCustomChar(7, funky2);


	_delay_ms(2);



	// Animation: Hero walks from the side and introduces itself
	for (u8 i = 0; i < 7; i++) {
		LCD_voidGoTo(3, i);
		LCD_voidWriteData(0); // Display heroWalk1
		_delay_ms(200);
		LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
		LCD_voidGoTo(3, i + 1);
		LCD_voidWriteData(1); // Display heroWalk2
		_delay_ms(200);
	}

	LCD_voidGoTo(0, 0);
	_delay_ms(2);

	//LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
	LCD_voidPrintWithWrapping("Hello, I am the Hero!",2);
	//_delay_ms(1000);

	// Animation: Hero waves to the screen
	for (u8 i = 0; i < 7; i++) {
		LCD_voidGoTo(3, 7);
		LCD_voidWriteData(2); // Display heroWave1
		_delay_ms(200);
		//LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
		LCD_voidGoTo(3, 7);
		LCD_voidWriteData(3); // Display heroWave2
		_delay_ms(200);
	}
	// Story Introduction
	LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
	LCD_voidGoTo(3, 7);
	LCD_voidWriteData(3);
	LCD_voidGoTo(0, 0);
	LCD_voidPrintWithWrapping("Once upon a time",3);
	_delay_ms(DELAY);

	// Story Introduction
	LCD_voidGoTo(0, 0);
	LCD_voidPrintWithWrapping("In a world wherefitness ruled,",2);
	_delay_ms(DELAY);


	LCD_voidGoTo(0, 0);
	LCD_voidPrintWithWrapping("there lived a jumping jack hero",2);
	_delay_ms(DELAY);
	LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);

	LCD_voidGoTo(0, 0);
	LCD_voidPrintWithWrapping("named Jack Jackerson.",2);
	for (u8 i = 0; i < 7; i++) {
		LCD_voidGoTo(3, 7);
		LCD_voidWriteData(0); // Display heroWalk1
		_delay_ms(200);
		//LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
		LCD_voidGoTo(3, 7);
		LCD_voidWriteData(1); // Display heroWalk2
		_delay_ms(200);
	}


	LCD_voidGoTo(0, 0);
	LCD_voidPrintWithWrapping("Armed with elastic enthusiasm",2);
	_delay_ms(DELAY);

	LCD_voidGoTo(0, 0);
	LCD_voidPrintWithWrapping("he bounced into action whenever",2);

	for (u8 i = 0; i < 7; i++) {
		LCD_voidGoTo(3, 7);
		LCD_voidWriteData(4); // Display bounce1
		_delay_ms(200);
		LCD_voidGoTo(3, 7);
		LCD_voidWriteData(' ');
		LCD_voidGoTo(2, 7);
		LCD_voidWriteData(5); // Display bounce2
		_delay_ms(200);
		LCD_voidGoTo(2, 7);
		LCD_voidWriteData(' ');
	}

	LCD_voidGoTo(3, 7);
	LCD_voidWriteData(4);

	LCD_voidGoTo(0, 0);
	LCD_voidPrintWithWrapping("people lacked motivation to exercise.",3);
	_delay_ms(DELAY);

	LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
	LCD_voidGoTo(3, 7);
	LCD_voidWriteData(4);
	LCD_voidGoTo(0, 0);
	LCD_voidPrintWithWrapping("With a leap and a laugh, he transformed gym ",3);
	_delay_ms(DELAY);


	LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
	LCD_voidGoTo(3, 7);
	LCD_voidWriteData(4);
	LCD_voidGoTo(0, 0);
	LCD_voidPrintWithWrapping("floors into dance floors,making workouts as fun",3);
	_delay_ms(DELAY);

	LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
	LCD_voidGoTo(3, 7);
	LCD_voidWriteData(4);
	LCD_voidGoTo(0, 0);
	LCD_voidPrintWithWrapping("as a disco partyHis\"Jack Attack\"workouts had",3);

	for (u8 i = 0; i < 7; i++) {
		LCD_voidGoTo(3, 7);
		LCD_voidWriteData(6); // Display heroWalk1
		_delay_ms(200);
		//LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
		LCD_voidGoTo(3, 7);
		LCD_voidWriteData(7); // Display heroWalk2
		_delay_ms(200);
	}


	while (1) {
		// Keep the microcontroller running after the story ends
	}

	return 0;
}
