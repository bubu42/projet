#include <MLV/MLV_all.h>

void regles_du_jeu(){
int x,y;
    int interligne =10;

    /*NETTOIE LA FENETRE MENU POUR AFFICHER LES REGLES DU JEU*/
    MLV_clear_window(MLV_COLOR_BLACK);

    MLV_draw_adapted_text_box(0,0,
                          "Découvrez la règle du puissance 4, jeu de société à la fois simple mais demandant \nun minimum de stratégie.\nLe but étant de faire aligner 4 jetons de sa propre couleur.\n",
                          interligne,
                          MLV_COLOR_BLACK,
                          MLV_COLOR_WHITE,
                          MLV_COLOR_BLACK,
                          MLV_TEXT_LEFT
        );
    
    
    MLV_draw_adapted_text_box(0,80,
                          "Pour jouer au puissance 4, il vous faut :\n -Le plateau du jeu et ses 42 emplacements pour jetons répartis en 6 lignes et 7 colonnes.\n -42 jetons de 2 couleurs différentes\n -Être 2 joueurs\n",
                          interligne,
                          MLV_COLOR_BLACK,
                          MLV_COLOR_WHITE,
                          MLV_COLOR_BLACK,
                          MLV_TEXT_LEFT
        );

     
    MLV_draw_adapted_text_box(0,200,
                          "Commencer une partie de puissance 4 :\nPour commencer une partie de puissance 4, on désigne le premier joueur. Celui­ci met \nun de ses jetons de couleur\n dans l’une des colonnes de son choix. Le jeton tombe alors en bas de la colonne.\nLe deuxième joueur insère à son tour son jeton, \nde l’autre couleur dans la colonne de son choix. \nEt ainsi de suite jusqu’à obtenir une rangée de 4 jetons de même couleur.\n",
                          interligne,
                          MLV_COLOR_BLACK,
                          MLV_COLOR_WHITE,
                          MLV_COLOR_BLACK,
                          MLV_TEXT_LEFT
        );
    
    
    MLV_draw_adapted_text_box(0,350,
                          "Comment gagner une partie de puissance 4 :\nPour gagner une partie de puissance 4, il suffit d’être le premier à aligner 4 jetons \nde sa couleur horizontalement, verticalement et diagonalement.\nSi lors d’une partie, tous les jetons sont joués sans qu’il y est d’alignement de \njetons, la partie est déclaré nulle.\n",
                          interligne,
                          MLV_COLOR_BLACK,
                          MLV_COLOR_WHITE,
                          MLV_COLOR_BLACK,
                          MLV_TEXT_LEFT
        );
    
    MLV_draw_adapted_text_box(480,450,
                              "RETOUR AU MENU",
                              interligne,
                              MLV_COLOR_BLACK,
                              MLV_COLOR_MAGENTA,
                              MLV_COLOR_BLACK,
                              MLV_TEXT_CENTER
        );

    MLV_wait_mouse(&x,&y);
    if(x>=480 && y>=450){
        menu();
    }
    MLV_actualise_window();


  

}
