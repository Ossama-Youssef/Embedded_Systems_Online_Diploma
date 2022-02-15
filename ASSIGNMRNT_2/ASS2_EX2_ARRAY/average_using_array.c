/*
 * average_using_array.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Dell
 */
#include"stdio.h"

int main()
{
	float data[100] , sum=0.0;
	int number , i;
	printf("Enter the number of data :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);

	while(number<0 || number>100)
	{
		printf("Error, you entered incorrect number \n");
		printf("enter a correct number in range(1--->100):");
		fflush(stdin);fflush(stdout);
		scanf("%d",&number);

	}
	for(i=0 ; i<number ; i++)
	{
		printf("%d.Enter number:",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&data[i]);
		sum+=data[i];

	}
   printf("Average =%.3f",sum/number);


	return 0;
}


