#include "../lib/jouer.h"


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

int coup_valide(const board *b, int x, int y, int ind){ 
  int n = sqrt(b->brd.nb_nodes); 
  
  if ((x < 0 || x > n) || (y < 0 || y > n))
    return 0;
  if (b->brd.grph[ind].color != '.')
    return 0;
  
  return 1;
}

void jouer_coup(board *b,stack* stack, int *joueur, int *tour, element_group *eg){
   
  int x, y;
  int ind;
  do{
    printf ("\nSaisie :[ligne,colonne] (other commands 0 = historique || 99 = undo) :\n");
    scanf ("%d", &x);
      if (x==0)
      displayStack(stack);
      if(x==99)
	undo(b,stack);
    scanf ("%d", &y);
      if(y==0)
      displayStack(stack);
      if(y==99)
	undo(b,stack);
      
      if (x==99 ||y==99){
	(*joueur) = ((*joueur) + 1) % 2;
	(*tour)--;
      }
      
      
      
    ind = coordonnee(b, x, y);
  }while (!coup_valide(b, x, y, ind));
      
  if (*joueur == 1)
    b->brd.grph[ind].color = 'x';
  else
    b->brd.grph[ind].color = 'o';
  
 
    
  
    int player=*joueur;
    int turn=*tour;
  push(stack,turn,player,x,y);
  group *g = generateGroup(b, &b->brd.grph[ind]);
  insertElemGroup(eg, g);
  updateListGroup(eg);
  
  (*joueur) = ((*joueur) + 1) % 2;
  (*tour)++;

}

void startGame(){
  
    int joueur=1;
    int tour =1;
    board b=createBoard(4);
    stack stack;
    createStack(&stack);
    char winner='.';
     element_group *J1=createListGroup();    
     element_group *J2=createListGroup();
     element_group* current;
    
     displayBoard(&b);
      while(winner=='.'){
	if(joueur==1){
	current=J1;
	}else{
	current=J2;
	}
     jouer_coup(&b,&stack,&joueur,&tour,current);
     displayBoard(&b);
     winner=winning_group(current);
      }
      printf ("Les pions '%c' obtiennent un chaîne gagnant !",winner);
 
}
void createStack(stack* stack)
{
	stack->first= NULL;
	stack->size = 0;
}

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
    
    stack->first = newData;
 }
 
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
 
 
/*
 * Affiche la pile stack sur la sortie standard
 */
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

stack* undo(board *b,stack *stack){
  
  int x=stack->first->x;
  int y=stack->first->y;
  int ind=coordonnee(b,x,y);
  //supprimer ind de la liste des groupes du joueur ayant joué le dernier coup.
  printf ("Undo [Line : %d / Column : %d]",x,y);
  b->brd.grph[ind].color='.';
  displayBoard(b);
  pop(stack);
return stack;
}

    
