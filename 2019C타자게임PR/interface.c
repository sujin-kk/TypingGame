#include "head.h"

void gotoxy(int, int);

void interf()
{

	int i;

	gotoxy(6, 2);//214 => 220
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	gotoxy(6, 3);
	for (i = 0; i < 20; i++)
	{
		gotoxy(6, 3 + i);
		printf("弛");
	}
	gotoxy(111, 3);
	for (i = 0; i < 20; i++)
	{
		gotoxy(117, 3 + i); //111 -> 117
		printf("弛");
	}
	gotoxy(6, 23);//214 => 220
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	gotoxy(12, 3);
	printf("L I F E : \n\n");
	gotoxy(12, 5);
	printf("S C O R E :\n\n");
	gotoxy(12, 7);
	printf("S T A G E :\n\n");
	gotoxy(12, 9);
	printf("B L O C K :\n");

	gotoxy(12, 22);
	printf("部頂晦 Esc");

	gotoxy(33, 3);
	for (i = 0; i < 20; i++)
	{
		gotoxy(33, 3 + i);
		printf("弛");
	}

	for (i = 0; i < 5; i++) {
		gotoxy(37 + 15 * i, 16);
		printf("忙式式式式式忖\n");
		gotoxy(37 + 15 * i, 17);
		printf("戌式式式式式戎");
	}

	gotoxy(64, 18);
	printf("Ｂ式式\n");

	gotoxy(48, 20);
	printf("式式式式式式式式式式式式式式式式式式式式");

	gotoxy(73, 18);
	printf("式式Ｃ\n");

	gotoxy(73, 20);
	printf("式式式式式式式式式式式式式式式式式式式式");

	gotoxy(61, 22);
	printf("式式式式式式式式式式式式式式式式式式式式");
}