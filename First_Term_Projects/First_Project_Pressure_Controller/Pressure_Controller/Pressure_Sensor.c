/****************************************************************************************
           @file           : Pressure_Sensor.c
           @author         : Osama Youssef
           @brief          : program file for Pressure controller project functions
                                          and states definations
 ******************************************************************************************/
#include <Pressure_Sensor.h>


// Defination of variables : Pressure_Sensor_Reading
// Pressure_Sensor_Reading is the pressure of the cabin ,it become dangerous when increase above 20 bar

int Pressure_Sensor_Reading = 10 ;

// pointer to function to point to the current state
void (*Pressure_Sensor_state)();

// function to initialize the Pressure Sensor
void Pressure_Sensor_init()
{
	Pressure_Sensor_state = STATE_(Pressure_Sensor_reading);
}

//function for waiting state
STATE_Define(Pressure_Sensor_reading)
{
	Pressure_Sensor_Reading = getPressureVal();   // get the prssure reading from the sensor
	set_Pressure_Reading(Pressure_Sensor_Reading); // send the reading to the main function
	Pressure_Sensor_state = STATE_(Pressure_Sensor_waiting); // change the current state to be in waiting state

}


//function for reading state
STATE_Define(Pressure_Sensor_waiting)
{
	Delay(1000);  // make delay 1000
	Pressure_Sensor_state = STATE_(Pressure_Sensor_reading);  // change the current state to be in reading state to read anthor value
}








