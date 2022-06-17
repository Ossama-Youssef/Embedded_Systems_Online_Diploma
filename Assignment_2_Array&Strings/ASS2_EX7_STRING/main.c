/*
 * main.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Dell
 */
//EX6:C Program to find the frequency of character in strings
#include"stdio.h"

int main()
{
	char string[100],ch;
	int i , counter=0;
	printf("Enter a string :");
	fflush(stdin);fflush(stdout);
	gets(string);
	printf("Enter a character to find frequency :");
	fflush(stdin);fflush(stdout);
	scanf("%c",&ch);

	for(i=0 ;i<sizeof(string);i++)
	{
		if(ch==string[i])
		{
		counter++;
		}
	}
    printf("Frequency of %c =%d",ch,counter);


	return 0;
}
