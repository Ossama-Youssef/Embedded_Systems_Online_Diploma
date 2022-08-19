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
//Learn-in-depth
//Osama Youssef
//Mastering_Embedded System online diploma
typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
#define GPIOA_BASE  0x40010800
#define GPIOA_CRH  *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR  *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
// Clock Register address
#define RCC_BASE 0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR     *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR       *(volatile uint32_t *)(RCC_BASE + 0x00)

int main(void)
{
	/* initialization for clock of GPIO portA to enable the module*/
	// Write 1 on bit 2

	RCC_APB2ENR |= (1UL<<2);

	//Write 1 in bit 24 to enable PLL circuit
	RCC_CR |= (0b1<<24);


	// write 0110 in PLLMUL in bits 18:21 to get 32 MHz in APH
	RCC_CFGR |= (0b0110 << 18);


	// Write 10 in bits 0:1 to selet PLL as a system clock
	RCC_CFGR |= (0b10 << 0);

	// divide the speed of HSI clock by 4 to get 8 MHz in APB2 bus
	// write 101 in bits 11:13 in RCC_CFGR

	RCC_CFGR |= (0b101 << 11);

	// divide the speed of HSI clock by 2 to get 16 MHz in APB1 bus
	// write 101 in bits 8:10 in RCC_CFGR

	RCC_CFGR |= (0b100 << 8);

	//Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
