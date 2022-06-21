/*
 * main.c
 *
 *  Created on: Jun 17, 2022
 *      Author: Osama Youssef 
 */
#include"stdio.h"
void reverse();
int main()
{
	printf("Enter a sentence :");    
	reverse();   

	return 0;
}
void reverse()
{
	char c;
	scanf("%c",&c);
	if(c != '\n')
	{
		reverse();
		printf("%c",c);
	}
}

