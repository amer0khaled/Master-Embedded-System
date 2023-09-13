/*
 * button.h
 *
 * Created: 9/23/2022 3:37:17 PM
 *  Author: amrkh
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


void button_init(unsigned char port, unsigned char pin);

unsigned char button_read(unsigned char port, unsigned char pin);


#endif /* BUTTON_H_ */