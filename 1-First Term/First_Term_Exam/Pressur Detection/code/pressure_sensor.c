#include"pressure_sensor.h"

/*block variables*/
static int pval;

/*pointer to pressure sensor states*/
void (*ptr_PS_ST)();

STATE_DEFINE(PS_INIT)
{
	//state id
	PS_State_Status = PS_State_Init;
	
	//state action
	pval = 0;
	
	ptr_PS_ST = STATE(PS_READING);
	
}


STATE_DEFINE(PS_READING)
{
	//state id
	PS_State_Status = PS_State_Reading;
	
	//state action
	pval = getPressureVal();
	
	Set_Pressure_Value(pval);
	
	ptr_PS_ST = STATE(PS_WAITING);
	
	
}

STATE_DEFINE(PS_WAITING)
{
	//state id
	PS_State_Status = PS_State_Waiting;
	
	ptr_PS_ST = STATE(PS_READING);
}
