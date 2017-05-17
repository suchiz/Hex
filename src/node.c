#include "../lib/node.h"

/*****************************
 * Role: Create a new node   *
 * id : identity of the node *
 *****************************/
node* createNode (const int id){
    node *newNode = malloc(sizeof(struct node_s));
    
    if(newNode == NULL){
        printf("Erreur: Creating new node\n");
        exit(ERR_CREATE_NODE);
    }
    
    newNode->id = id;
    newNode->color = 'e';
    newNode->head = NULL;
    newNode->nb_members = 0;
    
    return newNode;
}

/*************************************************
 * Role: Display a list, may be useful to unbug *
 * n : node with the list to display	         *
 *************************************************/  
void displayNeighboursList (const node *n){
  element *current = n->head;
  
  while(current != NULL){
     printf("%d, ", current->n.id);
     current = current->next;
  }
}