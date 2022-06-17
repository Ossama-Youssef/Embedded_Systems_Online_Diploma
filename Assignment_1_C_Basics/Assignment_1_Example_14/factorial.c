/*
 * factorial.c
 *
 *  Created on: Feb 11, 2022
 *      Author: Dell
 */
//EX14:C Program to Calculate a Factorial
#include"stdio.h"

int main()
{
	int number , fact=1;
	printf("Enter an integer :");
	fflush(stdin);fflush(stdout);
    scanf("%d",&number);
    if(number<0)
    	printf("Error!! Factorial of negative number doesn't exist");
    else if(number==0 || number==1)
    	printf("Factorial = 1");
    else
    	{
    	  for(int i=1 ; i<= number ;i++)
    		  fact*=i;
    	  printf("Factorial =%d ",fact);
    	}

	return 0;
}

