#include "../lib/jouer.h"
#include "../lib/board.h"

int main()
{
	board newBoard = createBoard(4);
	
	/******************
	* coordonnee test *
	******************/
	int temoin_x = 2;
	int temoin_y = 3;
	// La case ciblée en (2,3) correspond à la case 6
	if(coordonnee(&newBoard,temoin_x,temoin_y) != 6)
	{
		printf("Failed coordonnee test\n");
		exit(1);
	}

	/*******************
	* coup_valide test *
	*******************/
	newBoard.brd.grph[1].color='x';
	// Un coup est valide lorsqu'il n'y a aucun pion sur la case, c'est à dire qu'elle n'a pas de couleur
	if(coup_valide(&newBoard,temoin_x,temoin_y,1) == 1)
	{
		printf("Failed coup_valide test\n");
		exit(2);
	}

	/**************
	* saisie test *
	**************/
	//La fonction retourne le résultat de la fonction coordonnee, test déjà réalisé donc

	/******************
	* jouer_coup test *
	******************/
	element_group* test = malloc(sizeof(struct element_group_s));
	int joueur = 0;
	int tour = 1;
	stack stack;
	int rep;

	createStack(&stack);
	displayBoard(&newBoard);
	jouer_coup(&newBoard,&stack,&joueur,&tour,test);
	displayBoard(&newBoard);

	printf("\nSatisfait du coup joué : \n");
	printf("1. Oui\n");
	printf("2. Non\n");
	printf("Choix : ");
	scanf("%d",&rep);

	if(rep != 1)
	{
		printf("Failed jouer_coup test\n");
		exit(3);
	}

	

	return 0;
}
	
