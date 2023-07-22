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
		
	}> FLASH
	
	.data : 
	{
		*(.data)
		
	}> FLASH
	
	.bss : 
	{
		*(.bss)
		
	}> SRAM






}