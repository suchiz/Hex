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

void jouer_coup(board *b, int *joueur, int *tour, element_group *eg){
   
  int x, y;
  int ind;
  do{
    printf ("\nSaisissez la ligne de la case puis la colonne: ");
    scanf ("%d", &x);
    scanf ("%d", &y);
    ind = coordonnee(b, x, y);
  }while (!coup_valide(b, x, y, ind));
      
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
  
    int joueur=1;
    int tour =1;
    board b=createBoard(4);

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
     jouer_coup(&b,&joueur,&tour,current);
     displayBoard(&b);
     winner=winning_group(current);
      }
      printf ("Les pions '%c' obtiennent un chaîne gagnant !",winner);
 
}

