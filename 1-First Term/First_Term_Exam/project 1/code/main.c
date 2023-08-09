#include <stdint.h>
#include <stdio.h>

#include "driver.h"

void Set_UP()
{
	GPIO_INITIALIZATION();
	
	ptr_PS_ST = STATE(PS_INIT);
	ptr_ALG_ST = STATE(ALG_WAITING);
	ptr_AC_ST = STATE(AC_INIT);
	
}

int main ()
{
	Set_UP();
	
	while (1)
	{
		(*ptr_PS_ST)();
		(*ptr_ALG_ST)();
		(*ptr_AC_ST)();
		
		Delay(20000);
	}

}
