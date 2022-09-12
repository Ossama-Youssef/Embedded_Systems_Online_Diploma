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
#include "STM32_F103X8.h"
#include "STM32_F103C6_GPIO_Driver.h"

// Keypad Pins Definition
#define ROW0 GPIO_PIN_0
#define ROW1 GPIO_PIN_1
#define ROW2 GPIO_PIN_3
#define ROW3 GPIO_PIN_4
#define COL0 GPIO_PIN_5
#define COL1 GPIO_PIN_6
#define COL2 GPIO_PIN_7
#define COL3 GPIO_PIN_8

// Keypad Configuration port
#define KEYPAD_PORT       GPIOB

//Keypad Functions prototypes
//function to initialize the Keypad : take nothing and return nothing
void HAL_KEYPAD_INIT(void);
//function to get character from the Keypad : take nothing and return character
char HAL_KEYPAD_GETCHAR(void);

#endif /* KEYPAD_H_ */
