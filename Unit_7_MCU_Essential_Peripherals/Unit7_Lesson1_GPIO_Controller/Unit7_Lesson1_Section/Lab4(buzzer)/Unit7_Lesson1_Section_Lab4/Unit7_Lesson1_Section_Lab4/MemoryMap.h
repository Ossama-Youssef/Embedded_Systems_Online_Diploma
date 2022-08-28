/*
 * MemoryMap.h
 *
 * Created: 8/27/2022 12:44:03 PM
 *  Author: Dell
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_
#include "Platform_types.h"

// macros to set , reset , toggle and read bits from pins
#define SET_BIT(ADDRESS,VALUE,BIT_NUMBER)      ADDRESS |= (VALUE << BIT_NUMBER)
#define RESET_BIT(ADDRESS,VALUE,BIT_NUMBER)    ADDRESS &=~(VALUE << BIT_NUMBER)
#define TOGGLE_BIT(ADDRESS,VALUE,BIT_NUMBER)   ADDRESS ^= (VALUE << BIT_NUMBER)
#define READ_BIT(ADDRESS,VALUE,BIT_NUMBER)    ((ADDRESS & (VALUE << BIT_NUMBER))>> BIT_NUMBER)


// GPIO port A Registers
#define DDRA  *((vuint8 *)(0x3A))
#define PORTA *((vuint8 *)(0x3B))
#define PINA  *((vuint8 *)(0x39))

// GPIO port B Registers
#define DDRB  *((vuint8 *)(0x37))
#define PORTB *((vuint8 *)(0x38))
#define PINB  *((vuint8 *)(0x36))

// GPIO port C Registers
#define DDRC  *((vuint8 *)(0x34))
#define PORTC *((vuint8 *)(0x35))
#define PINC  *((vuint8 *)(0x33))

// GPIO port D Registers
#define DDRD  *((vuint8 *)(0x31))
#define PORTD *((vuint8 *)(0x32))
#define PIND  *((vuint8 *)(0x30))

#endif /* MEMORYMAP_H_ */