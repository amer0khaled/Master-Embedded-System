#include"Platform_Types.h"

#define SYSCTL_BASE               (0x400FE000)
#define SYSCTL_RCGC_R             (*((volatile uint32*)(SYSCTL_BASE+0x108))) 

#define GPIOF_BASE                (0x40025000)
#define GPIO_PORTF_DIR_R          (*((volatile uint32*)(GPIOF_BASE+0x400)))
#define GPIO_PORTF_DEN_R          (*((volatile uint32*)(GPIOF_BASE+0x51C)))
#define GPIO_PORTF_DATA_R         (*((volatile uint32*)(GPIOF_BASE+0x3FC)))

#define SET_BIT(reg, bit_num)     reg |= (1<<bit_num)
#define CLR_BIT(reg, bit_num)     reg &= ~(1<<bit_num)
#define TOGGLE_BIT(reg, bit_num)  reg ^= (1<<bit_num)
#define READ_BIT(reg, bit_num)    ((reg & (1<<bit_num))>>bit_num)


int main(void)
{	
	volatile uint32 delay_count;
	
	SYSCTL_RCGC_R = 0x20; /*Enable clock of GPIOF*/
	
	for(delay_count = 0; delay_count < 2000; delay_count++);
	
	SET_BIT(GPIO_PORTF_DIR_R, 3);
	SET_BIT(GPIO_PORTF_DEN_R, 3);
	
	
	while(1)
	{
		TOGGLE_BIT(GPIO_PORTF_DATA_R, 3);
		
		for(delay_count = 0; delay_count < 20000; delay_count++);
		
	}
	
	return 0;
}
