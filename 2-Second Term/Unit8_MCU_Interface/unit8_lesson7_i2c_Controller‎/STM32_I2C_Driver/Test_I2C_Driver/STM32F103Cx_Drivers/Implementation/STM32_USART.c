#include "STM32_USART.h"
#include "stm32f103x8.h"



/*
 * for transmission:
 *
 	Procedure:
	1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
	2. Program the M bit in USART_CR1 to define the word length.
	3. Program the number of stop bits in USART_CR2.
	4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
	place. Configure the DMA register as explained in multibuffer communication.
	5. Select the desired baud rate using the USART_BRR register.
	6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
	7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
	for each data to be transmitted in case of single buffer.
	8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
	that the transmission of the last frame is complete. This is required for instance when
	the USART is disabled or enters the Halt mode to avoid corrupting the last
	transmission.

 */

/*
 * for Receiving:
 *

	Procedure:
1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
2. Program the M bit in USART_CR1 to define the word length.
3. Program the number of stop bits in USART_CR2.
4. Select DMA enable (DMAR) in USART_CR3 if multibuffer communication is to take
place. Configure the DMA register as explained in multibuffer communication. STEP 3
5. Select the desired baud rate using the baud rate register USART_BRR
6. Set the RE bit USART_CR1. This enables the receiver which begins searching for a
start bit.


 * */


//Global Variables

USART_Config * GP_USART1_Config = NULL;
USART_Config * GP_USART2_Config = NULL;
USART_Config * GP_USART3_Config = NULL;


void MCAl_USART_Init(USART_TypeDef * USART_Insatant, USART_Config * USART_CFG)
{

	uint32_t Pclk = 0, BRR = 0;



	//0. Enable USART Clock

	if(USART_Insatant == USART1)
	{
		RCC_USART1_CLK_EN();
		Pclk = MCAL_RCC_GetPCLK2_Freq();
	//	Pclk = 8000000;
		GP_USART1_Config = USART_CFG ;
	}
	else if(USART_Insatant == USART2)
	{
		RCC_USART2_CLK_EN();
		Pclk = MCAL_RCC_GetPCLK1_Freq();
	}
	else if(USART_Insatant == USART3)
	{
		RCC_USART3_CLK_EN();
		Pclk = MCAL_RCC_GetPCLK1_Freq();
	}


	//1. Enable the USART by writing the UE bit in USART_CR1 register to 1.

	SET_BIT(USART_Insatant->USART_CR1, 13);


	//2. Set the RE or TE bit USART_CR1.
	switch(USART_CFG->USART_Mode)
	{
	case USART_Mode_Rx:
		SET_BIT(USART_Insatant->USART_CR1, 2);
		break;

	case USART_Mode_Tx:
		SET_BIT(USART_Insatant->USART_CR1, 3);
		break;

	case USART_Mode_Rx_Tx:
		SET_BIT(USART_Insatant->USART_CR1, 2);
		SET_BIT(USART_Insatant->USART_CR1, 3);
		break;
	}


	//3. Select the desired baud rate using the USART_BRR register.

	BRR = USART_BRR_Register(Pclk, USART_CFG->USART_BaudRate);

	USART_Insatant->USART_BRR = BRR;


	//4. Program the M bit in USART_CR1 to define the word length.

	switch(USART_CFG->USART_DataLength)
	{
	case USART_DataLength_8Bits:
		CLEAR_BIT(USART_Insatant->USART_CR1, 12);
		break;

	case USART_DataLength_9Bits:
		SET_BIT(USART_Insatant->USART_CR1, 12);
		break;
	}


	//5. Specifies the Parity bit mode

	switch(USART_CFG->USART_ParityMode)
	{
	case USART_ParityMode_Even:
		SET_BIT(USART_Insatant->USART_CR1, 10);
		CLEAR_BIT(USART_Insatant->USART_CR1, 9);
		break;

	case USART_ParityMode_Odd:
		SET_BIT(USART_Insatant->USART_CR1, 10);
		SET_BIT(USART_Insatant->USART_CR1, 9);
		break;

	case USART_ParityMode_None:
		CLEAR_BIT(USART_Insatant->USART_CR1, 10);
		break;

	}


	//6. Program the number of stop bits in USART_CR2.

	switch(USART_CFG->USART_StopBits)
	{
	case USART_StopBits_1Bit:
		USART_Insatant->USART_CR2 &= ~(0b11 << 12);
		break;

	case USART_StopBits_2Bit:
		USART_Insatant->USART_CR2 &= ~(0b01 << 12);
		break;
	}


	//7. Program the HW_FlowCTRL

	switch(USART_CFG->HW_FlowCTRL)
	{
	case USART_HW_FlowCTRL_None:
		break;

	case USART_HW_FlowCTRL_CTS:
		SET_BIT(USART_Insatant->USART_CR3, 9);
		break;

	case USART_HW_FlowCTRL_RTS:
		SET_BIT(USART_Insatant->USART_CR3, 8);
		break;

	case USART_HW_FlowCTRL_CTS_RTS:
		USART_Insatant->USART_CR3 |= (0b11<<8);
		break;
	}


	//8. Enable or Disable USART Interrupt

	if(USART_CFG->USART_IRQ_EN != USART_IRQ_EN_None)
	{
		switch(USART_CFG->USART_IRQ_EN)
		{
		case USART_IRQ_EN_TXE:
			SET_BIT(USART_Insatant->USART_CR1, 7);
			break;

		case USART_IRQ_EN_TC:
			SET_BIT(USART_Insatant->USART_CR1, 6);
			break;

		case USART_IRQ_EN_RXNE:
			SET_BIT(USART_Insatant->USART_CR1, 5);
			break;

		case USART_IRQ_EN_PE:
			SET_BIT(USART_Insatant->USART_CR1, 8);
			break;
		}

		if(USART_Insatant == USART1)
		{
			NVIC_Enable_USART1_IRQ37;
		}
		else if(USART_Insatant == USART1)
		{
			NVIC_Enable_USART2_IRQ38;
		}
		else if(USART_Insatant == USART3)
		{
			NVIC_Enable_USART3_IRQ39;
		}
	}


}




void MCAL_USART_DeInit(USART_TypeDef * USART_Insatant)
{
	if(USART_Insatant == USART1)
	{
		RCC_USART1_CLK_Reset();
		NVIC_Disable_USART1_IRQ37;
	}
	else if(USART_Insatant == USART2)
	{
		RCC_USART2_CLK_Reset();
		NVIC_Disable_USART2_IRQ38;
	}
	else if(USART_Insatant == USART3)
	{
		RCC_USART3_CLK_Reset();
		NVIC_Disable_USART3_IRQ39;
	}
}



void MCAL_USART_SendData(USART_TypeDef * USART_Insatant, USART_Config * USART_CFG, uint16_t * P_TxBuffer, enum Polling_Mechanism PollingEN)
{
	// Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
	//for each data to be transmitted in case of single buffer.

	if(PollingEN == Enable)
	{
		while(READ_BIT(USART_Insatant->USART_SR, 7) == 0);
	}

	switch(USART_CFG->USART_DataLength)
	{
	case USART_DataLength_8Bits:
		USART_Insatant->USART_DR = ((*P_TxBuffer) & (uint16_t)0x00FF);
		break;

	case USART_DataLength_9Bits:
		USART_Insatant->USART_DR = ((*P_TxBuffer) & 0x01FF);
		break;


	}



}



void MCAL_USART_Wait_TC(USART_TypeDef * USART_Insatant)
{
	//wait until TC == 1

	while(READ_BIT(USART_Insatant->USART_SR, 6) == 0);

}


void MCAL_USART_ReceiveData(USART_TypeDef * USART_Insatant, USART_Config * USART_CFG, uint16_t * P_TxBuffer, enum Polling_Mechanism PollingEN)
{
	if(PollingEN == Enable)
	{
		while(READ_BIT(USART_Insatant->USART_SR, 5) == 0);
	}

	switch(USART_CFG->USART_DataLength)
	{
	case USART_DataLength_8Bits:

		if(USART_CFG->USART_ParityMode != USART_ParityMode_None)
		{
			(*P_TxBuffer) = USART_Insatant->USART_DR & (uint16_t)(0x007F);
		}
		else
		{
			(*P_TxBuffer) = USART_Insatant->USART_DR & (uint16_t)(0x00FF);
		}

		break;

	case USART_DataLength_9Bits:

		if(USART_CFG->USART_ParityMode != USART_ParityMode_None)
		{
			(*P_TxBuffer) = USART_Insatant->USART_DR & (uint16_t)(0x00FF);
		}
		else
		{
			(*P_TxBuffer) = USART_Insatant->USART_DR;
		}

		break;


	}
}


void MCAL_USART_GPIO_SetPins(USART_TypeDef * USART_Insatant, USART_Config * USART_CFG)
{
	GPIO_PinConfig_t PinCFG;

	if(USART_Insatant == USART1)
	{
		//PA.8 USART1_CK

		//PA.9 USART1_TX

		PinCFG.GPIO_PinNumber = GPIO_PIN_9;
		PinCFG.GPIO_PinMode   = GPIO_MODE_AFIO_OUTPUT_PUSH_PULL;
		PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOA, &PinCFG);


		//PA.10 USART1_RX

		PinCFG.GPIO_PinNumber = GPIO_PIN_10;
		PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;
		MCAL_GPIO_Init(GPIOA, &PinCFG);


		//PA.11 USART1_CTS



		//PA.12 USART1_RTS



		switch(USART_CFG->HW_FlowCTRL)
		{
		case USART_HW_FlowCTRL_CTS:

			PinCFG.GPIO_PinNumber = GPIO_PIN_11;
			PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			break;

		case USART_HW_FlowCTRL_RTS:

			PinCFG.GPIO_PinNumber = GPIO_PIN_12;
			PinCFG.GPIO_PinMode   = GPIO_MODE_AFIO_OUTPUT_PUSH_PULL;
			PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			break;

		case USART_HW_FlowCTRL_CTS_RTS:

			PinCFG.GPIO_PinNumber = GPIO_PIN_11;
			PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			PinCFG.GPIO_PinNumber = GPIO_PIN_12;
			PinCFG.GPIO_PinMode   = GPIO_MODE_AFIO_OUTPUT_PUSH_PULL;
			PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			break;

		}


	}

	if(USART_Insatant == USART2)
	{
		//PA.0 USART2_CTS

		//PA.1 USART2_RTS

		//PA.2 USART2_TX

		PinCFG.GPIO_PinNumber = GPIO_PIN_2;
		PinCFG.GPIO_PinMode   = GPIO_MODE_AFIO_OUTPUT_PUSH_PULL;
		PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOA, &PinCFG);

		//PA.3 USART2_RX

		PinCFG.GPIO_PinNumber = GPIO_PIN_3;
		PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;
		MCAL_GPIO_Init(GPIOA, &PinCFG);

		//PA.4 USART2_CK


		switch(USART_CFG->HW_FlowCTRL)
		{
		case USART_HW_FlowCTRL_CTS:

			PinCFG.GPIO_PinNumber = GPIO_PIN_0;
			PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &PinCFG);


			break;

		case USART_HW_FlowCTRL_RTS:

			PinCFG.GPIO_PinNumber = GPIO_PIN_1;
			PinCFG.GPIO_PinMode   = GPIO_MODE_AFIO_OUTPUT_PUSH_PULL;
			PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinCFG);
			break;

		case USART_HW_FlowCTRL_CTS_RTS:

			PinCFG.GPIO_PinNumber = GPIO_PIN_0;
			PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOA, &PinCFG);


			PinCFG.GPIO_PinNumber = GPIO_PIN_1;
			PinCFG.GPIO_PinMode   = GPIO_MODE_AFIO_OUTPUT_PUSH_PULL;
			PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PinCFG);

			break;

		}


	}

	if(USART_Insatant == USART3)
	{
		//PB.10 USART3_TX

		PinCFG.GPIO_PinNumber = GPIO_PIN_10;
		PinCFG.GPIO_PinMode   = GPIO_MODE_AFIO_OUTPUT_PUSH_PULL;
		PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOB, &PinCFG);

		//PB.11 USART3_RX

		PinCFG.GPIO_PinNumber = GPIO_PIN_11;
		PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;
		MCAL_GPIO_Init(GPIOB, &PinCFG);

		//PB.12 USART3_CK

		//PB.13 USART3_CTS

		//PB.14 USART3_RTS


		switch(USART_CFG->HW_FlowCTRL)
		{
		case USART_HW_FlowCTRL_CTS:

			PinCFG.GPIO_PinNumber = GPIO_PIN_13;
			PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOB, &PinCFG);


			break;

		case USART_HW_FlowCTRL_RTS:

			PinCFG.GPIO_PinNumber = GPIO_PIN_14;
			PinCFG.GPIO_PinMode   = GPIO_MODE_AFIO_OUTPUT_PUSH_PULL;
			PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB, &PinCFG);

			break;

		case USART_HW_FlowCTRL_CTS_RTS:

			PinCFG.GPIO_PinNumber = GPIO_PIN_13;
			PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;
			MCAL_GPIO_Init(GPIOB, &PinCFG);


			PinCFG.GPIO_PinNumber = GPIO_PIN_14;
			PinCFG.GPIO_PinMode   = GPIO_MODE_AFIO_OUTPUT_PUSH_PULL;
			PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB, &PinCFG);


			break;

		}

	}
}




//ISR

void USART1_IRQHandler(void)
{
	GP_USART1_Config->P_IRQ_CallBack();
}


void USART2_IRQHandler(void)
{
	GP_USART2_Config->P_IRQ_CallBack();
}


void USART3_IRQHandler(void)
{
	GP_USART3_Config->P_IRQ_CallBack();
}



