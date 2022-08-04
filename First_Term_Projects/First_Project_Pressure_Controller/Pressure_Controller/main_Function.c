/****************************************************************************************
           @file           : main_Function.c
           @author         : Osama Youssef
           @brief          : program file for Pressure controller project functions
                                          and states definations
 ******************************************************************************************/
#include <main_Function.h>
#include <Alarm_Monitor.h>

// Defination of variables : main_Function_Reading , threshold
// main_Function_Reading is the pressure of the cabin ,it become dangerous when increase above 20 bar
// threshold is the value of pressure that is distict between the safe pressure values and not safe values

int main_Function_Reading = 10 , threshold = 20;

// pointer to function to point to the current state
void (*main_Function_state)();

// function to sent the reading from pressure sensor to main function
void set_Pressure_Reading(int Pressure_Sensor_Reading)
{
	main_Function_Reading = Pressure_Sensor_Reading ;
	main_Function_state = STATE_(main_Function_detected_reading);
}


//function for waiting state
STATE_Define(main_Function_waiting)
{
	main_Function_state = STATE_(main_Function_waiting);
}

//function for detected reading state
STATE_Define(main_Function_detected_reading)
{

	
	if(main_Function_Reading <= threshold)
	{
		current_state = (Alarm_Monitor_turn_OFF);
	}
	else
	{
		current_state = (Alarm_Monitor_turn_ON );
	}

	main_Function_state = STATE_(main_Function_waiting);
}












