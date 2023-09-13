/*
 * DIO.h
 *
 * Created: 1/25/2023 7:55:25 PM
 *  Author: amrkh
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "STD_MACROS.h"

void DIO_SET_PIN_DIR(unsigned char port, unsigned char pin, unsigned char dir);

void DIO_SET_PORT_DIR(unsigned char port, unsigned char dir);

void DIO_WRITE_PIN(unsigned char port, unsigned char pin, unsigned char data );

void DIO_WRITE_PORT(unsigned char port, unsigned char data);

void DIO_TOG_PIN(unsigned char port, unsigned char pin);

void DIO_TOG_PORT(unsigned char port);

unsigned char DIO_READ_PIN(unsigned char port, unsigned char pin);

unsigned char DIO_READ_PORT(unsigned char port);

void DIO_WRITE_LOW_NIBBLE(unsigned char port, unsigned char data);

void DIO_WRITE_HIGH_NIBBLE(unsigned char port, unsigned char data);

void DIO_ACTIVE_INTERNAL_PULL_UP(unsigned char port, unsigned char pin);


#endif /* DIO_H_ */