/*
 * WDT.c
 *
 * Created: 11/26/2023 12:23:46 PM
 *  Author: Amer_Khaled
 */ 


#include <avr/io.h>
#include "WDT_Interface.h"


void WDT_START(WDT_TimeOut Time_Out)
{
	//enable WDT
	WDTCR |= (1<<WDE);
	
	//adjust WDT Clock
	if ( (WDT_TIM_OUT_16P3_MS<=Time_Out) && (WDT_TIM_OUT_2P1_SEC>=Time_Out) )
	{
		WDTCR |= (Time_Out << 0);
	}
	
}

void WDT_STOP()
{
	WDTCR |= (1<<WDE) | (WDTOE);
	WDTCR = 0x00;
}

