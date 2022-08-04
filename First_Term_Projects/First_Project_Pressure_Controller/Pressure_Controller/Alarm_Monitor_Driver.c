/****************************************************************************************
           @file           : Alarm_Monitor_Driver.c
           @author         : Osama Youssef
           @brief          : program file for Pressure controller project functions
                                          and states definations
 ******************************************************************************************/
#include <Alarm_Monitor_Driver.h>

// pointer to function to point to the current state
void (*Alarm_Monitor_Driver_state)();

// function to initialize the Alarm Monitor Driver
void Alarm_Monitor_Driver_init()
{
	Alarm_Monitor_Driver_state = STATE_(Alarm_Monitor_Driver_waiting);
}

//function for waiting state
STATE_Define(Alarm_Monitor_Driver_waiting)
{
	Alarm_Monitor_Driver_state = STATE_(Alarm_Monitor_Driver_waiting);
}

//function for Alarm ON state
STATE_Define(Alarm_Monitor_Driver_Alarm_ON)
{
	Set_Alarm_actuator(0);
	Alarm_Monitor_Driver_state = STATE_(Alarm_Monitor_Driver_waiting);
}
//function for Alarm OFF state
STATE_Define(Alarm_Monitor_Driver_Alarm_OFF)
{
	Set_Alarm_actuator(1);
	Alarm_Monitor_Driver_state = STATE_(Alarm_Monitor_Driver_waiting);
}

// function for high pressure detection
void High_Pressure_Detected()
{
	Alarm_Monitor_Driver_state = STATE_(Alarm_Monitor_Driver_Alarm_ON);
}

// function for low pressure detection
void Low_Pressure_Detected()
{
	Alarm_Monitor_Driver_state = STATE_(Alarm_Monitor_Driver_Alarm_OFF);
}
















