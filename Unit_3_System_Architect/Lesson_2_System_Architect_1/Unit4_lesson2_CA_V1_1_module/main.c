/****************************************************************************************
           @file           : main.c
           @author         : Osama Youssef
           @brief          : program file for Collision_Avoidance project functions
                                         run and test
 ******************************************************************************************/
#include "Collision_Avoidance.h"

void setup(void)
{
	//init all drivers
	//init IRQ ...
	//init HAL
	//init block
	CA_state = STATE_(CA_waiting);

}

int main(void)
{
	volatile int count ;
	setup();
	while(1)
	{
		CA_state();
      for(count = 0 ; count < 5000 ; count++){asm("nop");}
	}

	return 0 ;
}








