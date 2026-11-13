#include <stdlib.h>
#include <stdio.h>

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

int main()
{
	char grille[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	affichage(grille);
	return 0;
}
