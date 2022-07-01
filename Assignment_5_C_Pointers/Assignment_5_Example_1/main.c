/*
 * main.c
 *
 *  Created on: Jul 1, 2022
 *      Author: Dell
 */
/*C program demonstrate how to handle the pointers in the program.*/

#include"stdio.h"
#include"stdlib.h"


int main()
{
	int m = 29;
	printf("Address of m : 0x%p \n",&m);
	printf("Value of m : %d\n\n\n",m);

	int *ab = &m;
	printf("Now ab is assigned with the address of m.\n");
	printf("Address of pointer ab : 0x%p \n",ab);
	printf("Value of pointer ab : %d \n\n\n",*ab);

	m = 34;
	printf("The value of m assigned to 34 now.\n");
	printf("Address of pointer ab : 0x%p \n",ab);
    printf("Value of pointer ab : %d \n\n\n",*ab);

    *ab = 7;
    printf("The pointer variable ab is assigned with the value 7 now.\n");
    printf("Address of m : 0x%p \n",&m);
    printf("Value of m : %d\n\n\n",m);



	return 0;
}

