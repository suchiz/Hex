#ifndef DEFINITION_JOUER
#define DEFINITION_JOUER

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "board.h"
#include "group.h"
#include "save.h"
#include "stack.h"
#include "menu.h"

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

/**********************************************************
 * Role: return the node where the player want to play    *
 * b : current board	   				  *
 * x : line of the node on the board 			  *
 * y : column of the node on the board			  *
 **********************************************************/
int coordonnee(const board* b,int x,int y);

/*********************************************************************
 * Role: return 0 if the player is allowed to play the node picked   *
 * b : current board          	     		       		     *
 * x : line of the node on the board 			  	     *
 * y : column of the node on the board				     *
 *ind : number of the node found by int coordonnee and x,y	     *
 *********************************************************************/
int coup_valide(const board *b, int x, int y, int ind);


/*****************************************************************
 * Role: Seizure of the player (line / column of the node or menu*
 * b : current board           				         *
 * stack : stack where the data is pushed		  	 *
 * joueur : player who played					 *
 * tour : turn played by the player				 *
 * eg : list containing the groups of nodes of the current player* 
 *****************************************************************/
int saisie(board *b,stack* stack, int *joueur, int *tour, element_group *eg);



/*****************************************************************
 * Role: change the color of the node depending on the player    *
 * b : current board             				 *
 * stack : stack where the data is pushed		  	 *
 * joueur : player who played					 *
 * tour : turn played by the player				 *
 * eg : list containing the groups of nodes of the current player* 
 *****************************************************************/
void jouer_coup(board *b,stack* stack, int *joueur, int *tour, element_group *eg);

/****************************
 * Role: start a new game   *
 ****************************/
void startGame();

/*******************************************************************
 * Role: undo the last node played and back to the previous turn   *
 * b : current board						   *
 * stack : stack containing the data so the last node played	   *
 * joueur : back to the previous player 		       	   *
 * turn : back to te previous turn			     	   *
 * eg : delete the node in the list of group of the player who undo*
 *******************************************************************/
int undo(board *b,stack *stack);


#endif