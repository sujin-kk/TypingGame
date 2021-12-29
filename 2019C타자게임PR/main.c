#include "head.h"
#define LEFTWORDXPOS 49 //주어지는 왼쪽 단어의 x좌표
#define RIGHTWORDXPOS 74 //주어지는 오른쪽 단어의 X좌표
#define WORDYPOS 19 //주어지는 단어의 y좌표
#define BLOCKENDYPOS 13 //블럭이 가장 아래로 내려왔을 때의 y좌표
#define INITIALLIFE 3 //처음 목숨의 개수 
#define INITIALBLOCKAMOUNT 5 //떨어질 블럭의 총 개수
#define PLAYERMOVE 15 //플레이어가 한번에 이동하는 x좌표
#define PLAYERMIDDLEPOSX 69 //플레이어가 정중앙에 있을 때의 x좌표
#define PLAYERPOSY 13//플레이어의 y좌표

void gotoxy(int, int); //인풋으로 들어온 x,y 좌표로 커서를 이동시키는 함수
void interf();
void makeblock(int*, int*, int*);
void move(int*, int*, int);
void rand_letter(char**, int);
int loadPage(void); //UI 페이지 로드 함수
void displayWord(int, int, char*); //기존의 단어를 지우고 새로운 단어를 보여주는 함수
char* updateWord(char*, int); //인풋으로 들어온 단어의 중복을 피하여 새로운 단어를 만드는 함수

void displayPlayer(int, int); ////인풋으로 들어온 플레이어의 x좌표,y좌표로 플레이어를 화면 상에서 보여주는 함수
void removePlayer(int, int); //인풋으로 들어온 플레이어의 x좌표,y좌표로 플레이어를 화면 상에서 지우는 함수
void removeBlock(int, int, int); //인풋으로 블럭의 x,y 좌표, 레벨을 받아와서 블럭을 지우는 함수
char* findStage(int);//인풋 레벨에 해당하는 스테이지 이름의 문자열을 반환해주는 함수
void stageClear(void);
void gameClear(void);
void gameOver(void);
void cleanUpInput(char*); //사용자 입력으로 받은 문자열을 배열에서 지우고 공백을 출력하는 함수
void displayProgress(int, char*, int, int); //게임 진행 상황 정보를 출력(점수, 스테이지, 남은 블럭 개수, 목숨)


int main()
{
	int block_start;
	int left_letter_start, right_letter_start;
	int block_xposition, block_yposition;
	int player_xposition, player_yposition;//포인터
	int level;
	int i;
	int place = 0;
	char* left_letter = "A";
	char* right_letter = "A";
	char input[20] = { 0 };
	int life = INITIALLIFE, score = 0, left_block_amount = INITIALBLOCKAMOUNT, block_length;
	char* stage;
	player_xposition = PLAYERMIDDLEPOSX;
	player_yposition = PLAYERPOSY;

	srand(time(0));
	level = loadPage(); //1: 초급, 2: 중급, 3: 고급
	block_length = 15 * level;

	if (level == 0) //esc키로 인한 게임 종료
		return 0;

	stage = findStage(level);

	interf();
	displayPlayer(player_xposition, player_yposition);

	makeblock(&level, &block_xposition, &block_yposition);


	block_start = clock();
	left_letter_start = clock();
	right_letter_start = clock();

	left_letter = updateWord(right_letter, level);
	right_letter = updateWord(left_letter, level);

	displayWord(LEFTWORDXPOS, WORDYPOS, left_letter);
	displayWord(RIGHTWORDXPOS, WORDYPOS, right_letter);

	displayProgress(score, stage, left_block_amount, life);


	while (1)
	{
		if (block_yposition == BLOCKENDYPOS) //블럭이 가장 아래로 내려왔을 때
		{
			int isInContact = 0; //블럭과 플레이어가 닿았는지 확인하는 진리값 변수

			for (int block_loop = 0; block_loop < level; block_loop++) {
				if (player_xposition == block_xposition + block_loop * 15) //블럭과 캐릭터가 충돌했는지 확인
				{
					life--;
					displayProgress(score, stage, left_block_amount, life);
					removeBlock(block_xposition, block_yposition, level);
					makeblock(&level, &block_xposition, &block_yposition);

					move(&player_xposition, &player_yposition, 0);
					isInContact = 1;
					break;
				}
			}

			if (!isInContact) //블록과 캐릭터가 닿지 않았다면 실행
			{
				score++;
				displayProgress(score, stage, left_block_amount, life);
				isInContact = 0;
			}

			if (life == 0) {
				system("cls");
				gameOver();
				Sleep(3000);
				break;
			}





			//캐릭터랑 블럭이 닿지 않았을 때
			else { //새로운 위치로 블럭 이동
				removeBlock(block_xposition, block_yposition, level);
				makeblock(&level, &block_xposition, &block_yposition);


			}




			left_block_amount--;
			displayProgress(score, stage, left_block_amount, life);


			if (left_block_amount == 0)
			{
				system("cls");
				if (level != 3)
					stageClear();
				else
				{
					system("cls");
					gameClear();
					Sleep(3000);
					break;
				}
				Sleep(5000);

				//스테이지 클리어 출력

				level++;
				system("cls");
				interf();
				block_length += 15;

				makeblock(&level, &block_xposition, &block_yposition);



				block_start = clock();
				left_letter_start = clock();
				right_letter_start = clock();

				left_letter = updateWord(right_letter, level);
				right_letter = updateWord(left_letter, level);
				displayWord(RIGHTWORDXPOS, WORDYPOS, right_letter);
				displayWord(LEFTWORDXPOS, WORDYPOS, left_letter);
				left_block_amount = INITIALBLOCKAMOUNT;

				//캐릭터 위치 원상태로 초기화 후 움직이기
				place = 0;
				cleanUpInput(input);

				removePlayer(player_xposition, player_yposition);
				player_xposition = PLAYERMIDDLEPOSX;
				move(&player_xposition, &player_yposition, 0);


				stage = findStage(level);
				displayProgress(score, stage, left_block_amount, life);


				continue;
			}
		}

		if (_kbhit()) //키보드 입력 감지
		{
			char ch;

			gotoxy(62 + place, 21);
			ch = _getch();
			if (ch == 27)
			{
				system("cls");
				printf("게임 종료");
				break;
			}
			else if (strlen(input) >= 19) //널 문자를 제외한 길이이므로 19글자가 최대 입력 글자수  
			{
				place = 0;
				cleanUpInput(input);

			}
			else if (ch <= 'z' && ch >= 'a')
			{
				input[place] = ch;
				printf("%c", ch);
				(place)++;

			}
			else if (ch == 8) //백스페이스를 입력할 경우
			{
				if (place > 0)
				{
					gotoxy(62 + place - 1, 21);
					printf(" ");
					gotoxy(62 + place - 1, 21);
					(place)--;
					input[place] = 0; //널문자
				}
			}
			if (!strcmp(input, left_letter) && player_xposition > 39) { //단어를 올바르게 입력했다 && 왼쪽 벽에 닿지 않았다
				place = 0;
				move(&player_xposition, &player_yposition, -15);

				left_letter = updateWord(right_letter, level);
				displayWord(LEFTWORDXPOS, WORDYPOS, left_letter);


				gotoxy(62, 21);
				printf("                   ");
				left_letter_start = clock();
			}
			else if (!strcmp(input, right_letter) && player_xposition < 99) //단어를 올바르게 입력했다 && 오른쪽 벽에 닿지 않았다
			{
				place = 0;
				move(&player_xposition, &player_yposition, 15);

				right_letter = updateWord(left_letter, level);
				displayWord(RIGHTWORDXPOS, WORDYPOS, right_letter);

				gotoxy(62, 21);
				printf("                   ");
				right_letter_start = clock(); //오른쪽 단어 시간 재초기화
			}

			if (place == 0) //단어를 입력한 뒤에 배열 정리
			{
				for (i = 0; i < 20; i++)
				{
					input[i] = 0; //문자열의 끝을 확인가능
				}
			}
		}

		else if (clock() >= block_start + 500)
		{
			removeBlock(block_xposition, block_yposition, level);
			block_yposition++;
			gotoxy(block_xposition, block_yposition);
			for (i = 0; i < block_length; i++)
			{
				printf("*");
			}
			block_start = clock();
		}

		else if (clock() >= left_letter_start + 5000)
		{
			left_letter = updateWord(right_letter, level);
			displayWord(LEFTWORDXPOS, WORDYPOS, left_letter);
			left_letter_start = clock();
		}

		else if (clock() >= right_letter_start + 5000)
		{
			right_letter = updateWord(left_letter, level);
			displayWord(RIGHTWORDXPOS, WORDYPOS, right_letter);
			right_letter_start = clock();
		}
	}
}