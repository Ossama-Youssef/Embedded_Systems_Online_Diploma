/*
 * sumTwoNumber.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Dell
 */

//EX3:
//Write C Program to Add Two Integers
#include"stdio.h"

int main()
{
	int num1=0 ,num2=0;
	printf("Enter a two integer numbers:");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&num1,&num2);
	printf("sum =%d",num1+num2);
	return 0;
}
