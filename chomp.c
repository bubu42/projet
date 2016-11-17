#include<stdio.h>
#include<stdlib.h>
#include <MLV/MLV_all.h>

/*definition des structures*/

typedef enum Joueur Joueur;
typedef struct{
    int dim_x;
    int dim_y;
    int carreau[100][100];
}Tablette ;

enum Joueur
{
    JOUEUR1,JOUEUR2
};

typedef struct
{
    int x; 

    int y; 
}Coup;

typedef struct
{
    Tablette tab;
    enum Joueur joueur;
}Configuration;

/*creation de la tablette*/

Tablette creer_tablette(int m, int n){
    int i,j;
    Tablette tab;
    tab.dim_x=m;
    tab.dim_y=n;
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            tab.carreau[i][j]=1;
        }
    }
    return tab;
}

/*changement d'etat des carreaux*/

/*void manger(Tablette *t, int x, int y){
    int i
    while (t->carreau[x][y]==1){
        while (t->carreau[x][i]==1){
            t->carreau[x][i]=0;
            i++;
        }
        x++;
        i=y;
    }
    }*/
void manger(Tablette *t,int x,int y){
    int i,j;
    
    for(i=x;i<(t->dim_x);i++){
        for(j=y;j<(t->dim_y);j++){
            t->carreau[i][j]=0;
            
        }
    }
}
/*verification du coup*/

int est_legal(Configuration *config, Coup *cp){
    if (config->tab.carreau[cp->x][cp->y]==1){
        return 1;
    }
    return 0;
}

/*Verification de la fin de partie*/

int est_finie(Configuration *config, Joueur *gagnant){
    if (config->tab.carreau[0][0]==0){
        gagnant = &config->joueur;
        return 1;
    }
    return 0;
}

/*application du coup*/

void jouer_coup(Configuration *config, Coup *cp){
    manger(&config->tab, cp->x, cp->y);
    if (config->joueur==JOUEUR1){
        config->joueur=JOUEUR2;
    }else{
	config->joueur=JOUEUR1;
    }
}

/*affichage de la configuration 
 *(carrés pleins gris pour les cases restantes, vide rouge pour les cases mangées*/

void afficher_configuration(Configuration *config){
    int i,j;
    for (i=0; i<config->tab.dim_x; i++){ 
        for (j=0; j<config->tab.dim_y;  j++){ 
            if(config->tab.carreau[i][j]==1){
                MLV_draw_filled_rectangle( i*35, j*35, 30, 30, MLV_COLOR_GREY);
            }else{
                MLV_draw_rectangle( i*35, j*35, 30, 30, MLV_COLOR_RED);
                }
        }
    }
}

/*Lecture de la case cliquée par rapport a la position dela souris*/

Coup lire_coup(Configuration *config){
    Coup coup;
    int x,y;
    do{
        MLV_Event event_type=MLV_NONE;
        MLV_Keyboard_button touche;
        event_type = MLV_wait_keyboard_or_mouse( &touche, NULL, NULL, &x, &y );

        if( event_type == MLV_MOUSE_BUTTON ){
            MLV_get_mouse_position( &x, &y );
            MLV_actualise_window(); 
            coup.y=y/35;
            coup.x=x/35;

        }
        MLV_actualise_window();
    }while (est_legal(config,&coup)!=1);
    return coup;
}

/*assemblage dans le main*/

int main(int argc, char *argv[]){
    if (argc!=3 || atoi(argv[1])<2 || atoi(argv[1])>17 ||atoi(argv[2])<2 ||atoi(argv[2])>17){
     printf("\nentrez les dimensions de la tablette de cette maniere : \n%s <entier>(compris entre 2 et 14) <entier>(compris entre 2 et 13)\n\n",argv[0]);
    exit(-1);
    }
    int n=atoi(argv[1]);
    int m= atoi(argv[2]);
    Coup test;
    Configuration config;
    Tablette t= creer_tablette(n,m);
    Joueur gagnant;
    config.tab=t;
    config.joueur=JOUEUR1;
    MLV_create_window( "Jeu de chomp: Didier--Roche Francois", "Jeu de chomp", 640, 480 );
    while (est_finie(&config, &gagnant)!=1){
        MLV_clear_window( MLV_COLOR_BLACK );
        if (config.joueur == JOUEUR1){
            MLV_draw_text(
                500, 450, 
                "Joueur 1",
                MLV_COLOR_RED
                );
        }else{
            MLV_draw_text(
                500, 450, 
                "Joueur 2",
                MLV_COLOR_RED
                );
	}
        MLV_actualise_window();
	afficher_configuration(&config);
	MLV_actualise_window();
	test = lire_coup(&config);
	jouer_coup(&config, &test);

   
    }
    
    MLV_clear_window(MLV_COLOR_BLACK);
    
    if (config.joueur == JOUEUR1){
        MLV_draw_text(
            270, 240, 
            "Bien joué Joueur 1!",
            MLV_COLOR_RED
            );
        MLV_draw_text(
            275, 260, 
            "Tu as gagné!",
            MLV_COLOR_RED
            );
    }else{
        MLV_draw_text(
            290, 240, 
            "Bien joué Joueur 2!",
            MLV_COLOR_RED
            );
        MLV_draw_text(
            295, 260, 
            "Tu as gagné!",
            MLV_COLOR_RED
            );
    }
    MLV_actualise_window();
    MLV_wait_seconds( 10 );
    MLV_free_window();
    return 0;
}
	
	
