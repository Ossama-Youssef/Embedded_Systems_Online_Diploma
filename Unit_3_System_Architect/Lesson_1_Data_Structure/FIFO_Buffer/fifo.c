/****************************************************************************************
           @file           : lifo.c
           @author         : Osama Youssef
           @brief          : c file for FIFO Buffer , implementation for the API's

 ******************************************************************************************/
#include"fifo.h"
#include "Platform_types.h"
#define casting_type uint32
//Defination of FIFO API's

// API to initialize items to our FIFO : we will recive the FIFO, the array which will store in, the counter and return the FIFO status
FIFO_STATUS fifo_init_items( FIFO_BUFF_t* fifo_buf , Element_type* buf , uint32 length )
{
	if(buf == (Element_type*)0x0) // checking the pointer is points to NULL or not
		return FIFO_FULL;

	fifo_buf->base = buf ;              // base pointer points to base of FIFO
	fifo_buf->head = fifo_buf->base ;   // head pointer points to base of FIFO
	fifo_buf->tail = fifo_buf->base ;   // tail pointer points to base of FIFO
	fifo_buf->length = length ;         // set the length of FIFO
	fifo_buf->count = 0  ;              // reset the counter
	return FIFO_NO_ERROR ;
}


// API to add items to our FIFO : we will recive the FIFO ,the item and return the FIFO status
FIFO_STATUS fifo_enqueue( FIFO_BUFF_t* fifo_buf ,Element_type item )
{
	if (fifo_is_full(fifo_buf) == FIFO_FULL  ) // check if FIFO is full
		return FIFO_FULL ;
	if (!fifo_buf->base|| !fifo_buf->head ) // check if FIFO is exist
		return FIFO_NULL ;

	// adding the new item
	*(fifo_buf->head) = item ;
	fifo_buf->count++;

	// Circular FIFO
	if(fifo_buf->head == (fifo_buf->base + fifo_buf->length *sizeof(Element_type)))
		fifo_buf->head = fifo_buf->base ;
	else
		fifo_buf->head++ ;

	return FIFO_NO_ERROR ;
}

// API to get items to our FIFO : we will recive the FIFO ,the location ofitem and return the FIFO status
FIFO_STATUS fifo_dequeue( FIFO_BUFF_t* fifo_buf , Element_type* item )
{
	if (fifo_is_empty(fifo_buf) ==  FIFO_EMPTY) // check if FIFO is empty
		return FIFO_EMPTY ;
	if (!fifo_buf->base|| !fifo_buf->head || !fifo_buf->tail ) // check if FIFO is exist
		return FIFO_NULL ;


	// Dequening the item
	*item = *fifo_buf->tail ;
	fifo_buf->count--;
	// Circular FIFO
	if(fifo_buf->tail == (fifo_buf->base + fifo_buf->length *sizeof(Element_type)))
		fifo_buf->tail = fifo_buf->base ;
	else
		fifo_buf->tail++ ;

	return FIFO_NO_ERROR ;

}

// API to check if FIFO is full
FIFO_STATUS fifo_is_full( FIFO_BUFF_t* fifo_buf )
{
	if (!fifo_buf->base|| !fifo_buf->head || !fifo_buf->tail ) // check if FIFO is exist
		return FIFO_NULL ;

	if(fifo_buf->count == fifo_buf->length)
		return FIFO_FULL ;

	return FIFO_NO_ERROR ;

}

// API to check if FIFO is empty
FIFO_STATUS fifo_is_empty( FIFO_BUFF_t* fifo_buf )
{
	if (!fifo_buf->base|| !fifo_buf->head || !fifo_buf->tail ) // check if FIFO is exist
		return FIFO_NULL ;
	if (fifo_buf->count == 0 ) // check if FIFO is empty
		return FIFO_EMPTY ;

	return FIFO_NO_ERROR ;
}

// API to print the items of FIFO
void fifo_print( FIFO_BUFF_t* fifo_buf )
{
	Element_type* temp ;
	uint32  counter ;
	if(fifo_is_empty(fifo_buf) == FIFO_EMPTY )
		printf("...... FIFO is EMPTY ...... \n");
	else
	{
          temp = fifo_buf->tail ;
          printf("....... FIFO Print .......... \n");
          for (counter = 0 ; counter < fifo_buf->count ; counter ++ )
          {
        	  printf("\t %x \n",(casting_type)*temp);
        	  temp++;
          }
          printf("................................ \n");
	}

}

