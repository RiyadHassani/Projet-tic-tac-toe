#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//Source externe, voir AIDE_EXTERIEURE.md 3/
#include <unistd.h>
#include "tic_tac_toe.h"


//Fonction permettant d'afficher la grille
void affichage(char grille[3][3])
{
        int x=0;
        int y=0;
        while(y!=3)
        {
                printf("%c | %c | %c \n", grille[x][y], grille[x+1][y],grille[x+2][y]);
                y++;
                if(y!=3)
                {
                        printf("---------\n");
                }
        }
}
