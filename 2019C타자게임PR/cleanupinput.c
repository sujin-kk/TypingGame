#include "head.h"

void cleanUpInput(char* input_p)
{
	for (int i = 0; i < 20; i++) //���ڿ� ����
	{
		input_p[i] = 0; //���ڿ��� ���� Ȯ�ΰ���
	}

	gotoxy(62, 21);
	printf("                   ");
}