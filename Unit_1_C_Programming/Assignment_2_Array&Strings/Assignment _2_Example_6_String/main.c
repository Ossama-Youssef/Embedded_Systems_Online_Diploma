/*
 * main.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Dell
 */
#include"stdio.h"

int main()
{
   char text[1000];
   int i ;
	printf("Enter a string : ");
	fflush(stdin);fflush(stdout);
	gets(text);
    for(i=0 ; text[i]!='\0';i++);
    printf("Length of strings:%d",i);


	return 0;
}



