
#include"STM32_GPIO.h"


uint8_t Get_Position(uint16_t PinNumber)
{	

	volatile uint8_t Start_Position;

	switch(PinNumber)
	{	

	case GPIO_PIN_0:
	case GPIO_PIN_8:

		Start_Position = 0;
		break;

	case GPIO_PIN_1:
	case GPIO_PIN_9:

		Start_Position = 4;
		break;

	case GPIO_PIN_2:
	case GPIO_PIN_10:

		Start_Position = 8;
		break;


	case GPIO_PIN_3:
	case GPIO_PIN_11:

		Start_Position = 12;
		break;

	case GPIO_PIN_4:
	case GPIO_PIN_12:

		Start_Position = 16;
		break;

	case GPIO_PIN_5:
	case GPIO_PIN_13:

		Start_Position = 20;
		break;

	case GPIO_PIN_6:
	case GPIO_PIN_14:

		Start_Position = 24;
		break;

	case GPIO_PIN_7:
	case GPIO_PIN_15:

		Start_Position = 28;
		break;

	case GPIO_PIN_All:
		Start_Position = 0;
		break;

	}

	return  Start_Position;
}

/*=======================================

 * @fn				-MCAL_GPIO_Init
 * @brief			-initializes GPIOx PINy according to the specified parameters int the PinConfig
 * @param[in]		-GPIO_Instant: it can be the base address of any GPIO on the bus system (A..E depending on device used)
 * @param[in]		-PinConfig: pointer to the GPIO_PinConfig_t structure that contains the configuration information for the specified GPIO PIN
 * @retval			-none
 * @note				-stm32f103c8 has GPIO A, B, C, D, E Modules, but LQFP48 Package only used A, B and part of C, d


=======================================*/

void MCAL_GPIO_Init(GPIO_TypeDef *GPIO_Instant, GPIO_PinConfig_t *PinConfig)
{
	volatile uint32_t * GPIO_ConfigReg = 0;
	volatile uint8_t Start_Position    = Get_Position(PinConfig->GPIO_PinNumber);

	if(PinConfig->GPIO_PinNumber > GPIO_PIN_7)
	{
		GPIO_ConfigReg = (uint32_t *) &(GPIO_Instant->GPIOx_CRH);
	}
	else if(PinConfig->GPIO_PinNumber < GPIO_PIN_8)
	{
		GPIO_ConfigReg = (uint32_t *) &(GPIO_Instant->GPIOx_CRL);
	}


	//clear CNF and MODE at configuration register
	//configure MODE if PIN is input

	* GPIO_ConfigReg &= ~(0xF << Start_Position);



	//configure CNF if PIN is output or input
	switch(PinConfig->GPIO_PinMode)
	{
	case GPIO_MODE_INPUT_FLOATING:
	case GPIO_MODE_AFIO_INPUT:
	case GPIO_MODE_OUTPUT_OPEN_DRAIN:

		SET_BIT(*GPIO_ConfigReg, (Start_Position+2));
		break;

	case GPIO_MODE_INPUT_PULL_UP:
	case GPIO_MODE_INPUT_PULL_DOWN:

		SET_BIT(*GPIO_ConfigReg, (Start_Position+3));

		//according to Table 20. Port bit configuration table p.161
		if(PinConfig->GPIO_PinMode == GPIO_MODE_INPUT_PULL_UP)
		{
			SET_BIT(GPIO_Instant->GPIOx_ODR, PinConfig->GPIO_PinNumber);
		}
		else
		{
			CLEAR_BIT(GPIO_Instant->GPIOx_ODR, PinConfig->GPIO_PinNumber);
		}

		break;


	case GPIO_MODE_OUTPUT_PUSH_PULL:
	case GPIO_MODE_ANALOG:

		//CLEAR_BIT(GPIO_Instant->GPIO_ConfigReg, position+2);
		//CLEAR_BIT(GPIO_Instant->GPIO_ConfigReg, position+3);
		//Already CNF Cleared
		break;

	case GPIO_MODE_AFIO_OUTPUT_PUSH_PULL:

		SET_BIT(*GPIO_ConfigReg, (Start_Position+3));
		break;

	case GPIO_MODE_AFIO_OUTPUT_OPEN_DRAIN:

		SET_BIT(*GPIO_ConfigReg, (Start_Position+2));
		SET_BIT(*GPIO_ConfigReg, (Start_Position+3));
		break;


	}


	//if pin is output
	if( (PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_OPEN_DRAIN) || (PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_PUSH_PULL) || (PinConfig->GPIO_PinMode == GPIO_MODE_AFIO_OUTPUT_PUSH_PULL) || (PinConfig->GPIO_PinMode == GPIO_MODE_AFIO_OUTPUT_OPEN_DRAIN) )
	{
		//configure MODE if PIN is output
		switch(PinConfig->GPIO_PinSpeed)
		{
		case GPIO_OUTPUT_SPEED_10MHz:
			SET_BIT(*GPIO_ConfigReg, Start_Position);
			break;

		case GPIO_OUTPUT_SPEED_2MHz:
			SET_BIT(*GPIO_ConfigReg, (Start_Position+1));
			break;

		case GPIO_OUTPUT_SPEED_50MHz:
			SET_BIT(*GPIO_ConfigReg, Start_Position);
			SET_BIT(*GPIO_ConfigReg, (Start_Position+1));
			break;
		}
	}


}


/*=======================================

 * @fn				-MCAL_GPIO_DeInit
 * @brief			-Resets All GPIO Registers
 * @param[in]		-GPIO_Instant: it can be the base address of any GPIO on the bus system (A..E depending on device used)
 * @retval			-none
 * @note				-none


=======================================*/

void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIO_Instant)
{	
	/*
	GPIO_Instant  	-> GPIOx_CRL = 0x44444444;
	GPIO_Instant 	-> GPIOx_CRH = 0x44444444;
	//GPIO_Instant 	-> GPIOx_IDR = (Read Only);
	GPIO_Instant 	-> GPIOx_ODR = 0x00000000;
	GPIO_Instant 	-> GPIOx_BSRR = 0x00000000;
	GPIO_Instant 	-> GPIOx_BRR = 0x00000000;
	GPIO_Instant 	-> GPIOx_LCKR = 0x00000000;
	 */


	//or you can use the reset controller

	if(GPIO_Instant == GPIOA)
	{
		SET_BIT(RCC -> RCC_APB2RSTR, 2);
		CLEAR_BIT(RCC -> RCC_APB2RSTR, 2);
	}
	else if(GPIO_Instant == GPIOB)
	{
		SET_BIT(RCC -> RCC_APB2RSTR, 3);
		CLEAR_BIT(RCC -> RCC_APB2RSTR, 3);
	}
	else if(GPIO_Instant == GPIOC)
	{
		SET_BIT(RCC -> RCC_APB2RSTR, 4);
		CLEAR_BIT(RCC -> RCC_APB2RSTR, 4);
	}
	else if(GPIO_Instant == GPIOD)
	{
		SET_BIT(RCC -> RCC_APB2RSTR, 5);
		CLEAR_BIT(RCC -> RCC_APB2RSTR, 5);
	}
	else if(GPIO_Instant == GPIOE)
	{
		SET_BIT(RCC -> RCC_APB2RSTR, 6);
		CLEAR_BIT(RCC -> RCC_APB2RSTR, 6);
	}


}


/*=======================================

 * @fn				-MCAL_GPIO_ReadPin
 * @brief			-Reads Available Data on specific PIN
 * @param[in]		-GPIO_Instant: it can be the base address of any GPIO on the bus system (A..E depending on device used)
 * @param[in]		-PinNumber: set pin number according to @ref GPIO_PINS_define
 * @retval			-the input data on the pin according to @ref GPIO_PIN_State
 * @note				-none


=======================================*/

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIO_Instant, uint16_t PinNumber)
{
	return READ_BIT(GPIO_Instant -> GPIOx_IDR, PinNumber);
}



/*=======================================

 * @fn				-MCAL_GPIO_ReadPort
 * @brief			-Reads Available Data on specific port
 * @param[in]		-GPIO_Instant: it can be the base address of any GPIO on the bus system (A..E depending on device used)
 * @retval			-the input data on the port
 * @note				-none


=======================================*/

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIO_Instant)
{
	return READ_PORT(GPIO_Instant -> GPIOx_IDR);
}



/*=======================================

 * @fn				-MCAL_GPIO_WritePin
 * @brief			-Write Data on specific PIN
 * @param[in]		-GPIO_Instant: it can be the base address of any GPIO on the bus system (A..E depending on device used)
 * @param[in]		-PinNumber: set pin number according to @ref GPIO_PINS_define
 * @param[in]		-Data: the value that will be written to the pin
 * @retval			-none
 * @note				-none


=======================================*/

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIO_Instant, uint16_t PinNumber, uint8_t Data)
{
	if(Data >= GPIO_PIN_STATE_TRUE)
	{
		SET_BIT(GPIO_Instant -> GPIOx_ODR, PinNumber);

		//or

		//BSy: Port x Set bit y (y= 0 .. 15)
		//These bits are write-only and can be accessed in Word mode only.
		//0: No action on the corresponding ODRx bit
		//1: Set the corresponding ODRx bit

		//SET_BIT(GPIO_Instant -> GPIOx_BSRR, (uint32_t)PinNumber);

	}
	else if(Data <= GPIO_PIN_STATE_FALSE)
	{
		CLEAR_BIT(GPIO_Instant -> GPIOx_ODR, PinNumber);

		//or

		//BRy: Port x Reset bit y (y= 0 .. 15)
		//These bits are write-only and can be accessed in Word mode only.
		//0: No action on the corresponding ODRx bit
		//1: Reset the corresponding ODRx bit

		//SET_BIT(GPIO_Instant -> GPIOx_BRR, (uint32_t)PinNumber);

	}
}



/*=======================================

 * @fn				-MCAL_GPIO_WritePort
 * @brief			-Write Data on specific Port
 * @param[in]		-GPIO_Instant: it can be the base address of any GPIO on the bus system (A..E depending on device used)
 * @param[in]		-Data: the value that will be written to the port
 * @retval			-none
 * @note				-none


=======================================*/

void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIO_Instant, uint16_t Data)
{
	GPIO_Instant -> GPIOx_ODR = (uint32_t)Data;
}



void MCAL_GPIO_WriteLowPort(GPIO_TypeDef *GPIO_Instant, uint8_t Data)
{
	//clear low port
	(GPIO_Instant -> GPIOx_ODR) &= ~(0x00FF);

	//write data
	(GPIO_Instant -> GPIOx_ODR) |= Data;

}

void MCAL_GPIO_WriteHihgPort(GPIO_TypeDef *GPIO_Instant, uint16_t Data)
{
	//clear high port
	(GPIO_Instant -> GPIOx_ODR) &= ~(0xFF00);

	//write data
	(GPIO_Instant -> GPIOx_ODR) |= (Data << 8);

}


void MCAL_GPIO_Write_Nibble(GPIO_TypeDef *GPIO_Instant, uint8_t NibbleNumber, uint32_t Data)
{
	Data &= ~(0xFFF0);

	switch(NibbleNumber)
	{
	case 0:
		(GPIO_Instant -> GPIOx_ODR) |= (Data);
		break;

	case 1:
		(GPIO_Instant -> GPIOx_ODR) |= (Data << 4);
		break;

	case 2:
		(GPIO_Instant -> GPIOx_ODR) |= (Data << 8);
		break;

	case 3:
		(GPIO_Instant -> GPIOx_ODR) |= (Data << 12);
		break;

	}
}


/*=======================================

 * @fn				-MCAL_GPIO_TogglePin
 * @brief			-toggle Data on specific pin
 * @param[in]		-GPIO_Instant: it can be the base address of any GPIO on the bus system (A..E depending on device used)
 * @param[in]		-PinNumber: set pin number according to @ref GPIO_PINS_define
 * @retval			-none
 * @note				-none


=======================================*/

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIO_Instant, uint16_t PinNumber)
{
	TOGGLE_BIT(GPIO_Instant -> GPIOx_ODR, PinNumber);
}



/*=======================================

 * @fn				-MCAL_GPIO_TogglePort
 * @brief			-toggle Data on specific port
 * @param[in]		-GPIO_Instant: it can be the base address of any GPIO on the bus system (A..E depending on device used)
 * @retval			-none
 * @note				-none


=======================================*/

void MCAL_GPIO_TogglePort(GPIO_TypeDef *GPIO_Instant)
{
	TOGGLE_PORT(GPIO_Instant -> GPIOx_ODR);
}


/*=======================================

 * @fn				-MCAL_GPIO_LoackPin
 * @brief			-freeze the data on specific pin untill reset the peripheral
 * @param[in]		-GPIO_Instant: it can be the base address of any GPIO on the bus system (A..E depending on device used)
 * @param[in]		-PinNumber: set pin number according to @ref GPIO_PINS_define
 * @retval			-successful or failed loack according to @ref GPIO_LOACK_PIN_Status
 * @note				-none


=======================================*/


uint8_t LOCK_Key_Sequence(GPIO_TypeDef *GPIO_Instant)
{	
	volatile uint8_t temp;

	SET_BIT(GPIO_Instant -> GPIOx_LCKR, 16);
	CLEAR_BIT(GPIO_Instant -> GPIOx_LCKR, 16);
	SET_BIT(GPIO_Instant -> GPIOx_LCKR, 16);

	if(READ_BIT(GPIO_Instant -> GPIOx_LCKR, 16) == 0)
	{
		temp = GPIO_SUCCESSFUL_LOACK;
	}
	else
	{
		temp = GPIO_FAILED_LOACK;
	}

	if((READ_BIT(GPIO_Instant -> GPIOx_LCKR, 16) == 1)&&(temp == GPIO_SUCCESSFUL_LOACK))
	{
		temp = GPIO_SUCCESSFUL_LOACK;
	}
	else
	{
		temp = GPIO_FAILED_LOACK;
	}

	return temp;

}



uint8_t MCAL_GPIO_LoackPin(GPIO_TypeDef *GPIO_Instant, uint16_t PinNumber)
{
	SET_BIT(GPIO_Instant -> GPIOx_LCKR, PinNumber);

	if(LOCK_Key_Sequence(GPIO_Instant) == GPIO_SUCCESSFUL_LOACK)
	{
		return GPIO_SUCCESSFUL_LOACK;
	}
	else
	{
		return GPIO_FAILED_LOACK;
	}

}
