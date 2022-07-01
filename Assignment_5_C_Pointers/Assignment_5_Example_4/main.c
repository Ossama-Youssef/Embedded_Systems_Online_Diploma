/*
 * main.c
 *
 *  Created on: Jul 1, 2022
 *      Author: Dell
 */

//C Program to print the elements of an array in reverse order


#include"stdio.h"
#include"stdlib.h"
void reverse(int *sentence,int size);
int main()
{
	int elements[15],size ,i;
	printf("Input the number of elements to store in the array (max 15) :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size);
	printf("Input %d number of elements in the array : \n",size);
	for(i = 0 ; i < size ;i++)
	{
		printf("Element-%d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&elements[i]);
	}

	printf("The elements of array in reverse order are : \n");
	reverse(elements,size);
	return 0;
}
void reverse(int *elements,int size)
{
	int* ptr_elements = &elements[size-1],i;
	for(i = size-1 ; i >= 0 ; i--)
	{   printf("Element-%d : ",i+1);
		printf("%d \n",*ptr_elements);
		ptr_elements--;
	}

}
