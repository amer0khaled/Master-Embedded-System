#include "STM32_RCC.h"
#include "stm32f103x8.h"

const uint8_t APB1_Prescaler [] = {0, 0, 0, 0, 1, 2, 3, 4};
const uint8_t APB2_Prescaler [] = {0, 0, 0, 0, 1, 2, 3, 4};
const uint8_t AHB_Prescaler  [] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

uint32_t MCAL_RCC_GetSYSCLK_Freq(void)
{
	uint32_t SYS_CLK = 0;

	//consider that
	switch((RCC->RCC_CFGR >> 2) & 0b11)
	{
	case 0:
		SYS_CLK = HSI_RC_CLK;
		break;

	case 1:
		SYS_CLK = HSE_RC_CLK;
		break;

	case 2:
		SYS_CLK = PLL_RC_CLK;
		break;
	}

	return SYS_CLK;
}


uint32_t MCAL_RCC_GetHCLK_Freq(void)
{
	return (MCAL_RCC_GetSYSCLK_Freq() >> AHB_Prescaler[(RCC->RCC_CFGR >> 4) & 0xF]);
}


uint32_t MCAL_RCC_GetPCLK2_Freq(void)
{
	return (MCAL_RCC_GetHCLK_Freq() >> APB2_Prescaler[(RCC->RCC_CFGR >> 11) & 0b111]);
}


uint32_t MCAL_RCC_GetPCLK1_Freq(void)
{
	return (MCAL_RCC_GetHCLK_Freq() >> APB1_Prescaler[(RCC->RCC_CFGR >> 8) & 0b111]);
}
