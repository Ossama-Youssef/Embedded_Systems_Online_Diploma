/****************************************************************************************
           @file           : State.h
           @author         : Osama Youssef
           @brief          : Header file for define the states in any project

 ******************************************************************************************/

#ifndef STATE_H_
#define STATE_H_
#include <stdio.h>
#include <stdlib.h>

// Automatic state function generated by macros
#define STATE_Define(_STATEFUNC_) void ST_##_STATEFUNC_()
#define STATE_(_stateFUN_)          ST_##_stateFUN_
#endif /* STATE_H_ */
