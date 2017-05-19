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
} group;

/***************************
 * STRUCTURE OF AN ELEMENT *
 ***************************/
typedef struct element_group_s
{
    group grp;	
    int size;
    struct element_group_s *next;   // pointer to the next group
} element_group;

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
 * Role: Destroy a group    *
 * g : the group to destroy *
 ****************************/
void destroyGroup (group* group);

/*******************************************
 * Role: Merge group2 into group1          *
 * group1: group resulting from merge      *
 * group2: group destroyed after the merge *
 *******************************************/
void fusion (group* group1, group* group2);

/*************************************************
 * Role: Generate a group for the node we played *
 * b: the board we are playing in 	         *
 * n: the node we played		         *
 *************************************************/
group* generateGroup (const board *b, const node *n);

/*************************************
 * Role: Create a new list of groups *
 *************************************/
element_group* createListGroup ();

/**********************************************
 * Role: insert a group into a list of groups *
 * eg : the list we insert into	              *
 * groupToAdd: the group to add               *
 **********************************************/
void insertElemGroup (element_group *eg, const group* groupToAdd);

/********************************************
 * Role: Destroy an element of element_group*
 * eg : the element_group to destroy        *
 ********************************************/
void destroyElemGroup (element_group *eg);


/**********************************
 * Role: Display a list of groups *
 * eg : the list to display	  *
 **********************************/
void displayListGroup (const element_group *eg);

/**************************************************************
 * Role: Merge groups of the list if they have the same color *
 * eg : the list to update 		         	      *
 **************************************************************/
void updateListGroup (element_group *eg);

/************************************************************************
 * Role: return 1 if g1 and g2 have at least one adjency node in common *
 ************************************************************************/
int adjacentGroup (const group *g1, const group *g2);

/****************************************************************
 * Role: return 1 if g1 and g2 have at least one node in common *
 ****************************************************************/
int adjacentGroup2 (const group *g1, const group *g2);

/******************************************************************************
 * Role: return '.' if no winner found or 'o' or 'x' depending on the winner  *
 ******************************************************************************/
char winning_group(const element_group *eg);


#endif