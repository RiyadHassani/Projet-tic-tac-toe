#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//Source externe, voir AIDE_EXTERIEURE.md 3/
#include <unistd.h>
#include "tic_tac_toe.h"


//Fonction appelée lorsque c'est le tour de l'ordinateur
int ordinateur()
{
        //Pour donner un aspet "Intelligent à l'ordinateur, j'ai simplement fait générer un nombre entre 0 et 8 qui représente une case de la grille, source externe utilisé (voir le AIDE_EXTERIEURE.md 3/)
        int endroit = rand() % 9;
        return endroit;
}
