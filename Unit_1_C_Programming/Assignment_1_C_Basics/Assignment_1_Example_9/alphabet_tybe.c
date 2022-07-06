/*
 * alphabet_tybe.c
 *  Created on: Feb 10, 2022
 *      Author: Dell
 */
//EX9: C Program to Check Vowel or Consonant
#include"stdio.h"

int main()
{
	char character;
	printf(" Enter an alphabet:");
	fflush(stdin);fflush(stdout);
    scanf("%c",&character);
    switch(character)
    {
    	case 'a':
    	case 'A':
    	case 'i':
    	case 'I':
    	case 'o':
    	case 'O':
    	case 'y':
    	case 'Y':
    	case 'u':
    	case 'U':
    		printf("%c is a vowel",character);
    		break;
    	default:
		    printf("%c is consonant",character);
            break;
    }
	return 0;
}

