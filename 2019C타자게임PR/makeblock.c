#include "head.h"

void makeblock(int* level, int* block_xposition, int* block_yposition)
{
	int block_length = 15 * (*level); //��������� ���� ����
	*block_yposition = 3; //���� ��ǥ
	int i;

	*block_xposition = 39 + rand() % (6 - (*level)) * 15;
	/*
		level ������ �Ҵ�Ǵ� ��:
		1: �ʱ�
		2: �߱�
		3: ���
	*/

	gotoxy(*block_xposition, *block_yposition);
	for (i = 0; i < block_length; i++)
	{
		printf("*");
	}
}