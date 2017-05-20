#include "../lib/node.h"
#include "../lib/graph.h"
#include "../lib/group.h"
#include "../lib/board.h"
#include "../lib/jouer.h"


int main (){

  /*TODO   SUPPRIMER LA CASE UNDO DANS LA LISTE DES GROUPES */ 
  
  startGame();

  
return 0;
}


/* TEST STACK 
  int turn=1;
  int player = 2;
  int x= 3;
  int y = 3;
  
  stack test;
  createStack(&test);
  push(&test,turn,player,x,y);
  pop(&test);
  push(&test,5,5,5,5);
  displayStack(&test);
  
  displayStack(&test);

  */




/* TEST GROUP 
  group* g1=createGroup('o');
  group* g2=createGroup('o');
  group* g3=createGroup('o');
  group* g4=createGroup('o');
  node *n1=createNode(2);
  node *n2=createNode(3);
  node *n3=createNode(5);
  node *n4=createNode(6);
  
  addEdge(n1,n2);
  addEdge(n3,n4);
  addEdge(n4,n3);
  
  addToGroup(g1,n1);
  addToGroup(g1,n2);
  addToGroup(g1,n3);
  addToGroup(g2,n4);
  addToGroup(g3,n3);
  addToGroup(g4,n1);
  addToGroup(g4,n2);
  
  int test;
    printf("Test : Doit être Correct\n");
    test=adjacentGroup(g1,g2);
    printf("test = %d\n",test);
  
    printf("Test : Doit être Faux car Head g2 : n3=(5)->n4=(6) et head g4 : n1=(2), n2=(3) \n");
    test=adjacentGroup(g2,g4);
    
   printf("test = %d\n",test);
 
   
   //fusion(g1,g2);
   printf("\nAffiche G1 : (Ajout de g2 dans G1)");
   displayGroup(g1);
   printf(" le noeud n4=6 a bien été ajouté dans g1\n");
   
   
   
   
   
     element_group *eg = createListGroup();
     insertElemGroup(eg,g1); //n1 n2 n3
     insertElemGroup(eg,g2); //n4
    // insertElemGroup(eg,g3); 
    // insertElemGroup(eg,g4); 
     
     
     displayListGroup(eg);
    // element_group* tab=updateListGroup(eg);
     printf("UPDATED : \n");
     displayListGroup(eg);
   
*/      
 


  