#include "head.h"

void displayPlayer(int xpos, int ypos)
{
	gotoxy(xpos, ypos);
	printf("  o\n");
	gotoxy(xpos, ypos + 1);
	printf("¤¤|¤¡\n");
	gotoxy(xpos, ypos + 2);
	printf(" /¤¤");
}