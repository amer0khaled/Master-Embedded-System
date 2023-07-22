
#include "uart.h"

unsigned char String_Buffer[100] = "Learn_in_depth >>>> Amer_khaled";


void main(void)
{
	UART_Send_String(String_Buffer);
}