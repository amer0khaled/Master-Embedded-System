/*
 * button.c
 *
 * Created: 9/23/2022 3:33:45 PM
 *  Author: amrkh
 */ 
#include "DIO.h"


void button_init(unsigned char port, unsigned char pin)
{
	DIO_SET_PIN_DIR(port,pin,0);
}

unsigned char button_read(unsigned char port, unsigned char pin)
{
	return DIO_READ_PIN(port,pin);
}