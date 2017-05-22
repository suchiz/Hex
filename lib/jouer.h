#ifndef DEFINITION_JOUER
#define DEFINITION_JOUER

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>


#include "board.h"
#include "group.h"

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
/**********************
 * STRUCTURE OF STACK *
 **********************/
typedef struct stack_s

{
  int size;
 struct element_data_s *first;
}stack;

/*********************
 * STRUCTURE OF DATA *
 *********************/
typedef struct element_data_s{
    int turn;
    int player;
    int x;
    int y;
    struct element_data_s *next;

}element_data;

bool isEmptyStack (const stack *s);

int coordonnee(const board* b,int x,int y);

int coup_valide(const board *b, int x, int y, int ind);

void jouer_coup(board *b,stack* stack, int *joueur, int *tour, element_group *eg);

void startGame();

void createStack (stack* stack);

void push(stack *stack, int turn, int player,int x,int y);

void pop(stack *stack);

void displayStack(stack* stack);

int undo(board *b,stack *stack);

void save(board *b);

board load(int *joueur,int* tour);

void menu();

void inGameMenu(board *b,stack* stack, int *joueur, int *tour, element_group *eg);

void loadGame();


int saisie(board *b,stack* stack, int *joueur, int *tour, element_group *eg);
#endif