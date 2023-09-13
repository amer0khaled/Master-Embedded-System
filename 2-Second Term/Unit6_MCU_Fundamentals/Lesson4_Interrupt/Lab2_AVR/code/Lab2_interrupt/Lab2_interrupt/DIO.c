/*
 * DIO.c
 *
 * Created: 1/25/2023 7:54:40 PM
 *  Author: amrkh
 */ 

#include "DIO.h"

void DIO_SET_PIN_DIR(unsigned char port, unsigned char pin, unsigned char dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if (dir == 1)
		{
			SET_BIT(DDRA,pin);
		} 
		else
		{
			CLEAR_BIT(DDRA,pin);
		}
		break;
		
		
		case 'B':
		case 'b':
		if (dir == 1)
		{
			SET_BIT(DDRB,pin);
		}
		else
		{
			CLEAR_BIT(DDRB,pin);
		}
		break;
		
		case 'C':
		case 'c':
		if (dir == 1)
		{
			SET_BIT(DDRC,pin);
		}
		else
		{
			CLEAR_BIT(DDRC,pin);
		}
		break;
		
		case 'D':
		case 'd':
		if (dir == 1)
		{
			SET_BIT(DDRD,pin);
		}
		else
		{
			CLEAR_BIT(DDRD,pin);
		}
		break;
		
	}
}

void DIO_SET_PORT_DIR(unsigned char port, unsigned char dir)
{
	switch (port)
	{
		case 'A':
		case 'a':
		DDRA=dir;
		break;
		
		case 'B':
		case 'b':
		DDRB=dir;
		break;
		
		case 'C':
		case 'c':
		DDRC=dir;
		break;
		
		case 'D':
		case 'd':
		DDRD=dir;
		break;
	}
}

void DIO_WRITE_PIN(unsigned char port, unsigned char pin, unsigned char data )
{
	switch(port)
	{
		case 'A':
		case 'a':
		if (data == 1)
		{
			SET_BIT(PORTA,pin);
		} 
		else
		{
			CLEAR_BIT(PORTA,pin);
		}
		break;
		
		case 'B':
		case 'b':
		if (data == 1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLEAR_BIT(PORTB,pin);
		}
		break;
		
		case 'C':
		case 'c':
		if (data == 1)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLEAR_BIT(PORTC,pin);
		}
		break;
		
		case 'D':
		case 'd':
		if (data == 1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLEAR_BIT(PORTD,pin);
		}
		break;
	}
}

void DIO_WRITE_PORT(unsigned char port, unsigned char data)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA=data;
		break;
		
		case 'B':
		case 'b':
		PORTB=data;
		break;
		
		case 'C':
		case 'c':
		PORTC=data;
		break;
		
		case 'D':
		case 'd':
		PORTD=data;
		break;
		
	}
}

void DIO_TOG_PIN(unsigned char port, unsigned char pin)
{
	switch (port)
	{
		case 'A':
		case 'a':
		TOGGLE_BIT(PORTA,pin);
		break;
		
		case 'B':
		case 'b':
		TOGGLE_BIT(PORTB,pin);
		break;
		
		case 'C':
		case 'c':
		TOGGLE_BIT(PORTC,pin);
		break;
		
		case 'D':
		case 'd':
		TOGGLE_BIT(PORTD,pin);
		break;
	}
}


void DIO_TOG_PORT(unsigned char port)
{
	switch(port)
	{
		case 'A':
		case 'a':
		TOGGLE_BIT(PORTA,0);
		TOGGLE_BIT(PORTA,1);
		TOGGLE_BIT(PORTA,2);
		TOGGLE_BIT(PORTA,3);
		TOGGLE_BIT(PORTA,4);
		TOGGLE_BIT(PORTA,5);
		TOGGLE_BIT(PORTA,6);
		TOGGLE_BIT(PORTA,7);
		break;
		
		case 'B':
		case 'b':
		TOGGLE_BIT(PORTB,0);
		TOGGLE_BIT(PORTB,1);
		TOGGLE_BIT(PORTB,2);
		TOGGLE_BIT(PORTB,3);
		TOGGLE_BIT(PORTB,4);
		TOGGLE_BIT(PORTB,5);
		TOGGLE_BIT(PORTB,6);
		TOGGLE_BIT(PORTB,7);
		break;
		
		case 'C':
		case 'c':
		TOGGLE_BIT(PORTC,0);
		TOGGLE_BIT(PORTC,1);
		TOGGLE_BIT(PORTC,2);
		TOGGLE_BIT(PORTC,3);
		TOGGLE_BIT(PORTC,4);
		TOGGLE_BIT(PORTC,5);
		TOGGLE_BIT(PORTC,6);
		TOGGLE_BIT(PORTC,7);
		break;
		
		case 'D':
		case 'd':
		TOGGLE_BIT(PORTD,0);
		TOGGLE_BIT(PORTD,1);
		TOGGLE_BIT(PORTD,2);
		TOGGLE_BIT(PORTD,3);
		TOGGLE_BIT(PORTD,4);
		TOGGLE_BIT(PORTD,5);
		TOGGLE_BIT(PORTD,6);
		TOGGLE_BIT(PORTD,7);
		break;
		
	}
}


unsigned char DIO_READ_PIN(unsigned char port, unsigned char pin)
{
	unsigned char data;
	
	switch(port)
	{
		case 'A':
		case 'a':
		data=READ_BIT(PINA,pin);
		break;
		
		case 'B':
		case 'b':
		data=READ_BIT(PINB,pin);
		break;
		
		case 'C':
		case 'c':
		data=READ_BIT(PINC,pin);
		break;
		
		case 'D':
		case 'd':
		data=READ_BIT(PIND,pin);
		break;
	}
	
	return data;
}

unsigned char DIO_READ_PORT(unsigned char port)
{
	unsigned char data;
	switch(port)
	{
		case 'A':
		case 'a':
		data=PINA;
		break;
		
		case 'B':
		case 'b':
		data=PINB;
		break;
		
		case 'C':
		case 'c':
		data=PINC;
		break;
		
		case 'D':
		case 'd':
		data=PIND;
		break;
		
	}
	
	return data;
}

void DIO_ACTIVE_INTERNAL_PULL_UP(unsigned char port, unsigned char pin)
{
	switch(port)
	{
		case 'A':
		case 'a':
		SET_BIT(PORTA,pin);
		break;
		
		case 'B':
		case 'b':
		SET_BIT(PORTB,pin);
		break;
		
		case 'C':
		case 'c':
		SET_BIT(PORTC,pin);
		break;
		
		case 'D':
		case 'd':
		SET_BIT(PORTD,pin);
		break;
	}
}

void DIO_WRITE_LOW_NIBBLE(unsigned char port, unsigned char data)
{
	data&=0x0f;
	
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA&=0xf0;
		PORTA|=data;
		break;
		
		case 'B':
		case 'b':
		PORTB&=0xf0;
		PORTB|=data;
		break;
		
		case 'C':
		case 'c':
		PORTC&=0xf0;
		PORTC|=data;
		break;
		
		case 'D':
		case 'd':
		PORTD&=0xf0;
		PORTD|=data;
		break;
		
		
	}
}

void DIO_WRITE_HIGH_NIBBLE(unsigned char port, unsigned char data)
{
	data<<=4;
	
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA&=0x0f;
		PORTA|=data;
		break;
		
		case 'B':
		case 'b':
		PORTB&=0x0f;
		PORTB|=data;
		break;
		
		case 'C':
		case 'c':
		PORTC&=0x0f;
		PORTC|=data;
		break;
		
		case 'D':
		case 'd':
		PORTD&=0x0f;
		PORTD|=data;
		break;
	}
}