/****************************************************************************************
           @file           : DC_Motor.h
           @author         : Osama Youssef
           @brief          : Header file for DC_Motor project prototypes
                                          and data types used in project
 ******************************************************************************************/

#ifndef DC_Motor_H_
#define DC_Motor_H_
#include "State.h"


// Define the states of the DC_Motor
// there are two states : DC_Motor idling or DC_Motor busy
enum
{
	DC_Motor_idle,
	DC_Motor_busy
}DC_Motor_State_ID;


// prototypes for states functions
STATE_Define(DC_Motor_idle); // function for waiting state
STATE_Define(DC_Motor_busy); // function for driving state

// function to initialize the DC Motor
void DC_Motor_init();

// extern the pointer to function to be viewed at main since we include DC_Motor.h at main.c
// to avoid a linking error
extern void (*DC_Motor_state)();


#endif /* DC_Motor_H_ */
