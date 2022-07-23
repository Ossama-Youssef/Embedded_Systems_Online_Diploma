/****************************************************************************************
           @file           : US_Sensor.h
           @author         : Osama Youssef
           @brief          : Header file for US_Sensor project prototypes and data
                                          types used in project
 ******************************************************************************************/

#ifndef US_Sensor_H_
#define US_Sensor_H_
#include "State.h"


// Define the states of the US_Sensor
// there are one states : US_Sensor busy
enum
{
	US_Sensor_busy ,

}US_Sensor_State_ID;


// prototypes for states functions
STATE_Define(US_Sensor_busy); // function for busy state


// extern the pointer to function to be viewed at main since we include US_Sensor.h at main.c
// to avoid a linking error
extern void (*US_Sensor_state)();

// function to initialize the US sensor
void US_Sensor_init();

// function takes lower and upper values and generates values between it according to count number of times
int US_get_distance_random(int lower , int upper , int count);

#endif /* US_Sensor_H_ */
