/*
 * Unit7_Lesson1_Section_Lab1.c
 *
 * Created: 8/26/2022 10:50:16 PM
 * Author : Osama Youssef
 */ 

#include "MemoryMap.h"

// configure the frequency of processor 
#define F_CPU 8000000UL

// function to make delay
void delay(int x);

// function to turn on the leds of port D from 5 >>> 7
void TurnOnLeds();

// function to turn off the leds of port D from 5 >>> 7
void TurnOffLeds();

int main(void)
{
    // set the direction of pins 5 >> 7 of portD as output pins 
	SET_BIT(DDRD,0xE0,0);
    while (1) 
    {
		TurnOnLeds();
		TurnOffLeds();
    }
	
}
void delay(int x)
{
	vuint32 count1 , count2 ;
	for(count1 = 0 ; count1 < x ;count1++ )
	{
		for(count2 = 0 ; count2 < 50000 ; count2++);
	}
}
void TurnOnLeds()
{

	SET_BIT(PORTD,1,5);
	delay(1);
	SET_BIT(PORTD,1,6);
	delay(1);
	SET_BIT(PORTD,1,7);
	delay(1);
	
}
void TurnOffLeds()
{
	RESET_BIT(PORTD,1,7);
	delay(1);
	RESET_BIT(PORTD,1,6);
	delay(1);
	RESET_BIT(PORTD,1,5);
	delay(1);
}
