#ifndef STM32_GPIO_H_
#define STM32_GPIO_H_


//---------------------------------------------------
//Includes
//---------------------------------------------------

#include"stm32f103x8.h" //device header





//---------------------------------------------------
//User Type Definition (Structures)
//---------------------------------------------------

//configuration structure that will be sent to the initialization function
typedef struct
{
	uint16_t GPIO_PinNumber;	/*
									specifies the gpio pin to be configured
									this parameter must be set based on @ref GPIO_PINS_define 
								*/
								
	uint8_t GPIO_PinMode;		/*
									specifies the operating mode for the selected pin
									this parameter can be a value of @ref GPIO_MODE_define
								*/
								
	uint8_t GPIO_PinSpeed;		/*
									specifies the speed of output pin
									this parameter can be a value of GPIO_SPEED_define
								*/
}GPIO_PinConfig_t;




//---------------------------------------------------
//Macros Configuration References
//---------------------------------------------------


//@ref GPIO_PINS_define

#define GPIO_PIN_0		((uint16_t)(0)) /*pin 0 selected*/
#define GPIO_PIN_1		((uint16_t)(1)) /*pin 1 selected*/
#define GPIO_PIN_2		((uint16_t)(2)) /*pin 2 selected*/
#define GPIO_PIN_3		((uint16_t)(3)) /*pin 3 selected*/
#define GPIO_PIN_4		((uint16_t)(4)) /*pin 4 selected*/
#define GPIO_PIN_5		((uint16_t)(5)) /*pin 5 selected*/
#define GPIO_PIN_6		((uint16_t)(6)) /*pin 6 selected*/
#define GPIO_PIN_7		((uint16_t)(7)) /*pin 7 selected*/
#define GPIO_PIN_8		((uint16_t)(8)) /*pin 8 selected*/
#define GPIO_PIN_9		((uint16_t)(9)) /*pin 9 selected*/
#define GPIO_PIN_10		((uint16_t)(10)) /*pin 10 selected*/
#define GPIO_PIN_11		((uint16_t)(11)) /*pin 11 selected*/
#define GPIO_PIN_12		((uint16_t)(12)) /*pin 12 selected*/
#define GPIO_PIN_13		((uint16_t)(13)) /*pin 13 selected*/
#define GPIO_PIN_14		((uint16_t)(14)) /*pin 14 selected*/
#define GPIO_PIN_15		((uint16_t)(15)) /*pin 15 selected*/
#define GPIO_PIN_All	((uint16_t)(0xFFFF)) /*All pins selected*/



//@ref GPIO_MODE_define
/*
• Input floating
• Input pull-up
• Input-pull-down
• Analog
• Output open-drain
• Output push-pull
• Alternate function push-pull
• Alternate function open-drain
*/


#define GPIO_MODE_INPUT_FLOATING			0	/*Input floating*/
#define GPIO_MODE_INPUT_PULL_UP				1	/*Input pull-up*/
#define GPIO_MODE_INPUT_PULL_DOWN			2	/*Input-pull-down*/
#define GPIO_MODE_OUTPUT_OPEN_DRAIN			3	/*Output open-drain*/
#define GPIO_MODE_OUTPUT_PUSH_PULL			4	/*Output push-pull*/
#define GPIO_MODE_AFIO_OUTPUT_PUSH_PULL		5	/*Alternate function output push-pull*/
#define GPIO_MODE_AFIO_OUTPUT_OPEN_DRAIN	6	/*Alternate function output open-drain*/
#define GPIO_MODE_AFIO_INPUT				7	/*Alternate function input*/
#define GPIO_MODE_ANALOG					8	/*Analog*/


//@ref GPIO_SPEED_define

/*
0: Output mode, max speed 10 MHz.
1: Output mode, max speed 2 MHz.
2: Output mode, max speed 50 MHz.
*/


#define GPIO_OUTPUT_SPEED_10MHz 	0	/*Output mode, max speed 10 MHz*/
#define GPIO_OUTPUT_SPEED_2MHz 		1	/*Output mode, max speed 2 MHz*/
#define GPIO_OUTPUT_SPEED_50MHz 	2	/*Output mode, max speed 50 MHz*/


//@ref GPIO_PIN_State

#define GPIO_PIN_STATE_TRUE			1
#define GPIO_PIN_STATE_FALSE		0


//@ref GPIO_LOACK_PIN_Status

#define GPIO_SUCCESSFUL_LOACK		1
#define GPIO_FAILED_LOACK			0


//---------------------------------------------------
//APIs Supported by "MCAL GPIO Driver"
//---------------------------------------------------

void MCAL_GPIO_Init(GPIO_TypeDef *GPIO_Instant, GPIO_PinConfig_t *PinConfig);

void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIO_Instant);

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIO_Instant, uint16_t PinNumber);

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIO_Instant);

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIO_Instant, uint16_t PinNumber, uint8_t Data);

void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIO_Instant, uint16_t Data);

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIO_Instant, uint16_t PinNumber);

void MCAL_GPIO_TogglePort(GPIO_TypeDef *GPIO_Instant);

uint8_t MCAL_GPIO_LoackPin(GPIO_TypeDef *GPIO_Instant, uint16_t PinNumber);

#endif /*STM32_GPIO_H_*/
