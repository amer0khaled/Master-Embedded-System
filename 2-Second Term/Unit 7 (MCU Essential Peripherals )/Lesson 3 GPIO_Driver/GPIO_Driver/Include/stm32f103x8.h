#ifndef STM32F103X8_H_
#define STM32F103X8_H_
//---------------------------------------------------
//Includes
//---------------------------------------------------

#include<stdlib.h>
#include<stdint.h>


//---------------------------------------------------
//Base Addresses for Memories
//---------------------------------------------------

#define Flash_Memory_Base 					0x08000000
#define System_Memory_Base 					0x1FFFF000
#define SRAM_Memory_Base 					0x20000000
#define Peripherals_Base 					0x40000000
#define CortexM3_Internal_Peripherals_Base 	0xE0000000



//---------------------------------------------------
//Base Addresses for AHB Peripherals
//---------------------------------------------------

#define RCC_BASE 0x40021000


//---------------------------------------------------
//Base Addresses for APB2 Peripherals 
//---------------------------------------------------

//GPIO 
//A, B are fully included in LQFP48 Package

#define GPIOA_BASE 		0x40010800
#define GPIOB_BASE 		0x40010C00

//C, D are partially included in LQFP48 Package

#define GPIOC_BASE 		0x40011000
#define GPIOD_BASE 		0x40011400

//E is not included in LQFP48 Package

#define GPIOE_BASE 		0x40011800


//EXTI
#define EXTI_BASE 		0x40010400


//AFIO
#define AFIO_BASE 		0x40010000



//---------------------------------------------------
//Base Addresses for APB1 Peripherals
//---------------------------------------------------





//---------------------------------------------------
//Peripheral Register: GPIO
//---------------------------------------------------


typedef struct
{
    volatile uint32_t GPIOx_CRL;
    volatile uint32_t GPIOx_CRH;
	volatile uint32_t GPIOx_IDR;
    volatile uint32_t GPIOx_ODR;
    volatile uint32_t GPIOx_BSRR;
    volatile uint32_t GPIOx_BRR;
    volatile uint32_t GPIOx_LCKR;

}GPIO_TypeDef;


//---------------------------------------------------
//Peripheral Register: RCC
//---------------------------------------------------

typedef struct 
{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_APB2RSTR; 
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_AHBENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;

}RCC_TypeDef;



//---------------------------------------------------
//Peripheral Register: AFIO
//---------------------------------------------------

typedef struct 
{
    volatile uint32_t AFIO_EVCR;
    volatile uint32_t AFIO_MAPR;
    volatile uint32_t AFIO_EXTICR1;
    volatile uint32_t AFIO_EXTICR2;
    volatile uint32_t AFIO_EXTICR3;
    volatile uint32_t AFIO_EXTICR4;
    volatile uint32_t RESERVED0;
    volatile uint32_t AFIO_MAPR2;
    
}AFIO_TypeDef;




//---------------------------------------------------
//Peripheral Register: EXTI
//---------------------------------------------------

typedef struct 
{
    volatile uint32_t EXTI_IMR;
    volatile uint32_t EXTI_EMR;
    volatile uint32_t EXTI_RTSR;
    volatile uint32_t EXTI_FTSR;
    volatile uint32_t EXTI_SWIER;
    volatile uint32_t EXTI_PR;
    
}EXTI_TypeDef;




//---------------------------------------------------
// Peripheral Instants:
//---------------------------------------------------

//GPIO
#define GPIOA ((GPIO_TypeDef *)(GPIOA_BASE))
#define GPIOB ((GPIO_TypeDef *)(GPIOB_BASE))
#define GPIOC ((GPIO_TypeDef *)(GPIOC_BASE))
#define GPIOD ((GPIO_TypeDef *)(GPIOD_BASE))
#define GPIOE ((GPIO_TypeDef *)(GPIOE_BASE))


//RCC
#define RCC ((RCC_TypeDef *)(RCC_BASE)) 


//AFIO
#define AFIO ((AFIO_TypeDef *)(AFIO_BASE))


//EXTI
#define EXTI ((EXTI_TypeDef *)(EXTI_BASE))






//---------------------------------------------------
// Clock Enable Macros:
//---------------------------------------------------

//GPIO
#define RCC_GPIOA_CLK_EN()    (RCC->RCC_APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()    (RCC->RCC_APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()    (RCC->RCC_APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()    (RCC->RCC_APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()    (RCC->RCC_APB2ENR |= 1<<6)


//AFIO
#define RCC_AFIO_CLK_EN    (RCC->RCC_APB2ENR |= 1<<0)



//---------------------------------------------------
// Generic Macros:
//---------------------------------------------------

#define SET_BIT(REG, BIT)			REG |= (1U<<BIT)
#define CLEAR_BIT(REG, BIT)			REG &= ~(1U<<BIT)
#define READ_BIT(REG, BIT)			((REG & (1U<<BIT))>>BIT)
#define TOGGLE_BIT(REG, BIT)		REG ^= (1U<<BIT)
#define READ_PORT(REG)				REG & 0xFFFF
#define TOGGLE_PORT(REG)			REG ^= 0xFFFF



#endif /*STM32F103X8_H_*/