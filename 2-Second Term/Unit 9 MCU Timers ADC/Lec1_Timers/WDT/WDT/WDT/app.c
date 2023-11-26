/*
 * app.c
 *
 * Created: 11/26/2023 1:22:48 PM
 *  Author: Admin
 */



#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "WDT_Interface.h"


int main(void)
{
	//1. Make Pin0 on PortC as Output
	DDRC |= (1<<0);
	
	//_delay_ms(1000);
	while (1)
	{
		PORTC ^= (1<<0);
		WDT_START(WDT_TIM_OUT_1P0_SEC);
		_delay_ms(900);
		WDT_STOP();
	}
}