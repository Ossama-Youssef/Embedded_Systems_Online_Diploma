/*
 * main.c
 *
 *  Created on: Jul 1, 2022
 *      Author: Dell
 */
//C Program to print a string in reverse using a pointer

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
void reverse(char *sentence,int size);
int main()
{
	char sentence[100];
	printf("Input a string :");
	fflush(stdin);fflush(stdout);
	fgets(sentence,100,stdin);
	printf("Reverse of the string is :");
	reverse(sentence,strlen(sentence));
	return 0;
}
void reverse(char *sentence,int size)
{
	char* ptr_sentence = &sentence[size],i;
	for(i = 0 ; i <= size ; i++)
	{
		printf("%c",*ptr_sentence);
		ptr_sentence--;
	}

}
