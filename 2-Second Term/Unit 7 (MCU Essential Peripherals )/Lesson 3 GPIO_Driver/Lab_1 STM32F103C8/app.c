
#include "Platform_Types.h"
#include"STM32_GPIO.h"
#include"stm32f103x8.h"

void Clock_Init()
{
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
}



int main()
{

	Clock_Init();

	GPIO_PinConfig_t PinCFG;


	//PA.1 input floating
    //default input floating

	PinCFG.GPIO_PinNumber = GPIO_PIN_1;
	PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;

	MCAL_GPIO_Init(GPIOA, &PinCFG);

	//PB.1 output push pull 2 MHz
	PinCFG.GPIO_PinNumber = GPIO_PIN_1;
	PinCFG.GPIO_PinMode   = GPIO_MODE_OUTPUT_PUSH_PULL;
	PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_2MHz;

	MCAL_GPIO_Init(GPIOB, &PinCFG);


    //PA.13 input floating
	PinCFG.GPIO_PinNumber = GPIO_PIN_13;
	PinCFG.GPIO_PinMode   = GPIO_MODE_INPUT_FLOATING;

	MCAL_GPIO_Init(GPIOA, &PinCFG);

    //PB.13 output push pull 2 MHz
    PinCFG.GPIO_PinNumber = GPIO_PIN_13;
	PinCFG.GPIO_PinMode   = GPIO_MODE_OUTPUT_PUSH_PULL;
	PinCFG.GPIO_PinSpeed  = GPIO_OUTPUT_SPEED_2MHz;

	MCAL_GPIO_Init(GPIOB, &PinCFG);

    vuint32 i;

    while(1)
    {

        if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
        {
           MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);

           while (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0);

        }

        if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1)
        {
            MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);

            for(i = 0; i < 500; i++);
        }


    }


    return 0;
}
