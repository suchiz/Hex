#ifndef DEFINITION_GROUP
#define DEFINITION_GROUP

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "node.h"
#include "board.h"
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
 * STRUCTURE OF A GROUP *
 ************************/
typedef struct group_s // group = evolved chain
{
    char color; 		// color of the group, may be white or black only
    int length;		// lenght of the group
    element *head;		// group/list/array of element;
    struct tabGroup_s *first;
    
} group;

/***************************
 * STRUCTURE OF AN ELEMENT *
 ***************************/
typedef struct tabGroup_s
{
    group* group;		
    struct tabGroup *next;   // pointer to the next group
} tabGroup;



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

void destroyGroup(group* group);

void fusion(group* group1,group* group2);

void fusion(group* group1,group* group2);

group* generateGroup(board *b,const node *n);

#endif