/*
 * main.c
 *
 *  Created on: Jun 17, 2022
 *      Author: Dell
 */
//C Program to calculate the power of a number using recursion

#include"stdio.h"
int PowerOfNumber(int base ,int power);

int main()
{
	int base , power ;
	printf("Enter base number :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&base);
	printf("Enter power number(positive number):");
	fflush(stdin);fflush(stdout);
	scanf("%d",&power);
	printf("%d ^ %d = %d",base , power , PowerOfNumber(base,power));

	return 0;
}
int PowerOfNumber(int base ,int power)
{
	if (power ==1 )
		return base ;
	else
		return base * PowerOfNumber(base,power-1);
}


















