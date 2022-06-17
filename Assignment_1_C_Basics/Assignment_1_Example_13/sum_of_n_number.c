/*
 * sum_of_n_number.c
 *
 *  Created on: Feb 11, 2022
 *      Author: Dell
 */
//EX13:C Program to Calculate a Sum of Natural Numbers
#include"stdio.h"

int main()
{
	int number , sum=0;
    printf("Enter an integer :");
    fflush(stdin);fflush(stdout);
    scanf("%d",&number);
	for(int i=1 ; i<=number ; i++)
		sum+=i;
    printf("sum = %d",sum);

	return 0;
}

