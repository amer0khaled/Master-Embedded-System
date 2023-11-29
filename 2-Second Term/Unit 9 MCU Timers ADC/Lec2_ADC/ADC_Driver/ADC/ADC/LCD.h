/*
 * LCD.h
 *
 * Created: 2/7/2023 2:33:26 PM
 *  Author: amrkh
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "LCD_CONFIGURATION.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/*********************LCD COMMANDS*******************/

#define FUNCTION_SET_TO_EIGHT_BIT_MODE 0x38

#define FUNCTION_SET_TO_FOUR_BIT_MODE 0x28

#define CLEAR_SCREEN 0x01

#define RETURN_HOME 0x02

#define ENTRY_MODE 0x06

#define DISPLAY_ON_CURSOR_ON 0x0E

#define DISPLAY_OFF_CURSOR_OFF 0x08

#define DISPLAY_ON_CURSOR_BLINKING_ON 0x0F

#define DISPLAY_ON_CURSOR_OFF 0x0C

#define SHIFT_CURSOR_LEFT 0x10

#define SHIFT_CURSOR_RIGHT 0x14

#define SHIFT_DISPLAY_LEFT 0x18

#define SHIFT_DISPLAY_RIGHT 0x1C

/*******************************************************/

/*****************LCD FUNCTIONS PROTOTYPE***************/


void LCD_INIT();

void LCD_SEND_CHAR(unsigned char data);

void LCD_SEND_CMD(unsigned char cmd);

void LCD_SEND_STRING(const unsigned char * data);

void LCD_MOVE_CURSOR(unsigned char row , unsigned char col);

void LCD_CLEAR_SCREEN();

void LCD_ENABLE();


/******************************************************/

#endif /* LCD_H_ */