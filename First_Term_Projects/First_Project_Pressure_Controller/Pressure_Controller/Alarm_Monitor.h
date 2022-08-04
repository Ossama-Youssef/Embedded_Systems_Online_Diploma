/****************************************************************************************
           @file           : Alarm_Monitor.h
           @author         : Osama Youssef
           @brief          : Header file for Pressure controller project functions
                                          and states prototypes
 ******************************************************************************************/

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include<driver.h>


// Define the states of the Alarm Monitor
// there are two states : Alarm Monitor waiting  or Alarm Monitor idling , Alarm Monitor turning ON and Alarm Monitor turning OFF
typedef enum
{
	Alarm_Monitor_waiting ,
	Alarm_Monitor_idle ,
	Alarm_Monitor_turn_ON ,
	Alarm_Monitor_turn_OFF

}Alarm_Monitor_state_ID;

// prototypes for states functions
STATE_Define(Alarm_Monitor_waiting);  //function for waiting state
STATE_Define(Alarm_Monitor_idle);     //function for idling state
STATE_Define(Alarm_Monitor_turn_ON);  //function for turning on state
STATE_Define(Alarm_Monitor_turn_OFF); //function for turning off state



// extern the pointer to function to be viewed at main since we include Alarm_Monitor.h  at main.c
// to avoid a linking error
extern void (*Alarm_Monitor_state)();

extern  Alarm_Monitor_state_ID current_state ;

#endif /* ALARM_MONITOR_H_ */
