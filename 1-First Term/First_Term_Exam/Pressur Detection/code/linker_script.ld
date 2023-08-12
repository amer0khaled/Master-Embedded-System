/* Linker Script for Arm CortexM3
Eng: Amer Khaled
*/



MEMORY
{

	FLASH(RX): ORIGIN = 0x08000000, LENGTH = 128k
	
	SRAM(RWX): ORIGIN = 0x20000000, LENGTH = 20k

}

SECTIONS
{
	.text : 
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = . ;
		
	}> FLASH
	
	.data : 
	{	
		_S_data = . ;
		*(.data)
		. = ALIGN(4);
		_E_data = . ;
		
	}> SRAM AT> FLASH
	
	.bss : 
	{	
		_S_bss = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_bss = . ;
		
		
		. = . + 0x1000;
		. = ALIGN(4);
		_heap_top = . ;
		
		
		. = . + 0x1000;
		. = ALIGN(4);
		_stack_top = . ;
		
	}> SRAM
	
	
	.debug :
	{
		*(.debug*)
		*(.debug.*)
	}



}