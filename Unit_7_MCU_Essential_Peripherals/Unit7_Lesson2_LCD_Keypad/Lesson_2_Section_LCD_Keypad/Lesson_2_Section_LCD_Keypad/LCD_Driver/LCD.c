/*
 * LCD.c
 *
 * Created: 9/1/2022 2:52:11 PM
 *  Author: Osama Youssef 
 */ 

#include "LCD.h"

// counter to manipulate the end of rows when we write character by character 
static int static_counter = 0 ;

// Implementation of the function
void IS_LCD_BUSY(void)
{
   // configure the Data Direction as input depending on the LCD Mode 
	RESET_BIT(Data_Direction_LCD_Port,PORT_ENABLE,DATA_SHIFT); 
   // Set the LCD in read mode (RW on). 
	SET_BIT(LCD_CTRL,1,RW_SWITCH);
   // Reset the LCD in command mode (RS off).
   RESET_BIT(LCD_CTRL,1,RS_SWITCH);
   LCD_KICK();
   // change the Data Direction port as output port 
   SET_BIT(Data_Direction_LCD_Port,PORT_ENABLE,DATA_SHIFT); 
   // Set the LCD in Write mode (RW off).
   RESET_BIT(LCD_CTRL,1,RW_SWITCH);
}

void LCD_KICK()
{
	// Reset the Enable Switch 
	SET_BIT(LCD_CTRL,1,ENABLE_SWITCH);
	// Wait for period 
	asm volatile ("nop");
	asm volatile ("nop");
	_delay_ms(10);
	// Set the Enable Switch 
	RESET_BIT(LCD_CTRL,1,ENABLE_SWITCH);
}

void LCD_init()
{
	// wait a 30 ms to warm up the LCD 
	_delay_ms(25);
	// check if the LCD is busy 
	IS_LCD_BUSY();
	// Set the control pins as o/p pins 
	SET_BIT(Data_Direction_LCD_CTRL,0b111,1);
	// Reset the control pins 
	RESET_BIT(LCD_CTRL,0b111,1);
	// Set the LCD Port Pins as o/p pins 
	SET_BIT(Data_Direction_LCD_Port,PORT_ENABLE,DATA_SHIFT);
	// clear the Screen 
	LCD_CLEAR_SCREEN_FUNC();
	// configure the mode of the LCD 
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_CMD(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE 
	LCD_WRITE_CMD(0x02);
	LCD_WRITE_CMD(LCD_FUNCTION_4BIT_2LINES);
	_delay_ms(2);
	#endif
	LCD_WRITE_CMD(LCD_ENTRY_MODE);
	LCD_WRITE_CMD(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_CMD(LCD_DISP_ON_CURSOR_BLINKING);
}

void LCD_WRITE_CMD(unsigned char CMD)
{
	#ifdef EIGHT_BIT_MODE
	// check if the LCD is busy or not 
	IS_LCD_BUSY();
	// Set the Port Pins as O/p Pins 
	SET_BIT(Data_Direction_LCD_Port,PORT_ENABLE,0);
	// Write the command to Data Register
	LCD_Port = CMD ;
	// Reset the RW , RS Pins 
	RESET_BIT(LCD_CTRL,0b11,1);
	LCD_KICK();
	#endif 
	#ifdef FOUR_BIT_MODE
	// check if the LCD is busy or not
	IS_LCD_BUSY();
	// set the port 
	LCD_Port = ((LCD_Port & 0x0F) | (CMD & 0xF0));
	// Reset the RW , RS Pins
	RESET_BIT(LCD_CTRL,0b11,1);
	_delay_ms(2);
	LCD_KICK();
	// write the command 
    LCD_Port = ((LCD_Port & 0x0F) | (CMD << DATA_SHIFT));
	// Reset the RW , RS Pins
	RESET_BIT(LCD_CTRL,0b11,1);
	_delay_ms(2);
	LCD_KICK();
	#endif
	
}
void LCD_WRITE_CHAR(unsigned char CHAR)
{
	#ifdef EIGHT_BIT_MODE
	// check if the LCD is busy or not
	IS_LCD_BUSY();
	// Set the Port Pins as O/p Pins
	SET_BIT(Data_Direction_LCD_Port,PORT_ENABLE,0);
	// if counter = 16 this means the first row is fully
	if(static_counter == 16 )
	{
		LCD_GOTO_XY(2,0);
	}
	else if (static_counter == 32) // if the counter = 32 this means the LCD fully
	{
		LCD_CLEAR_SCREEN_FUNC();
		static_counter = 0 ;
	}
	// Write the Character to Data Register
	LCD_Port = CHAR ;
	static_counter++;
	// Reset the RW , Enable RS Pins
	SET_BIT(LCD_CTRL,1,RS_SWITCH);
	RESET_BIT(LCD_CTRL,1,RW_SWITCH);
	LCD_KICK();
	#endif
	#ifdef FOUR_BIT_MODE
	// check if the LCD is busy or not
	IS_LCD_BUSY();
	// if counter = 16 this means the first row is fully
	if(static_counter == 16 )
	{
		LCD_GOTO_XY(2,0);
	}
	else if (static_counter == 32) // if the counter = 32 this means the LCD fully
	{
		LCD_CLEAR_SCREEN_FUNC();
		static_counter = 0 ;
	}
	// set the port
	LCD_Port = ((LCD_Port & 0x0F) | (CHAR & 0xF0));
	// Reset the RW , Enable RS Pins
	SET_BIT(LCD_CTRL,1,RS_SWITCH);
	RESET_BIT(LCD_CTRL,1,RW_SWITCH);
	_delay_ms(2);
	LCD_KICK();
	// write the command
	LCD_Port = ((LCD_Port & 0x0F) | (CHAR << DATA_SHIFT));
	// Reset the RW , Enable RS Pins
	SET_BIT(LCD_CTRL,1,RS_SWITCH);
	RESET_BIT(LCD_CTRL,1,RW_SWITCH);
	_delay_ms(2);
	LCD_KICK();
	static_counter++;
	#endif
	
}
void LCD_GOTO_XY(int line , int position)
{
	// check the number of line and check the position then increment the position to line
	if(line == 1)
	{
		if(position >= 0 && position < 16)
		{
			LCD_WRITE_CMD(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	else if(line == 2)
	{
	if(position >= 0 && position < 16)
		{
			LCD_WRITE_CMD(LCD_BEGIN_AT_SECOND_ROW + position);
			static_counter = 16;
		}
	}
}

void LCD_WRITE_STRING(char* STR)
{
	// we will create a counter and increment it with every char we display to screen 
	// to guard the dimensions of the LCD 
	int counter = 0;
	while(*STR > 0)
	{
		// if counter = 16 this means the first row is fully 
		if(counter == 16 )
		{
			LCD_GOTO_XY(2,0);
		}
		else if (counter == 32) // if the counter = 32 this means the LCD fully 
		{
		    LCD_CLEAR_SCREEN_FUNC();
			LCD_GOTO_XY(1,0);
			counter = 0 ;
		}
		// increase the counter and the pointer after display the char
		LCD_WRITE_CHAR(*STR++);
		counter++;
	}
}
void LCD_WRITE_NUMBER(int NUMBER)
{
	// we will convert the number to string and then display it like string 
	char str[32];
	sprintf(str,"%d",NUMBER);
     LCD_WRITE_STRING(str);
}

void LCD_WRITE_REAL_NUMBER(double REAL_NUMBER)
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
	LCD_WRITE_STRING(str);  
	
}
void LCD_CLEAR_SCREEN_FUNC()
{
	// Implement the clear screen command
	LCD_WRITE_CMD(LCD_CLEAR_SCREEN);
	// set the cursor at the begin of the first line
	LCD_WRITE_CMD(LCD_BEGIN_AT_FIRST_ROW);
	// set the static variable in write character function to zero
	static_counter = 0;
}