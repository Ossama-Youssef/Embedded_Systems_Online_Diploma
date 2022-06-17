/*
 * main.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Dell
 */
#include"stdio.h"
#include"string.h"
int main()
{
	char text[1000],temp;
	int i ;
	printf("Enter a string : ");
	fflush(stdin);fflush(stdout);
	gets(text);
	for(i=0 ; i<strlen(text);i++)
	{

		if(i<strlen(text)/2)
		{
			temp=text[i];
			text[i]=text[strlen(text)-i-1];
			text[strlen(text)-i-1]=temp;
		}

	}

	printf("Reverse string is:%s",text);

	return 0;
}



