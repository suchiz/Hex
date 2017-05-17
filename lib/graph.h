#ifndef DEFINITION_GRAPH 
#define DEFINITION_GRAPH 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "node.h"

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
 * STRUCTURE OF A GRAPH *
 ************************/
typedef struct graph_s // board = graph
{ 
    int nb_nodes;         	// total number of nodes in the graph 
    node *grph;     	// array of nodes
} graph;

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
 * Role: Display a graph, may be useful to unbug *
 * g : the graph to display	                   *
 *************************************************/ 
void displayGraph (const graph *g);

/***********************************
 * Role: Link a graph with borders *
 * g : the graph to link	     *
 ***********************************/ 
void linkGraph (graph *g);



#endif

