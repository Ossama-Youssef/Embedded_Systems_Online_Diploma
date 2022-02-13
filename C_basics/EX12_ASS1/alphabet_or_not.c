/*
 * alphabet_or_not.c
 *
 *  Created on: Feb 11, 2022
 *      Author: Osama Youssef
 */
//EX12:C Program to Check Whether a Character iS an Alphabet or not
#include"stdio.h"

int main()
{
	char character;
		printf("Enter a character :");
		fflush(stdin);fflush(stdout);
		scanf("%c",&character);
		if((character>='a'&&character<='z')||(character>='A'&&character<='Z'))
			printf("%c is an alphabet",character);
		else
			printf("%c is not an alphabet",character);
	return 0;
}
