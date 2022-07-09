/*****************************************************************/
/*          @author : Osama Youssef                              */  
/*          @file   : uart.c                                     */
/*          @brief  : Function prints string using uart0 module  */ 
/*                    in versitalePB microcontroller based on    */
/*                    ARM926EJ-S microprocessor                  */
/*****************************************************************/
 

 #include "uart.h"

/* Register Defination */

#define UART0DR_BASE  0x101f1000

#define UART0DR  *((volatile unsigned int * const )((unsigned int *)(UART0DR_BASE)))

/* Uart_send_String Function Defination */

void Uart_send_String(unsigned char * ptr_tx_string)
{
    while(* ptr_tx_string != '\0')
    {
        UART0DR = (unsigned int) (* ptr_tx_string);
        ptr_tx_string++ ;
    }

}