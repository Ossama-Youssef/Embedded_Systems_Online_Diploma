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


#include "STM32_F103X8.h"
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_EXTI_Driver.h"
#include "Keypad.h"
#include "LCD.h"

// Global variable to clear the screen when the interrupt occured
uint8_t IRQ_Flag ;

// function to initialize the CLOCK module
void Clock_init();

// function to make delay
void wait_ms(int x);

// Interrupt service routine of EXTI9
void EXTI9_CallBack(void);

int main(void)
{
	// initialize t6he clock
	Clock_init();

	// Initialize the LCD
	HAL_LCD_init();
	HAL_LCD_CLEAR_SCREEN_FUNC();

	// Set the interrupt Configuration
	EXTI_PinConfig_t EXTI_CFG ;
	EXTI_CFG.EXTI_PIN = EXTI9PB9 ;
	EXTI_CFG.Triaggering_Case = EXTI_Triggering_RISING ;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_CallBack ;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_ENABLE ;
	MCAL_EXTI_GPIO_Init(&EXTI_CFG);
	// set the flag
	IRQ_Flag =1 ;

	while(1)
	{
		if(IRQ_Flag)
		{
			HAL_LCD_CLEAR_SCREEN_FUNC();
			// Reset the flag
			IRQ_Flag = 0 ;
		}

	}

}

void Clock_init()
{
	// initialization for clock of GPIO portA to enable the module
	RCC_GPIOA_CLK_ENABLE();
	// initialization for clock of GPIO portB to enable the module
	RCC_GPIOB_CLK_ENABLE();
	// initialization for clock of AFIO to enable the module
	RCC_AFIO_CLK_ENABLE();
}
void EXTI9_CallBack(void)
{
	// set the flag
	IRQ_Flag =1 ;
	HAL_LCD_WRITE_STRING("IRQ EXTI is happened _|-  ");
	wait_ms(1000);
	HAL_LCD_CLEAR_SCREEN_FUNC();



}
