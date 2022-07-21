/****************************************************************************************
           @file           : lifo.c
           @author         : Osama Youssef
           @brief          : c file for LIFO Buffer , implement the API's

 ******************************************************************************************/
#include"lifo.h"

//Defination of LIFO API's

// API to initialize items to our LIFO : we will recive the LIFO, the array which will store in, the counter and return the LIFO status
LIFO_STATUS lifo_init_items( LIFO_BUFF_t* lifo_buf , Element_type* buf , Element_type length )
{
	if(buf == (Element_type*)0x0) // checking the pointer is points to NULL or not
		return LIFO_FULL;

	lifo_buf->base = buf ; // base pointer points to base of LIFO
	lifo_buf->head = buf ; // head pointer points to base of LIFO
	lifo_buf->length = length ; // set the length of LIFO
	lifo_buf->count = 0  ; // reset the counter
	return LIFO_NO_ERROR ;
}


// API to add items to our LIFO : we will recive the LIFO ,the item and return the LIFO status
LIFO_STATUS lifo_push_item( LIFO_BUFF_t* lifo_buf ,Element_type item )
{
	if (lifo_buf->count == lifo_buf->length ) // check if LIFO is full
		return LIFO_FULL ;
	if (!lifo_buf->base|| !lifo_buf->head ) // check if LIFO is exist
		return LIFO_NULL ;

	// adding the new item
	*(lifo_buf->head) = item ;
	lifo_buf->head++;
	lifo_buf->count++;
	return LIFO_NO_ERROR ;


}

// API to get items to our LIFO : we will recive the LIFO ,the location ofitem and return the LIFO status
LIFO_STATUS lifo_pop_item( LIFO_BUFF_t* lifo_buf , Element_type* item )
{
	if (lifo_buf->count == 0 ) // check if LIFO is empty
		return LIFO_EMPTY ;
	if (!lifo_buf->base|| !lifo_buf->head ) // check if LIFO is exist
		return LIFO_NULL ;


	// poping the item
	lifo_buf->head--;
	lifo_buf->count--;
	*item = *lifo_buf->head ;
	return LIFO_NO_ERROR ;

}


