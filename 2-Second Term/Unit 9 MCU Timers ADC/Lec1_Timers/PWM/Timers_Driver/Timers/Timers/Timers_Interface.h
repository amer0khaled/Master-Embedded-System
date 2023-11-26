/*
 * Timers_Interface.h
 *
 * Created: 11/26/2023 2:41:48 PM
 *  Author: Amer_Khaled
 */ 


#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

//---------------------------------------------------
//Includes
//---------------------------------------------------

#include <stdint.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL


//---------------------------------------------------
//User Type Definition (Structures)
//---------------------------------------------------

//#define SREG *((uint8_t*)(0x5F))



typedef struct
{
	uint8_t Timer0_Mode;		//specifies timer mode (Normal or CTC)
							//this parameter must be set based on @ref Timer_Mode_define
							
	uint8_t Timer0_CLK_SRC;	//specifies timer clock source (internal or external) and prescaler in case of internal clock source
							// this parameter must be set based on @ref Timer_CLK_SRC_define
	
	
	uint8_t Timer0_IRQ;		//specifies whether enable or disable interrupt
							//this parameter must be set based on @ref Timer_IRQ_define
	
	
	void (*P_IRQ_CallBack)(void)		//set by the Function which will be called once IRQ Happens
	
}Timer0_Config;




//---------------------------------------------------
//Macros Configuration References
//---------------------------------------------------


//@ref Timer_Mode_define

#define Timer0_Mode_Normal					0U
#define Timer0_Mode_CTC						1U
#define Timer0_Mode_FastPWM_Inverting		2U
#define Timer0_Mode_FastPWM_NonInverting	3U


//@ref Timer_CLK_SRC_define

#define Timer0_NO_CLK_SRC						0U
#define Timer0_CLK_SRC_Internal_prescler_1		1U
#define Timer0_CLK_SRC_Internal_prescler_8		2U
#define Timer0_CLK_SRC_Internal_prescler_64		3U
#define Timer0_CLK_SRC_Internal_prescler_256	4U
#define Timer0_CLK_SRC_Internal_prescler_1024	5U
#define Timer0_CLK_SRC_External_T0_Falling		6U
#define Timer0_CLK_SRC_External_T0_Rising		7U


//@ref Timer_IRQ_define

#define Timer_IRQ_None				0U
#define Timer_IRQ_OverFlow			1U
#define Timer_IRQ_CompareMatch		2U



//---------------------------------------------------
//@ref Module REF Name define
//---------------------------------------------------



//---------------------------------------------------
//APIs Supported by "MCAL GPIO Driver"
//---------------------------------------------------

void Timer0_Init(Timer0_Config * TimerCFG);
void Timer0_DeInit();
void Timer0_SetCompareValue(uint8_t TicksNum);
void Timer0_GetCompareValue(uint8_t *TicksNum);
void Timer0_PWM_DutyCycle(uint8_t duty_cycle);

#endif /* TIMERS_INTERFACE_H_ */