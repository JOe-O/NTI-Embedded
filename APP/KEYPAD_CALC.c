///*
// * LCD.c
// *
// *  Created on: Jul 23, 2023
// *      Author: ART
// */
//
//#include "typedef.h"
//#include "DIO_int.h"
//#include "ATMEGA32_REGESTERS.h"
//#include "LCD_int.h"
//#include "LCD_Config.h"
//#include "Keypad_int.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <util/delay.h>
//
//u8 num1[10],num2[10];
//int main(void)
//{
//	start:
//
//	LCD_voidInit();
//	u8 KeyVal;
//	Keypad_voidInit();
//	//LCD_voidSendCommand(0x80);
//
//	u8 i = 0;
//	u8 flag = 0;
//	u32 answer = 0;
//
//	while(1)
//	{
//
//		KeyVal= Keypad_u8GetKey();
//		if(KeyVal != NOT_PRESSED)
//		{
//			if( (KeyVal != '+') && (KeyVal != '-') && (KeyVal != '*') && (KeyVal != '/') && (KeyVal != '#') )
//			{
//				LCD_voidWriteData(KeyVal);
//				num1[i] = KeyVal;
//				i++;
//			}else if(KeyVal == '+')
//			{
//				LCD_voidWriteData(KeyVal);
//				i=0;
//				flag = 1;
//				while(flag == 1)
//				{
//					KeyVal= Keypad_u8GetKey();
//					if(KeyVal != NOT_PRESSED)
//					{
//						if(KeyVal != '=')
//						{
//							LCD_voidWriteData(KeyVal);
//							num2[i] = KeyVal;
//							i++;
//						}
//						else if(KeyVal == '=')
//						{
//							LCD_voidWriteData(KeyVal);
//
//							LCD_voidGoTo(1,0);
//							answer = atoi(num1) + atoi(num2);
//							LCD_voidWriteNumber(answer);
//							//memset(num1, '\0', sizeof(num1));
//							//flag = 0;
//							//							LCD_voidGoTo(1,6);
//							//							LCD_voidWriteString(num2);
//						}
//						if(KeyVal == '#')
//						{
//							LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
//							flag = 0;
//							goto start;
//
//						}
//
//					}
//				}
//
//
//			}else if(KeyVal == '-')
//			{
//				LCD_voidWriteData(KeyVal);
//				i=0;
//				flag = 1;
//				while(flag == 1)
//				{
//					KeyVal= Keypad_u8GetKey();
//					if(KeyVal != NOT_PRESSED)
//					{
//						if(KeyVal != '=')
//						{
//							LCD_voidWriteData(KeyVal);
//							num2[i] = KeyVal;
//							i++;
//						}
//						else if(KeyVal == '=')
//						{
//							LCD_voidWriteData(KeyVal);
//
//							LCD_voidGoTo(1,0);
//							answer = atoi(num1) - atoi(num2);
//							LCD_voidWriteNumber(answer);
//							//memset(num1, '\0', sizeof(num1));
//							//flag = 0;
//							//							LCD_voidGoTo(1,6);
//							//							LCD_voidWriteString(num2);
//						}
//						if(KeyVal == '#')
//						{
//							LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
//							flag = 0;
//							goto start;
//
//						}
//
//					}
//				}
//
//
//			}
//			else if(KeyVal == '*')
//			{
//				LCD_voidWriteData(KeyVal);
//				i=0;
//				flag = 1;
//				while(flag == 1)
//				{
//					KeyVal= Keypad_u8GetKey();
//					if(KeyVal != NOT_PRESSED)
//					{
//						if(KeyVal != '=')
//						{
//							LCD_voidWriteData(KeyVal);
//							num2[i] = KeyVal;
//							i++;
//						}
//						else if(KeyVal == '=')
//						{
//							LCD_voidWriteData(KeyVal);
//
//							LCD_voidGoTo(1,0);
//							answer = atoi(num1) * atoi(num2);
//							LCD_voidWriteNumber(answer);
//							//memset(num1, '\0', sizeof(num1));
//							//flag = 0;
//							//							LCD_voidGoTo(1,6);
//							//							LCD_voidWriteString(num2);
//						}
//						if(KeyVal == '#')
//						{
//							LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
//							flag = 0;
//							goto start;
//
//						}
//
//					}
//				}
//
//
//			}
//			else if(KeyVal == '/')
//			{
//				LCD_voidWriteData(KeyVal);
//				i=0;
//				flag = 1;
//				while(flag == 1)
//				{
//					KeyVal= Keypad_u8GetKey();
//					if(KeyVal != NOT_PRESSED)
//					{
//						if(KeyVal != '=')
//						{
//							LCD_voidWriteData(KeyVal);
//							num2[i] = KeyVal;
//							i++;
//						}
//						else if(KeyVal == '=')
//						{
//							LCD_voidWriteData(KeyVal);
//
//							LCD_voidGoTo(1,0);
//							answer = atoi(num1) / atoi(num2);
//							LCD_voidWriteNumber(answer);
//							//memset(num1, '\0', sizeof(num1));
//							//flag = 0;
//							//							LCD_voidGoTo(1,6);
//							//							LCD_voidWriteString(num2);
//						}
//						if(KeyVal == '#')
//						{
//							LCD_voidSendCommand(LCD_u8CLEAR_DISPLAY);
//							flag = 0;
//							goto start;
//
//						}
//
//					}
//				}
//
//
//			}
//
//
//
//		}
//		//		else if(KeyVal == '+')
//		//		{
//		//			LCD_voidGoTo(1,0);
//		//			LCD_voidWriteString(num1);
//		//		}
//
//
//
//
//
//
//
//	}
//
//
//	return 0;
//}
