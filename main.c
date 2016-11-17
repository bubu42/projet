#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "regles_du_jeu.h"


void usage (char *s){
    int largeur=360,hauteur=240;
    
    MLV_create_window("USAGE","CHOIX TYPE DE JEU",largeur,hauteur);
    MLV_draw_text(largeur/2,
                  hauteur/2,
                  "Usage : %s <1> || <2>, 1 pour graphique 2 pour terminale",
                  MLV_COLOR_RED,
                  s
        );
    MLV_actualise_window();
    MLV_wait_seconds(5);
    MLV_free_window();
}




void menu();




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













void menu(){
    int x,y;
  
    int interligne =10;
    
    MLV_clear_window(MLV_COLOR_BLACK);

    MLV_draw_text(240,50,"BIENVENUE AU JEU PUISSANCE 4",MLV_COLOR_RED);
    
    MLV_draw_adapted_text_box(240,100,"NOUVELLE PARTIE",interligne,
                              MLV_COLOR_BLACK,
                              MLV_COLOR_DARK_BLUE,
                              MLV_COLOR_GREY,
                              MLV_TEXT_CENTER
        );
    MLV_draw_adapted_text_box(240,200,"CHARGER PARTIE",
                              interligne,
                              MLV_COLOR_BLACK,
                              MLV_COLOR_DARK_BLUE,
                              MLV_COLOR_GREY,
                              MLV_TEXT_CENTER
        );
    MLV_draw_adapted_text_box(240,300,"CLASSEMENT",
                              interligne,
                              MLV_COLOR_BLACK,
                              MLV_COLOR_DARK_BLUE,
                              MLV_COLOR_GREY,
                              MLV_TEXT_CENTER
        );
    MLV_draw_adapted_text_box(240,400,"REGLES DU JEU",
                              interligne,
                              MLV_COLOR_BLACK,
                              MLV_COLOR_DARK_BLUE,
                              MLV_COLOR_GREY,
                              MLV_TEXT_CENTER
        );
    
    //MLV_draw_text(120,300,"CITAK BUNYAMIN",MLV_COLOR_RED);

    MLV_actualise_window();

    MLV_wait_mouse(&x,&y);
    /*
      if((x>100 && y>120) && (x<110 && y<480-120)){
      //nouvelle_partie();
        
      }
      if((x>200 && y>120) && (x<210 && y<480-120)){
      //charger_partie();
      }
      if((x>300 && y>120) && (x<310 && y<480-120)){
      // classement();
      }*/
    // if((x>100 && y>120) && (x<410 && y<480-120))
    if(x!=0 || y!=0){
      regles_du_jeu();
      }
}
int main(int argc, char *argv[]){
    int largeur=640,hauteur=480;
    
   
   
    MLV_create_window("CITAK BUNYAMIN","JEU PUISSANCE 4 - PROJET DE PROGRAMMATION S3 2016/17",largeur,hauteur);
    
    menu();

    MLV_wait_seconds(10);
    MLV_free_window();
    return 0;
    
}
