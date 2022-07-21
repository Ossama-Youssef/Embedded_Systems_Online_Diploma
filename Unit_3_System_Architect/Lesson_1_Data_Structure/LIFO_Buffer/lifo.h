/****************************************************************************************
           @file           : lifo.h
           @author         : Osama Youssef
           @brief          : Header file for LIFO Buffer data structure

 ******************************************************************************************/


#ifndef LIFO_H_
#define LIFO_H_


#include "Platform_types.h"
// user configration
// choose the size of data type (uint8 , uint16 , uint32 , ....)
typedef uint32 Element_type ;



// Defination of LIFO Parameters like : base , head , length and counter
// we will use struct to combine them in one place and treat with LIFO as an object
typedef struct
{
	unsigned int length ;
	unsigned int count  ;
	Element_type *base  ;
	Element_type *head  ;

}LIFO_BUFF_t;

// Defination of LIFO status like : LIFO_FULL , LIFO_EMPTY , LIFO_NULL and LIFO_NO_ERROR
// we will use enum data type to be more realable

typedef enum
{
	LIFO_NO_ERROR ,
	LIFO_NULL     ,
	LIFO_EMPTY    ,
	LIFO_FULL

}LIFO_STATUS;

// Prototypes of LIFO API's

// API to add items to our LIFO : we will recive the LIFO ,the item and return the LIFO status
LIFO_STATUS lifo_push_item( LIFO_BUFF_t* lifo_buf ,Element_type item );

// API to get items to our LIFO : we will recive the LIFO ,the location ofitem and return the LIFO status
LIFO_STATUS lifo_pop_item( LIFO_BUFF_t* lifo_buf , Element_type* item );

// API to initialize items to our LIFO : we will recive the LIFO, the array which will store in, the counter and return the LIFO status
LIFO_STATUS lifo_init_items( LIFO_BUFF_t* lifo_buf , Element_type* buf ,Element_type length );



#endif /* LIFO_H_ */
