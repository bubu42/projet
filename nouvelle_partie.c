#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "structures.h"


Plateau creer_plateu(int n,int m){
    Plateau p;
    int i,j;

    p.ligne=n;
    p.colonne=m;
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            p.valeur[n][m]=VIDE;
        }
    }
    return p;
}

void initialisation_jeu(Partie *partie){
    partie->P=creer_plateu(6,7);
    partie->Joueur=joueur1;
}

Coup lire_coup(){
    int X,Y;
    Coup cp;
    MLV_wait_mouse(&X,&Y);
    cp.x=X;
    cp.y=Y;
    return cp;
}

int est_finie(Partie *partie, Joueur *gagnant){
    int i,j;
    for(i=0;i<partie->ligne;i++){
        for(j=0;j<partie->colonne;j++){
            if(!gagner(&partie) || ){
    
        
            }
        }
    }
}
