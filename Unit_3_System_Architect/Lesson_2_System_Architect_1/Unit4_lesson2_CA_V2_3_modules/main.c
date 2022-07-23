/****************************************************************************************
           @file           : main.c
           @author         : Osama Youssef
           @brief          : program file for Collision_Avoidance project functions
                                         run and test
 ******************************************************************************************/
#include "CA.h"
#include "US_Sensor.h"
#include "DC_Motor.h"


void setup(void)
{
	//init all drivers
	//init IRQ ...
	//init HAL
	US_Sensor_init();
	DC_Motor_init();
	//init block
	CA_state = STATE_(CA_waiting);
	US_Sensor_state = STATE_(US_Sensor_busy);
	DC_Motor_state = STATE_(DC_Motor_idle);
}

int main(void)
{
	volatile int count ;
	setup();
	while(1)
	{
		fflush(stdin);fflush(stdout);
		// call state for each block
		US_Sensor_state();
		CA_state();
		DC_Motor_state();
		for(count = 0 ; count < 5000 ; count++){asm("nop");}
	}

	return 0 ;
}








