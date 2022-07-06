/*
 * even_or_odd.c
 *  Created on: Feb 10, 2022
 *      Author: Dell
 */
//EX8: Write C Program to Check Whether a Number is Even or Odd
#include"stdio.h"
int main()
{
	int number;
	printf("Enter an integer you want to check :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	if(number%2==0)
		printf("%d is even",number);
	else if(number%2!=2)
		printf("%d is odd",number);
	else
		printf("you entered incorrect value");
	return 0;
}

