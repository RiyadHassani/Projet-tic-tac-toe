#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//Source externe, voir AIDE_EXTERIEURE.md 3/
#include <unistd.h>

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

//Fonction appelée lorsque c'est le tour de l'ordinateur
int ordinateur()
{
	//Pour donner un aspet "Intelligent à l'ordinateur, j'ai simplement fait générer un nombre entre 0 et 8 qui représente une case de la grille, source externe utilisé (voir le AIDE_EXTERIEURE.md 3/)
	int endroit = rand() % 9;
	return endroit;
}

//Fonction appelée pour vérifier si il y a une condition de fin de jeu, victoire ou défaite.
int verif(char grille[3][3])
{
    int i = 0;
    //La boucle après à pour but de parcourir chaque colonne et ligne du tableau, avec i en variable, on check si la premiere ligne a des symbole identiques (sauf espace), puis deuxieme ligne,puis troisième, après même chose pour les colonnes.
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


//On a après le main, le corps de tout le jeu qui dicte toute la chronologie de la partie.
int main()
{
	//srand(time(NULL)); vient d'une source externe (voir le AIDE_EXTERIEURE.md 3/), il est au début de main comme ça il va etre lancé dès le début et il n'y aura pas besoin d'attendre que la fonction ordinateur() se lance.
	srand(time(NULL));
	//Pour chaque case il y a un char ' ' (espace) qui sera modifié par X ou O par la suite. Source externe utilisée, lire le AIDE_EXTERIEURE.md 1/
	char grille[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	affichage(grille);
	int coups = 0;
	//La partie la plus longue en morpion est de 9 tours (égalité), on vérifie juste si il n'y a pas match nul.
	while (coups < 9)
	{
		int x=0;
                int y=0;
		int coup = joueur();
		if (coup == -1)
		{
			//On arrète le jeu car le joueur a triché et donc la fonction main a renvoyé -1
    			return 0;
		}
		y=coup/3;
		x=coup%3;
		//On vérifie aussi que le joueur ait pris une case vide. Si elle n'est pas vide, on le lui dit pour qu'il reprenne une case
		while(grille[x][y]!=' ')
		{
			printf("Case déjà prise\n");
			coup = joueur();
			if (coup == -1)
                	{
                        	return 0;
                	}
                	y=coup/3;
                	x=coup%3;
		}

		grille[x][y]='X';
		affichage(grille);
		coups++;
		//Directement après le tour du joueur, on vérifie si il a aligné les trois symboles.
    		if (verif(grille)==1)
    		{
        		printf("Gagné !\n");
        		break;
    		}
		//Sans ce if, l'ordinateur rejouait un coup alors que la partie était finie.
    		if (coups == 9)
		{
        		break;
		}


		printf("Au tour de l'ordinateur...\n");
		//Temps d'atente sinon la partie est illisible, source externe utilisée (voir le AIDE_EXTERIEURE.md 4/ )
		sleep(2);
		while (grille[x][y]!=' ')
		{
			coup = ordinateur();
			y=coup/3;
			x=coup%3;
		}
		grille[x][y]='O';
		affichage(grille);
		coups++;
    		if (verif(grille)==1)
    		{
        		printf("Perdu !\n");
        		break;
    		}

	}

	//Enfin si toute les cases sont remplies et que l'on ne détecte aucun gagnant, on dit qu'il y a match nul
	if (verif(grille) == 0)
	{
    		printf("Match nul !\n");
	}

	return 0;
}

