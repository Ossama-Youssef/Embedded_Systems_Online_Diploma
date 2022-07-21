/****************************************************************************************
           @file           : main.c
           @author         : Osama Youssef
           @brief          : program file , we will test the FIFO here

 ******************************************************************************************/
#include<stdio.h>
#include "fifo.h"
#include "Platform_types.h"
#define casting_type uint32

#define length 7 // length of FIFO
Element_type buffer[length]; // array with length items


int main()
{
	Element_type counter , temp ;
	FIFO_BUFF_t uart_fifo ;

	// initialize the FIFO
	if(fifo_init_items(& uart_fifo,buffer,length) == FIFO_NO_ERROR )
	{
		printf("FIFO initialization............ Done \n");
	}

	// Enqueuing values to FIFO
	for(counter = 0 ; counter < 10 ; counter++ )
	{
		printf("FIFO Enqueue : %x \n", (casting_type)counter);
		if (fifo_enqueue(&uart_fifo , counter ) == FIFO_NO_ERROR )
			printf("\t FIFO Enqueue ............... Done \n");
		else
			printf("\t FIFO Enqueue ............... failed \n");

	}


	fifo_print(&uart_fifo);


	// Dequeuing values from FIFO

	if (fifo_dequeue(&uart_fifo ,&temp) == FIFO_NO_ERROR )
	{
		printf("\t FIFO Dequeue : %x \n",(casting_type)temp);
		printf("\t FIFO Dequeue ............... Done \n");

	}
	else
		printf("\t FIFO Dequeue ............... failed \n");

	if (fifo_dequeue(&uart_fifo ,&temp) == FIFO_NO_ERROR )
	{
		printf("\t FIFO Dequeue : %x \n",(casting_type) temp);
		printf("\t FIFO Dequeue ............... Done \n");
	}
	else
		printf("\t FIFO Dequeue ............... failed \n");

	if (fifo_dequeue(&uart_fifo ,&temp) == FIFO_NO_ERROR )
	{
		printf("\t FIFO Dequeue : %x \n",(casting_type)temp);
		printf("\t FIFO Dequeue ............... Done \n");
	}
	else
		printf("\t FIFO Dequeue ............... failed \n");

	fifo_print(&uart_fifo);


	return 0;
}

