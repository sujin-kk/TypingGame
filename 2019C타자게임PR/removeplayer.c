#include "head.h"

void removePlayer(int xpos, int ypos)
{
	gotoxy(xpos, ypos);
	printf("   ");
	gotoxy(xpos, ypos + 1);
	printf("    ");// ���Ӥ��� �ޱ� ���ؼ� 4�� �����̽�
	gotoxy(xpos, ypos + 2);
	printf("   "); // /���� �ޱ� ���ؼ� 3�� �����̽�
}