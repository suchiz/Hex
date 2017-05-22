#include "../lib/node.h"
#include "../lib/board.h"
#include "../lib/graph.h"

int main()
{
	/******************
	* createNode test *
	******************/
	node *test_node = createNode(5);
 	if(test_node->id != 5 || test_node->color != 'e' || test_node->head != NULL || test_node->nb_members != 0) {
		printf("Failed createNode test\n");
		exit(1);
	}

	/*****************************
	* displayNeighboursList test *
	*****************************/
	
	// Un affichage sera plus parlant pour juger si displayNeighboursList renvoie bien ce qu'il faut
	board newBoard = createBoard(4);	
	displayGraph(&newBoard.brd);
	int dim = sqrt(newBoard.brd.nb_nodes);
	int esp = 0;
	int i, j;
	for (i = 0; i < newBoard.brd.nb_nodes; i++)
	{
		if(i % dim == 0){
			printf("\n   ");
			esp++;
			for(j = 0; j < esp; j++)
				printf ("  ");
			} 
		printf("(%d)", newBoard.brd.grph[i].id);
	}
	printf("\n");

	return 0;
	
}
