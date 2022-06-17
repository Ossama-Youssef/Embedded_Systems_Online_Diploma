/*
 * main.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Dell
 */

//EX5:C Program to search an element in array
#include"stdio.h"

int main()
{
	int data[100],i ,number,element;
	printf("Enter no of elements : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	for(i=0 ; i<number ;i++)
	{
		scanf("%d",&data[i]);
	}
	printf("Enter the element to be searched: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&element);
	for(i=0 ; i<number ;i++)
	{
		if(element==data[i])
		{
			printf("number found at location : %d",i+1);
			break;
		}
	}
	if(i==number)
		printf("number not found");

	return 0;
}


