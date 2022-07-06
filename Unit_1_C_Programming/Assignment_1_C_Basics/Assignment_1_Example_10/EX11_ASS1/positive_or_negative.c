/*
 * positive_or_negative.c
 *
 *  Created on: Feb 11, 2022
 *      Author: Dell
 */
//EX11: C Program to Check Whether a Number is Positive or Negative
#include<stdio.h>

void main()
{
	float number;
	printf("Enter a number :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&number);
	if(number>0)
		printf("%.2f is positive",number);
	else if(number<0)
		printf("%.2f is negative",number);
	else
		printf("You entered zero");

}
