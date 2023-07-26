

#include"Platform_Types.h"
#include<stdlib.h>

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


void* _sbrk(int incr)
{
	extern uint32 _E_bss;
	extern uint32 _heap_top;
	volatile static uint8 * new_heap = NULL;
	volatile uint8 * prev_heap = NULL;
	
	/*first time initialized*/
	if(new_heap == NULL)
	{
		new_heap = (uint8 *)&_E_bss;
	}
	
	/*check if the new size ranged within heap boundaries or not*/
	if((uint8 *)(new_heap + incr) > (uint8 *)(&_heap_top))
	{
		return (void *)NULL;
	}
	
	prev_heap = new_heap;
	
	new_heap += incr;
	
	return (void *)prev_heap;
}


int main(void)
{	

	
	
	RCC_APB2ENR  |=  RCC_IOPAEN;
	GPIOA_CRH    &=  0xFF0FFFFF;
	GPIOA_CRH    |=  0x00200000;
	int i = 0;
	
	int * ptr = (int *)malloc(4 * sizeof(int));

	while(1)
	{
		R_ODR->Pin.pin_13 = 1;
		for(i = 0; i < 50000; i++);

		R_ODR->Pin.pin_13 = 0;
		for(i = 0; i < 50000; i++);

	}

	return 0;
}

void MemMange_Handler(void)
{
}