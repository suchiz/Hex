#include "../lib/group.h"

/******************************
 * Role: Create a new group 	*
 * color : color of the group *
 ******************************/
group* createGroup (const char color){
  group *newGroup = malloc(sizeof(struct group_s));
  
  if(newGroup == NULL){
      printf("Erreur: Creating new group\n");
      exit(ERR_CREATE_GROUP);
  }

  newGroup->color = color;
  newGroup->length = 0;
  newGroup->head = NULL;
  
  return newGroup;
}

/***************************************************************************
 * Role: Create a new group 	 				     *
 * color : color of the group 				     *
 * nodeToAdd : constant, no modification on it, member to add to the group *
 ***************************************************************************/
void addToGroup (group *g, const node *nodeToAdd){
  element *current = g->head;
  bool notADup = true;
  
  while(current != NULL && notADup){
     notADup = current->n.id != nodeToAdd->id;
     current = current->next;
  }
  
  if (notADup){
    element *newElement = malloc(sizeof(struct element_s));
    
    if(newElement == NULL){
        printf("Erreur: Creating new element\n");
        exit(ERR_CREATE_ELEMENT);
    }
    
    newElement->n = (*nodeToAdd);
    newElement->next = g->head;
    
    g->length++;
    g->head = newElement;
  }
}

/*************************************************
 * Role: Display a group, may be useful to unbug *
 * g : the group to display	                   *
 *************************************************/
void displayGroup (const group *g){
  if(g == NULL)
      printf ("Group is empty\n");
 
  element *current = g->head;
  
  printf ("\nLENGTH: %d\n", g->length);
  printf ("MEMBERS: ");
  while(current != NULL){
     printf("%d, ", current->n.id);
     current = current->next;
  }
  printf("\n");
}