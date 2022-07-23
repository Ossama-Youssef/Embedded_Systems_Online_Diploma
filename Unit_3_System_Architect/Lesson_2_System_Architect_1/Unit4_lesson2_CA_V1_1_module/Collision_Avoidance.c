/****************************************************************************************
           @file           : Collision_Avoidance.c
           @author         : Osama Youssef
           @brief          : program file for Collision_Avoidance project functions
                                          and states definations
 ******************************************************************************************/
#include "Collision_Avoidance.h"


// Defination of variables : CA_speed , CA_distance and CA_threshold
// CA_speed is the speed of car and takes two values 0 and 30 : 0 when the car detect object and 30 when don't detect
// CA_distance is the distance between the car and any detected object if distance is greater the threshold
//             become 30 and the car moves , else the speed become 0  and the car stops
// CA_threshold is the distance which makes the car take the action or not as explained

unsigned int CA_speed = 0 ,CA_distance = 0 , CA_threshold= 50 ;

// pointer to function to point to the current state
void (*CA_state)();

// states function defination
STATE_Define(CA_waiting) // function for waiting state
{
	// state name
	CA_State_ID = CA_waiting ;

	// state action
	// DC motor ---> in real application it will contact upon drive
	// DC_motor(CA_speed)
	CA_speed = 0;
	//ultrasonic sensor ----> in real  application it will get the distance from ultrasonic sensor
	//US_get_distance(CA_distance)
	CA_distance =  US_get_distance_random(45,55,1);	// event check
	if(CA_distance <= CA_threshold)
	{
		CA_state = STATE_(CA_waiting); // it will remain in the same state (waiting state)
	}
	else
	{
		CA_state = STATE_(CA_driving); // it will go to driving state
	}
	printf("CA_waiting state : distance = %d  speed = %d \n ", CA_distance , CA_speed);
}
STATE_Define(CA_driving) // function for driving state
{

	// state name
	CA_State_ID = CA_driving ;

	// state action
	// DC motor ---> in real application it will contact upon drive
	// DC_motor(CA_speed)
	CA_speed = 30;
	//ultrasonic sensor ----> in real  application it will get the distance from ultrasonic sensor
	//US_get_distance(CA_distance)
	CA_distance =  US_get_distance_random(45,55,1);
	// event check
	if(CA_distance <= CA_threshold)
	{
		CA_state = STATE_(CA_waiting); //it will go to waiting state
	}
	else
	{
		CA_state = STATE_(CA_driving); // it will remain in the same state (driving state)
	}
	printf("CA_driving state : distance = %d  speed = %d \n ", CA_distance , CA_speed);

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








