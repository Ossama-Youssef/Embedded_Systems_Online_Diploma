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
#include "STM32_F103X8.h"
#include "STM32_F103C6_GPIO_Driver.h"

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
		if(MCAL_GPIO_READ_PIN(GPIOA, GPIO_PIN_1) == 0)
		{
			MCAL_GPIO_TOGGLE_PIN(GPIOB, GPIO_PIN_1); // toogle the led
			while(MCAL_GPIO_READ_PIN(GPIOA, GPIO_PIN_1) == 0); // single press
		}
		if(MCAL_GPIO_READ_PIN(GPIOA, GPIO_PIN_13) == 1)
		{
			// multipress
			MCAL_GPIO_TOGGLE_PIN(GPIOB, GPIO_PIN_13); // toogle the led

		}
		wait(1);
	}

}
void GPIO_init()
{
	// Configuration of input and output pins
	GPIO_Pin_Config_t PinCfg ;


	// configure port A pin 1 as highZ input
	PinCfg.GPIO_PinNumber = GPIO_PIN_1 ;
	PinCfg.GPIO_MODE= GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	// configure port B pin 1 as push pull output
	PinCfg.GPIO_PinNumber = GPIO_PIN_1 ;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);


	// configure port A pin 13 as highZ input
	PinCfg.GPIO_PinNumber = GPIO_PIN_13 ;
	PinCfg.GPIO_MODE= GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCfg);


	// configure port B pin 13 as push pull output
	PinCfg.GPIO_PinNumber = GPIO_PIN_13 ;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}

void Clock_init()
{
	// initialization for clock of GPIO portA to enable the module
	RCC_GPIOA_CLK_ENABLE();
	// initialization for clock of GPIO portB to enable the module
	RCC_GPIOB_CLK_ENABLE();
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
