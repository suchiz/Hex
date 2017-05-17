#ifndef DEFINITION_NODE
#define DEFINITION_NODE

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/********************
 * ERROR DEFINITION *
 ********************/
#define OK		0
#define ERR_CREATE_NODE	1
#define ERR_CREATE_GROUP	2
#define ERR_CREATE_ELEMENT	3
#define ERR_CREATE_GRAPH	4
#define ERR_ADD_EDGE	5

/***********************
 * STRUCTURE OF A NODE *
 ***********************/
typedef struct node_s // Case = hexagone = node = summit
{
    char color;		// white 'x', black 'o', or empty '.'
    int id;        		// identity of the node = coordonate in the graph
    int nb_members;       	// numbers of edges
    struct element_s *head;     	// list of adjacents nodes
} node;

/***************************
 * STRUCTURE OF AN ELEMENT *
 ***************************/
typedef struct element_s //element for list implementation
{
    node n;		// a node in the graph
    struct element_s *next;   // pointer to the next element of the group
} element;

/*****************************
 * Role: Create a new node   *
 * id : identity of the node *
 *****************************/
node* createNode (const int id);

/*************************************************
 * Role: Display a list, may be useful to unbug  *
 * n : node with the list to display	         *
 *************************************************/  
void displayNeighboursList (const node *n);

#endif