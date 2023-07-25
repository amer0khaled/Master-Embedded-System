/*
startup.c
Eng: Amer Khaled
*/

#include <stdint.h>
#define STACK_START_SP 0x20001000 /*stack starting address*/


/*

weak -> let you to overwrite on the handler code;

alias -> make all unused handlers point to the same default_handler to save memory
so you don't have to write all handlers implementation only the used handlers;

*/


extern int main(void);
void Reset_Handler(void);
void NMI_Handler()           __attribute__ ((weak,alias("Default_Handler")));
void HardFault_Handler()     __attribute__ ((weak,alias("Default_Handler")));
void MemMange_Handler()      __attribute__ ((weak,alias("Default_Handler")));
void BusFault_Handler()      __attribute__ ((weak,alias("Default_Handler")));
void UsageFault_Handler()    __attribute__ ((weak,alias("Default_Handler")));
void Default_Handler();



void Default_Handler()
{
	Reset_Handler();
}


extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;

uint32_t i = 0;

void Reset_Handler(void)
{	
	uint32_t data_size = (uint8_t*)&_E_data - (uint8_t*)&_S_data;
	uint32_t bss_size = (uint8_t*)&_E_bss - (uint8_t*)&_S_bss;
	
	/*copy data section from FLASH to SRAM*/
	uint8_t * p_src = (uint8_t *)(&_E_text);
	uint8_t * p_dst = (uint8_t *)(&_S_data);
	
	for(i = 0; i < data_size; i++)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
	}
	
	/*init the .bss section in SRAM with zero*/
	p_dst = (uint8_t *)(&_S_bss);
	
	for(i = 0; i < bss_size; i++)
	{
		*p_dst =(uint8_t) 0;
		p_dst++;
	}
	
    /*jump to main function*/
	main();
}


/*

this array will be written starting from the ENTRY_POINT so the STACK_START_SP 
will be written at the ENTRY_POINT as the ARM CortexM says then the handlers;

__atribute__((section(".vectors"))) -> pass to the compiler to put
this array at .vectors section in flash;

*/


volatile static uint32_t arr[256]; // this array will be stored in 1024 byte in .bss section 


//uint32_t _stack_top ;
/*********************************************************************************

const uint32_t vectors[] __attribute__((section(".vectors"))) = 
{
	(uint32_t)&_stack_top,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&HardFault_Handler,
	(uint32_t)&MemMange_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&UsageFault_Handler
	
	/*
	----------------
	rest of handlers
	----------------
	
	
};

**********************************************************************************/

void(* vectors_2[])() __attribute__((section(".vectors"))) =
{
	
	(void(*)())((uint32_t*)arr+(uint32_t)sizeof(arr)+(uint32_t)0x1000),
	&Reset_Handler,
	&NMI_Handler,
	&HardFault_Handler,
	&MemMange_Handler,
	&BusFault_Handler,
	&UsageFault_Handler
	
};