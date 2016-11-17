#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "structures.h"


/*On cree une grille vide*/
Tablette creer_grille(){
    int i,j;
    Plateau grille;
    grille.ligne=6;
    grille.colonne=7;

    for(i=0;i<grille.ligne;i++){
        for(j=0;j<grille.colonne;j++){
            grille.valeur[grille.ligne][grille.colonne]=VIDE;
        }
    }

    return grille;
}


/*affichage des traits de la grille dans lequel le jeu va se derouler*/
void grille_MLV(){
    int i;
     

    MLV_draw_line(1,1,630,1,MLV_COLOR_RED);
    for(i=1;i<=6;i++)
        MLV_draw_line(1,i*70,630,i*70,MLV_COLOR_RED);
    
    MLV_draw_line(1,419,1,0,MLV_COLOR_BLUE);
    for(i=1;i<=7;i++)
        MLV_draw_line(i*90,419,i*90,0,MLV_COLOR_BLUE);
    MLV_actualise_window();

}


/*verifie qu'une case est vide pour un coup donné*/
int verif_case_vide(Partie *partie, Coup *coup){
    if(partie->P.valeur[cp->x][cp->y]==VIDE){
        return 1;
    }
    else return 0;
}


    
/*Si le joueur1 joue une case case vide alors elle devient jaune sinon rouge, sinon rien ne se passe*/
Partie changement_couleur_pion(Partie *partie,int x,int y){
    Coup cp;
    cp.x=x;
    cp.y=y;
    
    if(verif_case_vide(&partie,&cp)==1 && partie->J=joueur1){
        partie->P.valeur[cp.x][cp.y]=JAUNE;
    }
    if(verif_case_vide(&partie,&cp)==1 && partie->J=joueur2){
        partie->P.valeur[cp.x][cp.y]=ROUGE;
    }
    return partie;   
}    
