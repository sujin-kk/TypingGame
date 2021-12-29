#include "head.h"

void gotoxy(int, int);

void displayWord(int x, int y, char* word) {
	gotoxy(x, y);
	printf("                   ");
	gotoxy(x, y);
	printf("%s", word);

}