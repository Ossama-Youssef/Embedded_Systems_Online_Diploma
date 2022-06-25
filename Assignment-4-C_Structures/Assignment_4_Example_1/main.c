/*
 * main.c
 *
 *  Created on: Jun 24, 2022
 *      Author: Dell
 */
// C Program to store information (name , roll and marks) of student using structure

#include"stdio.h"

struct SPerson
{
	char name[50];
	int roll ;
	float marks ;
}student;
struct SPerson ReadData();
void DisplayData(struct SPerson student);

int main()
{
	student =  ReadData();
	DisplayData(student);

	return 0;
}
struct SPerson ReadData()
{
	struct SPerson student ;
	printf("Enter Information of student : \n");
	printf("Enter name :");
	fflush(stdin);fflush(stdout);
	fgets(student.name,50,stdin);
	printf("Enter roll number :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&student.roll);
	printf("Enter marks :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&student.marks);
	return student;
}
void DisplayData(struct SPerson student)
{
	printf("Displaying Data : \n");
	fflush(stdout);
    printf("Name :%s",student.name);
	fflush(stdout);
    printf("Roll :%d \n",student.roll);
	fflush(stdout);
    printf("Marks : %0.2f",student.marks);

}
