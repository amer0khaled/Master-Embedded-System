/*
 * STD_MACROS.h
 *
 * Created: 1/25/2023 12:22:35 PM
 *  Author: amrkh
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_


/*STANDARD MACROS*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define REGISTER_SIZE 8

#define CLEAR_BIT(REG , PIN) REG&=~(1<<PIN)

#define SET_BIT(REG , PIN) REG|=(1<<PIN)

#define READ_BIT(REG , PIN) (REG&(1<<PIN))>>PIN

#define TOGGLE_BIT(REG , PIN) REG^=(1<<PIN)

#define ROTATE_LEFT(REG , NUM) REG=(REG<<NUM)|(REG>>(REGISTER_SIZE-NUM)) 

#define ROTATE_RIGHT(REG , NUM) REG=(REG>>NUM)|(REG<<(REGISTER_SIZE-NUM))


/////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*REGISTERS MACROS*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*PORT A*/
#define PORTA *((volatile unsigned char*)(0x3B))

#define DDRA *((volatile unsigned char*)(0x3A))

#define PINA *((volatile unsigned char*)(0x39))


/*PORT B*/
#define PORTB *((volatile unsigned char*)(0x38))

#define DDRB *((volatile unsigned char*)(0x37))

#define PINB *((volatile unsigned char*)(0x36))


/*PORT C*/
#define PORTC *((volatile unsigned char*)(0x35))

#define DDRC *((volatile unsigned char*)(0x34))

#define PINC *((volatile unsigned char*)(0x33))


/*PORT D*/
#define PORTD *((volatile unsigned char*)(0x32))

#define DDRD *((volatile unsigned char*)(0x31))

#define PIND *((volatile unsigned char*)(0x30))


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************SPECIAL FUNCTION INPUT/OUTPUT REGISTER (64)*************************************/

#define SFIOR *((volatile unsigned char *)(0x50))

/*PULL UP DISABLE PIN*/
#define PUD 2

/*AUTO TRIGGERED PINS FOR ADC*/
#define ADTS0 5

#define ADTS1 6

#define ADTS2 7

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*EEPROM REGISTERS*/

/*EEPROM ADDRESS REGISTER LOW*/
#define EEARL *((volatile unsigned char *)(0x3E))

/*EEPROM ADDRESS REGISTER HIGH*/
#define EEARH *((volatile unsigned char *)(0x3F))

/*EEPROM DATA REGISTER*/
#define EEDR *((volatile unsigned char *)(0x3D))

/*EEPROM CONTROL REGISTER*/
#define EECR *((volatile unsigned char *)(0x3C))

/*EEPROM READ ENABLE*/
#define EERE 0

/*EEPROM WRITE ENABLE*/
#define EEWE 1

/*EEPROM MASTER WRITE ENABLE*/
#define EEMWE 2

/*EEPROM READ INTERRUPT ENABLE*/
#define EERIE 3

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**********************************************INTERRUPT REGISTERS*****************************************/

/*STATUS REGISTER*/
#define SREG *((volatile unsigned char *)(0x5F))

/*GLOBAL INTERRUPT BIT*/
#define I_BIT 7


/*EXTERNAL INTERRUPTS*/

#define GICR *((volatile unsigned char *)(0x5B))

#define INT0 6
#define INT1 7
#define INT2 5

#define GIFR *((volatile unsigned char *)(0x5A))

#define INTF0 6
#define INTF1 7
#define INTF2 5

#define MCUCR *((volatile unsigned char *)(0x55))

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define MCUCSR *((volatile unsigned char *)(0x54))

#define ISC2 6

/*TIMER INTERRUPT*/

#define TIMSK *((volatile unsigned char *)(0x59))

#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2 6
#define OCIE2 7

#define TIFR *((volatile unsigned char *)(0x58))

#define TOV0 0
#define OCF0 1
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2 7

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/***************************************************ADC*****************************************************/

/*ADC MUX REGISTER*/

#define ADMUX *((volatile unsigned char *)(0x27))

#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4

#define ADLAR 5

#define REFS0 6
#define REFS1 7

/*ADC CONTROL AND STATUS REGISTER*/

#define ADCSRA *((volatile unsigned char *)(0x26))

#define ADPS0 0
#define ADPS1 1
#define ADPS2 2

#define ADIE 3
#define ADIF 4

#define ADATE 5

#define ADSC 6

#define ADEN 7


/*ADC HIGH REGISTER*/

#define ADCH *((volatile unsigned char *)(0x25))

/*ADC LOW REGISTER*/

#define ADCL *((volatile unsigned char *)(0x24))


////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**********************************************TIMER0******************************************************/

#define TCNT0 *((volatile unsigned char *)(0x52))

#define TCCR0 *((volatile unsigned char *)(0x53))
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM00 6
#define WGM01 3

#define OCR0 *((volatile unsigned char *)(0x5C))










////////////////////////////////////////////////////////////////////////////////////////////////////////////



#endif /* STD_MACROS_H_ */