/****************************************************************************************
           @file           : Collision_Avoidance.h
           @author         : Osama Youssef
           @brief          : Header file for Collision_Avoidance project prototypes
                                          and data types used in project
 ******************************************************************************************/

#ifndef COLLISION_AVOIDANCE_H_
#define COLLISION_AVOIDANCE_H_
#include "State.h"


// Define the states of the car
// there are two states : car waiting or car moving
enum
{
	CA_waiting ,
	CA_driving
}CA_State_ID;


// prototypes for states functions
STATE_Define(CA_waiting); // function for waiting state
STATE_Define(CA_driving); // function for driving state


// extern the pointer to function to be viewed at main since we include Collision_Avoidance.h at main.c
// to avoid a linking error
extern void (*CA_state)();

// function takes lower and upper values and generates values between it according to count number of times
int US_get_distance_random(int lower , int upper , int count);

#endif /* COLLISION_AVOIDANCE_H_ */
