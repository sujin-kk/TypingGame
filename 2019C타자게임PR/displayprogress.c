#include "head.h"

void displayProgress(int score, char* stage, int left_block, int life)
{
	int i;
	gotoxy(20, 3);
	for (i = 0; i < life; i++)
		printf("     ");

	gotoxy(20, 3);
	for (i = 0; i < life; i++)
		printf("¢¾ ");

	gotoxy(24, 5);
	printf("%2d", score);

	gotoxy(24, 7);
	printf("%s", stage);

	gotoxy(24, 9);
	printf("%2d", left_block);
}