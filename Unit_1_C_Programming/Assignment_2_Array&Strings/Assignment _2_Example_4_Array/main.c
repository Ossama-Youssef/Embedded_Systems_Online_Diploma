/*
 * main.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Dell
 */
//EX4:C Program to insert an element
#include"stdio.h"

int main()
{
	int data[100],i , place,number,element;
	printf("Enter no of elements : ");
	fflush(stdin);fflush(stdout);
    scanf("%d",&number);
    for(i=0 ; i<number ;i++)
    {
    	scanf("%d",&data[i]);
    }
    printf("Enter the element to be inserted: ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&element);
    printf("Enter the location : ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&place);
    for(i=number+1;i>=place;i--)
    {
    	data[i]=data[i-1];
    }
    data[place-1]=element;
    for(i=0 ; i<(number+1) ;i++)
      {
      	printf("%d  ",data[i]);
      }
	return 0;
}
