/*
 * transpose_of_array.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Dell
 */
#include"stdio.h"

int main()
{
	float arr1[10][10],arr2[10][10];
	int r , c  , j , i;
	printf("Enter rows and column of matrix:");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&r,&c);
	for(i=0 ; i<r ; i++)
	{
		for( j=0 ;j<c ;j++)
		{
			printf("Enter item[%d][%d]:",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&arr1[i][j]);
		}
	}
	printf("Array before Transpose:\r\n");

	for( i=0 ; i<r;i++)
	{
		for( j=0 ;j<c ;j++)
		{
			printf("%5.2f",arr1[i][j]);
			printf("    ");
		}
		printf("\r\n");
	}
	for( i=0 ; i<r;i++)
	{
		for( j=0 ;j<c ;j++)
		{
			arr2[j][i]=arr1[i][j];
		}
	}

	printf("Array after transpose :\r\n");
	for( i=0 ; i<c ;i++)
	{
		for( j=0 ;j<r ;j++)
		{
			printf("%5.2f",arr2[i][j]);
			printf("    ");
		}
		printf("\r\n");
	}

	return 0;
}



