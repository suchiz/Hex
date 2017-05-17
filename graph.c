#include "graph.h"


/***********************
 * STRUCTURE OF A NODE *
 ***********************/
struct node_s // Case = hexagone = node = summit
{
    char color;		// white 'x', black 'o', or empty '.'
    int id;        		// identity of the node = coordonate in the graph
    int nb_members;       	// numbers of edges
    element *head;     	// list of adjacents nodes
};
 
/************************
 * STRUCTURE OF A GRAPH *
 ************************/
struct graph_s // board = graph
{ 
    int nb_nodes;         	// total number of nodes in the graph 
    node *grph;     	// array of nodes
};

/***************************
 * STRUCTURE OF AN ELEMENT *
 ***************************/
struct element_s //element for list implementation
{
    node n;		// a node in the graph
    struct element_s *next;   // pointer to the next element of the group
};

/************************
 * STRUCTURE OF A GROUP *
 ************************/
struct group_s // group = evolved chain
{
    char color; 		// color of the group, may be white or black only
    int length;		// lenght of the group
    element *head;		// group/list/array of element;
};

/************************
 * STRUCTURE OF A BOARD *
 ************************/
struct board_s
{
  graph brd;
};

/*****************************
 * Role: Create a new node   *
 * id : identity of the node *
 *****************************/
node* createNode (const int id){
    node *newNode = (node*) malloc(sizeof(struct node_s));
    
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

/******************************
 * Role: Create a new group 	*
 * color : color of the group *
 ******************************/
group* createGroup (const char color){
  group *newGroup = (group*) malloc(sizeof(struct group_s));
  
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
  element *newElement = (element*) malloc(sizeof(struct element_s));
  
  if(newElement == NULL){
      printf("Erreur: Creating new element\n");
      exit(ERR_CREATE_ELEMENT);
  }
  
  newElement->n = (*nodeToAdd);
  newElement->next = g->head;
  
  g->length++;
  g->head = newElement;
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
 * Role: Create a new graph *
 * n : lenght of the graph  *
 ****************************/
graph* createGraph (const int n){
  graph *newGraph = (graph*) malloc(sizeof(struct graph_s));
  newGraph->grph = (node*) malloc(n * n * sizeof(struct node_s));
  
  if(newGraph == NULL || newGraph->grph == NULL){
    printf("Erreur: Creating new graph\n");
    exit(ERR_CREATE_GRAPH);
  }
  
  newGraph->nb_nodes = n * n;
  
  int i;
  for(i = 0; i < n * n; i++)
  {
    newGraph->grph[i].color = '.';
    newGraph->grph[i].id = i;
    newGraph->grph[i].head = NULL;
    newGraph->grph[i].nb_members = 0;
  }
 
  return newGraph;
}

/************************************************
 * Role: Create a new edge between src and dest *
 * src: In fact, there's no really a source     *
 * dest: nor a destination, they add each other *
 ************************************************/
void addEdge (node *src, node *dest){
  element *newElement_src = (element*) malloc(sizeof(struct element_s));
  element *newElement_dest = (element*) malloc(sizeof(struct element_s));
  
  if(newElement_src == NULL || newElement_dest == NULL){
      printf("Erreur: Creating new edge\n");
      exit(ERR_ADD_EDGE);
  }
  
  newElement_src->n = (*dest);
  newElement_src->next = src->head;
  src->nb_members++;
  src->head = newElement_src;
  
  newElement_dest->n = (*src);
  newElement_dest->next = dest->head;
  dest->nb_members++;
  dest->head = newElement_dest;
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
 
/*************************************************
 * Role: Display a graph, may be useful to unbug *
 * g : the graph to display	                   *
 *************************************************/ 
void displayGraph (const graph *g){
  if(g == NULL)
      printf ("Graph is empty\n");
  
  int i;
  printf("DISPLAYING GRAPH: \n");
  for (i = 0; i < g->nb_nodes; i++)
  {
    printf("I am the node n°%d, my neighbours are: ", g->grph[i].id);
    displayNeighboursList(&g->grph[i]);
    printf("\n");
  }
} 

/***********************************
 * Role: Link a graph with borders *
 * g : the graph to link	     *
 ***********************************/ 
void linkGraph (graph *g){
  node *B1 = createNode(1000); 	// Top
  node *B2 = createNode(1001);	// Bot
  node *W1 = createNode(2000);	// Left
  node *W2 = createNode(2001);	// Right
  
  int n = sqrt(g->nb_nodes);
  int i, j;
 
  for (i = 0; i < g->nb_nodes; i = i + n) 	// link left and right borders
  {
    addEdge(&g->grph[i], W1);
    addEdge(&g->grph[i + n - 1], W2);
  }

  for (i = 0; i < n; i++)		// link top border
    addEdge(&g->grph[i], B1);
  
  for (i = g->nb_nodes; i > g->nb_nodes - n; i--)		// link bot border
    addEdge(&g->grph[i], B2);
    
  for (i = n; i < g->nb_nodes; i = i + n){	
     for(j = 0; j < n; j++){
        addEdge(&g->grph[i + j], &g->grph[i + j - n]); // link upper node
     }
     
     for(j = 0; j < n - 1; j++){
        addEdge(&g->grph[i + j], &g->grph[i + j + 1]); 	 // link right node
        addEdge(&g->grph[i + j], &g->grph[i + j - n + 1]); 	 // link diagonal upper right
     }
  }
}

/****************************
 * Role: Create a new board *
 * n : size of n * n        *
 ****************************/ 
board createBoard (const int n){
  board newBoard;
  graph *g = createGraph(n);
  linkGraph(g);
  (&newBoard)->brd = (*g);
  
  return newBoard;
}
  
/******************************************
 * Role: Display the board, it is the GUI *
 * b :the board to display                *
 ******************************************/ 
void displayBoard(const board *b){
  int dim = sqrt(b->brd.nb_nodes);
  int esp = 0;
  int i, j;
  for (i = 0; i < b->brd.nb_nodes; i++)
  {
    if(i % dim == 0){
      printf("\n   ");
      esp++;
      for(j = 0; j < esp; j++)
      printf ("  ");
    } 
    printf("(%c)", b->brd.grph[i].color);
  }
  printf ("\n");
}

int main ()
{
  board b = createBoard(8);
  displayGraph(&b.brd);
  displayBoard(&b);
  
  //Regarde je met un commentaire dans le main là
  
  return 0;
}

