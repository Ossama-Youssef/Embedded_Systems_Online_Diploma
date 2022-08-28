/**********************************************************/
/*          @author : Osama Youssef                       */  
/*          @file   : Platform_Types                      */
/*          @brief  : File containg type defination       */
/*                        for all data types              */ 
/*                                                        */  
/**********************************************************/

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include<stdint.h>

/************ Unsigned data types ***********/

typedef unsigned char          Bool;
typedef unsigned char          uint8;
typedef unsigned short         uint16;
typedef unsigned long          uint32;
typedef unsigned long long     uint64;

/********************************************/

/************** signed data types ***********/

typedef  signed char            sint8;
typedef  signed short           sint16;
typedef  signed long            sint32;
typedef signed long long        sint64;

/*******************************************/

/**** Real floating point data types *******/

typedef float           float32; 
typedef double          float64;

/********************************************/

/******* Volatile unsigned data types *******/

typedef volatile unsigned char          vuint8;
typedef volatile unsigned short         vuint16;
typedef volatile unsigned long          vuint32;
typedef volatile unsigned long long     vuint64;

/**********************************************/

/******* Volatile signed data types *******/

typedef volatile signed char          vsint8;
typedef volatile signed short         vsint16;
typedef volatile signed long          vsint32;
typedef volatile signed long long     vsint64;

/**********************************************/

/****** volatile real floating point data types ********/

typedef volatile float           vfloat32; 
typedef volatile double          vfloat64;

/***********************************************/

#endif /*PLATFORM_TYPES_H_*/ 