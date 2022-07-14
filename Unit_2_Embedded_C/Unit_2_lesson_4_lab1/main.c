/***********************************************************************************************
 * @file           : main.c
 * @author         : Osama Youssef
 * @brief          : project to toggle a led using TM4C123GH6PM cortex m4 0 microprocessor

 **********************************************************************************************/

#include<stdint.h>
typedef  volatile uint32_t vuint32_t;

/***********************************  Registers Address ****************************************/

#define SYSCTR_RCGC2_R_BASE   0x400FE000 // system control base address 
#define GPIO_PORTF_BASE       0x40025000 // GPIO port F base addrees 
#define SYSCTR_RCGC2_R        (*((vuint32_t * )( SYSCTR_RCGC2_R_BASE + 0x108 ))) // Enable GPIO port F
#define GPIO_PORTF_DIR_R      (*((vuint32_t * )( GPIO_PORTF_BASE + 0x400 ))) // set direction of pin 3 
#define GPIO_PORTF_DEN_R      (*((vuint32_t * )( GPIO_PORTF_BASE + 0x51c ))) // enable the pin 3 
#define GPIO_PORTF_DATA_R     (*((vuint32_t * )( GPIO_PORTF_BASE + 0x3fc ))) // O/ping data on pin 3 


/************************************************************************************************/


/**************************************** Main  Function ****************************************/

void main(void)
{    
    vuint32_t delay_counter ; // variable for looping and making delay 


	SYSCTR_RCGC2_R = 0x20 ; // Enable GPIO port F
	for(delay_counter = 0 ; delay_counter < 500 ; delay_counter++){asm("nop");} 
	// delay to make sure that is GPIO port F is up and running 


	GPIO_PORTF_DIR_R |= 1<<3 ; // set the direction register --> pin 3 is o/p pin 
    GPIO_PORTF_DEN_R |= 1<<3 ; // enable the pin 3 from port f register pins 
	while(1)
	{
		
	for(delay_counter = 0 ; delay_counter < 5000 ; delay_counter++){asm("nop");} // Delay 
        GPIO_PORTF_DATA_R |= 1<<3 ;     //o/ping 1 ---> led is on
	for(delay_counter = 0 ; delay_counter < 5000 ; delay_counter++){asm("nop");} // Delay  
        GPIO_PORTF_DATA_R &= ~(1<<3) ;  //o/ping 0 ---> led is off 
	}

}
/************************************************************************************************/
