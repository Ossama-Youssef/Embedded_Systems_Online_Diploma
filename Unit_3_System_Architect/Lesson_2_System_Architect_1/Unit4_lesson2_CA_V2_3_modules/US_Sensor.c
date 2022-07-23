/****************************************************************************************
           @file           : US_Sensor.c
           @author         : Osama Youssef
           @brief          : program file for US_Sensor project functions
                                          and states definations
 ******************************************************************************************/
#include "US_Sensor.h"


// Defination of variables : US_Sensor_distance
// US_Sensor_distance is the distance between the car and any detected object if distance is greater the threshold
//             become 30 and the car moves , else the speed become 0  and the car stops

unsigned int US_Sensor_distance = 0 ;

// pointer to function to point to the current state
void (*US_Sensor_state)();

// function to initialize the US sensor
void US_Sensor_init()
{
	printf("\n US Sensor init ........ Done \n");
}

// states function defination
STATE_Define(US_Sensor_busy) // function for busy state
{
	// state name
	US_Sensor_State_ID = US_Sensor_busy ;

	//ultrasonic sensor ----> in real  appliction it will get the distance from ultrasonic sensor
	//US_get_distance(US_Sensor_distance)
	US_Sensor_distance =  US_get_distance_random(45,55,1);	// event check
	printf("US_Sensor_busy state : distance = %d \n ", US_Sensor_distance );
	US_set_distance(US_Sensor_distance);
	US_Sensor_state = STATE_(US_Sensor_busy);
}

int US_get_distance_random(int lower , int upper , int count)
{
	int i , result ;
	for(i = 0 ; i < count ; i++)
	{
		result = (rand()%(upper-lower+1)+lower);
	}

	return result;
}








