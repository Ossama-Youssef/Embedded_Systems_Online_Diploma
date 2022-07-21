/****************************************************************************************
           @file           : main.c
           @author         : Osama Youssef
           @brief          : program file to run the program and interact with console

 ******************************************************************************************/
#include<stdio.h>
#include"Linked_list.h"

int main()
{
	char main_temp_text[30];
	do
	{
		Dprintf("\n=======================================\n");
		Dprintf("Choose from the following choices : \n");
		Dprintf("1 : Add student \n");
		Dprintf("2 : Delete student \n");
		Dprintf("3 : display all students\n");
		Dprintf("4 : Delete all students \n");
		Dprintf("5 : get nth student \n");
		Dprintf("6 : get nth student from end \n");
		Dprintf("7 : get nth node from end using two pointer \n");
		Dprintf("8 : get length iterativily \n");
		Dprintf("9 : get length recursivily \n");
		Dprintf("10 : get the middle of list \n");
		Dprintf("11 : reverse the list \n");
		Dprintf("12 : Quit the system \n");
		Dprintf("\n========================================\n")
		Dprintf(" Enter the choice : ");
		fgets(main_temp_text,30,stdin);
		switch(atoi(main_temp_text))
		{
		case 1:
			add_student();break;
		case 2:
			delete_student();break;
		case 3:
			display_all_students();break;
		case 4:
			delete_all_students();break;
		case 5:
			get_nth_node();break;
		case 6:
			get_nth_node_from_end();break;
		case 7:
			get_nth_node_from_end_using_two_pointer();break;
		case 8:
			get_length_iterativily();break;
		case 9:
			print_get_length_recursivily();break;
		case 10:
			get_middle();break;
		case 11:
			reverse_list();break;
		case 12:
			Dprintf("\n **** Thank U ^_^*****\n");break;
		default:
			Dprintf("Wrong option !");break;

		}

	}while((atoi(main_temp_text))!= 12);

	return 0 ;
}
