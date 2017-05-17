#ifndef DEFINITION_BOARD
#define DEFINITION_BOARD

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "graph.h"

/********************
 * ERROR DEFINITION *
 ********************/
#define OK		0
#define ERR_CREATE_NODE	1
#define ERR_CREATE_GROUP	2
#define ERR_CREATE_ELEMENT	3
#define ERR_CREATE_GRAPH	4
#define ERR_ADD_EDGE	5

/************************
 * STRUCTURE OF A BOARD *
 ************************/
typedef struct board_s
{
  graph brd;
} board;

/****************************
 * Role: Create a new board *
 * n : size of n * n        *
 ****************************/ 
board createBoard (const int n);

/******************************************
 * Role: Display the board, it is the GUI *
 * b :the board to display                *
 ******************************************/ 
void displayBoard(const board *b);


#endif

