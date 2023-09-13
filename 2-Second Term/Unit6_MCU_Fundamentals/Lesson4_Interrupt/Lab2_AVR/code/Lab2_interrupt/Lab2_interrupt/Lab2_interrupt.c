/*
 * Lab2_Intrrupt.c
 *
 * Created: 8/28/2023 12:57:54 PM
 *  Author: Admin
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "LED.h"
#include "button.h"


//Status Register
#define SREG *((volatile unsigned char *)(0x5F))

//General Interrupt Control Register
#define GICR *((volatile unsigned char *)(0x5B))

//MCU Control Register
#define MCUCR *((volatile unsigned char *)(0x55))

//MCU Control and Status Register
#define MCUCSR *((volatile unsigned char *)(0x54))



void EXTI_Init(void)
{	
	//set global interrupt bit
	SET_BIT(SREG, 7);
	
	//enable INT0, INT1, INT2
	GICR |= (0b111<<5);
	
	//Any logical change on INT0 generates an interrupt request
	SET_BIT(MCUCR, 0);
	
	//The rising edge of INT1 generates an interrupt request
	MCUCR |= (0b11<<2);
	
	//The falling edge of INT2 generates an interrupt request
	CLEAR_BIT(MCUCSR, 6);
	
	
}


int main(void)
{	
	EXTI_Init();
	
	button_init('b', 2);
	button_init('d', 2);
	button_init('d', 3);
	
	LED_INIT('a', 0);
	LED_INIT('a', 1);
	LED_INIT('a', 2);
	
	
    while(1)
    {
       LED_OFF('a', 0);
	   LED_OFF('a', 1);
	   LED_OFF('a', 2);
    }
}

ISR(INT0_vect)
{
	LED_ON('a', 0);
	_delay_ms(1000);
	
}

ISR(INT1_vect)
{
	LED_ON('a', 1);
	_delay_ms(1000);
	
}

ISR(INT2_vect)
{
	LED_ON('a', 2);
	_delay_ms(1000);
	
}