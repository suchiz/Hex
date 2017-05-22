#ifndef DEFINITION_MENU
#define DEFINITION_MENU

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "board.h"
#include "group.h"
#include "save.h"
#include "stack.h"
#include "jouer.h"
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

/************************************************************
 * Role: Main menu of the game (new game, load, quit)       *
 ************************************************************/
void menu();

/******************************************************************************************
 * Role: inGameMenu to save,undo,display hstoric,restart a game or back  to main menu     *
 * b : board to save if we save								  *
 * stack : stack to display if asked by a player					  *
 * joueur : back to the previous player if 'undo'					  *
 * turn : back to te previous turn if 'undo'						  *
 * eg : delete the node in the list of group of the player who played			  * 
 ******************************************************************************************/
 void inGameMenu(board *b,stack* stack, int *joueur, int *tour, element_group *eg);

#endif