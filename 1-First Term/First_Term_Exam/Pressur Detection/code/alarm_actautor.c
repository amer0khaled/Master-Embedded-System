#include"alarm_actautor.h"

//variables
static int alarm_status;

/*pointer to block states*/
void (*ptr_AC_ST)();


STATE_DEFINE(AC_INIT)
{
	//state id
	AC_State_Status = AC_State_Init;
	
	ptr_AC_ST = STATE(AC_WAITING);
	
}

void Alarm_Status(int status)
{
	alarm_status = status;
}

STATE_DEFINE(AC_WAITING)
{	
	AC_State_Status = AC_State_Waiting;
	
	if(alarm_status == 1)
	{
		ptr_AC_ST = STATE(AC_ALARM_ON);
	}
	else
	{
		ptr_AC_ST = STATE(AC_ALARM_OFF);
	}
	
}
STATE_DEFINE(AC_ALARM_ON)
{	
	AC_State_Status = AC_State_Alarm_ON;
	Set_Alarm_actuator(0);
	Delay(60000);
	ptr_AC_ST = STATE(AC_WAITING);
}

STATE_DEFINE(AC_ALARM_OFF)
{	
	AC_State_Status = AC_State_Alarm_OFF;
	Set_Alarm_actuator(1);
	ptr_AC_ST = STATE(AC_WAITING);
}