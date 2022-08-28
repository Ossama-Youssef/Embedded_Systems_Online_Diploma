/*
 * Unit7_Lesson1_Section_Lab2.c
 *
 * Created: 8/27/2022 12:42:25 PM
 * Author : Dell
 */ 
#define F_CPU 8000000UL
#include "MemoryMap.h"

void delay(int x);

int main(void)
{
	// configure the pins 5 >> 7 of PortC as output pins 
	SET_BIT(DDRD,0b111,5);
	RESET_BIT(PORTD,0x0,0);
	// configure the pin 0 of portD as an input pin 
	RESET_BIT(DDRD,1,0);
	SET_BIT(PORTD,1,0);
	static uint8 flag = 0; 
    while (1) 
    {
		if(READ_BIT(PIND,1,0) == 1)
		{
			flag++;
		}
		switch(flag)
		{
			case 1:
			SET_BIT(PORTD,1,5);delay(1); break;
			case 2:
		    SET_BIT(PORTD,1,6);delay(1);  break;
			case 3:
			SET_BIT(PORTD,1,7);delay(1);  break;
			case 4:
			RESET_BIT(PORTD,0b111,5);flag=0;delay(1); break;
		}
		
    }
}
void delay(int x)
{
	vuint32 count1 , count2 ;
	for(count1 = 0 ; count1 < x ;count1++ )
	{
		for(count2 = 0 ; count2 <10000 ; count2++);
	}
}

