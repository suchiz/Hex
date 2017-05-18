#ifndef DEFINITION_JOUER
#define DEFINITION_JOUER

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "board.h"
#include "group.h"

/********************
 * ERROR DEFINITION *
 ********************/
#define OK		0
#define ERR_CREATE_NODE	1
#define ERR_CREATE_GROUP	2
#define ERR_CREATE_ELEMENT	3
#define ERR_CREATE_GRAPH	4
#define ERR_ADD_EDGE	5


int coordonnee(const board* b,int x,int y);

int coup_valide(const board *b, int x, int y, int ind);

void jouer_coup(board *b, int *joueur, int *tour, element_group *eg);


#endif