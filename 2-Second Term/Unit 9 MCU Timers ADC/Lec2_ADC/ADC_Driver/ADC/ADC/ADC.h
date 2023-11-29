/*
 * ADC.h
 *
 * Created: 11/28/2023 7:28:34 PM
 *  Author: Admin
 */ 


#ifndef ADC_H_
#define ADC_H_



//---------------------------------------------------
//Includes
//---------------------------------------------------

#include <stdint.h>
#include <avr/interrupt.h>


//---------------------------------------------------
//User Type Definition (Structures)
//---------------------------------------------------


/*
Starting a Conversion
A single conversion is started by writing a logical one to the ADC Start Conversion bit, ADSC. This bit stays high aslong as the conversion is in progress and will be cleared by hardware when the conversion is completed. If a different data channel is selected while a conversion is in progress, the ADC will finish the current conversion beforeperforming the channel change.


*/


typedef enum
{
	Disable,
	Enable
	
}PollingMechanism;






typedef struct
{
	uint8_t ADC_Prescaler;			//specifies the division factor of ADC input clock
									//this parameter must be set based on @ref ADC_Prescaler_define
									
									
	uint8_t ADC_Mode;				//specifies ADC Mode (single conversion mode or free running mode) 
									//this parameter must be set based on @ref ADC_Mode_define
									
									
	uint8_t ADC_RefVoltage;			//specifies ADC reference voltage
									//this parameter must be set based on @ref ADC_RefVoltage_define
									
									
	uint8_t ADC_LeftAdjust;			//enable or disable Left Adjust the ADC Result
									//this parameter must be set based on @ref ADC_LeftAdjust_define
									
									
	uint8_t ADC_Channel;			//select ADC Channel
									//this parameter must be set based on @ref ADC_Channel_define
									
		
								
	uint8_t ADC_IRQ_Enable;			//enable or disable ADC conversion complete interrupt
									//this parameter must be set based on @ref ADC_IRQ_Enable_define
									
									
	void (*P_CallBack)(void);		//set the Function which will be called once IRQ Happens
	
	
}ADC_Config;


//---------------------------------------------------
//Macros Configuration References
//---------------------------------------------------

//@ref ADC_Prescaler_define

#define ADC_Prescaler_2			(1<<0)
#define ADC_Prescaler_4			(2<<0)
#define ADC_Prescaler_8			(3<<0)
#define ADC_Prescaler_16		(4<<0)
#define ADC_Prescaler_32		(5<<0)
#define ADC_Prescaler_64		(6<<0)
#define ADC_Prescaler_128		(7<<0)


//@ref ADC_IRQ_Enable_define

#define ADC_IRQ_Enable_None		(0<<3)
#define ADC_IRQ_Enable_ADIE		(1<<3)

//@ref ADC_Mode_define

#define ADC_Mode_Single_Conversion		1
#define ADC_Mode_Free_Running			0

//@ref ADC_RefVoltage_define

#define ADC_RefVoltage_AREF_EXT		(0<<6 | 0<<7)
#define ADC_RefVoltage_AVCC_EXT		(1<<6 | 0<<7)	//AVCC with external capacitor at AREF pin
#define ADC_RefVoltage_INT			(1<<6 | 1<<7)			//Internal 2.56V Voltage Reference with external capacitor at AREF pin


//@ref ADC_LeftAdjust_define

#define ADC_LeftAdjust_Enable		(1<<5)
#define ADC_LeftAdjust_Disable		0

//@ref ADC_Channel_define

#define ADC_Channel_0		0
#define ADC_Channel_1		1
#define ADC_Channel_2		2
#define ADC_Channel_3		3
#define ADC_Channel_4		4
#define ADC_Channel_5		5
#define ADC_Channel_6		6
#define ADC_Channel_7		7


//---------------------------------------------------
//@ref Module REF Name define
//---------------------------------------------------



//---------------------------------------------------
//APIs Supported by "MCAL ADC Driver"
//---------------------------------------------------


void MCAL_ADC_Init(ADC_Config * UserConfig);

void MCAL_ADC_DeInit(void);

void MCAL_ADC_Start_Conversion(void);

void MCAl_ADC_Read(uint16_t * AdcResult, PollingMechanism polling);





#endif /* ADC_H_ */