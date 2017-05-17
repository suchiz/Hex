#ifndef DEFINITION_GRAPH 
#define DEFINITION_GRAPH 

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


/**************
 * STRUCTURES *
 **************/
typedef struct node_s node;
typedef struct graph_s graph;
typedef struct element_s element;
typedef struct group_s group;
typedef struct board_s board;

/*****************************
 * Role: Create a new node   *
 * id : identity of the node *
 *****************************/
node* createNode (const int id);

/******************************
 * Role: Create a new group 	*
 * color : color of the group *
 ******************************/
group* createGroup (const char color);

/***************************************************************************
 * Role: Create a new group 	 				     *
 * color : color of the group 				     *
 * nodeToAdd : constant, no modification on it, member to add to the group *
 ***************************************************************************/
void addToGroup (group *g, const node *nodeToAdd);

/*************************************************
 * Role: Display a group, may be useful to unbug *
 * g : the group to display	                   *
 *************************************************/
void displayGroup (const group *g);

/****************************
 * Role: Create a new graph *
 * n : lenght of the graph  *
 ****************************/
graph* createGraph (const int n);

/************************************************
 * Role: Create a new edge between src and dest *
 * src: In fact, there's no really a source     *
 * dest: nor a destination, they add each other *
 ************************************************/
void addEdge (node *src, node *dest);

/*************************************************
 * Role: Display a list, may be useful to unbug *
 * n : node with the list to display	         *
 *************************************************/  
void displayNeighboursList (const node *n);

/*************************************************
 * Role: Display a graph, may be useful to unbug *
 * g : the graph to display	                   *
 *************************************************/ 
void displayGraph (const graph *g);

/***********************************
 * Role: Link a graph with borders *
 * g : the graph to link	     *
 ***********************************/ 
void linkGraph (graph *g);

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

