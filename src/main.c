#include "../lib/node.h"
#include "../lib/graph.h"
#include "../lib/group.h"
#include "../lib/board.h"
#include "../lib/jouer.h"

int main (){

    jouer();
   board b = createBoard(3);
   displayGraph(&b.brd);
   displayBoard(&b);

   group* g=createGroup('.');
addToGroup(g,&b.brd.grph[1]);
addToGroup(g,&b.brd.grph[2]);
addToGroup(g,&b.brd.grph[2]);
addToGroup(g,&b.brd.grph[2]);

group* g1=createGroup('l');
addToGroup(g,&b.brd.grph[3]);
addToGroup(g,&b.brd.grph[5]);

fusion(g1,g);

displayGroup(g1);
fusion(g1,g);

displayGroup(g1);
  jouer();
  
  return OK;
}

  