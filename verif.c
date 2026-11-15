#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//Source externe, voir AIDE_EXTERIEURE.md 3/
#include <unistd.h>
#include "tic_tac_toe.h"



//Fonction appelée pour vérifier si il y a une condition de fin de jeu, victoire ou défaite.
int verif(char grille[3][3])
{
    int i = 0;
    //La boucle après à pour but de parcourir chaque colonne et ligne du tableau, avec i en variable, on check si la premiere ligne a des symbole identiques (sauf espace), puis deuxieme ligne,puis troisième, >
    while (i < 3)
    {
        if (grille[i][0] != ' ' && grille[i][0] == grille[i][1] && grille[i][1] == grille[i][2]) return 1;
        if (grille[0][i] != ' ' && grille[0][i] == grille[1][i] && grille[1][i] == grille[2][i]) return 1;
        i++;
    //On vérifie après si il y a les mêmes symboles dans l'une des deux diagonales
    }
    if (grille[1][1] != ' ' && grille[0][0] == grille[1][1] && grille[1][1] == grille[2][2]) return 1;
    if (grille[1][1] != ' ' && grille[0][2] == grille[1][1] && grille[1][1] == grille[2][0]) return 1;

    return 0;
}
