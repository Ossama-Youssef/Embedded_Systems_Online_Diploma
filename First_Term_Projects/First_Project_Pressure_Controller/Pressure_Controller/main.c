#include <stdint.h>
#include <stdio.h>

#include "Alarm_Monitor.h"
#include "Alarm_Monitor_Driver.h"
#include "Pressure_Sensor.h"
#include "main_Function.h"
void setup()
{
	GPIO_INITIALIZATION();
	Pressure_Sensor_init();
	main_Function_state = STATE_(main_Function_waiting);
	Alarm_Monitor_state = STATE_(Alarm_Monitor_waiting);
	Alarm_Monitor_Driver_init();

}


int main (){
	setup();

	while (1)
	{
		Pressure_Sensor_state();
		main_Function_state();
		Alarm_Monitor_state();
		Alarm_Monitor_Driver_state();
	}

}
