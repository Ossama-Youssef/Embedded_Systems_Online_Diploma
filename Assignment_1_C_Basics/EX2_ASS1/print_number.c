/*
 * print_number.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Osama Youssef
 *
 *EX2
 *Write C Program to Print a Integer Entered by a User
*/
#include"stdio.h"

int main()
{
	int number;
	printf("Enter an integer :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	printf("You entered : %d",number);
	return 0;
}


