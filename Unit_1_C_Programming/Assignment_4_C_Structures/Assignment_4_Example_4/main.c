/*
 * main.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Dell
 */
// C Program to store informations (name , roll and marks) of students using structure

#include"stdio.h"
#define NumberOfStudents  5
struct SPerson
{
	char name[50];
	float marks ;
}student[NumberOfStudents];
struct SPerson ReadData(int rollNumber);
void DisplayData(struct SPerson student,int rollNumber);

int main()
{
	int  rollNumber = 0;
	printf("Enter Information of students : \n");
	for(rollNumber = 0 ; rollNumber < NumberOfStudents ; ++rollNumber)
	  {
		student[rollNumber] =  ReadData(rollNumber);
	  }
	printf("Displaying Information for students: \n");

	for(rollNumber = 0 ; rollNumber < NumberOfStudents ; ++rollNumber)
	  {
		DisplayData(student[rollNumber],rollNumber);
	  }

	return 0;
}
struct SPerson ReadData(int rollNumber)
{
	struct SPerson student ;
	printf("For roll number %d \n",rollNumber+1);
	printf("Enter name :");
	fflush(stdin);fflush(stdout);
	fgets(student.name,50,stdin);
	printf("Enter marks :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&student.marks);
	printf("\n");
	return student;
}
void DisplayData(struct SPerson student , int rollNumber)
{
	printf("Information of roll %d \n",rollNumber + 1);
	fflush(stdout);
	printf("Name :%s",student.name);
	fflush(stdout);
	printf("Marks : %3.1f",student.marks);
	fflush(stdout);
	printf("\n");
}

