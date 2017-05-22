#ifndef DEFINITION_SAVE
#define DEFINITION_SAVE

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>


#include "board.h"
#include "group.h"
#include "jouer.h"
#include "stack.h"
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

/*******************************************
 * Role: Save the current board            *
 * board: the board currently played       *
 *******************************************/
void save(board *b);


/*******************************************
 * Role: Load the borard of a game saved   *
 *******************************************/
void loadGame();

/***********************************************************************
 * Role: Start the board load to play on 			       *
 * joueur : The player who must start to play on the bord loaded       *
 ***********************************************************************/
board load(int *joueur,int* tour,element_group* J1,element_group* J2);

#endif