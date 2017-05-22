#ifndef DEFINITION_STACK
#define DEFINITION_STACK

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "board.h"
#include "group.h"

/********************
 * ERROR DEFINITION *
 ********************/
#define OK			0
#define ERR_CREATE_NODE		1
#define ERR_CREATE_GROUP	2
#define ERR_CREATE_ELEMENT	3
#define ERR_CREATE_GRAPH	4
#define ERR_ADD_EDGE		5
#define ERR_CREATE_DATA		6

/**********************
 * STRUCTURE OF STACK *
 **********************/
typedef struct stack_s

{
  int size;
 struct element_data_s *first;
}stack;

/*********************
 * STRUCTURE OF DATA *
 *********************/
typedef struct element_data_s{
    int turn;
    int player;
    int x;
    int y;
    struct element_data_s *next;

}element_data;


/*******************************************
 * Role: Create a stack of DATA            *
 * stack : Stack of data (player, turn,x,y *
 *******************************************/
void createStack (stack* stack);


bool isEmptyStack (const stack *s);



/********************************************
 * Role: Add data  			    *
 * stack : stack containing all the data    *
 * turn : turn played			    *
 * player : player of the turn		    *
 * x : line played by the player this turn  *
 * y : column played by the player this turn*
 ********************************************/
void push(stack *stack, int turn, int player,int x,int y);

/**************************************
 * Role: unstack the upper data       *
 * stack : stack where we pop the data*
 **************************************/
void pop(stack *stack);

/*****************************************************
 * Role: Display all the data containing by the stack*
 * eg : the stack to display			     *
 *****************************************************/
void displayStack(stack* stack);


#endif