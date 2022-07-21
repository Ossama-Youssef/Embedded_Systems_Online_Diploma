/****************************************************************************************
           @file           : fifo.h
           @author         : Osama Youssef
           @brief          : Header file of FIFO data Structure contain data types definations
                                 and the API's prototypes

 ******************************************************************************************/
#ifndef FIFO_H_
#define FIFO_H_
#include<stdio.h>
#include "Platform_types.h"
// user configration
// choose the size of data type (uint8 , uint16 , uint32 , ....)
typedef uint32 Element_type ;
#define casting_type uint32
// Defination of FIFO Parameters like : base , head , tail, length and counter
// we will use struct to combine them in one place and treat with FIFO as an object
typedef struct
{
	unsigned int length ;
	unsigned int count  ;
	Element_type *base  ;
	Element_type *head  ;
	Element_type *tail  ;

}FIFO_BUFF_t;

// Defination of FIFO status like : FIFO_FULL , FIFO_EMPTY , FIFO_NULL and FIFO_NO_ERROR
// we will use enum data type to be more realable

typedef enum
{
	FIFO_NO_ERROR ,
	FIFO_NULL     ,
	FIFO_EMPTY    ,
	FIFO_FULL

}FIFO_STATUS;

// Prototypes of FIFO API's

// API to add items to our FIFO : we will recive the FIFO ,the item and return the FIFO status
FIFO_STATUS fifo_enqueue( FIFO_BUFF_t* fifo_buf ,Element_type item );

// API to get items to our FIFO : we will recive the FIFO ,the location ofitem and return the FIFO status
FIFO_STATUS fifo_dequeue( FIFO_BUFF_t* fifo_buf , Element_type* item );

// API to initialize items to our FIFO : we will recive the FIFO, the array which will store in, the counter and return the FIFO status
FIFO_STATUS fifo_init_items( FIFO_BUFF_t* fifo_buf , Element_type* buf , uint32 length );

// API to check if FIFO is full
FIFO_STATUS fifo_is_full( FIFO_BUFF_t *fifo_buf );

// API to check if FIFO is empty
FIFO_STATUS fifo_is_empty( FIFO_BUFF_t* fifo_buf );

// API to print the items of FIFO
void fifo_print( FIFO_BUFF_t* fifo_buf );


#endif /* FIFO_H_ */
