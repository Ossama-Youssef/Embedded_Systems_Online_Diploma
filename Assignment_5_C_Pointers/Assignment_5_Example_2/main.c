/*
 * main.c
 *
 *  Created on: Jul 1, 2022
 *      Author: Dell
 */

//C Program to print all the alphabets using a pointer

#include"stdio.h"
#include"stdlib.h"


int main()
{
	char alphabet ='A',i;
    char *ptr_alphabet = &alphabet;
    printf("The Alphabets are : \n");
    for(i = 0 ; i < 26 ; i++,alphabet++)
         printf("%c   ",*ptr_alphabet);

	return 0;
}
