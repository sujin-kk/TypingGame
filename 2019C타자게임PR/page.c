#include "head.h"

#define MIDDLEX 40 //콘솔창 가운데 x좌표
#define MIDDLEY 12 //콘솔창 가운데 y좌표


void loadMainPage(void);
void showString(char*, int);
void loadLevelPage(void);
void loadGameGuide(void);
void gotoxy(int, int);

char* backspace = "(Press backspace to go back)";

int loadPage(void) {
	char selection; //메인 페이지에서 사용자 입력
	int isMainPageOn = 0, isLevelPageOn = 0, isGameGuideOn = 0, level = 0; //각각 메인페이지, 레벨선택페이지, 게임방법페이지가 화면에 나타났는지 의미하는 진리값/각각 초급모드, 중급모드, 고급모드가 실행되었는지 의미하는 진리값
	loadMainPage();
	isMainPageOn = 1;
	do {
		if (_kbhit() == 1) { //키보드 입력 감지

			selection = _getch();

			if (selection == 27) {
				break;
			}
			else if (isMainPageOn) {
				/*
				 selection 입력값:
				 '1' => 게임 시작
				 '2' => 게임 방법
				 '3' => 게임 종료
				 27 => esc의 아스키 코드
				 */
				if (selection == '1') { //게임 시작 버튼을 누를 경우
					isMainPageOn = 0;
					isLevelPageOn = 1;
					system("cls");
					loadLevelPage();
				}
				else if (selection == '2') { //게임 방법 버튼을 누를 경우
					isMainPageOn = 0;
					isGameGuideOn = 1;
					system("cls");
					loadGameGuide();
				}
				else if (selection == '3') { //종료 키를 누를 경우
					level = 0; //게임 종료
					break;
				}
			}
			else if (isLevelPageOn) {
				/*
				selection 입력값:
				'1' => 초급
				'2' => 중급
				'3' => 고급
				 8  => 백스페이스의 아스키 코드
				 */
				if (selection == '1') {
					isLevelPageOn = 0;
					level = 1; //초급
					system("cls");
					break;
				}
				else if (selection == '2') {
					isLevelPageOn = 0;
					level = 2; //중급
					system("cls");
					break;
				}
				else if (selection == '3') {
					isLevelPageOn = 0;
					level = 3; //고급
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



void loadMainPage(void) {  //메인페이지 로드
	int textPositionY = MIDDLEY;//텍스트의 y좌표
	char* textMainPage[4] = { "1. Game start","2. How to play", "3. Exit", "Press number on keyboard" };
	//!! issue 1: 문자열이 한글일 경우 문자의 길이를 제대로 세지 못한다. => strlen 함수를 사용하지 못하여 코드의 길이가 늘어날 수 있다.
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

void loadLevelPage(void) { //레벨선택페이지 로드
	int textPositionY = MIDDLEY; //문자열 Y좌표
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

void loadGameGuide(void) { //게임선택페이지 로드
	char* guideLines[3] = { "위에서 블럭이 떨어집니다.",
		"왼쪽 단어를 입력하면 왼쪽으로, 오른쪽 단어를 입력하면 오른쪽으로 이동합니다.",
		"캐릭터를 움직여 장애물을 피하세요!" }; //게임 방법 문자열
	char textPositionY = MIDDLEY; //문자열 Y좌표
	int count; //라인별 문자열 출력 개수

	textPositionY -= 2;
	for (count = 0; count < 3; count++) {
		showString(guideLines[count], textPositionY);
		textPositionY += 1;
	}

	textPositionY += 6;
	showString(backspace, textPositionY);
}

void showString(char string[], int positionY) { //페이지에 들어가는 문자열이 가로로 가운데에 오게 출력
	int strMiddle = strlen(string) / 2;
	int positionX = MIDDLEX - strMiddle;
	gotoxy(positionX, positionY);
	puts(string);
}
