/*
 * Unit7_Lesson1_Section_Lab3.c
 *
 * Created: 8/26/2022 10:50:16 PM
 * Author : Osama Youssef
 */ 
#define F_CPU 8000000UL
#include "MemoryMap.h"
#include <util/delay.h>
// configure the frequency of processor 
#define F_CPU 8000000UL

int main(void)
{
    // set the direction of all pins of portA as output pins except pin 7
	SET_BIT(DDRC,0xff,0);
	unsigned char count1 , count2 ;
    while (1) 
    {
		for(count1 = 0 ; count1 < 10 ;count1++)
		{
			for(count2 = 0 ; count2 < 10 ;count2++)
			{
			   // configure the pins to turn the first 7seg
			   	PORTC=(0b1000 | (count1 << 4));
			   _delay_ms(50);	  
			    // configure the pins to turn the first 7seg
			    PORTC=(0b0100 | (count1 << 4));
			    _delay_ms(50); 
			}
		}
	}
}




