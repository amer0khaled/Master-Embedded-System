/*
 * LCD.c
 *
 * Created: 2/7/2023 2:33:14 PM
 *  Author: amrkh
 */ 

#include "LCD.h"

void LCD_INIT()
{	
	_delay_ms(50);
	
	#if defined EIGHT_BIT_MODE
	
	DIO_SET_PORT_DIR(DATA_PORT , 0xFF);
	
	DIO_SET_PIN_DIR(CTRL_PORT , RW , 1);
	DIO_SET_PIN_DIR(CTRL_PORT , EN , 1);
	DIO_SET_PIN_DIR(CTRL_PORT , RS , 1);
	
	DIO_WRITE_PIN(CTRL_PORT , RW , 0);
	
	LCD_SEND_CMD(FUNCTION_SET_TO_EIGHT_BIT_MODE);
	_delay_ms(1);
	
	LCD_SEND_CMD(DISPLAY_ON_CURSOR_ON);
	_delay_ms(1);
	
	LCD_SEND_CMD(CLEAR_SCREEN);
	_delay_ms(3);
	
	LCD_SEND_CMD(ENTRY_MODE);
	_delay_ms(2);
	
	#elif defined FOUR_BIT_MODE
	
	DIO_SET_PIN_DIR(DATA_PORT , 4 ,1);
	DIO_SET_PIN_DIR(DATA_PORT , 5 ,1);
	DIO_SET_PIN_DIR(DATA_PORT , 6 ,1);
	DIO_SET_PIN_DIR(DATA_PORT , 7 ,1);
	
	DIO_SET_PIN_DIR(CTRL_PORT , RW ,1);
	DIO_SET_PIN_DIR(CTRL_PORT , EN ,1);
	DIO_SET_PIN_DIR(CTRL_PORT , RS ,1);
	
	DIO_WRITE_PIN(CTRL_PORT , RW , 0);
	
	LCD_SEND_CMD(RETURN_HOME);
	_delay_ms(1);
	
	LCD_SEND_CMD(FUNCTION_SET_TO_FOUR_BIT_MODE);
	_delay_ms(1);
	
	LCD_SEND_CMD(DISPLAY_ON_CURSOR_ON);
	_delay_ms(1);
	
	LCD_SEND_CMD(CLEAR_SCREEN);
	_delay_ms(3);
	
	LCD_SEND_CMD(ENTRY_MODE);
	_delay_ms(2);
	
	#endif
	
}

void LCD_SEND_CHAR(unsigned char data)
{
	#if defined EIGHT_BIT_MODE
	
	/*configure read/write pin*/
	DIO_WRITE_PIN(CTRL_PORT , RW , 0);
	
	/*send data on the data port*/
	DIO_WRITE_PORT(DATA_PORT , data);
	
	/*save in data register*/
	DIO_WRITE_PIN(CTRL_PORT , RS , 1);
	
	/*send pulse on the enable pin*/
	LCD_ENABLE();
	
	_delay_ms(1);
	
	#elif defined FOUR_BIT_MODE
	
	/*configure read/write pin*/
	DIO_WRITE_PIN(CTRL_PORT , RW , 0);
	
	/*WRITE MOST FOUR BITS TO DATA REGISTER FIRSTLY*/
	DIO_WRITE_HIGH_NIBBLE(DATA_PORT , data>>4);
	
	/*save in data register*/
	DIO_WRITE_PIN(CTRL_PORT , RS , 1);
	
	/*send pulse on the enable pin*/
	LCD_ENABLE();
	
	/*WRITE LEAST FOUR BITS TO DATA REGISTER */
	DIO_WRITE_HIGH_NIBBLE(DATA_PORT , data);
	
	/*save in data register*/
	DIO_WRITE_PIN(CTRL_PORT , RS , 1);
		
	/*send pulse on the enable pin*/
	LCD_ENABLE();
	 
	 
	_delay_ms(1);
	
	#endif
}

void LCD_SEND_CMD(unsigned char cmd)
{	
	#if defined EIGHT_BIT_MODE 
	
	/*configure the read/write pin*/
	DIO_WRITE_PIN(DATA_PORT , RW , 0);
	
	/*send command on the data port */
	DIO_WRITE_PORT(DATA_PORT , cmd);
	
	/*save in command register*/
	DIO_WRITE_PIN(CTRL_PORT , RS , 0);
	
	/*send pulse on the enable pin*/
	LCD_ENABLE();
	
	_delay_ms(1);
	
	#elif defined FOUR_BIT_MODE
	
	/*configure the read/write pin*/
	DIO_WRITE_PIN(DATA_PORT , RW , 0);
	
	/*WRITE MOST FOUR BIT TO COMMAND REGISTER*/
	DIO_WRITE_HIGH_NIBBLE(DATA_PORT , cmd>>4);
	
	/*save in command register*/
	DIO_WRITE_PIN(CTRL_PORT , RS , 0);
	
	/*send pulse on the enable pin*/
	LCD_ENABLE();
	
	/*WRITE LEAST FOUR BIT TO COMMAND REGISTER*/
	DIO_WRITE_HIGH_NIBBLE(DATA_PORT , cmd);
	
	/*save in command register*/
	DIO_WRITE_PIN(CTRL_PORT , RS , 0);
	
	/*send pulse on the enable pin*/
	LCD_ENABLE();
	
	_delay_ms(1);
	
	#endif
}

void LCD_SEND_STRING(const unsigned char * data)
{	
	while(*data != '\0')
	{
		LCD_SEND_CHAR(*data);
		data++;
	}		
	 
}

void LCD_MOVE_CURSOR(unsigned char row , unsigned char col)
{	
	unsigned char position;
	
	if (row == 1)
	{
		position = 0x80 + col -1;
	}
	else if(row == 2)
	{
		position = 0xc0 + col -1;
	}
	else if (row == 3)
	{
		position = 0x94 + col -1;
	}
	else if (row == 4)
	{
		position = 0xD4 + col -1;
	}
	else if ((row > 4)||(col > 20)||(row < 1)||(col < 1))
	{
		position = 0x80;
	}
	
	LCD_SEND_CMD(position);
	
	_delay_ms(1);
}

void LCD_CLEAR_SCREEN()
{
	LCD_SEND_CMD(CLEAR_SCREEN);
}

void LCD_ENABLE()
{
	DIO_WRITE_PIN(CTRL_PORT , EN , 1);
	
	_delay_ms(2);
	
	DIO_WRITE_PIN(CTRL_PORT , EN , 0);
	
	_delay_ms(2);
}