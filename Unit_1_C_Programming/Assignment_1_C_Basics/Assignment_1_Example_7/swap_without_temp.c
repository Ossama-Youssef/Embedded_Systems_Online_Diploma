/*
 * swap_without_temp.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Dell
 */
//EX7:
//it is an interview trick
//Write Source Code to Swap Two Numbers without temp variable.
#include"stdio.h"

int main()
{
	float a , b , result ;
	printf("Enter value of a:");
	fflush(stdin);fflush(stdout);
    scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin);fflush(stdout);
    scanf("%f",&b);
    result = a*b ;
    a=result/a;
    b=result/b;
    printf("After swapping, value of a = %5.2f \n",a);
    printf("After swapping, value of b = %5.2f",b);
	return 0;
}



