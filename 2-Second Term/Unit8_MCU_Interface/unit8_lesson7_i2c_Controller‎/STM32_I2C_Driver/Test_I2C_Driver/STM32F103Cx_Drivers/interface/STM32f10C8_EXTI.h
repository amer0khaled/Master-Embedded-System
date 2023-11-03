#ifndef STM32F103C8_EXTI_H_
#define STM32F103C8_EXTI_H_


//---------------------------------------------------
//Includes
//---------------------------------------------------

#include "STM32_GPIO.h"
#include "stm32f103x8.h"

//---------------------------------------------------
//User Type Definition (Structures)
//---------------------------------------------------

typedef struct
{
	uint8_t 		EXTI_LineNumber;

	GPIO_TypeDef *	GPIO_Port;

	uint16_t		GPIO_Pin_Number;

	uint8_t			IVT_IRQ_Number;


}EXTI_GPIO_Mapping_t;




typedef struct
{

	EXTI_GPIO_Mapping_t EXTI_Pin;			//Specifies the EXTI GPIO Pin
											//This Parameters Must Be Set Based On @ref EXTI_define

	uint8_t EXTI_Trigger;					//Specifies the EXTI Trigger
											//This Parameters Must Be Set Based On @ref EXTI_Trigger_define

	uint8_t IRQ_EN;							//Specifies whether the Interrupt mask (in mask register and NVIC)
											//This Parameters Must Be Set Based On @ref EXTI_Mask_define

	void(*P_CallBack_Function)(void);		/*this pointer must be set with the address of
											the function you want to execute when the interrupt happen*/




}EXTI_PinConfig;





//---------------------------------------------------
//Macros Configuration References
//---------------------------------------------------



//EXTI Line Number

#define EXTI0		0U
#define EXTI1		1U
#define EXTI2		2U
#define EXTI3		3U
#define EXTI4		4U
#define EXTI5		5U
#define EXTI6		6U
#define EXTI7		7U
#define EXTI8		8U
#define EXTI9		9U
#define EXTI10		10U
#define EXTI11		11U
#define EXTI12		12U
#define EXTI13		13U
#define EXTI14		14U
#define EXTI15		15U



//---------------------------------------------------
//@ref Module REF Name define
//---------------------------------------------------


//@ref EXTI_define

#define EXTI0_PA0		(EXTI_GPIO_Mapping_t){EXTI0, GPIOA, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0_PB0		(EXTI_GPIO_Mapping_t){EXTI0, GPIOB, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0_PC0		(EXTI_GPIO_Mapping_t){EXTI0, GPIOC, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0_PD0		(EXTI_GPIO_Mapping_t){EXTI0, GPIOD, GPIO_PIN_0, EXTI0_IRQ}

#define EXTI1_PA1		(EXTI_GPIO_Mapping_t){EXTI1, GPIOA, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1_PB1		(EXTI_GPIO_Mapping_t){EXTI1, GPIOB, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1_PC1		(EXTI_GPIO_Mapping_t){EXTI1, GPIOC, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1_PD1		(EXTI_GPIO_Mapping_t){EXTI1, GPIOD, GPIO_PIN1, EXTI1_IRQ}

#define EXTI2_PA2		(EXTI_GPIO_Mapping_t){EXTI2, GPIOA, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2_PB2		(EXTI_GPIO_Mapping_t){EXTI2, GPIOB, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2_PC2		(EXTI_GPIO_Mapping_t){EXTI2, GPIOC, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2_PD2		(EXTI_GPIO_Mapping_t){EXTI2, GPIOD, GPIO_PIN_2, EXTI2_IRQ}

#define EXTI3_PA3		(EXTI_GPIO_Mapping_t){EXTI3, GPIOA, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3_PB3		(EXTI_GPIO_Mapping_t){EXTI3, GPIOB, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3_PC3		(EXTI_GPIO_Mapping_t){EXTI3, GPIOC, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3_PD3		(EXTI_GPIO_Mapping_t){EXTI3, GPIOD, GPIO_PIN_3, EXTI3_IRQ}

#define EXTI4_PA4		(EXTI_GPIO_Mapping_t){EXTI4, GPIOA, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4_PB4		(EXTI_GPIO_Mapping_t){EXTI4, GPIOB, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4_PC4		(EXTI_GPIO_Mapping_t){EXTI4, GPIOC, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4_PD4		(EXTI_GPIO_Mapping_t){EXTI4, GPIOD, GPIO_PIN_4, EXTI4_IRQ}

#define EXTI5_PA5		(EXTI_GPIO_Mapping_t){EXTI5, GPIOA, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5_PB5		(EXTI_GPIO_Mapping_t){EXTI5, GPIOB, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5_PC5		(EXTI_GPIO_Mapping_t){EXTI5, GPIOC, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5_PD5		(EXTI_GPIO_Mapping_t){EXTI5, GPIOD, GPIO_PIN_5, EXTI5_IRQ}

#define EXTI6_PA6		(EXTI_GPIO_Mapping_t){EXTI6, GPIOA, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6_PB6		(EXTI_GPIO_Mapping_t){EXTI6, GPIOB, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6_PC6		(EXTI_GPIO_Mapping_t){EXTI6, GPIOC, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6_PD6		(EXTI_GPIO_Mapping_t){EXTI6, GPIOD, GPIO_PIN_6, EXTI6_IRQ}

#define EXTI7_PA7		(EXTI_GPIO_Mapping_t){EXTI7, GPIOA, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7_PB7		(EXTI_GPIO_Mapping_t){EXTI7, GPIOB, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7_PC7		(EXTI_GPIO_Mapping_t){EXTI7, GPIOC, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7_PD7		(EXTI_GPIO_Mapping_t){EXTI7, GPIOD, GPIO_PIN_7, EXTI7_IRQ}

#define EXTI8_PA8		(EXTI_GPIO_Mapping_t){EXTI8, GPIOA, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8_PB8		(EXTI_GPIO_Mapping_t){EXTI8, GPIOB, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8_PC8		(EXTI_GPIO_Mapping_t){EXTI8, GPIOC, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8_PD8		(EXTI_GPIO_Mapping_t){EXTI8, GPIOD, GPIO_PIN_8, EXTI8_IRQ}

#define EXTI9_PA9		(EXTI_GPIO_Mapping_t){EXTI9, GPIOA, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9_PB9		(EXTI_GPIO_Mapping_t){EXTI9, GPIOB, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9_PC9		(EXTI_GPIO_Mapping_t){EXTI9, GPIOC, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9_PD9		(EXTI_GPIO_Mapping_t){EXTI9, GPIOD, GPIO_PIN_9, EXTI9_IRQ}

#define EXTI10_PA10		(EXTI_GPIO_Mapping_t){EXTI10, GPIOA, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10_PB10		(EXTI_GPIO_Mapping_t){EXTI10, GPIOB, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10_PC10		(EXTI_GPIO_Mapping_t){EXTI10, GPIOC, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10_PD10		(EXTI_GPIO_Mapping_t){EXTI10, GPIOD, GPIO_PIN_10, EXTI10_IRQ}

#define EXTI11_PA11		(EXTI_GPIO_Mapping_t){EXTI11, GPIOA, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11_PB11		(EXTI_GPIO_Mapping_t){EXTI11, GPIOB, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11_PC11 	(EXTI_GPIO_Mapping_t){EXTI11, GPIOC, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11_PD11		(EXTI_GPIO_Mapping_t){EXTI11, GPIOD, GPIO_PIN_11, EXTI11_IRQ}

#define EXTI12_PA12		(EXTI_GPIO_Mapping_t){EXTI12, GPIOA, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12_PB12		(EXTI_GPIO_Mapping_t){EXTI12, GPIOB, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12_PC12		(EXTI_GPIO_Mapping_t){EXTI12, GPIOC, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12_PD12		(EXTI_GPIO_Mapping_t){EXTI12, GPIOD, GPIO_PIN_12, EXTI12_IRQ}

#define EXTI13_PA13		(EXTI_GPIO_Mapping_t){EXTI13, GPIOA, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13_PB13		(EXTI_GPIO_Mapping_t){EXTI13, GPIOB, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13_PC13		(EXTI_GPIO_Mapping_t){EXTI13, GPIOC, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13_PD13		(EXTI_GPIO_Mapping_t){EXTI13, GPIOD, GPIO_PIN_13, EXTI13_IRQ}

#define EXTI14_PA14		(EXTI_GPIO_Mapping_t){EXTI14, GPIOA, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14_PB14		(EXTI_GPIO_Mapping_t){EXTI14, GPIOB, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14_PC14		(EXTI_GPIO_Mapping_t){EXTI14, GPIOC, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14_PD14		(EXTI_GPIO_Mapping_t){EXTI14, GPIOD, GPIO_PIN_14, EXTI14_IRQ}

#define EXTI15_PA15		(EXTI_GPIO_Mapping_t){EXTI15, GPIOA, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15_PB15		(EXTI_GPIO_Mapping_t){EXTI15, GPIOB, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15_PC15		(EXTI_GPIO_Mapping_t){EXTI15, GPIOC, GPIO_PIN_15, EXTI15_IRQ}
#define EXTI15_PD15		(EXTI_GPIO_Mapping_t){EXTI15, GPIOD, GPIO_PIN_15, EXTI15_IRQ}


//@ref EXTI_Mask_define

#define EXTI_Mask_Disable		0
#define EXTI_Mask_Enable		1


//@ref EXTI_Trigger_define

#define EXTI_Trigger_Falling				0
#define EXTI_Trigger_Rising					1
#define EXTI_Trigger_Falling_And_Rising		2

//---------------------------------------------------
//Generic Variables
//---------------------------------------------------

void (*GP_IRQ_CallBack[15])(void);

//---------------------------------------------------
//APIs Supported by "MCAL GPIO Driver"
//---------------------------------------------------


/*=======================================

 * @fn					-MCAL_EXTI_GPIO_Init
 * @brief				-this is used to initialize EXTI
 * @param[in]			-EXTI_Config set by @ref EXTI_define, EXTI_Mask_define, EXTI_Trigger_define
 * @retval				-none
 * @note					-stm32f103c8 has GPIO A, B, C, D, E Modules, but LQFP48 Package only used A, B and part of C, d
						-also mandatory to enable clock for AFIO and the corresponding GPIO

=======================================*/


void MCAL_EXTI_GPIO_Init(EXTI_PinConfig * EXTI_Config);



/*=======================================

 * @fn					-MCAL_EXTI_GPIO_DeInit
 * @brief				-Reset the EXTI Registers and NVIC corresponding IRQ Mask
 * @param[in]			-none
 * @retval				-none
 * @note					-none

=======================================*/


void MCAL_EXTI_GPIO_DeInit(void);



/*=======================================

 * @fn					-MCAL_EXTI_GPIO_Update
 * @brief				-this is used to initialize EXTI
 * @param[in]			-EXTI_Config set by @ref EXTI_define, EXTI_Mask_define, EXTI_Trigger_define
 * @retval				-none
 * @note					-stm32f103c8 has GPIO A, B, C, D, E Modules, but LQFP48 Package only used A, B and part of C, d
						-also mandatory to enable clock for AFIO and the corresponding GPIO

=======================================*/


void MCAL_EXTI_GPIO_Update(EXTI_PinConfig * EXTI_Config);








#endif /*STM32F103C8_EXTI_H_*/
