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




#endif /* STD_MACROS_H_ */