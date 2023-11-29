/*
 * app.c
 *
 * Created: 11/28/2023 7:25:53 PM
 *  Author: Amer_Khaled
 */ 


#include <avr/io.h>
#include <stdint.h>
#include "ADC.h"
#include "DIO.h"
#include "LCD.h"

int main(void)
{
	
	LCD_INIT();
	
	ADC_Config adc;
	adc.ADC_Channel = ADC_Channel_3;
	adc.ADC_IRQ_Enable = ADC_IRQ_Enable_None;
	adc.ADC_LeftAdjust=ADC_LeftAdjust_Disable;
	adc.ADC_Mode=ADC_Mode_Single_Conversion;
	adc.ADC_Prescaler=ADC_Prescaler_64;
	adc.ADC_RefVoltage=ADC_RefVoltage_AVCC_EXT;
	adc.P_CallBack = 0;
	
	DIO_SET_PIN_DIR('a',3,0);
	MCAL_ADC_Init(&adc);
	
	
	uint16_t * AdcData;
	uint16_t vin;
	int temp;
	
	LCD_SEND_STRING("val:");
	
	
    while(1)
    {
        MCAL_ADC_Start_Conversion();
		MCAl_ADC_Read(AdcData, Enable);
		LCD_MOVE_CURSOR(1, 6);
		
		temp = ((*AdcData)*(5.0/1023.0))*100.0;
		if (temp < 10)
		{
			LCD_SEND_CHAR(temp + '0');
		}
		else if (temp >= 10)
		{
			LCD_SEND_CHAR((temp/10) + '0');
			LCD_MOVE_CURSOR(1,7);
			LCD_SEND_CHAR((temp%10) + '0');
		}
		
		
    }
}