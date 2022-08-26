/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Osama Youssef
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// macros to set , reset , toggle and read bits from pins
#define SET_BIT(ADDRESS,VALUE,BIT_NUMBER)      ADDRESS |= (VALUE << BIT_NUMBER)
#define RESET_BIT(ADDRESS,VALUE,BIT_NUMBER)    ADDRESS &=~(VALUE << BIT_NUMBER)
#define TOGGLE_BIT(ADDRESS,VALUE,BIT_NUMBER)   ADDRESS ^= (VALUE << BIT_NUMBER)
#define READ_BIT(ADDRESS,VALUE,BIT_NUMBER)    ((ADDRESS & (VALUE << BIT_NUMBER))>> BIT_NUMBER)


// GPIO port A register address
#define GPIOA_BASE  0x40010800
#define GPIOA_CRL   *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH   *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_IDR   *(volatile uint32_t *)(GPIOA_BASE + 0x08)
#define GPIOA_ODR   *(volatile uint32_t *)(GPIOA_BASE + 0x0C)


// GPIO port B register address
#define GPIOB_BASE  0x40010C00
#define GPIOB_CRL   *(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH   *(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_IDR   *(volatile uint32_t *)(GPIOB_BASE + 0x08)
#define GPIOB_ODR   *(volatile uint32_t *)(GPIOB_BASE + 0x0C)

// Clock Register address
#define RCC_BASE 0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)

// function to initialize the GPIO modules
void GPIO_init();

// function to initialize the CLOCK module
void Clock_init();

// function to make delay
void wait(int x);

int main(void)
{
	Clock_init();
	GPIO_init();

	while(1)
	{
		// PORTA Pin 1 connected to External push up resistor
		// take action when read 0 from pin
		if(READ_BIT(GPIOA_IDR,1,1) == 0)
		{
			TOGGLE_BIT(GPIOB_ODR,1,1); // toogle the led
			while(READ_BIT(GPIOA_IDR,1,1) == 0); // single press
		}
		if(READ_BIT(GPIOA_IDR,1,13) == 1)
		{
			// multipress
			TOGGLE_BIT(GPIOB_ODR,1,13); // toogle the led

		}
		wait(1);
	}

}
void GPIO_init()
{
	// Configuration of input and output pins
	// configure port A pin 1 as highZ input
	SET_BIT(GPIOA_CRL,0b0100,4);
	// configure port B pin 1 as push pull output
	SET_BIT(GPIOB_CRL,0b0001,4);
	// configure port A pin 13 as highZ input
	SET_BIT(GPIOA_CRH,0b0100,20);
	// configure port B pin 13 as push pull output
	SET_BIT(GPIOB_CRH,0b0001,20);
}

void Clock_init()
{
	// initialization for clock of GPIO portA to enable the module
	// Write 1 on bit 2
	SET_BIT(RCC_APB2ENR,1,2);
	// initialization for clock of GPIO portB to enable the module
	// Write 1 on bit 3
	SET_BIT(RCC_APB2ENR,1,3);
}

void wait(int x)
{
	vuint32_t count1 , count2 ;
	for(count1 = 0 ; count1 < x ;count1++ )
	{
		for(count2 = 0 ; count2 < 255 ; count2++)
		{
			asm("nop");
		}
	}
}

