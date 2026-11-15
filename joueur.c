#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//Source externe, voir AIDE_EXTERIEURE.md 3/
#include <unistd.h>
#include "tic_tac_toe.h"


//Fonction appelée lorsque c'est le tour du joueur
int joueur()
{
    int endroit;

    printf("Décidez où jouer (0-8) :\n");
    //Juste après on vérifie si le joueur a entré un chiffre entre 0 et 8, source externe utilisé (Voir le AIDE_EXTERIEURE.md 2/)
    if (scanf("%d", &endroit) != 1 || endroit < 0 || endroit > 8)
    {
        printf("Tu as triché, fin du jeu ;)\n");
        //Fini le programme si le joueur essaie de tricher
        return -1;
    }
    return endroit;
}
