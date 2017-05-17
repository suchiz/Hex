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
  for (i = 0; i < b->brd.nb_nodes; i++)
  {
    if(i % dim == 0){
      printf("\n   ");
      esp++;
      for(j = 0; j < esp; j++)
      printf ("  ");
    } 
    printf("(%c)", b->brd.grph[i].color);
  }
  printf ("\n");
}
