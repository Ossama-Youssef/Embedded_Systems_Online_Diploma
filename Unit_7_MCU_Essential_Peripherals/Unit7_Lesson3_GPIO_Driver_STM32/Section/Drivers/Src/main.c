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
#include "Keypad.h"
#include "LCD.h"

// Number from 1 to 9 in Hexadecimal form
#define Zero	0x40
#define One 	0x79
#define Two		0x24
#define Three	0x30
#define Four	0x19
#define Five	0x12
#define Six		0x02
#define Seven	0x78
#define Eight	0x00
#define Nine	0x18

// function to initialize the GPIO modules
void GPIO_init();

// function to initialize the CLOCK module
void Clock_init();

// function to make delay
void wait_ms(int x);

int main(void)
{
	Clock_init();
	//	GPIO_init();
	HAL_LCD_init();
	HAL_KEYPAD_INIT();

	unsigned char Seven_Segment[] = {Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine,Zero};
	unsigned char LCD[] = {'0','1','2','3','4','5','6','7','8','9','0'};
	for(unsigned char i = 0 ; i< 11 ; i++)
	{
		MCAL_GPIO_WRITE_Port(GPIOB, Seven_Segment[i]<<9);
		HAL_LCD_WRITE_CHAR(LCD[i]);
		wait_ms(1000);
	}
	HAL_KEYPAD_INIT();
	HAL_LCD_WRITE_STRING("keypad is ready :");
	wait_ms(25);
	HAL_LCD_CLEAR_SCREEN_FUNC();
	unsigned char key_pressed;
	while(1)
	{
		key_pressed =HAL_KEYPAD_GETCHAR();

		switch(key_pressed){
		case 'A':break;
		case '?':HAL_LCD_CLEAR_SCREEN_FUNC();break;
		default:HAL_LCD_WRITE_CHAR(key_pressed);break;
		}

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
