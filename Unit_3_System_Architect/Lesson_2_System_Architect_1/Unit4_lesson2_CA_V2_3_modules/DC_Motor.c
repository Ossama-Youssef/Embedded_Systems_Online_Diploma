/****************************************************************************************
           @file           : DC_Motor.c
           @author         : Osama Youssef
           @brief          : program file for DC_Motor project functions and states definations
 ******************************************************************************************/
#include "DC_Motor.h"


// Defination of variables : DC_Motor_speed
// DC_Motor_speed is the speed of DC_Motor and takes two values 0 and 30 : 0 when the car detect object and 30 when don't detect


unsigned int DC_Motor_speed = 0 ;

// pointer to function to point to the current state
void (*DC_Motor_state)();

// function to initialize the DC Motor
void DC_Motor_init()
{

	printf("\n DC Motor init ........ Done \n");
}
// connection state which connect between CA module and DC Motor module
void DC_Motor_set_speed(int speed)
{

	DC_Motor_speed = speed ;
	DC_Motor_state = STATE_(DC_Motor_busy);
	printf("CA ..... speed= %d ......> DC Motor \n",DC_Motor_speed);
}

// states function defination
STATE_Define(DC_Motor_idle) // function for waiting state
{
	// state name
	DC_Motor_State_ID = DC_Motor_idle ;

	// state action
	// DC motor ---> in real appliDC_Motortion it will contact upon drive
	// DC_motor(DC_Motor_speed)

	printf("DC_Motor_idle state : speed = %d \n " , DC_Motor_speed);


}
STATE_Define(DC_Motor_busy) // function for driving state
{

	// state name
	DC_Motor_State_ID = DC_Motor_busy ;

	// state action
	// DC motor ---> in real appliDC_Motortion it will contact upon drive
	// DC_motor(DC_Motor_speed)
	DC_Motor_state = STATE_(DC_Motor_idle);
	printf("DC_Motor_busy state :  speed = %d \n ", DC_Motor_speed);
}










