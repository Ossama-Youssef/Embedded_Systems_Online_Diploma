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

// GPIO register address
#define GPIOA_BASE  0x40010800
#define GPIOA_CRL  *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH  *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR  *(volatile uint32_t *)(GPIOA_BASE + 0x0C)


// Clock Register address
#define RCC_BASE 0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)

// Interrupt registers
#define EXTI_BASE 0x40010400
#define EXTI_IMR  *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR   *(volatile uint32_t *)(EXTI_BASE + 0x14)

// AFIO register
#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1   *(volatile uint32_t *)(EXTI_BASE + 0x00)

// NVIC register
#define NVIC_BASE 0xE000E100
#define NVIC_EXTICE0  *(volatile uint32_t *)(NVIC_BASE + 0x00)


void Clock_init()
{
	// initialization for clock of GPIO portA to enable the module
	// Write 1 on bit 2
	RCC_APB2ENR |= (1UL<<2);
	//Alternate Function I/O clock enabled
	// Write 1 on bit 0
	RCC_APB2ENR |= (1UL<<0);
}

void GPIO_init()
{
	//Init GPIOA pin 13 as an output pin
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	// pin 0 in port A is floating input
	GPIOA_CRL |=(1<<2);
}

int main(void)
{
	 Clock_init();
	 GPIO_init();

	// routing pin 0 in port A to EXTI0
	AFIO_EXTICR1 |= (0b0000<<0);

	// masking pin 0 of EXTI0
	EXTI_IMR |= (1<<0);

	// enabling the raising triggering edge for pin 0
	EXTI_RTSR |=(1<<0);


	// enabling NVIC IRQ6
	NVIC_EXTICE0 |=(1<<6);


	while(1);

}
void EXTI0_IRQHandler()
{
	// IRQ is happend EXTI0 >> portA pin 0 >> raising edge
	// toogle a led >>> PortA pin 13
	GPIOA_ODR ^= (1<<13);

	// clearing the interrupt pending register for line 0
	EXTI_PR |= (1<<0);

}



