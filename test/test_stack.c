#include "../lib/stack.h"

int main()
{
	/************
	* createStack test *
	************/
	stack stack;
	createStack(&stack);
	if(stack.first != NULL || stack.size != 0)
	{
		printf("Failed createStack test \n");
		exit(1);
	}

	/************
	* push test *
	************/
	int tour = 1;
	int joueur = 1;
	int x = 1;
	int y = 1;
	push(&stack,tour,joueur,x,y);
	if(stack.first->x != x || stack.first->y != y || stack.first->player != joueur || stack.first->turn != tour)
	{
		printf("Failed push test \n");
		exit(2);
	}

	int tour2 = 5;
	int joueur2 = 2;
	int x2 = 5;
	int y2 = 3;
	push(&stack,tour2,joueur2,x2,y2);
	if(stack.first->x != x2 || stack.first->y != y2 || stack.first->player != joueur2 || stack.first->turn != tour2)
	{
		printf("Failed push test\n");
		exit(3);
	}

	/***********
	* pop test *
	***********/
	pop(&stack);
	if(stack.first->x != x || stack.first->y != y || stack.first->player != joueur || stack.first->turn != tour)
	{
		printf("Failed pop test\n");
		exit(4);
	}

	pop(&stack);
	if(stack.first != NULL)
	{
		printf("Failed pop test\n");
		exit(5);
	}

	/********************
	* displayStack test *
	********************/
	displayStack(&stack);
	int rep;
	//La pile est vide
	printf("Satisfait du test ?\n");
	printf("1. Oui\n");
	printf("2. Non\n");
	scanf("%d",&rep);
	if(rep != 1)
	{
		printf("Failed displayStack test \n");
		exit(6);
	}
	
	return 0;
}
