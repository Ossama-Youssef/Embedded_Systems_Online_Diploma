/*
 * largest_number.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Dell
 */
//EX10:C Program to Find the Largest Number Among Three Numbers
#include"stdio.h"

int main()
{
	float x , y , z;
	printf("Enter three number :");
	fflush(stdin);fflush(stdout);
    scanf("%f %f %f",&x,&y,&z);
    if(x>=y && x>=z)
    	printf("Largest number :%5.3f",x);
    else if(y>=x && y>=z)
       	printf("Largest number :%5.3f",y);
    else
       	printf("Largest number :%5.3f",z);

}
