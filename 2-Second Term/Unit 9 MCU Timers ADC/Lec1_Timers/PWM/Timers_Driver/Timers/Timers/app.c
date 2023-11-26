/*
 * app.c
 *
 * Created: 11/26/2023 8:34:21 PM
 *  Author: Admin
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include "Timers_Interface.h"


#define null ((void *)0)

int main()
{
	DDRB |= (1<<3);
	
	Timer0_Config timer;
	
	timer.Timer0_Mode    = Timer0_Mode_FastPWM_Inverting;
	timer.P_IRQ_CallBack = null;
	timer.Timer0_CLK_SRC = Timer0_CLK_SRC_Internal_prescler_8;
	timer.Timer0_IRQ     = Timer_IRQ_None;
	
	Timer0_Init(&timer);
	Timer0_PWM_DutyCycle(50);
	
	while(1)
	{
	
		
	}
}