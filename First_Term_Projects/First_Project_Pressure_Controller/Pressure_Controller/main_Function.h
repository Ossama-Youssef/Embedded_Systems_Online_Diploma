/****************************************************************************************
           @file           : main_Functionr.h
           @author         : Osama Youssef
           @brief          : Header file for Pressure controller project functions
                                          and states prototypes
 ******************************************************************************************/

#ifndef MAIN_FUNCTION_H_
#define MAIN_FUNCTION_H_

#include<driver.h>

// Define the states of the main Algorith
// there are two states : main Functionrwaiting  or main Functionr reading
typedef enum
{
	main_Function_waiting ,
	main_Function_detected_reading

}main_Function_state_ID;

// prototypes for states functions
STATE_Define(main_Function_waiting); //function for waiting state
STATE_Define(main_Function_detected_reading); //function for detected reading state

// extern the pointer to function to be viewed at main since we include main_Function.h  at main.c
// to avoid a linking error
extern void (*main_Function_state)();

#endif /* MAIN_FUNCTION_H_ */
