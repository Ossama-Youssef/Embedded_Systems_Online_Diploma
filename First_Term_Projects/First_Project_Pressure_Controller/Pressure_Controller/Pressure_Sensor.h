/****************************************************************************************
           @file           : Pressure_Sensor.h
           @author         : Osama Youssef
           @brief          : Header file for Pressure controller project functions
                                          and states prototypes
 ******************************************************************************************/

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include <driver.h>

// Define the states of the Pressure Sensor
// there are two states : Pressure Sensor waiting  or Pressure Sensor reading
typedef enum
{
	Pressure_Sensor_waiting ,
	Pressure_Sensor_reading

}Pressure_Sensor_state_ID;

// prototypes for states functions
STATE_Define(Pressure_Sensor_waiting); //function for waiting state
STATE_Define(Pressure_Sensor_reading); //function for reading state


// function to initialize the Pressure Sensor
void Pressure_Sensor_init();

// extern the pointer to function to be viewed at main since we include Pressure_Sensor.h  at main.c
// to avoid a linking error
extern void (*Pressure_Sensor_state)();

#endif /* PRESSURE_SENSOR_H_ */
