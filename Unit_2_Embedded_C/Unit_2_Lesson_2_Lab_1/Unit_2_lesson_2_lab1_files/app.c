/**********************************************************************/
/*         @author : Osama Youssef                                    */  
/*         @file   : main.c                                           */
/*         @brief  : main function  that containg the string -we want */ 
/*                     transmit it-and calls Uart_send_String         */
/*                                                                    */
/**********************************************************************/
 

 #include "Uart.h"

// define the string 

unsigned char string_name[100] ="Learn-in-depth : < Osama Youssef >";


void main(void)
{

	Uart_send_String(string_name);
}