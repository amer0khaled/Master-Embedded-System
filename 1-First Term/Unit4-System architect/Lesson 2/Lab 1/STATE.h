/**
 * @file state.h
 *
 * @brief this file is used to interface between the
 * application different modules.
 *
 * @author Amer_khaled
 *
 * @date 03-08-2023
 *
 */


#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

/*Function names and declaration generators */
#define state(state_id) ST_##state_id
#define state_define(state_id) void state(state_id)()

void (* current_state)();

void setup();
void US_get_distance(int distance);
void Motor_set_speed(int speed);

#endif /* STATE_H_ */



