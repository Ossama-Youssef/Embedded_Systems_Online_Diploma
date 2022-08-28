/*
 * Unit7_Lesson1_Section_Lab4.c
 *
 * Created: 8/28/2022 8:33:43 PM
 * Author : Dell
 */ 

#include <avr/io.h>


#define F_CPU 8000000UL
#include "MemoryMap.h"
#include <util//delay.h>
int main(void)
{
	// configure the pin 4 of portD as an output pin 
	SET_BIT(DDRD,1,4);
	RESET_BIT(PORTD,1,4);
	// configure the pin 0 of portD as an input pin 
	RESET_BIT(DDRD,1,0);
	SET_BIT(PORTD,1,0);
    while (1) 
    {
		if(READ_BIT(PIND,1,0) == 1)
		{
			SET_BIT(PORTD,1,4);
			_delay_ms(100);
		}
		else
	    {
		   RESET_BIT(PORTD,1,4);
		   _delay_ms(100);	
		}
    }
}

