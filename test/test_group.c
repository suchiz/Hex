#include "../lib/group.h"

int main()
{
	/*******************
	* createGroup test *
	*******************/
	group* test = createGroup('x');
	if(test == NULL)
	{
		printf("Failed createGroup test \n");
		exit(1);
	}

	/******************
	* addToGroup test *
	******************/
	node* n1 = createNode(5);
	node* n2 = createNode(1);
	
	addToGroup(test,n1);
	addToGroup(test,n2);

	printf("Element du groupe test : %d\n",test->head->n.id);
	printf("Element du groupe test : %d\n",test->head->next->n.id);
	
	if(test->head->n.id != 1 || test->head->next->n.id != 5)
	{
		printf("Failed addToGroup test\n");
		exit(2);
	}

	/********************
	* displayGroup test *
	********************/
	// Il s'agit d'un affichage donc pas de soucis
	displayGroup(test);

	/********************
	* destroyGroup test *
	********************/
	destroyGroup(test);
	element* current = test->head;
	while(current != NULL)
	{
		if(current->n.id != 0)
		{
			printf("Failed destroyGroup test\n");
			exit(3);
		}
		current = current->next;
	}

	/**************
	* fusion test *
	**************/
	group* g1 = createGroup('o');
	group* g2 = createGroup('o');

	node* n3 = createNode(9);
	node* n4 = createNode(15);

	addToGroup(g1,n1);
	addToGroup(g1,n3);
	addToGroup(g2,n2);
	addToGroup(g2,n4);

	fusion(g1,g2);
	displayGroup(g1);
	
	bool ok = false;
	bool okk = false;

	current = g1->head;
	while(current != NULL)
	{
		if(current->n.id == n2->id)
		{
			ok = true;
		}
		if(current->n.id == n4->id)
		{
			okk = true;
		}
		current = current->next;
	}
	if(ok != true && okk != true)
	{
		printf("Failed fusion test\n");
		exit(4);
	}
	
	/*********************
	* generetaGroup test *
	*********************/
	board b = createBoard(4);
	group* g3 = createGroup('x');
	addToGroup(g3,n3);
	group* g5 = generateGroup(&b,n3);
	
	if(g3->head->n.id != g5->head->n.id)
	{
		printf("Failed generateGroup test\n");
		exit(5);
	}

	/***********************
	* createListGroup test *
	***********************/
	element_group *eg = malloc(sizeof(struct element_group_s));
	eg->next = NULL;
	eg->size = 0;

	element_group *eg2 = createListGroup();

	if(eg->next != eg2->next || eg->size != eg2->size)
	{
		printf("Failed createListGroup test \n");
		exit(6);
	}
	
	/***********************
	* insertElemGroup test *
	***********************/
	insertElemGroup(eg,g1);
	while(eg->grp.head != NULL)
	{
		if(eg->grp.head->n.id != n1->id || eg->grp.head->n.id != n2->id || eg->grp.head->n.id != n3->id || eg->grp.head->n.id != n4->id)
		{
			printf("Failed insertElemGroup test\n");
			exit(7);
		}
		eg->grp.head = eg->grp.head->next;
	}

	/************************
	* destroyElemGroup test *
	************************/
	destroyElemGroup(eg);
	element* curr = eg->grp.head;
	while(curr != NULL)
	{
		if(curr->n.id != 0)
		{
			printf("Failed destroyElemGroup test\n");
			exit(8);
		}
		curr = curr->next;
	}

	/********************
	* displayGroup test *
	********************/
	//Simple affichage, test inutile

	/*********************
	* adjacentGroup test *
	*********************/
	group* g6 = createGroup('x');
	node* n8 = createNode(10);
	addToGroup(g6,n8);
	//G1 contient les noeuds n1(5) et n3(9), G6 contient le noeud n8(10) mais les groupes sont de couleurs différentes donc non adjacents.
	if(adjacentGroup(g1,g6) != 0)
	{
		printf("Failed adjacentGroup test\n");
		exit(9);
	}
	
	/**********************
	* adjacentGroup2 test *
	**********************/
	// Même principe que pour adjacentGroup, s'y référer

	/***********************
	* updateListGroup test *
	***********************/
	group* g10 = createGroup('o');
	group* g11 = createGroup('o');
	
	node* n10 = createNode(15);
	node* n11 = createNode(16);
	node* n12 = createNode(17);
	node* n13 = createNode(18);
	node* n14 = createNode(19);
	node* n15 = createNode(20);

	addToGroup(g10,n10);
	addToGroup(g10,n11);
	addToGroup(g10,n12);
	addToGroup(g11,n13);
	addToGroup(g11,n14);
	addToGroup(g11,n15);

	element_group* update = malloc(sizeof(struct element_group_s));
	
	insertElemGroup(update,g10);
	insertElemGroup(update,g11);

	updateListGroup(update);
	// La fonction fusionne les groupes s'ils sont adjacents et de même couleur, on vérifie si la fusion a été effectué

	curr = update->grp.head;
	while(curr != NULL)
	{
		if(curr->n.id != n10->id || curr->n.id != n11->id || curr->n.id != n12->id || curr->n.id != n13->id || curr->n.id != n14->id || curr->n.id != n15->id)
		{
			printf("Failed updateListGroup test \n");
			exit(10);
		}
		curr = curr->next;
	}

	/*********************
	* winning_group test *
	*********************/
	node *n16 = createNode(1000);
	node *n17 = createNode(1001);
	addToGroup(g11,n16);
	addToGroup(g11,n17);
	insertElemGroup(update,g11);
	// On donne les noeuds témoins d'une victoire 'o' et on vérifie si la fonction nous renvoie bien 'o'
	updateListGroup(update);
	if(winning_group(update) != 'o')
	{
		printf("Failed winnin_group test \n");
		exit(11);
	}

	return 0;
}
