/*
 * lesson_2_section_LCD_Keypad.c
 *
 * Created: 9/1/2022 2:50:04 PM
 * Author : Osama Youssef 
 */ 

#include "LCD_Driver/LCD.h"
#include "Keypad_Driver/Keypad.h"

int main(void)
{
    char key_Pressed ; 
    LCD_init();
	KEYPAD_INIT();
	LCD_WRITE_STRING("Osama Youssef :");
	LCD_GOTO_XY(2,0);
	LCD_WRITE_STRING("Learn In Depth ");
	LCD_CLEAR_SCREEN_FUNC();
	LCD_WRITE_STRING("Decimal Number :");
	LCD_GOTO_XY(2,0);
	LCD_WRITE_NUMBER(1234);
	LCD_CLEAR_SCREEN_FUNC();
	LCD_WRITE_STRING("Real Number :");
	LCD_GOTO_XY(2,0);
	LCD_WRITE_REAL_NUMBER(56.56);
	LCD_CLEAR_SCREEN_FUNC();
	LCD_WRITE_STRING("i/p from Keypad :");
    while (1) 
    {
		key_Pressed = KEYPAD_GETCHAR();
		switch(key_Pressed)
		{
			case ('C'): // this means to clear the screen 
			LCD_CLEAR_SCREEN_FUNC();
			break;
			case ('A'):
			break;
			default:
			LCD_WRITE_CHAR(key_Pressed);
			break;	
		}
		
    }
}



