#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include"STATE.h"
#include"alarm_actautor.h"

enum{
	
	ALG_State_Waiting,
	ALG_State_Check_Pressure,
	ALG_State_High_Pressure_Detection
	
}ALG_State_Status;

/*POINTER TO ALGORITHM BLOCK STATES */
extern void (*ptr_ALG_ST)();

/*BLOCK STATES*/
STATE_DEFINE(ALG_WAITING);

STATE_DEFINE(ALG_CHECK_PRESSURE);

STATE_DEFINE(ALG_HIGH_PRESSURE_DETECTION);

void Set_Pressure_Value(int p_sensor);

#endif/*ALGORITHM_H_*/