#include "../lib/jouer.h"


int coordonnee(const board* b,int x,int y){
   int n=sqrt(b->brd.nb_nodes);
   
    int ret1=0;
    int ret2=0;
   
    while (ret1<(x*n)-n){
        ret1=ret1+n;
    }
    
    while (ret2<y-1){
        ret2=ret2+1;   
    }
    
    return (ret1+ret2);
}

int coup_valide(const board *b,const int ind){
    if(b->brd.grph[ind].color=='.'){
        return (true);
    }else{
        return(false);
    }
}

int jouer_coup(board b,int joueur){
    
    int x,y;
    int ind;
    int valide=0;
   
  while(valide==0){
    printf ("\nSaisissez la ligne de la case puis la colonne :");
    scanf ("%d", &x);
    scanf ("%d", &y);
     ind=coordonnee(&b,x,y);
    
     if(coup_valide(&b,ind)){
       valide=1;
        if (joueur==1){
            
            b.brd.grph[ind].color='x';
            
        }else{ 
            b.brd.grph[ind].color='x';
        }
      group *g=generateGroup(&b,&b.brd.grph[ind]);
        displayGroup(g);
       // displayGraph(&b.brd);
     }
     if(valide==0){
         printf("Saisie invalide, résseyez !\n");
     }
    
   }
   
    return ((joueur+1)%2);
    
}

int jouer(){
            
 board b=createBoard(3);

    
    int joueur=1;
    int tour=1;
    printf(" JEU HEX : ");
    displayBoard(&b);

    while(tour<=10){  //mettre condition gagnent
        printf("\n Tour n°%d (joueur %d): ", tour,joueur);
        joueur= jouer_coup(b,joueur);
        displayBoard(&b);
        tour++;
    }

    return 0;
    
}

