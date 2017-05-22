#include "../lib/board.h"

/****************************
 * Role: Create a new board *
 * n : size of n * n        *
 ****************************/ 
board createBoard (const int n){
  board newBoard;
  graph *g = createGraph(n);
  linkGraph(g);
  (&newBoard)->brd = (*g);
  
  return newBoard;
}
  
/******************************************
 * Role: Display the board, it is the GUI *
 * b :the board to display                *
 ******************************************/ 
void displayBoard(const board *b){
  int dim = sqrt(b->brd.nb_nodes);
  int esp = 0;
  int i, j;
  
  printf ("    ");
  for (int i=0;i<=dim;i++){
    printf(" W ");
  }
  for (i = 0; i < b->brd.nb_nodes; i++)
  {
    if(i % dim == 0){
      printf(" B ");
      printf("\n   ");
   
      esp++;
      for(j = 0; j < esp; j++){
      printf ("  ");
      }
       printf(" B ");  
    } 
    
    
    printf("(%c)", b->brd.grph[i].color);
  }
  
  printf (" B \n");
    for(j = 0; j <= esp+1; j++){
      printf ("  ");
      }
    for (int i=0;i<=dim+1;i++){
    printf(" W ");
  }
  printf ("\n");
}
