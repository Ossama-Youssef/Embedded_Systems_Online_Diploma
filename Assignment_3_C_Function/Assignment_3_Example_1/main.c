/*
 * main.c
 *
 *  Created on: Jun 16, 2022
 *      Author: Dell
 */
//Program to calculate prime numbers between two numbers (intervals)
#include"stdio.h"
int prime(int x);
int main()
{
	int number1 , number2 ,check , i;
	printf("Enter two number(intervals):");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&number1,&number2);
	fflush(stdin);fflush(stdout);
	printf("Prime numbers between %d and %d are :",number1,number2);
	for(i=number1+1;i<number2;i++)
	{
		check=prime(i);
		if(check==0)
			printf("%d ",i);
	}

	return 0;
}
int prime(int num)
{     int z=0 , j;
for(j=2 ; j<=(num/2);j++)
	if(num%j==0)
	{
		z=1;
		break;
	}
return z;
}
