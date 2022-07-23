/****************************************************************************************
           @file           : CA.c
           @author         : Osama Youssef
           @brief          : program file for CA project functions  and states definations

 ******************************************************************************************/
#include "CA.h"


// Defination of variables : CA_speed , CA_distance and CA_threshold
// CA_speed is the speed of car and takes two values 0 and 30 : 0 when the car detect object and 30 when don't detect
// CA_distance is the distance between the car and any detected object if distance is greater the threshold
//             become 30 and the car moves , else the speed become 0  and the car stops
// CA_threshold is the distance which makes the car take the action or not as explained

unsigned int CA_speed = 0 ,CA_distance = 0 , CA_threshold= 50 ;

// pointer to function to point to the current state
void (*CA_state)();

// connection state which connect between CA module and Us sensor module
void US_set_distance(int distance)
{

	CA_distance = distance ;
	if(CA_distance <= CA_threshold)
	{
		CA_state = STATE_(CA_waiting); // it will remain in the same state (waiting state)
	}
	else
	{
		CA_state = STATE_(CA_driving); // it will go to driving state
	}
	printf("US_Sensor ..... distance= %d ......> CA \n",CA_distance);
}

// states function defination
STATE_Define(CA_waiting) // function for waiting state
{
	// state name
	CA_State_ID = CA_waiting ;
	printf("CA_waiting state : distance = %d  speed = %d \n ", CA_distance , CA_speed);
	// state action
	// DC motor ---> in real application it will contact upon drive
	// DC_motor(CA_speed)
	CA_speed = 0;
	DC_Motor_set_speed( CA_speed);
}
STATE_Define(CA_driving) // function for driving state
{

	// state name
	CA_State_ID = CA_driving ;
	printf("CA_driving state : distance = %d  speed = %d \n ", CA_distance , CA_speed);

	// state action
	// DC motor ---> in real application it will contact upon drive
	// DC_motor(CA_speed)
	CA_speed = 30;
	DC_Motor_set_speed( CA_speed);

}









