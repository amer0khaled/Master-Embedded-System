/*
 * WDT_Interface.h
 *
 * Created: 11/26/2023 12:24:26 PM
 *  Author: Admin
 */ 


typedef enum
{
	 WDT_TIM_OUT_16P3_MS  = 0b000 ,
	 WDT_TIM_OUT_32P5_MS  = 0b001 ,
	 WDT_TIM_OUT_65P0_MS  = 0b010 ,
	 WDT_TIM_OUT_0P13_SEC = 0b011 ,
	 WDT_TIM_OUT_0P26_SEC = 0b100 ,
	 WDT_TIM_OUT_0P52_SEC = 0b101 ,
	 WDT_TIM_OUT_1P0_SEC  = 0b110 ,
	 WDT_TIM_OUT_2P1_SEC  = 0b111
}WDT_TimeOut;





#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

void WDT_START(WDT_TimeOut Time_Out);
void WDT_STOP();

#endif /* WDT_INTERFACE_H_ */