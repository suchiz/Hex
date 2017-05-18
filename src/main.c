#include "../lib/node.h"
#include "../lib/graph.h"
#include "../lib/group.h"
#include "../lib/board.h"
#include "../lib/jouer.h"


int main (){

    //B1 = 1000 TOP = 'o'
    //B2 = 1001 BOT = 'o'
    //W1,W2 = LEFT,RIGHT = 2000,2001= 'x'
    int joueur=1;
    int tour =1;
    board b=createBoard(3);
    displayBoard(&b);
    
    element_group *J1=createListGroup();    
    element_group *J2=createListGroup();
    element_group *current;
    
    char winning='.';
   
   while(winning=='.'){ 
       
       if(joueur==1){
           current=J1; //joueur= X
       }else{
           current=J2; //joueur= O
       }
     jouer_coup(&b,&joueur,&tour,current);
     
     displayListGroup(current);
     displayBoard(&b);    
     
      winning=winning_group(current);

  
       
      
}
    
    
    
    

return 0;
//     
} 

    /*TEST GROUP*
        
    char win;
  element_group *eg = createListGroup();
  group* groupToAdd = createGroup('o');
  group* groupToAdd2 = createGroup('o');
  group* groupToAdd3 = createGroup('x');
  
  node * n = createNode(2);
  node * n2 = createNode(3);
  node * n3 = createNode(4);
  node * n5 = createNode(5);
  node * B1 = createNode(1000);
  node * B2 = createNode(1001);
  addToGroup(groupToAdd, n);
  addToGroup(groupToAdd, n2);
  addToGroup(groupToAdd2, n);
  addToGroup(groupToAdd,B1);
  addToGroup(groupToAdd2,B2);
  
   addToGroup(groupToAdd2, n3);
   addToGroup(groupToAdd3, n5);
   addToGroup(groupToAdd3, n2);
   
   
  insertElemGroup (eg, groupToAdd);
  insertElemGroup (eg, groupToAdd2);
  insertElemGroup (eg, groupToAdd3);
  
  

  printf("adjacent: %d\n", adjacentGroup(groupToAdd, groupToAdd2));
  //printf("adjacent: %d\n", adjacentGroup(groupToAdd, groupToAdd3));
 printf ("\nDisp list group\n");
  displayListGroup(eg);
  
  updateListGroup(eg);
  printf ("Apres update\n");
  displayListGroup(eg);
  
  win=winning_group(eg);
printf ("Le gagnant est '%c' \n",win);  
    
    
*/
 


  