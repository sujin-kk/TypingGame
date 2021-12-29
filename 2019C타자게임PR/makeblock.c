#include "head.h"

void makeblock(int* level, int* block_xposition, int* block_yposition)
{
	int block_length = 15 * (*level); //만들어지는 블럭의 길이
	*block_yposition = 3; //블럭의 좌표
	int i;

	*block_xposition = 39 + rand() % (6 - (*level)) * 15;
	/*
		level 변수에 할당되는 값:
		1: 초급
		2: 중급
		3: 고급
	*/

	gotoxy(*block_xposition, *block_yposition);
	for (i = 0; i < block_length; i++)
	{
		printf("*");
	}
}