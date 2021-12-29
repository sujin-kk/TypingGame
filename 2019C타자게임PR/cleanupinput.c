#include "head.h"

void cleanUpInput(char* input_p)
{
	for (int i = 0; i < 20; i++) //문자열 비우기
	{
		input_p[i] = 0; //문자열의 끝을 확인가능
	}

	gotoxy(62, 21);
	printf("                   ");
}