#include "../lib/save.h"

/*******************************************
 * Role: Save the current board            *
 * board: the board currently played       *
 *******************************************/
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



/*******************************************
 * Role: Load the borard of a game saved   *
 *******************************************/
board load(int*joueur, int *tour, element_group* J1,element_group* J2){

    
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
            newBoard.brd.grph[i].color = ch;
        i++;
        }
        fscanf(F,"%c",&ch);
    }
 
    if(fclose(F)!=0)
    {
        printf("\nFailed close save\n");
            exit(1);
    }
    
    int tour_actuel = 0;
    int nb_x = 0;
    int nb_o = 0;
    for(int i=0; i < size*size; i++)
    {
        if(newBoard.brd.grph[i].color != '.')
        {
            tour_actuel++;
        }
        if(newBoard.brd.grph[i].color == 'o')
        {
	  group *g2 = generateGroup(&newBoard, &newBoard.brd.grph[i]);
	  insertElemGroup(J2, g2);
          updateListGroup(J2);
            nb_o++;
        }
        if(newBoard.brd.grph[i].color == 'x')
        {
	  group *g1=generateGroup(&newBoard, &newBoard.brd.grph[i]);
	  insertElemGroup(J1, g1);
          updateListGroup(J1);
            nb_x++;
        }
    //printf("case %d : %c\n",i,newBoard.brd.grph[i].color);
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
 //displayBoard(&newBoard);
  return(newBoard);
}


/***********************************************************************
 * Role: Start the board load to play on 			       *
 * joueur : The player who must start to play on the bord loaded       *
 ***********************************************************************/
void loadGame(){


  int joueur;
  int tour;
  char winner='.';

      element_group *J1=createListGroup();    
     element_group *J2=createListGroup();
     element_group* current;
   
    board b;
    b=load(&joueur,&tour,J1,J2);
  printf(" \n Debut de la partie chargée:\n");
  printf ("\n");
    stack stack;
    createStack(&stack);
    

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
