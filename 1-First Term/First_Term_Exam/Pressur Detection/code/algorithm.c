#include"algorithm.h"

//variables
static int pval;
static int p_threshold = 20;
static int alarm_status;


/*POINTER TO ALGORITHM BLOCK STATES */
void (*ptr_ALG_ST)();

STATE_DEFINE(ALG_WAITING)
{
	//state id
	ALG_State_Status = ALG_State_Waiting;
}

void Set_Pressure_Value(int p_sensor)
{
	pval = p_sensor;
	
	ptr_ALG_ST = STATE(ALG_CHECK_PRESSURE);
}

STATE_DEFINE(ALG_CHECK_PRESSURE)
{	
	//state id
	ALG_State_Status = ALG_State_Check_Pressure;
	
	//state action
	if(pval > p_threshold)
	{	
		alarm_status = 1;
		ptr_ALG_ST = STATE(ALG_HIGH_PRESSURE_DETECTION);
	}
	else
	{
		alarm_status = 0;
		Alarm_Status(alarm_status);
		ptr_ALG_ST = STATE(ALG_WAITING);
	}
}

STATE_DEFINE(ALG_HIGH_PRESSURE_DETECTION)	
{	
	//state id
	ALG_State_Status = ALG_State_High_Pressure_Detection;
	
	//state action
	Alarm_Status(alarm_status);
	
	ptr_ALG_ST = STATE(ALG_WAITING);
}