#include "head.h"

void removeBlock(int xpos, int ypos, int level)
{
	int block_length = level * 15;
	gotoxy(xpos, ypos);
	for (int i = 0; i < block_length; i++)
	{
		printf(" ");
	}

}