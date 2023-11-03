#ifndef STM32_RCC_H_
#define STM32_RCC_H_

//Includes

#include "stm32f103x8.h"
#include "STM32_GPIO.h"

#define HSI_RC_CLK		(uint32_t)8000000
#define HSE_RC_CLK		(uint32_t)16000000
#define PLL_RC_CLK		(uint32_t)16000000



uint32_t MCAL_RCC_GetSYSCLK_Freq(void);
uint32_t MCAL_RCC_GetHCLK_Freq(void);
uint32_t MCAL_RCC_GetPCLK2_Freq(void);
uint32_t MCAL_RCC_GetPCLK1_Freq(void);


#endif /*STM32_RCC_H_*/
