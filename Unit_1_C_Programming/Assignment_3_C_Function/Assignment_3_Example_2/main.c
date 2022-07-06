/*
 * main.c
 *
 *  Created on: Jun 16, 2022
 *      Author: Dell
 */
// C Program to calculate the factorial of number by recursion
#include"stdio.h"
int factorial(int number);
int main()
{
	int number ;
	printf("Enter an positive number :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	printf("Factorial of %d = %d ",number,factorial(number));


	return 0;
}
int factorial(int number)
{ int result=number;
 if (number==2)
	return 2;
 else
	return result * factorial(number-1);

}
