#include"STM32f10C8_EXTI.h"



void NVIC_Enable(uint8_t EXTI_LineNumber)
{
	switch(EXTI_LineNumber)
	{
	case 0:
		NVIC_Enable_EXTI0_IRQ6;
		break;

	case 1:
		NVIC_Enable_EXTI1_IRQ7;
		break;

	case 2:
		NVIC_Enable_EXTI2_IRQ8;
		break;

	case 3:
		NVIC_Enable_EXTI3_IRQ9;
		break;

	case 4:
		NVIC_Enable_EXTI4_IRQ10;
		break;

	case 5 ... 9:
	NVIC_Enable_EXTI9_5_IRQ23;
	break;

	case 10 ... 15:
	NVIC_Enable_EXTI15_10_IRQ40;
	break;


	}
}

void NVIC_Disable(uint8_t EXTI_LineNumber)
{
	switch(EXTI_LineNumber)
	{
	case 0:
		NVIC_Disable_EXTI0_IRQ6;
		break;

	case 1:
		NVIC_Disable_EXTI1_IRQ7;
		break;

	case 2:
		NVIC_Disable_EXTI2_IRQ8;
		break;

	case 3:
		NVIC_Disable_EXTI3_IRQ9;
		break;

	case 4:
		NVIC_Disable_EXTI4_IRQ10;
		break;

	case 5 ... 9:
	NVIC_Disable_EXTI9_5_IRQ23;
	break;

	case 10 ... 15:
	NVIC_Disable_EXTI15_10_IRQ40;
	break;


	}
}


void MCAL_EXTI_GPIO_Init(EXTI_PinConfig * EXTI_Config)
{
	//1- configure GPIO to be AF Floating Input
	GPIO_PinConfig_t PinCFG;

	PinCFG.GPIO_PinNumber = EXTI_Config->EXTI_Pin.GPIO_Pin_Number;
	PinCFG.GPIO_PinMode   = GPIO_MODE_AFIO_INPUT;
	MCAL_GPIO_Init(EXTI_Config->EXTI_Pin.GPIO_Port, &PinCFG);


	/*__________________________________________________________________________________________*/

	//2- map the pin to it's corresponding EXTI line

	volatile uint8_t AFIO_EXTICR_index    = ((uint32_t)(EXTI_Config->EXTI_Pin.EXTI_LineNumber) / 4);

	volatile uint8_t AFIO_EXTICR_Position = ((uint32_t)(EXTI_Config->EXTI_Pin.GPIO_Pin_Number) % 4) * 4;

	//clear 4 bit
	AFIO -> AFIO_EXTICR[AFIO_EXTICR_index] &= ~ (0xf << AFIO_EXTICR_Position);


	if(EXTI_Config->EXTI_Pin.GPIO_Port == GPIOA)
	{
		AFIO -> AFIO_EXTICR[AFIO_EXTICR_index] = 0x0 << AFIO_EXTICR_Position;
	}
	else if(EXTI_Config->EXTI_Pin.GPIO_Port == GPIOB)
	{
		AFIO -> AFIO_EXTICR[AFIO_EXTICR_index] = 0x1 << AFIO_EXTICR_Position;
	}
	else if(EXTI_Config->EXTI_Pin.GPIO_Port == GPIOC)
	{
		AFIO -> AFIO_EXTICR[AFIO_EXTICR_index] = 0x2 << AFIO_EXTICR_Position;
	}
	else if(EXTI_Config->EXTI_Pin.GPIO_Port == GPIOD)
	{
		AFIO -> AFIO_EXTICR[AFIO_EXTICR_index] = 0x3 << AFIO_EXTICR_Position;
	}


	/*__________________________________________________________________________________________*/

	//3- configure the trigger signal

	//clear EXTI_FTSR
	EXTI -> EXTI_FTSR = 0x00000000;

	//clear EXTI_RTSR
	EXTI -> EXTI_RTSR = 0x00000000;

	switch(EXTI_Config -> EXTI_Trigger)
	{
	case EXTI_Trigger_Falling:

		SET_BIT(EXTI -> EXTI_FTSR, EXTI_Config->EXTI_Pin.EXTI_LineNumber);
		break;

	case EXTI_Trigger_Rising:

		SET_BIT(EXTI -> EXTI_RTSR, EXTI_Config->EXTI_Pin.EXTI_LineNumber);
		break;

	case EXTI_Trigger_Falling_And_Rising:
		SET_BIT(EXTI -> EXTI_FTSR, EXTI_Config->EXTI_Pin.EXTI_LineNumber);
		SET_BIT(EXTI -> EXTI_RTSR, EXTI_Config->EXTI_Pin.EXTI_LineNumber);
		break;
	}


	/*__________________________________________________________________________________________*/

	//4- update IRQ Handler CallBack
	GP_IRQ_CallBack[EXTI_Config->EXTI_Pin.EXTI_LineNumber] = EXTI_Config->P_CallBack_Function;


	/*__________________________________________________________________________________________*/

	//5- Enable mask and IRQ in NVIC

	switch(EXTI_Config -> IRQ_EN)
	{
	case EXTI_Mask_Disable:

		CLEAR_BIT(EXTI->EXTI_IMR, EXTI_Config->EXTI_Pin.EXTI_LineNumber);
		NVIC_Disable(EXTI_Config->EXTI_Pin.EXTI_LineNumber);

		break;

	case EXTI_Mask_Enable:

		SET_BIT(EXTI->EXTI_IMR, EXTI_Config->EXTI_Pin.EXTI_LineNumber);
		NVIC_Enable(EXTI_Config->EXTI_Pin.EXTI_LineNumber);

		break;
	}



}




void MCAL_EXTI_GPIO_Update(EXTI_PinConfig * EXTI_Config)
{

	MCAL_EXTI_GPIO_Init(EXTI_Config);

}






void MCAL_EXTI_GPIO_DeInit(void)
{
	//reset EXTI registers

	EXTI->EXTI_IMR 		= 0x00000000;
	EXTI-> EXTI_EMR		= 0x00000000;
	EXTI->EXTI_RTSR 	= 0x00000000;
	EXTI->EXTI_FTSR 	= 0x00000000;
	EXTI->EXTI_SWIER 	= 0x00000000;
	EXTI->EXTI_PR 		= 0xFFFFFFFF;	//rc_w1	>> read - clear by write 1


	//reset IRQ Mask in NVIC

	NVIC_Disable_EXTI0_IRQ6;
	NVIC_Disable_EXTI1_IRQ7;
	NVIC_Disable_EXTI2_IRQ8;
	NVIC_Disable_EXTI3_IRQ9;
	NVIC_Disable_EXTI4_IRQ10;
	NVIC_Disable_EXTI9_5_IRQ23;
	NVIC_Disable_EXTI15_10_IRQ40;

}


/*********ISR***********/


void EXTI0_IRQHandler(void)
{
	//clear padding status to prevent entering in infinite loop of calling the ISR
	EXTI->EXTI_PR |= 1<<0 ;

	//Call IRQ_CallBack_Function
	GP_IRQ_CallBack[0]();

}

void EXTI1_IRQHandler(void)
{
	//clear padding status to prevent entering in infinite loop of calling the ISR
	EXTI->EXTI_PR |= 1<<1 ;

	//Call IRQ_CallBack_Function
	GP_IRQ_CallBack[1]();

}


void EXTI2_IRQHandler(void)
{
	//clear padding status to prevent entering in infinite loop of calling the ISR
	EXTI->EXTI_PR |= 1<<2 ;

	//Call IRQ_CallBack_Function
	GP_IRQ_CallBack[2]();

}

void EXTI3_IRQHandler(void)
{
	//clear padding status to prevent entering in infinite loop of calling the ISR
	EXTI->EXTI_PR |= 1<<3 ;

	//Call IRQ_CallBack_Function
	GP_IRQ_CallBack[3]();

}

void EXTI4_IRQHandler(void)
{
	//clear padding status to prevent entering in infinite loop of calling the ISR
	EXTI->EXTI_PR |= 1<<4 ;

	//Call IRQ_CallBack_Function
	GP_IRQ_CallBack[4]();

}


void EXTI9_5_IRQHandler(void)
{

	if(READ_BIT(EXTI->EXTI_PR, 5) == 1 )
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<5;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[5]();

	}
	if(READ_BIT(EXTI->EXTI_PR, 6) == 1)
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<6;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[6]();
	}
	if(READ_BIT(EXTI->EXTI_PR, 7) == 1)
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<7;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[7]();
	}
	if(READ_BIT(EXTI->EXTI_PR, 8) == 1)
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<8;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[8]();
	}
	if(READ_BIT(EXTI->EXTI_PR, 9) == 1)
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<9;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[9]();
	}


}


void EXTI15_10_IRQHandler(void)
{
	if(READ_BIT(EXTI->EXTI_PR, 10) == 1 )
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<10;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[10]();

	}
	if(READ_BIT(EXTI->EXTI_PR, 11) == 1)
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<11;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[11]();
	}
	if(READ_BIT(EXTI->EXTI_PR, 12) == 1)
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<12;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[12]();

	}
	if(READ_BIT(EXTI->EXTI_PR, 13) == 1)
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<13;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[13]();

	}
	if(READ_BIT(EXTI->EXTI_PR, 14) == 1)
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<14;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[14]();
	}
	if(READ_BIT(EXTI->EXTI_PR, 15) == 1)
	{
		//clear padding status to prevent entering in infinite loop of calling the ISR
		EXTI->EXTI_PR |= 1<<15;

		//Call IRQ_CallBack_Function
		GP_IRQ_CallBack[15]();

	}


}





















