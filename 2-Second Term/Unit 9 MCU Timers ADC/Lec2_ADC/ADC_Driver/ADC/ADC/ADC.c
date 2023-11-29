/*
 * ADC.c
 *
 * Created: 11/28/2023 7:28:22 PM
 *  Author: Amer_Khaled
 */ 


#include "ADC.h"

#include "STD_MACROS.h"

ADC_Config * GP_UserConfig;



void MCAL_ADC_Init(ADC_Config * UserConfig)
{
	GP_UserConfig = UserConfig;
	
	//ADC Prescaler
	ADCSRA |= UserConfig->ADC_Prescaler;
	
	//Left Adjust state
	ADMUX |= UserConfig->ADC_LeftAdjust;
	
	//ADC Reference Voltage
	ADMUX |= UserConfig->ADC_RefVoltage;
	
	//config ADC channel and make it as Input pin
	ADMUX &= ~(0b11111 << 0);
	ADMUX |= (UserConfig->ADC_Channel);
	//DDRA &= ~(1<<(UserConfig->ADC_Channel));
	CLEAR_BIT(DDRA, UserConfig->ADC_Channel);
	
	
	//ADC IRQ
	ADCSRA |= UserConfig->ADC_IRQ_Enable;
	
	if (UserConfig->ADC_IRQ_Enable == ADC_IRQ_Enable_ADIE)
	{
		sei();
	}
	
	//ADC Enable
	ADCSRA |= (1<<ADEN);
	
	if (UserConfig->ADC_Mode == ADC_Mode_Free_Running)
	{
		ADCSRA |= (1<<ADSC);
	}
	
}


void MCAL_ADC_DeInit(void)
{
	ADMUX = 0x00;
	ADCSRA =0x00;
	SFIOR &= ~(1<<5 | 1<<6 | 1<<7);
}


void MCAL_ADC_Start_Conversion(void)
{
	if (GP_UserConfig->ADC_Mode == ADC_Mode_Single_Conversion)
	{
		ADCSRA |= (1<<ADSC);
	}
}

void MCAl_ADC_Read(uint16_t * AdcResult, PollingMechanism polling)
{
	if (polling == Enable)
	{
		while( ( (ADCSRA & (1<<ADIF)) >> ADIF) == 0);
	}
	
	
	if (GP_UserConfig->ADC_LeftAdjust == ADC_LeftAdjust_Disable)
	{
		*AdcResult = ADCL;
		*AdcResult |= (ADCH<<8);
	}
	else
	{
		*AdcResult = (ADCH << 2);
		
	}
	
}






