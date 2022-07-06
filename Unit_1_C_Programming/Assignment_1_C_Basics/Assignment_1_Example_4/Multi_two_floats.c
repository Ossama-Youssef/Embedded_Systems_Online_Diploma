/*
 * Multi_two_floats.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Dell
 */
//EX4:
//Write C Program to Multiply two Floating Point Numbers

#include"stdio.h"

int main()
{
	float num1=0 ,num2=0;
	printf("Enter a two float numbers:");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&num1,&num2);
	printf("sum =%f",num1*num2);
	return 0;
}

