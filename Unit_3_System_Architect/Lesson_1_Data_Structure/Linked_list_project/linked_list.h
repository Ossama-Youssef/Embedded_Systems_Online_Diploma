/****************************************************************************************
           @file           : Linked_list.h
           @author         : Osama Youssef
           @brief          : Header file for linked list data structure contain
                                    API's prototypes and data types
 ******************************************************************************************/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

// Include all used library in whole program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define Dprintf(...) { fflush(stdin);fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);fflush(stdout);}


// struct contains the student information like : ID , Name and Height
// Effective Data
typedef struct
{
	int m_ID ;
	char m_name[30];
	float m_height ;
}SData_t;

// struct contain the effictive data plus the pointer which points to the next node
// linked list nodes

typedef struct
{
	SData_t student ;
	struct SStudent_t* ptr_nextStudent ;
}SStudent_t;

// Prototype for linked list API's

// API to add a student to the linked list
void add_student();

// API to delete a student from the linked list
int delete_student();

// API to display all students in the linked list
void display_all_students();

// API to delete all students in the linked list
void delete_all_students();

// API to Fill a given record with data
void fill_student(SStudent_t* ptr_newstudent);

// API to gets nth node in linked list
void get_nth_node();

// API to display certain record
void display_student_nth(SStudent_t *ptr_currentStudent,unsigned int index);

// API to get length of linked list by using iterative method
void get_length_iterativily();

// API to get length of linked list by using recursive method
unsigned int get_length_recursivily(SStudent_t* ptr_currentStudent);
void print_get_length_recursivily();

// API to get nth node from end using the length of linked list
void get_nth_node_from_end();

// API to get nth node from end using the two pointer techniques
void get_nth_node_from_end_using_two_pointer();

// API to get the middle of the linked list if odd and second middle if even
void get_middle();

// API to reverse the linked list
void reverse_list();

#endif /* LINKED_LIST_H_ */
