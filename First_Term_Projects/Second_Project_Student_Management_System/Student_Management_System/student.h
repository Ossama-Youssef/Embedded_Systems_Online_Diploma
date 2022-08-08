/****************************************************************************************
           @file           : student.h
           @author         : Osama Youssef
           @brief          : Header file of student Management system data types definations
                                 and the API's prototypes
 ******************************************************************************************/

#ifndef STUDENT_H_
#define STUDENT_H_

// include the used libraries in the project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "platform_types.h"

#define Dprintf(...) {fflush(stdin);fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);fflush(stdout);}

#define Dscanf(val,...) {fflush(stdin);fflush(stdout);\
		scanf(__VA_ARGS__,val);\
		fflush(stdin);fflush(stdout);}

/*****************************************************************************************/

// Defination of struct contains student information
/* student information will be 1- first name
 *                             2- last name
 *                             3- unique roll number
 *                             4- GPA
 *                             5- courses ID
 */
typedef struct
{
	char fname[50];
	char lname[50];
	int roll;
	float GPA ;
	int cid[10];
}sinfo;

/*****************************************************************************************/

// determine the total number of student in the system
#define TotalNumber 50
sinfo Students[TotalNumber];

/*****************************************************************************************/

// Defination of FIFO Parameters like : base , head , tail, length and counter
// we will use struct to combine them in one place and treat with FIFO as an object
typedef struct
{
	unsigned int length ;
	unsigned int count  ;
	sinfo *base  ;
	sinfo *head  ;
	sinfo *tail  ;

}FIFO_BUFF_t;

/*****************************************************************************************/

// Defination of FIFO status like : FIFO_FULL , FIFO_EMPTY , FIFO_NULL and FIFO_NO_ERROR
// we will use enum data type to be more realable

typedef enum
{
	FIFO_NO_ERROR ,
	FIFO_NULL     ,
	FIFO_EMPTY    ,
	FIFO_FULL

}FIFO_STATUS;

/*****************************************************************************************/

// Prototypes of system API's

// API to initialize items to our FIFO : we will recive the FIFO, the array which will store in , and the lenth
void FIFO_Init_Items( FIFO_BUFF_t* fifo_buf , sinfo* buf , uint32 length );

// API to add students info from file to our FIFO : we will recive the FIFO
void Add_Student_From_File( FIFO_BUFF_t* fifo_buf );

// API to add student info manually to our FIFO : we will recive the FIFO
void Add_Student_Manually( FIFO_BUFF_t* fifo_buf );

// API to search and find the student information by roll number
void Find_Student_By_Roll( FIFO_BUFF_t* fifo_buf );

// API to search and find the student information by first name
void Find_Student_By_First_Name( FIFO_BUFF_t* fifo_buf );

//API to find the number of student inrolled in course using course ID
void Find_NO_Of_Student_IN_Course(FIFO_BUFF_t* fifo_buf );

// API to count the total number of student
void Find_Total_Number( FIFO_BUFF_t* fifo_buf );

// API to delete student information from the system
void Delete_Student( FIFO_BUFF_t* fifo_buf );

// API to update student information in the system the system
void Update_Student_Info( FIFO_BUFF_t* fifo_buf );

// API to show all students infomation in the system
void Show_Student( FIFO_BUFF_t* fifo_buf );

// API to check if FIFO is full
FIFO_STATUS fifo_is_full( FIFO_BUFF_t *fifo_buf );

// API to check if FIFO is empty
FIFO_STATUS fifo_is_empty( FIFO_BUFF_t* fifo_buf );

// API to check if FIFO is empty
FIFO_STATUS fifo_is_null( FIFO_BUFF_t* fifo_buf );

// API to check if the roll number of student is exist before or not
int Check_Roll(FIFO_BUFF_t* fifo_buf , sinfo* buf , uint32 number);

// API to swap two students
void Swap(sinfo* student1 , sinfo * student2);

#endif /* STUDENT_H_ */
