#include "../lib/node.h"
#include "../lib/graph.h"
#include "../lib/group.h"
#include "../lib/board.h"

int main (){
   board b = createBoard(3);
   displayGraph(&b.brd);
   displayBoard(&b);

  
  return OK;
}

  