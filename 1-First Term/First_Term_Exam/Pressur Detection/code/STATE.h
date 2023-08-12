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
#include"driver.h"

/*Function names and declaration generators */
#define STATE(_state_id) State_##_state_id
#define STATE_DEFINE(_state_id) void State_##_state_id()

void (* current_state)();

void setup();

#endif /* STATE_H_ */


