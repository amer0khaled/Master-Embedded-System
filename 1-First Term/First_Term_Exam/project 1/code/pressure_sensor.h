#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include"STATE.h"
#include"algorithm.h"

enum{
	
	PS_State_Init,
	PS_State_Reading,
	PS_State_Waiting
	
}PS_State_Status;

/*pointer to pressure sensor states*/
extern void (*ptr_PS_ST)();

/*block states*/
STATE_DEFINE(PS_INIT);

STATE_DEFINE(PS_READING);

STATE_DEFINE(PS_WAITING);



#endif/*PRESSURE_SENSOR_H_*/