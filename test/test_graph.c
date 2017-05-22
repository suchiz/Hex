#include "../lib/graph.h"
#include "../lib/board.h"

/* Les fonctions d'affichage ne seront pas traitées pour des raisons évidentes */

int main()
{	
	/*******************
	* createGraph test *
	*******************/
	int n = 3;
	/* Création du témoin pour tester la fonction */
	graph *temoin = malloc(sizeof(struct graph_s));
	temoin->grph = malloc(n * n * sizeof(struct node_s));
	temoin->nb_nodes = n * n; 
	for(int i = 0; i < n * n; i++)
	{
		temoin->grph[i].color = '.';
		temoin->grph[i].id = i;
		temoin->grph[i].head = NULL;
		temoin->grph[i].nb_members = 0;
	}

	/* Utilisation de la fonction */
	graph *new = createGraph(n);

	/* Vérification de la fonction */
	for(int i = 0; i < n * n; i++)
	{
		if(temoin->grph[i].color != new->grph[i].color || temoin->grph[i].id != new->grph[i].id || temoin->grph[i].head != new->grph[i].head || temoin->grph[i].nb_members != new->grph[i].nb_members)
		{
			printf("Failed createGraph test\n");
			exit(1);
		}
	}

	/***************
	* addEdge test *
	***************/
	element *elt1 = malloc(sizeof(struct element_s));
	elt1->n.color = 'b';
	elt1->n.id = 3;
	elt1->n.nb_members = 0;
	elt1->n.head = NULL;
	
	element *elt2 = malloc(sizeof(struct element_s));
	elt2->n.color = 'b';
	elt2->n.id = 7;
	elt2->n.nb_members = 0;
	elt2->n.head = NULL;
	/* Création du témoin pour tester la fonction */
	node *src = malloc(sizeof(struct node_s));
	src->id = 5;
	src->color = 'b';
	src->head = elt1;
	src->nb_members = 0;

	node *dest = malloc(sizeof(struct node_s));
	dest->id = 2;
	dest->color = 'b';
	dest->head = elt2;
	dest->nb_members = 0;
    
	/* Utilisation de la fonction */
	printf("=== Before addEdge ===\n");
	printf("id src->head = %d\n",src->head->n.id);
	addEdge(src,dest);
	printf("\n=== After addEdge ===\n");
	printf("id src->head = %d\n\n",src->head->n.id);

	/* Vérification de la fonction */
	if(src->head->n.id != dest->id)
	{
		printf("Failed addEdge test\n");
		exit(2);
	}
	
	/*****************
	* linkGraph test *
	*****************/
	board b = createBoard(3);
	if((&b.brd) == NULL)
	{
		printf("Failed linkGraph test\n");
	}
	printf("La fonction linkGraph est une fonction d'affichage des noeuds adjacents, elle réutilise la fonction addEdge dont nous venons d'effectuer le test. L'affichage suivant sera plus parlant \n\n");
  	displayGraph(&b.brd);
	int dim = sqrt(b.brd.nb_nodes);
	int esp = 0;
	int i, j;
	for (i = 0; i < b.brd.nb_nodes; i++)
	{
		if(i % dim == 0){
			printf("\n   ");
			esp++;
			for(j = 0; j < esp; j++)
				printf ("  ");
			} 
		printf("(%d)", b.brd.grph[i].id);
	}
 	printf ("\n");
  	printf("Les noeuds 1000, 1001, 2000 et 2001 étant les bords du plateau\n");
	return OK;
}
