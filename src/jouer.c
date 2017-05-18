#include "../lib/jouer.h"

int coordonnee (const board *b, int x, int y){
  int n = sqrt(b->brd.nb_nodes);
  return (n * x + y);
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
  
  (*joueur) = ((*joueur) + 1) % 2;
  (*tour)++;
}

