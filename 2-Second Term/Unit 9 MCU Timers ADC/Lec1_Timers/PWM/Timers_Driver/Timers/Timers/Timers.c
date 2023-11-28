/*
 * Timers.c
 *
 * Created: 11/26/2023 2:38:56 PM
 *  Author: Amer_Khaled
 */ 


/*
===========================================
		Includes
===========================================
*/

#include <avr/io.h>
#
#include "Timers_Interface.h"



/*
===========================================
		Generic Variables
===========================================
*/


static Timer0_Config * GP_Timer0_User_Config;

void (*GP_IRQ_CallBack)(void);

/*
===========================================
		Generic Macros
===========================================
*/

/*

/*
===========================================
			Generic APIs
===========================================
 */


/*===========================================
			APIs
===========================================
*/

void Timer0_Init(Timer0_Config * TimerCFG)
{
	if(TimerCFG != 0)
	{
		//Reset Timer Counter Register
		//TCNT0 = 0x00;
		
		//set Global Pointer By Configuration Structure
		GP_Timer0_User_Config = TimerCFG;
		
		//select Timer Mode
		switch(TimerCFG->Timer0_Mode)
		{
			case Timer0_Mode_Normal:
			TCCR0 &= (~(1<<3)) | (~(1<<6));
			break;
			
			case Timer0_Mode_CTC:
			TCCR0 &= ~(1<<3);
			TCCR0 |= (1<<6);
			break;
			
			case Timer0_Mode_FastPWM_NonInverting:
			case Timer0_Mode_FastPWM_Inverting:
			TCCR0 |= (1<<3) | (1<<6);
			
			//make OC0 PB.3 as output pin
			DDRB |= (1<<3);
			
			if (TimerCFG->Timer0_Mode == Timer0_Mode_FastPWM_Inverting)
			{
				TCCR0 |= (1<<4) | (1<<5);
			}
			else if(TimerCFG->Timer0_Mode == Timer0_Mode_FastPWM_NonInverting)
			{
				TCCR0 &= ~(1<<4);
				TCCR0 |= (1<<5);
			}
			break;
			
		}
		
		//set Timer Clock
		TCCR0 |= (TimerCFG->Timer0_CLK_SRC);
		
		if ( (TimerCFG->Timer0_CLK_SRC == Timer0_CLK_SRC_External_T0_Falling) || (TimerCFG->Timer0_CLK_SRC == Timer0_CLK_SRC_External_T0_Rising) )
		{
			//make T0 at PB.0 as output pin
			DDRB |= (1<<0);
		}
		
		
		//config Timer Interrupt
		if(TimerCFG->Timer0_IRQ != Timer_IRQ_None)
		{
			//Enable Global Interrupt Mask I-Bit at SREG
			SREG |= (1<<7);
			
			if (TimerCFG->Timer0_IRQ == Timer_IRQ_OverFlow)
			{
				TIMSK |= (1<<TOIE0);
			}
			else if (TimerCFG->Timer0_IRQ == Timer_IRQ_CompareMatch)
			{
				TIMSK |= (1<<OCIE0);
			}
		}
		
		/* Call back function address */
		GP_IRQ_CallBack = TimerCFG->P_IRQ_CallBack;
	}
	else
	{
		// ToDo Error In Configuration Pointer
	}
	
}


void Timer0_DeInit(void)
{
	// put zeros in cs0 , cs1 , cs2
	TCCR0 &= ~((1<<0)|(1<<1)|(1<<2));
}

void Timer0_SetCompareValue(uint8_t TicksNum)
{
	OCR0 |= TicksNum;
}


void Timer0_GetCompareValue(uint8_t *TicksNum)
{
	*TicksNum = TCNT0;
}

void Timer0_PWM_DutyCycle(uint8_t duty_cycle)
{
	if (GP_Timer0_User_Config->Timer0_Mode == Timer0_Mode_FastPWM_Inverting)
	{
		OCR0 = (uint8_t)(255 - ((duty_cycle/100.0)*256));
	}
	else if (GP_Timer0_User_Config->Timer0_Mode == Timer0_Mode_FastPWM_NonInverting)
	{
		OCR0 = (uint8_t)((duty_cycle/100.0)*256) - 1;
	}
}


/* ================================================================ */
/* ================ ISR Functions Definations ===================== */
/* ================================================================ */


//overflow ISR
ISR(TIMER0_OVF_vect)
{
	GP_IRQ_CallBack();
}

//compare match ISR
ISR(TIMER0_COMP_vect)
{
	GP_IRQ_CallBack();
}