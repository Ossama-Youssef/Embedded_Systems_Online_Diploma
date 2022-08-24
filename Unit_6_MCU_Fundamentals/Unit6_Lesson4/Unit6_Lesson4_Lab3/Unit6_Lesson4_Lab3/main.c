/*
 * Unit6_Lesson4_Lab3.c
 *
 * Created: 8/24/2022 9:38:48 AM
 * Author : Osama Youssef 
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// macros to set , reset , toggle and read bits from pins 
#define SET_BIT(ADDRESS,BIT_NUMBER)     ADDRESS |= (1 << BIT_NUMBER)
#define RESET_BIT(ADDRESS,BIT_NUMBER)   ADDRESS &=~(1 << BIT_NUMBER)
#define TOGGLE_BIT(ADDRESS,BIT_NUMBER)  ADDRESS ^= (1 << BIT_NUMBER)
#define READ_BIT(ADDRESS,BIT_NUMBER)    ((ADDRESS & (1 << BIT_NUMBER))>> BIT_NUMBER)

//function to initialize the interrupts
void INTERUPT_INIT();

//function to initialize the GPIO module 
void GPIO_INIT();


int main(void)
{
	INTERUPT_INIT();
    GPIO_INIT();
    while (1) 
    {
		// clear the pins to turn off any led 
		RESET_BIT(PORTD,5);
		RESET_BIT(PORTD,6);
		RESET_BIT(PORTD,7);
    }
}
void INTERUPT_INIT()
{
	// enable the interrupt module 
	sei();
	// set INT0 to change with any logical change  
	SET_BIT(MCUCR,0);
	RESET_BIT(MCUCR,1);
	// set INT1 to change with raising edge 
    SET_BIT(MCUCR,3);
	SET_BIT(MCUCR,4);
	// set INT1 to change with falling edge 
	SET_BIT(MCUCR,6);
	
	// enable the external interrupt INT0 , INT1 and INT2
	SET_BIT(GICR,5);
	SET_BIT(GICR,6);
	SET_BIT(GICR,7);

}
void GPIO_INIT()
{
	// Set the direction of the 5 , 6 , 7 pins 
	SET_BIT(DDRD,5);
    SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
	// clear the pins 
	RESET_BIT(PORTD,5);
	RESET_BIT(PORTD,6);
	RESET_BIT(PORTD,7);
}
// external interrupt 0 >>>> PORTD pin 5 
ISR(INT0_vect)
{
	// set the pin to turn on the led
	SET_BIT(PORTD,5);
	// wait for 1s 
	_delay_ms(1000);
}
// external interrupt 1 >>>> PORTD pin 6
ISR(INT1_vect)
{
	// set the pin to turn on the led
	SET_BIT(PORTD,6);
	// wait for 1s
	_delay_ms(1000);
}
// external interrupt 2 >>>> PORTD pin 7
ISR(INT2_vect)
{
	// set the pin to turn on the led
	SET_BIT(PORTD,7);
	// wait for 1s
	_delay_ms(1000);
}

