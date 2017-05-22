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
  
  printf ("\nLENGTH of GROUP: %d\n", g->length);
  printf ("MEMBERS of GROUP: ");
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
      //updateListGroup(&b->brd.grph[current->n.id]);
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
  printf ("MEMBERS OF LIST: \n");
  while(current != NULL){
   //  printf("color of group: %c ", current->grp.color);
     displayGroup(&current->grp);
     current = current->next;
  }
  printf("\n");
}

/****************************************************************
 * Role: return 1 if g1 and g2 have at least one node in common *
 ****************************************************************/
int adjacentGroup (const group *g1, const group *g2){
  element* current_group1 = g1->head;
  int adjacent = 0;
 
  while (current_group1 != NULL && !adjacent){
    element *current_group2 = g2->head;
    while (current_group2 != NULL && !adjacent){
        element *current_node = g2->head->n.head;
        while (current_node != NULL && !adjacent){
    if (current_group1->n.id == current_node->n.id)
      adjacent++;
    current_node = current_node->next;
        }
      current_group2 = current_group2->next;
    }
    current_group1 = current_group1->next;
  }
  return adjacent;
}

/******************************************************************************
 * Role: return '.' if no winner found or 'o' or 'x' depending on the winner  *
 ******************************************************************************/
int adjacentGroup2 (const group *g1, const group *g2){
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
  
        if (adjacentGroup(&eg->grp, &current->grp)||adjacentGroup(&current->grp,&eg->grp)||adjacentGroup2(&current->grp,&eg->grp)){
	    fusion(&eg->grp, &current->grp);
        }       
        current = current->next;  
    }
    eg = eg->next;
  }
}

/******************************************************************************
 * Role: return '.' if no winner found or 'o' or 'x' depending on the winner  *
 ******************************************************************************/
char winning_group(const element_group *eg){
    bool noeud_deb_o = false;
    bool noeud_fin_o = false;
    bool noeud_deb_x = false;
    bool noeud_fin_x = false;
    if(eg == NULL){
      return '.';
    }
    
   element_group *current_group=eg->next;

    while (current_group!=NULL){
     
    element* current=current_group->grp.head;
           while(current != NULL){

            if(current->n.id == 1000) {
                noeud_deb_o = true;
            }
            if(current->n.id == 1001) {
                noeud_fin_o = true;
            }
            if(current->n.id == 2000) {
                noeud_deb_x = true;
            }
            if(current->n.id == 2001) {
                noeud_fin_x = true;
            }
             if(noeud_deb_o && noeud_fin_o) {
            return 'o';
	    }
        else if(noeud_deb_x && noeud_fin_x) {
            return 'x';
        }
	    current=current->next;
	   }
	noeud_deb_o = false;
        noeud_fin_o = false;
        noeud_deb_x = false;
        noeud_fin_x = false;

      current_group = current_group->next;
	}	
    return '.';
}





void undoListGroup (element_group *eg,int ind){

   element_group *current_group=eg->next;
  
    while (current_group!=NULL){
     
    element* current=current_group->grp.head;
           while(current != NULL){
	     element* current_node = current->n.head;
	      while(current_node != NULL){

	      
	      
	      if(current_node->n.id == 2001 && current->n.id== ind) {
		
               printf ("il faut supprimer 2001 du groupe du groupe courant");
	      }
            
	      if(current_node->n.id == 2000 && current->n.id== ind) {
                printf ("il faut supprimer 2000 du groupe courrant\n");
		
	      }
	      
	        if(current_node->n.id == 1001 && current->n.id== ind) {
                printf ("ilfaut supprimer 1001 du groupe courrant\n");
	      }
            
	      if(current_node->n.id == 1000 && current->n.id== ind) {
                printf ("ilfaut supprimer 1000 du groupe courrant\n");

	      }
	      
	      
	      
	      
	      current_node = current_node->next;
	      }
	      
	      if(current->n.id == ind) {
                current->n.id=-1;
	      }
	      
	    current=current->next;
	   }
      updateListGroup(current_group);	     
      current_group = current_group->next;
	}
	
}



