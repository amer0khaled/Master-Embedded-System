/**
 * @file CA.h
 *
 * @brief this file is the header for the
 * collision avoidance Application.
 *
 * @author Amer_khaled
 *
 * @date 3-08-2023
 *
 * @version 2.0
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"

enum {
    CA_waiting,
    CA_driving
}CA_state_id;

void (* CA_state)();

void CA_init();
state_define(CA_waiting);
state_define(CA_driving);

#endif /* CA_H_ */
