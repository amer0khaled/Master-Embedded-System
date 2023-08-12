#ifndef ALAM_ACTAUTOR_H_
#define ALAM_ACTAUTOR_H_

#include"STATE.h"

enum{
	
	AC_State_Init,
	AC_State_Waiting,
	AC_State_Alarm_ON,
	AC_State_Alarm_OFF
	
}AC_State_Status;

/*pointer to block states*/
extern void (*ptr_AC_ST)();

/*block states*/
STATE_DEFINE(AC_INIT);
STATE_DEFINE(AC_WAITING);
STATE_DEFINE(AC_ALARM_ON);
STATE_DEFINE(AC_ALARM_OFF);
void Alarm_Status(int status);

#endif/*ALAM_ACTAUTOR_H_*/