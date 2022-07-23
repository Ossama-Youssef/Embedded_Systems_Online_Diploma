/****************************************************************************************
           @file           : CA.h
           @author         : Osama Youssef
           @brief          : Header file for CA project prototypes and data
                                   types used in project
 ******************************************************************************************/

#ifndef CA_H_
#define CA_H_
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


// extern the pointer to function to be viewed at main since we include CA.h at main.c
// to avoid a linking error
extern void (*CA_state)();


#endif /* CA_H_ */
