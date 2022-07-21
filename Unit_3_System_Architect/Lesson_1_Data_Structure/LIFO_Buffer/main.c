/****************************************************************************************
           @file           : main.c
           @author         : Osama Youssef
           @brief          : program file , we will test the LIFO here

 ******************************************************************************************/
#include<stdio.h>
#include "lifo.h"
#include "Platform_types.h"
#define length 10 // length of LIFO
Element_type buffer[length]; // array will contain items
int main()
{
	Element_type counter , temp ;
	LIFO_BUFF_t uart_lifo ;

	// initialize the LIFO
	lifo_init_items(& uart_lifo,buffer,length);

	// push values to LIFO
	for(counter = 0 ; counter < length ; counter++ )
	{
		if (lifo_push_item(&uart_lifo ,counter ) == LIFO_NO_ERROR )
			printf("\n LIFO push item : %ld", counter);
	}
    printf("\n\n\n");
	// pop values from LIFO
	for(counter = 0 ; counter < length ; counter++ )
	{
		if (lifo_pop_item(&uart_lifo , &temp ) == LIFO_NO_ERROR )
			printf("\n LIFO pop item : %ld", temp);
	}


	return 0;
}
