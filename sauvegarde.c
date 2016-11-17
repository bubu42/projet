#include <stdio.h>
#include <stdlib.h>
#include "./include/structures.h"
#include "MLV_all.h"






void sauvegarde(Partie *partie) {
    FILE* fichier = NULL;
    int i, j;
    char succes[33]="La partie a bien été sauvegardé !";
    char erreur[35]="La partie n'a pas été sauvergardé !";
    char* text ;
    char sauv[]=".sauv"
    MLV_actualis_window();


    MLV_wait_input_box(
        10,70,
        200,90,
        MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
        "Nom de la sauvegarde : ",
        &text
        );
   
    snprintf(text,sizeof text,"%s%s",filename,sauv); /*concatenation du nom de la sauvegarde avec .sauv */


    fichier=fopen(filenamedat,"wb+");/*on ouvre le fichier,si il existe on efface ce qui est dedans*/
   


    if(fichier == NULL) {/* Quitte si le fichier n'a pas pu s'ouvrir*/
        MLV_draw_text(100,100,erreur,MLV_COLOR_RED);
        MLV_actualis_window();
        
    }
    
    else {
        fprintf(fichier, "%d\n", , partie.J); /* Enregistre au début le tour du prochain joueur */
        for(i = 0; i< partie.nb_lignes; i++) { /* Ecrit l'état du plateau*/
            for(j = 0; j < partie.nb_colonnes; j++){
                fprintf(fichier, "%d", partie.plateau[i][j]);
            }
            fprintf(fichier, "\n");
        }
        MLV_draw_text(100,100,succes,MLV_COLOR_RED);
        MLV_actualis_window();
        fclose(fichier);/* Ferme le fichier*/
    }
    
    free( text ); /*libère l'allocation pour le text*/
    MLV_free_window();/*libère la fenetre*/
    
}
