/*
 * LCD.c
 *
 * Created: 9/1/2022 2:52:11 PM
 *  Author: Osama Youssef
 */

#include "Inc/LCD.h"

// Configuration of input and output pins
GPIO_Pin_Config_t PinCfg ;

//function to make delay
void wait_ms(int x)
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

// counter to manipulate the end of rows when we write character by character
static int static_counter = 0 ;

// Implementation of the function
void HAL_IS_LCD_BUSY(void)
{
	// configure the Data Direction as input depending on the LCD Mode
#ifdef EIGHT_BIT_MODE
	// Set the data pins as i/p pins
	// pin 0
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 1
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 2
	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 3
	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 4
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 5
	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 6
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 7
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

#endif
#ifdef FOUR_BIT_MODE
	// set the data pin D4 .. D7 as input pins
	// pin 4
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 5
	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 6
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 7
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

#endif

	// Set the LCD in read mode (RW on).
	MCAL_GPIO_WRITE_PIN(LCD_Port, RW_SWITCH, GPIO_PIN_SET);
	// Reset the LCD in command mode (RS off).
	MCAL_GPIO_WRITE_PIN(LCD_Port, RS_SWITCH, GPIO_PIN_RESET);
	HAL_LCD_KICK();
	// change the Data Direction port as output port
#ifdef EIGHT_BIT_MODE
	// Set the data pins as o/p pins with 10 MHz speed
	// pin 0
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 1
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 2
	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 3
	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 4
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 5
	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 6
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 7
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
#endif
#ifdef FOUR_BIT_MODE
	// set the data pin D4 .. D7 as o/p pins with 10Mhz
	// pin 4
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 5
	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 6
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 7
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

#endif
	// Set the LCD in Write mode (RW off)
	MCAL_GPIO_WRITE_PIN(LCD_Port, RW_SWITCH, GPIO_PIN_RESET);
}

void HAL_LCD_KICK()
{
	// set the Enable Switch
	MCAL_GPIO_WRITE_PIN(LCD_Port, ENABLE_SWITCH, GPIO_PIN_SET);
	// Wait for period
	asm volatile ("nop");
	asm volatile ("nop");
	wait_ms(50);
	// reSet the Enable Switch
	MCAL_GPIO_WRITE_PIN(LCD_Port, ENABLE_SWITCH, GPIO_PIN_RESET);
}

void HAL_LCD_init()
{
	// wait a 30 ms to warm up the LCD
	wait_ms(100);
	// check if the LCD is busy
	HAL_IS_LCD_BUSY();
	// Set the control pins as o/p pins
	// RS Pin
	PinCfg.GPIO_PinNumber = RS_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// READ_WRITE pin
	PinCfg.GPIO_PinNumber = RW_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// Enable Pin
	PinCfg.GPIO_PinNumber = ENABLE_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// Reset the control pins
	MCAL_GPIO_WRITE_PIN(LCD_Port, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_Port, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_Port, ENABLE_SWITCH, GPIO_PIN_RESET);
	// configure the mode of the LCD
#ifdef EIGHT_BIT_MODE
	// Set the data pins as o/p pins with 10 MHz speed
	// pin 0
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 1
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 2
	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 3
	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 4
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 5
	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 6
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 7
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

	// clear the Screen
	HAL_LCD_CLEAR_SCREEN_FUNC();
	HAL_LCD_WRITE_CMD(LCD_FUNCTION_8BIT_2LINES);
#endif
#ifdef FOUR_BIT_MODE
	// set the data pin D4 .. D7 as o/p pins with 10Mhz
	// pin 4
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 5
	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 6
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 7
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// clear the Screen
	HAL_LCD_CLEAR_SCREEN_FUNC();
	HAL_LCD_WRITE_CMD(0x02);
	HAL_LCD_WRITE_CMD(LCD_FUNCTION_4BIT_2LINES);
	wait_ms(2);
#endif
	HAL_LCD_WRITE_CMD(LCD_ENTRY_MODE);
	HAL_LCD_WRITE_CMD(LCD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_WRITE_CMD(LCD_DISP_ON_CURSOR_BLINKING);
}

void HAL_LCD_WRITE_CMD(uint16_t CMD)
{
#ifdef EIGHT_BIT_MODE
	// check if the LCD is busy or not
	HAL_IS_LCD_BUSY();
	// Write the command to Data Register
	MCAL_GPIO_WRITE_Port(LCD_Port, CMD);
	// Reset the RW , RS Pins
	MCAL_GPIO_WRITE_PIN(LCD_Port, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_Port, RW_SWITCH, GPIO_PIN_RESET);
	HAL_LCD_KICK();
#endif
#ifdef FOUR_BIT_MODE
	// check if the LCD is busy or not
	HAL_IS_LCD_BUSY();
	// set the data pin D4 .. D7 as o/p pins with 10Mhz
	// pin 4
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 5
	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 6
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 7
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// set the port
	MCAL_GPIO_WRITE_Port(LCD_Port, (GPIO_TypeDef *)((LCD_Port & 0x0F) | (CMD & 0xF0)));
	// Reset the RW , RS Pins
	MCAL_GPIO_WRITE_PIN(LCD_Port, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_Port, RW_SWITCH, GPIO_PIN_RESET);
	wait_ms(2);
	HAL_LCD_KICK();
	// write the command
	MCAL_GPIO_WRITE_Port(LCD_Port, (GPIO_TypeDef *)((LCD_Port & 0x0F) | (CMD << 4 )));

	// Reset the RW , RS Pins
	MCAL_GPIO_WRITE_PIN(LCD_Port, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_Port, RW_SWITCH, GPIO_PIN_RESET);
	wait_ms(2);
	HAL_LCD_KICK();
#endif

}
void HAL_LCD_WRITE_CHAR(uint16_t CHAR)
{
#ifdef EIGHT_BIT_MODE
	// check if the LCD is busy or not
	HAL_IS_LCD_BUSY();
	// Set the Port Pins as O/p Pins
	// Set the data pins as o/p pins with 10 MHz speed
	// pin 0
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	// pin 1
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 2
	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 3
	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 4
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 5
	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 6
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);
	// pin 7
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

	// if counter = 16 this means the first row is fully
	if(static_counter == 16 )
	{
		HAL_LCD_GOTO_XY(2,0);
	}
	else if (static_counter == 32) // if the counter = 32 this means the LCD fully
	{
		HAL_LCD_CLEAR_SCREEN_FUNC();
		static_counter = 0 ;
	}
	// Write the Character to Data Register
	MCAL_GPIO_WRITE_Port(LCD_Port, CHAR);
	static_counter++;
	// Reset the RW , Enable RS Pins
	MCAL_GPIO_WRITE_PIN(LCD_Port, RS_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WRITE_PIN(LCD_Port, RW_SWITCH, GPIO_PIN_RESET);
	HAL_LCD_KICK();
#endif
#ifdef FOUR_BIT_MODE
	// check if the LCD is busy or not
	HAL_IS_LCD_BUSY();
	// if counter = 16 this means the first row is fully
	if(static_counter == 16 )
	{
		HAL_LCD_GOTO_XY(2,0);
	}
	else if (static_counter == 32) // if the counter = 32 this means the LCD fully
	{
		HAL_LCD_CLEAR_SCREEN_FUNC();
		static_counter = 0 ;
	}
	// set the port
	MCAL_GPIO_WRITE_Port(LCD_Port, (GPIO_TypeDef *)((LCD_Port & 0x0F) | (CHAR & 0xF0)));
	// Reset the RW , Enable RS Pins
	MCAL_GPIO_WRITE_PIN(LCD_Port, RS_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WRITE_PIN(LCD_Port, RW_SWITCH, GPIO_PIN_RESET);
	wait_ms(2);
	HAL_LCD_KICK();
	// write the command
	MCAL_GPIO_WRITE_Port(LCD_Port, (GPIO_TypeDef *)((LCD_Port & 0x0F) | (CHAR << 4 )));
	// Reset the RW , Enable RS Pins
	MCAL_GPIO_WRITE_PIN(LCD_Port, RS_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WRITE_PIN(LCD_Port, RW_SWITCH, GPIO_PIN_RESET);
	wait_ms(2);
	HAL_LCD_KICK();
	static_counter++;
#endif

}
void HAL_LCD_GOTO_XY(int line , int position)
{
	// check the number of line and check the position then increment the position to line
	if(line == 1)
	{
		if(position >= 0 && position < 16)
		{
			HAL_LCD_WRITE_CMD(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	else if(line == 2)
	{
		if(position >= 0 && position < 16)
		{
			HAL_LCD_WRITE_CMD(LCD_BEGIN_AT_SECOND_ROW + position);
			static_counter = 16;
		}
	}
}

void HAL_LCD_WRITE_STRING(char* STR)
{
	// we will create a counter and increment it with every char we display to screen
	// to guard the dimensions of the LCD
	int counter = 0;
	while(*STR > 0)
	{
		// if counter = 16 this means the first row is fully
		if(counter == 16 )
		{
			HAL_LCD_GOTO_XY(2,0);
		}
		else if (counter == 32) // if the counter = 32 this means the LCD fully
		{
			HAL_LCD_CLEAR_SCREEN_FUNC();
			HAL_LCD_GOTO_XY(1,0);
			counter = 0 ;
		}
		// increase the counter and the pointer after display the char
		HAL_LCD_WRITE_CHAR(*STR++);
		counter++;
	}
}
void HAL_LCD_WRITE_NUMBER(int NUMBER)
{
	// we will convert the number to string and then display it like string
	char str[32];
	sprintf(str,"%d",NUMBER);
	HAL_LCD_WRITE_STRING(str);
}

void HAL_LCD_WRITE_REAL_NUMBER(double REAL_NUMBER)
{
	// we will convert the real number to string and then display it like string
	// first will get the sign
	// then get the int number of real number
	// then get the fraction and multiply it by number of digit (1xxxx)
	char str[32] , *sign;
	sign = (REAL_NUMBER  < 0) ?"-":"";
	float TEMP_REAL_NUMBER = (REAL_NUMBER < 0)? -REAL_NUMBER : REAL_NUMBER;
	int IntPart1 = TEMP_REAL_NUMBER;
	float fraction = TEMP_REAL_NUMBER - IntPart1;
	int IntPart2 = fraction *10000 ;
	sprintf(str,"%s%d.%d",sign,IntPart1,IntPart2);
	HAL_LCD_WRITE_STRING(str);

}
void HAL_LCD_CLEAR_SCREEN_FUNC()
{
	// Implement the clear screen command
	HAL_LCD_WRITE_CMD(LCD_CLEAR_SCREEN);
	// set the cursor at the begin of the first line
	HAL_LCD_WRITE_CMD(LCD_BEGIN_AT_FIRST_ROW);
	// set the static variable in write character function to zero
	static_counter = 0;
}
