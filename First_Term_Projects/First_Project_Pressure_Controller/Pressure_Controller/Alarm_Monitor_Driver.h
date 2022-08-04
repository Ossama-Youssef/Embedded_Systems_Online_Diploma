/****************************************************************************************
           @file           : Alarm_Monitor_Driver.h
           @author         : Osama Youssef
           @brief          : Header file for Pressure controller project functions
                                          and states prototypes
 ******************************************************************************************/

#ifndef ALARM_MONITOR_DRIVER_H_
#define ALARM_MONITOR_DRIVER_H_
#include <driver.h>

// Define the states of the Alarm Monitor Driver
// there are two states : Alarm Monitor Driver waiting  or Alarm Monitor Driver reading
typedef enum
{
	Alarm_Monitor_Driver_waiting ,
	Alarm_Monitor_Driver_Alarm_ON ,
	Alarm_Monitor_Driver_Alarm_OFF

}Alarm_Monitor_Driver_state_ID;

// prototypes for states functions
STATE_Define(Alarm_Monitor_Driver_waiting); //function for waiting state
STATE_Define(Alarm_Monitor_Driver_Alarm_ON); //function for Alarm ON state
STATE_Define(Alarm_Monitor_Driver_Alarm_OFF); //function for Alarm OFF state


// function to initialize the Alarm Monitor Driver
void Alarm_Monitor_Driver_init();

// extern the pointer to function to be viewed at main since we include Alarm_Monitor_Driver.h  at main.c
// to avoid a linking error
extern void (*Alarm_Monitor_Driver_state)();


#endif /* ALARM_MONITOR_DRIVER_H_ */
