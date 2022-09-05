/*
 * LCD.h
 *
 * Created: 9/1/2022 2:51:54 PM
 *  Author: Osama Youssef 
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU  8000000UL    // define the speed of crystal to 10MHZ

// include the used libraries 
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

// macros to set , reset , toggle and read bits from pins
#define SET_BIT(ADDRESS,VALUE,BIT_NUMBER)      ADDRESS |= (VALUE << BIT_NUMBER)
#define RESET_BIT(ADDRESS,VALUE,BIT_NUMBER)    ADDRESS &=~(VALUE << BIT_NUMBER)
#define TOGGLE_BIT(ADDRESS,VALUE,BIT_NUMBER)   ADDRESS ^= (VALUE << BIT_NUMBER)
#define READ_BIT(ADDRESS,VALUE,BIT_NUMBER)    ((ADDRESS & (VALUE << BIT_NUMBER))>> BIT_NUMBER)

// macros 
// Defining Data and Control Ports 
#define LCD_Port PORTA
#define Data_Direction_LCD_Port DDRA
#define LCD_CTRL PORTB
#define Data_Direction_LCD_CTRL DDRB

// Defining Control Pins 
#define RS_SWITCH             (1) 
#define RW_SWITCH             (2)
#define ENABLE_SWITCH         (3) 

// Defining the LCD Modes 
#define EIGHT_BIT_MODE                // Data will be on (D0 ...... D7)
//#define FOUR_BIT_MODE               // Data will be on (D4 ...... D7)  


#ifdef FOUR_BIT_MODE
#define DATA_SHIFT                             (4)
#endif
#ifdef EIGHT_BIT_MODE
#define DATA_SHIFT                             (0)
#endif


// Defining some used values 
#define LCD_REGISTER_SELECT_PIN                (0) 
#define LCD_READ_WRITE_PIN                     (1) 
#define LCD_ENABLE_PIN                         (2) 
#define LCD_REGISTER_SELECT_ENABLE             (1) 
#define LCD_REGISTER_SELECT_DISABLE            (0) 
#define READ_FROM_LCD                          (1)
#define WRITE_TO_LCD			               (0)
#define LCD_ENABLE                             (1)
#define LCD_DIABLE                             (0)
#define LCD_FIRST_LINE                         (0)
#define LCD_SECOND_LINE                        (1)
#define PORT_ENABLE                            (0XFF)
#define PORT_DISABLE                           (0X00) 
 
// defining LCD Instructions 
#define LCD_FUNCTION_8BIT_2LINES               (0X38)
#define LCD_FUNCTION_4BIT_2LINES               (0X28)
#define LCD_MOVE_DISP_RIGHT                    (0X1C)
#define LCD_MOVE_DISP_LEFT                     (0X18)
#define LCD_MOVE_CURSOR_RIGHT                  (0X14)
#define LCD_MOVE_CURSOR_LEFT                   (0X10)
#define LCD_DISP_OFF                           (0X08)
#define LCD_DISP_ON_CURSOR                     (0X0E)
#define LCD_DISP_ON_CURSOR_BLINKING            (0X0F)
#define LCD_DISP_ON_BLINKING                   (0X0D)
#define LCD_DISP_ON                            (0X0C)
#define LCD_ENTRY_DEC                          (0X04)
#define LCD_ENTRY_DEC_SHIFT                    (0X05)
#define LCD_ENTRY_INC                          (0X06)
#define LCD_ENTRY_INC_SHIFT                    (0X07)
#define LCD_BEGIN_AT_FIRST_ROW                 (0X80)
#define LCD_BEGIN_AT_SECOND_ROW                (0XC0)
#define LCD_CLEAR_SCREEN                       (0X01)
#define LCD_ENTRY_MODE                         (0X06)

//Functions prototypes 
//function to initialize the LCD : take nothing and return nothing 
void LCD_init(void);
// function to check if the LCD is busy or not : take nothing and return nothing 
void IS_LCD_BUSY(void);
// function to send command to LCD : takes unsigned char (0Xxx) and return nothing
void LCD_WRITE_CMD(unsigned char CMD); 
// function to send character to LCD : takes unsigned char ('x') and return nothing
void LCD_WRITE_CHAR(unsigned char CHAR);
// function to send string to LCD : takes pointer to char and return nothing
void LCD_WRITE_STRING(char* STR);
// function to ensure that enable is not free now : take nothing and return nothing 
void LCD_KICK(void);
// function to clear the screen :take nothing and return nothing 
void LCD_CLEAR_SCREEN_FUNC(); 
// function to force the cursor to write at certain position : take two arguments (int line , int position ) and return nothing 
void LCD_GOTO_XY(int line , int position); 
// function to send number to LCD : takes int (x) and return nothing
void LCD_WRITE_NUMBER(int NUMBER);
// function to send real number to LCD : takes double and return nothing
void LCD_WRITE_REAL_NUMBER(double REAL_NUMBER);

#endif /* LCD_H_ */