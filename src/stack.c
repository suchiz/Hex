#include "../lib/stack.h"

/*******************************************
 * Role: Create a stack of DATA            *
 * stack : Stack of data (player, turn,x,y *
 *******************************************/
void createStack(stack* stack)
{
	stack->first= NULL;
	stack->size = 0;
}

bool isEmptyStack (const stack *s){
 return s->size == 0 && s->first == NULL; 
}

/********************************************
 * Role: Add data  			    *
 * stack : stack containing all the data    *
 * turn : turn played			    *
 * player : player of the turn		    *
 * x : line played by the player this turn  *
 * y : column played by the player this turn*
 ********************************************/
void push(stack *stack, int turn, int player,int x,int y){
 
     element_data *newData = malloc(sizeof(*newData));
    if (stack == NULL || newData == NULL)
    {
        exit(ERR_CREATE_DATA);
    }

    newData->turn = turn;
    newData->player=player;
    newData->x=x;
    newData->y=y;
    newData->next = stack->first;
    
    stack->size++;
    stack->first = newData;
 }
 
 /**************************************
 * Role: unstack the upper data       *
 * stack : stack where we pop the data*
 **************************************/
 void pop(stack *stack){
    if (stack == NULL)
    {
    exit(EXIT_FAILURE);
    }

    element_data *element = stack->first;
    

    if (stack != NULL && stack->first != NULL)
    {

        element->player = stack->first->player;
	element->turn = stack->first->turn;
	element->x = stack->first->x;
	element->y=stack->first->y;
	
	stack->first=element->next;
	stack->size--;
        free(element);

    }
 }
 
 
/*****************************************************
 * Role: Display all the data containing by the stack*
 * eg : the stack to display			     *
 *****************************************************/
void displayStack(stack* stack)
{
	element_data* current;

	current= stack->first;
	
	while (current != NULL)
	{
	  printf ("\n Tour n°%d : (joueur %d) [Line : %d / Column : %d] ",current->turn,current->player,current->x, current->y);
	  current = current->next;
	}
	printf ("\n");
	
}

