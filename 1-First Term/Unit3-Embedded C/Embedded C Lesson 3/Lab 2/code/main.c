

#include"Platform_Types.h"

#define RCC_BASE    0x40021000
#define GPIOA_BASE  0x40010800
#define RCC_APB2ENR *(vuint32 *)(RCC_BASE + 0X18)
#define GPIOA_CRH   *(vuint32 *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR   *(vuint32 *)(GPIOA_BASE + 0x0c)

#define RCC_IOPAEN  (1<<2)
#define GPIOA13     (1UL<<13)

typedef union
{
	vsint32 all_fields;
	struct
	{
		vsint32 reserved :13;
		vsint32 pin_13 	 :1;
	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

int main(void)
{
	RCC_APB2ENR  |=  RCC_IOPAEN;
	GPIOA_CRH    &=  0xFF0FFFFF;
	GPIOA_CRH    |=  0x00200000;
	int i = 0;
	
	while(1)
	{
		R_ODR->Pin.pin_13 = 1;
		for(i = 0; i < 50000; i++);

		R_ODR->Pin.pin_13 = 0;
		for(i = 0; i < 50000; i++);

	}

	return 0;
}
