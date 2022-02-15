/*
 * main.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Dell
 */
//EX1:Write a C program to calculate sum two matrix of order 2*2 , entered by user
#include"stdio.h"

int main()
{
	float a[2][2] , b[2][2];
	int i , j ;
	printf("Enter the elements of 1st matrix :\r\n");
	fflush(stdin);fflush(stdout);
	for(i=0 ; i<2;i++)
	{
		for(j=0 ; j<2 ;j++)
		{
			printf("Enter a[%d][%d]:",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}
	printf("Enter the elements of 2st matrix :\r\n");
	fflush(stdin);fflush(stdout);
	for(i=0 ; i<2;i++)
	{
		for(j=0 ; j<2 ;j++)
		{
			printf("Enter b[%d][%d]:",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}
	for(i=0 ; i<2;i++)
	{
		for(j=0 ; j<2 ;j++)
		{
			a[i][j]+=b[i][j];
		}
	}
	printf("The sum of two matrix:\r\n");
	for(i=0 ; i<2;i++)
	{
		for(j=0 ; j<2 ;j++)
		{
			printf("%.2f",a[i][j]);
			printf("   ");
		}
		printf("\n");
	}

	return 0;
}


