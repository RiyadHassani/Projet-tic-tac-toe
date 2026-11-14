#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

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




int joueur()
{
    int endroit;

    printf("Décidez où jouer (0-8) :\n");
    if (scanf("%d", &endroit) != 1 || endroit < 0 || endroit > 8)
    {
        printf("Tu as triché, fin du jeu ;)\n");
        return -1;
    }
    return endroit;
}

int ordinateur()
{
	int endroit = rand() % 9;
	return endroit;
}



int main()
{
	srand(time(NULL));
	char grille[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	affichage(grille);
	int coup = joueur();
	if (coup == -1)
	{
    		return 0;
	}
	int x=0;
        int y=0;
	y=coup/3;
	x=coup%3;
	grille[x][y]='X';
	affichage(grille);
	printf("Au tour de l'ordinateur\n");
	sleep(2);
	while (grille[x][y]!=' ')
	{
		coup = ordinateur();
		y=coup/3;
        	x=coup%3;
	}
	grille[x][y]='O';
	affichage(grille);
	return 0;
}
