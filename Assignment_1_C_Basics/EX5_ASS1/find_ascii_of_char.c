/*
 * find_ascii_of_char.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Dell
 */
//EX5:
//Write C Program to Find ASCII Value of a Character

#include"stdio.h"

int main()
{
	char character;
	printf("Enter a character:");
	fflush(stdin);fflush(stdout);
    scanf("%c",&character);
    printf("ASCII value of %c = %d ",character,character);

	return 0;
}
