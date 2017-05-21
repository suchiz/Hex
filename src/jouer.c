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

int saisie(board *b,stack* stack, int *joueur, int *tour, element_group *eg){
    int x, y;
  int ind;

  do{
    printf ("\n \n Tour : %d (joueur %d)\n", *tour,*joueur);

    printf ("\nLigne : ");
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

void jouer_coup(board *b,stack* stack, int *joueur, int *tour, element_group *eg){
   
int ind =saisie(b,stack,joueur,tour,eg);
  if (*joueur == 1)
    b->brd.grph[ind].color = 'x';
  else
    b->brd.grph[ind].color = 'o';
  
 
  group *g = generateGroup(b, &b->brd.grph[ind]);
  insertElemGroup(eg, g);
  updateListGroup(eg);
  
  (*joueur) = ((*joueur) + 1) % 2;
  (*tour)++;

}

void startGame(){
  int size;
  int joueur;
  int tour = 1;
  char winner='.';
  
  printf ("Chosissez la taille du plateau de jeu : ");
  scanf("%d",&size);
  
  printf ("\nChoisissez le joueur qui commence (1 ou 2) : ");
  scanf ("%d",&joueur);
   
    board b=createBoard(size);
    stack stack;
    createStack(&stack);
    
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
      printf ("\nLes pions '%c' obtiennent un chaîne gagnant !\n",winner);

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

void save(board *b)
{
	FILE *F;
	char ch;
	char sauvegarde[100];
	char type[100]=".txt";
	char save[100]="./save/";
	int i=0;
	
	printf("\nNom de la sauvegarde : ");
	scanf("%s",sauvegarde);

	strcat(save,sauvegarde);
	strcat(save,type);
        
	F=fopen(save,"wt");
	if(F==NULL)
	{
		printf("\nFailed open save\n");
		exit(1);
	}
	
	int n = sqrt(b->brd.nb_nodes);
	board *current = b;
	fprintf(F,"%d\n",n);
	while(current->brd.grph[i].head != NULL && i < n*n)
	{
		ch = current->brd.grph[i].color;
		fprintf(F,"%c\n",ch);
		i++;
	}
	
	if(fclose(F)!=0)
	{
		printf("\nFailed close save\n");
        	exit(2);
	}

}


board load(int*joueur, int *tour){

    
    char doss[100] = "./save/";
    DIR* directory = opendir(doss);
    struct dirent* direct;
    int i=0;
    printf("\n=========================\n");
    printf("* Liste des sauvegardes *\n");
    printf("=========================\n");
    while ((direct = readdir(directory)) != NULL)
    {
        printf("%s\n",direct->d_name);
    }
    closedir(directory);
 
    char sauvegarde[100];
    printf("\nNom complet de la sauvegarde à charger : ");
    scanf("%s", sauvegarde);
        
    FILE *F;
    strcat(doss,sauvegarde);
    F=fopen(doss,"rt");
    char ch;
    int size;
 
    fscanf(F,"%d", &size);
    board newBoard = createBoard(size);
    
    i=0;
    char temoin1='o';
    char temoin2='x';
    char temoin3='.';
    fscanf(F,"%c",&ch);
    while(!feof(F))
    {
        if(ch == temoin1 || ch == temoin2 || ch == temoin3)
        {
            newBoard.brd.grph[i/2].color = ch;
        }
        i++;
        fscanf(F,"%c",&ch);
    }
 
    if(fclose(F)!=0)
    {
        printf("\nFailed close save\n");
            exit(1);
    }
 
    int k=0;
    board realBoard = createBoard(size);
    for(int i=0; i<size*size; i++)
    {
        if(i%2 == 0)
        {
            realBoard.brd.grph[k]=newBoard.brd.grph[i/2];
            
	    k++;
        }
    
    }
    
    int tour_actuel = 0;
    int nb_x = 0;
    int nb_o = 0;
    for(int i=0; i < size*size; i++)
    {
        if(realBoard.brd.grph[i].color != '.')
        {
            tour_actuel++;
        }
        if(realBoard.brd.grph[i].color == 'o')
        {
            nb_o++;
        }
        if(realBoard.brd.grph[i].color == 'x')
        {
            nb_x++;
        }
    }
    char joueur_actuel;
    if(nb_x > nb_o)
    {
        joueur_actuel = 'o';
    }
    else
    {
        joueur_actuel = 'x';
    }
    tour_actuel++;
    printf("Au tour %d du joueur '%c' :\n",tour_actuel,joueur_actuel);
  (*tour)=tour_actuel;
  (*joueur)=((joueur_actuel) + 1) % 2;
 //displayBoard(&realBoard);
  return(realBoard);
}

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
			default :printf ("Les choix possibles sont 1,2 ou 3 !");
		}
  }while(choix !=3);
}

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
			
					
			case 1 : break;
			
			case 2 : printf ("Historique des coups :  \n"); 
				displayStack(stack);
				break;
			
			case 3 : 
				  undo1=undo(b,stack);
				 undoListGroup(eg,undo1);
				 (*joueur) = ((*joueur) + 1) % 2;
				 (*tour)--;
				  
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
				
				
			default :printf ("Les choix possibles sont 1,2 ou 3 !");
		}
  }while(choix !=1 && choix !=2 && choix!=3);
}



void loadGame(){


  int joueur;
  int tour;
  char winner='.';

   
    board b;
    b=load(&joueur,&tour);
   printf (" TOOOUUUUR = %d", tour);
    
    stack stack;
    createStack(&stack);
    
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
      printf ("\nLes pions '%c' obtiennent un chaîne gagnant !\n",winner);

}