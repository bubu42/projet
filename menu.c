#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "./include/nouvelle_partie.h"
#include "./include/charger_partie.h"
#include "./include/classement.h"
#include "./include/regles_du_jeu.h"

void menu(){
    int x,y;
    int interligne =10;
 
    
    MLV_draw_adapted_text_box(100,120,"NOUVELLE PARTIE",
                              interligne,
                              MLV_COLOR_BLACK,
                              MLV_COLOR_DARK_BLUE,
                              MLV_COLOR_GREY,
                              MLV_TEXT_CENTER
        );
    MLV_draw_adapted_text_box(200,120,"CHARGER PARTIE",
                              interligne,
                              MLV_COLOR_BLACK,
                              MLV_COLOR_DARK_BLUE,
                              MLV_COLOR_GREY,
                              MLV_TEXT_CENTER
        );
    MLV_draw_adapted_text_box(300,120,"CLASSEMENT",
                              interligne,
                              MLV_COLOR_BLACK,
                              MLV_COLOR_DARK_BLUE,
                              MLV_COLOR_GREY,
                              MLV_TEXT_CENTER
        );
    MLV_draw_adapted_text_box(400,120,"REGLES DU JEU",
                              interligne,
                              MLV_COLOR_BLACK,
                              MLV_COLOR_DARK_BLUE,
                              MLV_COLOR_GREY,
                              MLV_TEXT_CENTER
        );
    
    MLV_draw_text(500,120,"CITAK BUNYAMIN",MLV_COLOR_RED);

    MLV_actualise_window();

    MLV_wait_mouse(&x,&y);
    
    if((x>100 && y>120) && (x<110 && y<480-120)){
        nouvelle_partie();
    }
    if((x>200 && y>120) && (x<210 && y<480-120)){
        charger_partie();
    }
    if((x>300 && y>120) && (x<310 && y<480-120)){
        classement();
    }
    if((x4100 && y>120) && (x<410 && y<480-120)){
        regles_du_jeu();
    }
}
