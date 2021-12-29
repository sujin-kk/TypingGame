#include "head.h"

void removePlayer(int xpos, int ypos)
{
	gotoxy(xpos, ypos);
	printf("   ");
	gotoxy(xpos, ypos + 1);
	printf("    ");// ㄴㅣㄱ을 받기 위해서 4번 스페이스
	gotoxy(xpos, ypos + 2);
	printf("   "); // /ㄴ을 받기 위해서 3번 스페이스
}