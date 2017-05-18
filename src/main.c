#include "../lib/node.h"
#include "../lib/graph.h"
#include "../lib/group.h"
#include "../lib/board.h"
#include "../lib/jouer.h"

/*int main (){

  board b = createBoard(3);
  element_group *eg = createListGroup();
  int joueur = 0;
  int tour = 1;
  
  printf(" JEU HEX : ");
  displayBoard(&b);

  while(tour <= 10){  //mettre condition gagnent
    
      printf("\n Tour n°%d (joueur %d): ", tour, joueur + 1);
      jouer_coup (&b, &joueur, &tour, eg);
      displayBoard(&b);
    
  }
  
  return OK;
}*/

int main (){
  element_group *eg = createListGroup();
  group* groupToAdd = createGroup('x');
  group* groupToAdd2 = createGroup('o');
  group* groupToAdd3 = createGroup('o');
  node * n = createNode(2);
  node * n2 = createNode(3);
  addToGroup(groupToAdd, n);
  addToGroup(groupToAdd2, n);
  addToGroup(groupToAdd3, n2);
  insertElemGroup (eg, groupToAdd);
  insertElemGroup (eg, groupToAdd2);
  insertElemGroup (eg, groupToAdd3);
  printf("adjacent: %d\n", adjacentGroup(groupToAdd, groupToAdd2));
  printf("adjacent: %d\n", adjacentGroup(groupToAdd, groupToAdd3));
  displayListGroup(eg);
  
  updateListGroup(eg);
  displayListGroup(eg);
  
  return OK;
}

  