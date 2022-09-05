/*
 * Keypad.h
 *
 * Created: 9/4/2022 1:47:49 PM
 *  Author: Osama Youssef 
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU  8000000UL    // define the speed of crystal to 10MHZ

// include the used libraries
#include <avr/io.h>
#include <util/delay.h>

// macros to set , reset , toggle and read bits from pins
#define SET_BIT(ADDRESS,VALUE,BIT_NUMBER)      ADDRESS |= (VALUE << BIT_NUMBER)
#define RESET_BIT(ADDRESS,VALUE,BIT_NUMBER)    ADDRESS &=~(VALUE << BIT_NUMBER)
#define TOGGLE_BIT(ADDRESS,VALUE,BIT_NUMBER)   ADDRESS ^= (VALUE << BIT_NUMBER)
#define READ_BIT(ADDRESS,VALUE,BIT_NUMBER)    ((ADDRESS & (VALUE << BIT_NUMBER))>> BIT_NUMBER)

// Keypad Pins Definition  
#define ROW0 0
#define ROW1 1
#define ROW2 2
#define ROW3 3
#define COL0 4
#define COL1 5
#define COL2 6 
#define COL3 7

// Keypad Configuration port 
#define KEYPAD_PORT          PORTD
#define KEYPAD_DATA_DIR      DDRD
#define KEYPAD_PIN           PIND

//Keypad Functions prototypes 
//function to initialize the Keypad : take nothing and return nothing
void KEYPAD_INIT(void);
//function to get character from the Keypad : take nothing and return character 
char KEYPAD_GETCHAR(void);

#endif /* KEYPAD_H_ */