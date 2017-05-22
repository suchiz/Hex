#include "../lib/jouer.h"

/**********************************************************
 * Role: return the node where the player want to play    *
 * b : current board	   				  *
 * x : line of the node on the board 			  *
 * y : column of the node on the board			  *
 **********************************************************/
int coordonnee(const board* b,int x,int y){
   int n=sqrt(b->brd.nb_nodes);
   
    int ret1=0;
    int ret2=0;
   
    while (ret1<(x*n)-n){
        ret1=ret1+n;
    }
    
    while (ret2<y-1){
        ret2=ret2+1;   
    }
    
    return (ret1+ret2);
}

/*********************************************************************
 * Role: return 0 if the player is allowed to play the node picked   *
 * b : current board          	     		       		     *
 * x : line of the node on the board 			  	     *
 * y : column of the node on the board				     *
 *ind : number of the node found by int coordonnee and x,y	     *
 *********************************************************************/
int coup_valide(const board *b, int x, int y, int ind){ 
  int n = sqrt(b->brd.nb_nodes); 
  
  if ((x <= 0 || x > n) || (y <= 0 || y > n))
    return 0;
  if (b->brd.grph[ind].color != '.')
    return 0;
  
  return 1;
}

/*****************************************************************
 * Role: Seizure of the player (line / column of the node or menu*
 * b : current board           				         *
 * stack : stack where the data is pushed		  	 *
 * joueur : player who played					 *
 * tour : turn played by the player				 *
 * eg : list containing the groups of nodes of the current player* 
 *****************************************************************/
int saisie(board *b,stack* stack, int *joueur, int *tour, element_group *eg){
    int x, y;
    int ind;
  do{
    
    printf ("Ligne : ");
    scanf ("%d", &x);

    if (x==0)
      inGameMenu(b,stack,joueur,tour,eg);
	
    if(x!=0){  
    printf("\nColonne : ");
    scanf ("%d", &y);
    }
   if(y==0)
      inGameMenu(b,stack,joueur,tour,eg);
      
    ind = coordonnee(b, x, y);
  }while (!coup_valide(b, x, y, ind));
  push(stack,(*tour),(*joueur),x,y);
      return ind;
}


/*****************************************************************
 * Role: change the color of the node depending on the player    *
 * b : current board             				 *
 * stack : stack where the data is pushed		  	 *
 * joueur : player who played					 *
 * tour : turn played by the player				 *
 * eg : list containing the groups of nodes of the current player* 
 *****************************************************************/
void jouer_coup(board *b,stack* stack, int *joueur, int *tour, element_group *eg){
   
int ind =saisie(b,stack,joueur,tour,eg);
  if (*joueur == 1)
    b->brd.grph[ind].color = 'x';
  else
    b->brd.grph[ind].color = 'x';
  
 
  group *g = generateGroup(b, &b->brd.grph[ind]);
  insertElemGroup(eg, g);
  updateListGroup(eg);
  
  (*joueur) = ((*joueur) + 1) % 2;
  (*tour)++;

}

/****************************
 * Role: start a new game   *
 ****************************/
void startGame(){
  int size;
  int joueur;
  int tour = 1;
  char winner='.';

  printf ("Taille du plateau de jeu : ");
  scanf("%d",&size);
  
  do{
  printf ("\nJoueur qui commence (1 ou 2) : ");
  scanf ("%d",&joueur);
  }while(joueur!=1 && joueur!=2);
  joueur--;
  
  
  printf(" \n [Debut de la nouvelle partie]\n");
    printf ("\n");
    
    board b=createBoard(size);
    stack stack;
    createStack(&stack);
    
     element_group *J1=createListGroup();    
   //  element_group *J2=createListGroup();
     element_group* current;
     displayBoard(&b);
     
      while(winner=='.'){
	if(joueur==1){

	current=J1;
	 printf ("\n \n Tour : %d (joueur %d ['x']->B) [Accès menu = 0]\n", tour,joueur+1);
	 
      jouer_coup(&b,&stack,&joueur,&tour,J1);
	}else{
	current=J1;
	 printf ("\n \n Tour : %d (joueur %d ['o']->W) [Accès menu = 0]\n", tour,joueur+1);
      jouer_coup(&b,&stack,&joueur,&tour,J1);
	}
     
      
      
      displayListGroup(current);
     displayBoard(&b);
     winner=winning_group(current);
      }
      printf ("\nLes pions '%c' obtiennent un chaîne gagnant !\n",winner);
      printf (" Le joueur %d gagne la partie.\n",joueur);
}


/*******************************************************************
 * Role: undo the last node played and back to the previous turn   *
 * b : current board						   *
 * stack : stack containing the data so the last node played	   *
 * joueur : back to the previous player 		       	   *
 * turn : back to te previous turn			     	   *
 * eg : delete the node in the list of group of the player who undo*
 *******************************************************************/
int undo(board *b,stack *stack){
  
  int x=stack->first->x;
  int y=stack->first->y;
  int ind=coordonnee(b,x,y);
  printf ("\nUndo [Line : %d / Column : %d]\n",x,y);
  b->brd.grph[ind].color='.';
  displayBoard(b);
  pop(stack);
return ind;
}
