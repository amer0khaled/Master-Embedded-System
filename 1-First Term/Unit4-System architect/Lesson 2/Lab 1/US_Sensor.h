/**
 * @file US_Sensor.h
 *
 * @brief this header file is the Ultrasonic APIs.
 *
 * @author Amer_khaled
 *
 * @date 03-08-2023
 *
 */
#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "state.h"

enum {
    US_busy
}US_state_id;

void (* US_state)();

void US_init();
state_define(US_busy);

#endif /* US_SENSOR_H_ */
