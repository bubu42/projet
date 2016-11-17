#ifndef STRUCTURES_H
#define STRUCTURES_H

#define VIDE 0
#define ROUGE 1
#define JAUNE 2



typedef struct{
    int ligne;
    int colonne;
    int valeur[ligne][colonne];
}Plateau;

typedef struct enum Joueur{joueur1,joueur2} ;


typedef struct{
    Plateau P;
    Joueur J;
}Partie;


typedef struct{
    int x;
    int y;
}Coup;

#endif
