/****************************************************************************************
           @file           : Alarm_Monitor.h
           @author         : Osama Youssef
           @brief          : Header file for Pressure controller project functions
                                          and states prototypes
 ******************************************************************************************/
#include<Alarm_Monitor.h>

Alarm_Monitor_state_ID current_state = Alarm_Monitor_turn_OFF ;

// pointer to function to point to the current state
void (*Alarm_Monitor_state)();

//function for waiting state
STATE_Define(Alarm_Monitor_waiting)
{
	
	if(current_state == Alarm_Monitor_turn_ON)
	{
		Alarm_Monitor_state = STATE_(Alarm_Monitor_turn_ON);
	}
	else
	{
		Alarm_Monitor_state = STATE_(Alarm_Monitor_turn_OFF);
	}

}

//function for idling state
STATE_Define(Alarm_Monitor_idle)
{
  Delay(60000);
  Alarm_Monitor_state = STATE_(Alarm_Monitor_waiting);
}

//function for turning on state
STATE_Define(Alarm_Monitor_turn_ON)
{
	High_Pressure_Detected();
	Alarm_Monitor_state = STATE_(Alarm_Monitor_idle) ;

}
//function for turning off state
STATE_Define(Alarm_Monitor_turn_OFF)
{
	Low_Pressure_Detected();
	Alarm_Monitor_state = STATE_(Alarm_Monitor_waiting);

}







