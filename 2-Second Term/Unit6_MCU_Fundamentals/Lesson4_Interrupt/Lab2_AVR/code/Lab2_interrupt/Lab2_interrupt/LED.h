/*
 * LED.h
 *
 * Created: 1/25/2023 11:52:41 PM
 *  Author: amrkh
 */ 


#ifndef LED_H_
#define LED_H_

void LED_INIT(unsigned char port, unsigned char pin);

void LED_ON(unsigned char port, unsigned char pin);

void LED_OFF(unsigned char port, unsigned char pin);

void LED_TOGGLE(unsigned char port, unsigned char pin);

unsigned char LED_READ(unsigned char port, unsigned char pin);

void LED_INIT_PORT(unsigned char port);

void LED_ON_PORT(unsigned port);

void LED_OFF_PORT(unsigned char port);

void LED_TOGGLE_PORT(unsigned char port);

unsigned char LED_READ_PORT(unsigned port);



#endif /* LED_H_ */