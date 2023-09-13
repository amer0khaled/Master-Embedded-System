
#include "Platform_Types.h"


#define SET_BIT(REG, BIT)     REG |= (1U<<BIT)
#define CLEAR_BIT(REG, BIT)   REG &= ~(1U<<BIT)
#define READ_BIT(REG, BIT)    ((REG & (1U<<BIT))>>BIT)
#define TOGGLE_BIT(REG, BIT)  REG ^= (1U<<BIT) 


#define RCC_BASE 0x40021000
#define RCC_APB2ENR *((vuint32 *)(RCC_BASE +  0x18))


#define GPIOA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00


#define GPIOA_CRL *((vuint32 *)(GPIOA_BASE + 0x00))
#define GPIOA_CRH *((vuint32 *)(GPIOA_BASE + 0x04))
#define GPIOA_IDR *((vuint32 *)(GPIOA_BASE + 0x08))
#define GPIOA_ODR *((vuint32 *)(GPIOA_BASE + 0x0c))

 
#define GPIOB_CRL *((vuint32 *)(GPIOB_BASE + 0x00))
#define GPIOB_CRH *((vuint32 *)(GPIOB_BASE + 0x04))
#define GPIOB_IDR *((vuint32 *)(GPIOB_BASE + 0x08))
#define GPIOB_ODR *((vuint32 *)(GPIOB_BASE + 0x0c))


void Clock_Init(void)
{
    SET_BIT(RCC_APB2ENR, 2);
    SET_BIT(RCC_APB2ENR, 3);
}

int main()
{	
	
	Clock_Init();
	
    //PA.1 input floating
    //default input floating

    //PB.1 output push pull 2 MHz
    SET_BIT(GPIOB_CRL, 5);
    CLEAR_BIT(GPIOB_CRL, 6);
    
    //PA.13 input floating
    //default input floating

    //PB.13 output push pull 2 MHz
    SET_BIT(GPIOB_CRH, 21);
    CLEAR_BIT(GPIOB_CRH, 22);

    vuint32 i;

    while(1)
    {
        if(READ_BIT(GPIOA_IDR, 1) == 0)
        {   
           TOGGLE_BIT(GPIOB_ODR, 1);

           while (READ_BIT(GPIOA_IDR, 1) == 0);
          
        }

        if(READ_BIT(GPIOA_IDR, 13) == 1)
        {
            TOGGLE_BIT(GPIOB_ODR, 13);

            for(i = 0; i < 500; i++);
        }

    }


    return 0;
}