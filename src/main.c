#include "../lib/node.h"
#include "../lib/graph.h"
#include "../lib/group.h"
#include "../lib/board.h"
#include "../lib/jouer.h"

int main (){
  
   board b = createBoard(3);
   displayGraph(&b.brd);
   displayBoard(&b);

   group* g=createGroup('.');
  addToGroup(g,&b.brd.grph[2]);


group* g1=createGroup('l');
addToGroup(g1,&b.brd.grph[3]);
addToGroup(g1,&b.brd.grph[5]);

displayGroup(g1);
displayGroup(g);
  

g1=fusion(g1,g);

displayGroup(g1);
displayGroup(g);
  
  
  return OK;
}

  