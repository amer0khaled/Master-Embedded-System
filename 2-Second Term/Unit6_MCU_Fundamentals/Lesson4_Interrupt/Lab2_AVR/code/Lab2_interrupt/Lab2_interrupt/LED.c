/*
 * LED.c
 *
 * Created: 1/25/2023 11:38:01 PM
 *  Author: amrkh
 */ 

#include "DIO.h"

void LED_INIT(unsigned char port, unsigned char pin)
{
	DIO_SET_PIN_DIR(port,pin,1);
}

void LED_ON(unsigned char port, unsigned char pin)
{
	DIO_WRITE_PIN(port,pin,1);
}

void LED_OFF(unsigned char port, unsigned char pin)
{
	DIO_WRITE_PIN(port,pin,0);
}

void LED_TOGGLE(unsigned char port, unsigned char pin)
{
	DIO_TOG_PIN(port,pin);
}

unsigned char LED_READ(unsigned char port, unsigned char pin)
{
	return DIO_READ_PIN(port,pin);
}

void LED_INIT_PORT(unsigned char port)
{
	DIO_SET_PORT_DIR(port,0xff);
}

void LED_ON_PORT(unsigned port)
{
	DIO_WRITE_PORT(port,0xff);
}

void LED_OFF_PORT(unsigned char port)
{
	DIO_WRITE_PORT(port,0x00);
}

void LED_TOGGLE_PORT(unsigned char port)
{
	DIO_TOG_PORT(port);
}

unsigned char LED_READ_PORT(unsigned port)
{
	return DIO_READ_PORT(port);
} 
