#include "head.h"

void gotoxy(int, int);
void displayPlayer(int, int);

void move(int* player_xposition, int* player_yposition, int horizontal_travel)
{
	removePlayer(*player_xposition, *player_yposition);
	*player_xposition += horizontal_travel;
	displayPlayer(*player_xposition, *player_yposition);
}