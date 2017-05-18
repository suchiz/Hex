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

/****************************
 * Role: Destroy a group    *
 * g : the group to destroy *
 ****************************/
void destroyGroup(group* group){
    if(group == NULL){
        exit(EXIT_FAILURE);
    }
    
    if(group != NULL){
    element* current=group->head;
    
    while(current != NULL){
      element* tmp=current;
      current = current->next;
      free(tmp);        
    }

    free(group);    
  }
}

/*******************************************
 * Role: Merge group2 into group1          *
 * group1: group resulting from merge      *
 * group2: group destroyed after the merge *
 *******************************************/
void fusion(group* group1, group* group2){ 
  element* current = group2->head;
 
  while(current != NULL){
     addToGroup(group1, &current->n);
     current=current->next;
  }
  destroyGroup(group2);
}

/*************************************************
 * Role: Generate a group for the node we played *
 * b: the board we are playing in 	         *
 * n: the node we played		         *
 *************************************************/
group* generateGroup(const board *b, const node *n){
   group *newGroup = createGroup(n->color);
   addToGroup(newGroup, n);
    
   /*check neighbours color group*/
   element *current = n->head;
   while(current != NULL){
      if(b->brd.grph[current->n.id].color == n->color) 		//Add neighbours -> No need if use updateListGroup;
          addToGroup(newGroup, &b->brd.grph[current->n.id]);
      if (current->n.color == n->color)
        addToGroup(newGroup, &current->n);			//Add borders
        
      current = current->next;
   }
  return newGroup; 
}

/*************************************
 * Role: Create a new list of groups *
 *************************************/
element_group* createListGroup (){
  element_group *eg = malloc(sizeof(struct element_group_s));
  
  eg->next = NULL;
  eg->size = 0;
  
  return eg;
}

/**********************************************
 * Role: insert a group into a list of groups *
 * eg : the list we insert into	      *
 * groupToAdd: the group to add               *
 **********************************************/
void insertElemGroup (element_group *eg, const group *groupToAdd){
  element_group *newElement = malloc(sizeof(struct element_group_s));
  
  if(newElement == NULL){
      printf("Erreur: Creating new group\n");
      exit(ERR_CREATE_GROUP);
  }
  
  newElement->grp = (*groupToAdd);
  newElement->next = eg->next;
  
  eg->size++;
  eg->next = newElement;
  
}

void destroyElemGroup (element_group *eg){
    if (eg == NULL){
        exit(EXIT_FAILURE);
    }
    
    if (eg->next !=NULL){
        element_group *current=eg->next;
        while(current != NULL){
        element_group *tmp=current;
        current=current->next;
        free(tmp);
        }
    }
   // free(eg);
}
        

/**********************************
 * Role: Display a list of groups *
 * eg : the list to display	    *
 **********************************/
void displayListGroup (const element_group *eg){
  if(eg == NULL)
      printf ("List is empty\n");
 
  element_group *current = eg->next;
  
  printf ("\nLENGTH LIST: %d\n", eg->size);
  printf ("MEMBERS: \n");
  while(current != NULL){
     printf("color: %c ", current->grp.color);
     displayGroup(&current->grp);
     current = current->next;
  }
  printf("\n");
}

/****************************************************************
 * Role: return 1 if g1 and g2 have at least one node in common *
 ****************************************************************/
int adjacentGroup (const group *g1, const group *g2){
  element* current1 = g1->head;
  int adjacent = 0;
  
  while (current1 != NULL && !adjacent){
    element *current2 = g2->head;
    while (current2 != NULL && !adjacent){
      if (current1->n.id == current2->n.id)
        adjacent++;
      current2 = current2->next;
    }
    current1 = current1->next;
  }
  return adjacent;
}

/**************************************************************
 * Role: Merge groups of the list if they have the same color *
 * eg : the list to update 		         	            *
 **************************************************************/
void updateListGroup (element_group *eg){
  
  while (eg != NULL){
     element_group *current = eg->next;
     while(current != NULL){
        if (eg->grp.color == current->grp.color && adjacentGroup(&eg->grp, &current->grp)){
            
             displayGroup(&current->grp);
            fusion(&eg->grp, &current->grp);
           
          //destroyElemGroup(current);
            updateListGroup(eg);
        }
       
        current = current->next;
    }
    eg = eg->next;
  }
  
}




char winning_group(element_group* eg){
    
    bool noeud_deb_o = false;
    bool noeud_fin_o = false;
    bool noeud_deb_x = false;
    bool noeud_fin_x = false;
    while(eg != NULL)
    {
        while(eg->grp.head != NULL)
        {
            if(eg->grp.head->n.id == 1000) {
                noeud_deb_o = true;
            }
            if(eg->grp.head->n.id == 1001) {
                noeud_fin_o = true;
            }
            if(eg->grp.head->n.id == 2000) {
                noeud_deb_x = true;
            }
            if(eg->grp.head->n.id == 2001) {
                noeud_fin_x = true;
            }
            eg->grp.head = eg->grp.head->next;
        }

        if(noeud_deb_o && noeud_fin_o) {
            return 'o';
        }
        else if(noeud_deb_x && noeud_fin_x) {
            return 'x';
        }

        noeud_deb_o = false;
        noeud_fin_o = false;
        noeud_deb_x = false;
        noeud_fin_x = false;

        eg = eg->next;
    }
    return '.';
}

int winner(element_group* eg){
    
    char win = winning_group(eg);
    if(win == 'o') {
        printf("White player won the game !\n");
        return 1;
    }
    else if(win == 'x') {
        printf("Black player won the game !\n");
        return 2;
    }
    return 0;
}
