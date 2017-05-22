#include "../lib/menu.h"

/************************************************************
 * Role: Main menu of the game (new game, load, quit)       *
 ************************************************************/
void menu(){
  int choix;
  do{
    
    		printf ("------------ Sélectionnez une option ------------\n");
		printf ("	1. Nouvelle partie\n");
		printf ("	2. Charger une partie\n");
		printf ("	3. Quitter\n");


		printf ("\nVotre choix : ");
		scanf ("%d", &choix);

		printf ("\n");

		switch (choix)
		{
			
					
			case 1 : startGame();
				 break;
			
			case 2 : loadGame();
				 break;
				 
			case 3 : printf ("\n A bientôt sur Hex Game !\n");
				  exit (EXIT_SUCCESS);
				break;
			default :printf ("Les choix possibles sont 1,2 ou 3 !\n");
		}
  }while(choix !=3);
}


/******************************************************************************************
 * Role: inGameMenu to save,undo,display hstoric,restart a game or back  to main menu     *
 * b : board to save if we save								  *
 * stack : stack to display if asked by a player					  *
 * joueur : back to the previous player if 'undo'					  *
 * turn : back to te previous turn if 'undo'						  *
 * eg : delete the node in the list of group of the player who played			  * 
 ******************************************************************************************/
void inGameMenu(board *b,stack* stack, int *joueur, int *tour, element_group *eg){
  int choix;
  char choix_save;
  int undo1;
  do{
  
  printf ("\n------------ Sélectionnez une option ------------\n");
		printf ("	1. Reprendre\n");
		printf ("	2. Historique\n");
		printf ("	3. Annuler coup\n");
		printf ("	4. Recommencer\n");
		printf ("	5. Sauvegarder\n");
		printf ("	6. Quitter la partie\n");
		

		printf ("\nVotre choix : ");
		scanf ("%d", &choix);

		printf ("\n");

		switch (choix)
		{
			
					
			case 1 : 
				 displayBoard(b);
				 break;
			
			case 2 : printf ("Historique des coups :  \n"); 
				displayStack(stack);
				displayBoard(b);
				break;
			
			case 3 :  if (!isEmptyStack(stack)){
			 
				  undo1=undo(b,stack);
				  
				 undoListGroup(eg,undo1);
				 displayListGroup(eg);
				 (*joueur) = ((*joueur) + 1) % 2;
				 (*tour)--;
				  }
				  else {
				    printf ("Aucun coup à annuler\n");
				    displayBoard(b);
				  }
				  
				  
				  break;
				  
			case 4 : startGame();
			
			case 5 : save(b);
				 break;
				
			
			case 6 :do{ 
				  printf("Voulez-vous sauvegarder la partie avant de quitter ? (o/n)\n");
				  
				 scanf("%c",&choix_save);
				  switch(choix_save){
				    
				    case 'o' : save(b);
				    
				    case 'n' : menu();
				      break;
				   
				    default : break;
				  }
				}while (choix_save=='n' || choix_save !='o');

				break;
				
				
			default :printf ("Les choix possibles sont 1,2,3,4,5 ou 6 !\n");
		}
  }while(choix !=1 && choix !=2 && choix!=3);
}