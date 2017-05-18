#include "../lib/graph.h"


/****************************
 * Role: Create a new graph *
 * n : lenght of the graph  *
 ****************************/
graph* createGraph (const int n){
  graph *newGraph = malloc(sizeof(struct graph_s));
  newGraph->grph = malloc(n * n * sizeof(struct node_s));
  
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
 * src: the node which is add a neighbour       *
 * dest: the neighbour to add into src          *
 ************************************************/
void addEdge (node *src, const node *dest){
  element *newElement_src = malloc(sizeof(struct element_s));
  
  if(newElement_src == NULL){
      printf("Erreur: Creating new edge\n");
      exit(ERR_ADD_EDGE);
  }
  
  newElement_src->n = (*dest);
  newElement_src->next = src->head;
  src->nb_members++;
  src->head = newElement_src;
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
  B1->color='x';
  node *B2 = createNode(1001);	// Bot
  B2->color='x';
  node *W1 = createNode(2000);	// Left
  W1->color='o';
  node *W2 = createNode(2001);	// Right x
  W2->color='o';
  
  int n = sqrt(g->nb_nodes);
  int i, j, k;
 
  //BORDERS
  for (i = 0; i < g->nb_nodes; i = i + n) 	// link left and right borders
  {
    addEdge(&g->grph[i], W1);
    addEdge(&g->grph[i + n - 1], W2);
  }
  for (i = 0; i < n; i++)		// link top border
    addEdge(&g->grph[i], B1);
  for (i = g->nb_nodes; i > g->nb_nodes - n; i--)		// link bot border
    addEdge(&g->grph[i], B2);
    
  // GENERIC
  for (i = 0; i < g->nb_nodes; i++)
    for (j = (i / n) - 1; j <= (i / n) + 1; j++)
      for (k = (i % n) - 1; k <= (i % n) + 1; k++)
        if (j >= 0 && j < n && k >= 0 && k < n)
	if ((j == (i/n) - 1 && k == (i%n)) || (j == (i/n) - 1 && k == (i%n) + 1) || (j == (i/n) && k == (i%n) - 1) ||
	    (j == (i/n) && k == (i%n) + 1) || (j == (i/n) + 1 && k == (i%n) - 1) || (j == (i/n) + 1 && k == (i%n)))
	  addEdge(&g->grph[i], &g->grph[n * j + k]);
	
}


