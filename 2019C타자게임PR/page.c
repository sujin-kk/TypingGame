#include "head.h"

#define MIDDLEX 40 //�ܼ�â ��� x��ǥ
#define MIDDLEY 12 //�ܼ�â ��� y��ǥ


void loadMainPage(void);
void showString(char*, int);
void loadLevelPage(void);
void loadGameGuide(void);
void gotoxy(int, int);

char* backspace = "(Press backspace to go back)";

int loadPage(void) {
	char selection; //���� ���������� ����� �Է�
	int isMainPageOn = 0, isLevelPageOn = 0, isGameGuideOn = 0, level = 0; //���� ����������, ��������������, ���ӹ���������� ȭ�鿡 ��Ÿ������ �ǹ��ϴ� ������/���� �ʱ޸��, �߱޸��, ��޸�尡 ����Ǿ����� �ǹ��ϴ� ������
	loadMainPage();
	isMainPageOn = 1;
	do {
		if (_kbhit() == 1) { //Ű���� �Է� ����

			selection = _getch();

			if (selection == 27) {
				break;
			}
			else if (isMainPageOn) {
				/*
				 selection �Է°�:
				 '1' => ���� ����
				 '2' => ���� ���
				 '3' => ���� ����
				 27 => esc�� �ƽ�Ű �ڵ�
				 */
				if (selection == '1') { //���� ���� ��ư�� ���� ���
					isMainPageOn = 0;
					isLevelPageOn = 1;
					system("cls");
					loadLevelPage();
				}
				else if (selection == '2') { //���� ��� ��ư�� ���� ���
					isMainPageOn = 0;
					isGameGuideOn = 1;
					system("cls");
					loadGameGuide();
				}
				else if (selection == '3') { //���� Ű�� ���� ���
					level = 0; //���� ����
					break;
				}
			}
			else if (isLevelPageOn) {
				/*
				selection �Է°�:
				'1' => �ʱ�
				'2' => �߱�
				'3' => ���
				 8  => �齺���̽��� �ƽ�Ű �ڵ�
				 */
				if (selection == '1') {
					isLevelPageOn = 0;
					level = 1; //�ʱ�
					system("cls");
					break;
				}
				else if (selection == '2') {
					isLevelPageOn = 0;
					level = 2; //�߱�
					system("cls");
					break;
				}
				else if (selection == '3') {
					isLevelPageOn = 0;
					level = 3; //���
					system("cls");
					break;
				}
				else if (selection == 8) {
					isLevelPageOn = 0;
					isMainPageOn = 1;
					system("cls");
					loadMainPage();
				}
			}
			else if (isGameGuideOn) {
				if (selection == 8) { //backspace
					isGameGuideOn = 0;
					isMainPageOn = 1;
					system("cls");
					loadMainPage();
				}
			}
		}
	} while (1);

	system("cls");

	return level;
}



void loadMainPage(void) {  //���������� �ε�
	int textPositionY = MIDDLEY;//�ؽ�Ʈ�� y��ǥ
	char* textMainPage[4] = { "1. Game start","2. How to play", "3. Exit", "Press number on keyboard" };
	//!! issue 1: ���ڿ��� �ѱ��� ��� ������ ���̸� ����� ���� ���Ѵ�. => strlen �Լ��� ������� ���Ͽ� �ڵ��� ���̰� �þ �� �ִ�.
	//test case: printf("%d", strMiddle);

	textPositionY -= 2;
	showString(textMainPage[0], textPositionY);

	textPositionY += 2;
	showString(textMainPage[1], textPositionY);

	textPositionY += 2;
	showString(textMainPage[2], textPositionY);

	textPositionY += 2;
	showString(textMainPage[3], textPositionY);
}

void loadLevelPage(void) { //�������������� �ε�
	int textPositionY = MIDDLEY; //���ڿ� Y��ǥ
	char* textLevelPage[] = { "Choose a level", "1. Beginner", "2. Intermediate", "3. Advanced" };

	textPositionY -= 2;
	showString(textLevelPage[0], textPositionY);

	textPositionY += 2;
	showString(textLevelPage[1], textPositionY);

	textPositionY += 2;
	showString(textLevelPage[2], textPositionY);

	textPositionY += 2;
	showString(textLevelPage[3], textPositionY);

	textPositionY += 2;
	showString(backspace, textPositionY);
}

void loadGameGuide(void) { //���Ӽ��������� �ε�
	char* guideLines[3] = { "������ ���� �������ϴ�.",
		"���� �ܾ �Է��ϸ� ��������, ������ �ܾ �Է��ϸ� ���������� �̵��մϴ�.",
		"ĳ���͸� ������ ��ֹ��� ���ϼ���!" }; //���� ��� ���ڿ�
	char textPositionY = MIDDLEY; //���ڿ� Y��ǥ
	int count; //���κ� ���ڿ� ��� ����

	textPositionY -= 2;
	for (count = 0; count < 3; count++) {
		showString(guideLines[count], textPositionY);
		textPositionY += 1;
	}

	textPositionY += 6;
	showString(backspace, textPositionY);
}

void showString(char string[], int positionY) { //�������� ���� ���ڿ��� ���η� ����� ���� ���
	int strMiddle = strlen(string) / 2;
	int positionX = MIDDLEX - strMiddle;
	gotoxy(positionX, positionY);
	puts(string);
}
