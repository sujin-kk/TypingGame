#include "head.h"
#define LEFTWORDXPOS 49 //�־����� ���� �ܾ��� x��ǥ
#define RIGHTWORDXPOS 74 //�־����� ������ �ܾ��� X��ǥ
#define WORDYPOS 19 //�־����� �ܾ��� y��ǥ
#define BLOCKENDYPOS 13 //���� ���� �Ʒ��� �������� ���� y��ǥ
#define INITIALLIFE 3 //ó�� ����� ���� 
#define INITIALBLOCKAMOUNT 5 //������ ���� �� ����
#define PLAYERMOVE 15 //�÷��̾ �ѹ��� �̵��ϴ� x��ǥ
#define PLAYERMIDDLEPOSX 69 //�÷��̾ ���߾ӿ� ���� ���� x��ǥ
#define PLAYERPOSY 13//�÷��̾��� y��ǥ

void gotoxy(int, int); //��ǲ���� ���� x,y ��ǥ�� Ŀ���� �̵���Ű�� �Լ�
void interf();
void makeblock(int*, int*, int*);
void move(int*, int*, int);
void rand_letter(char**, int);
int loadPage(void); //UI ������ �ε� �Լ�
void displayWord(int, int, char*); //������ �ܾ ����� ���ο� �ܾ �����ִ� �Լ�
char* updateWord(char*, int); //��ǲ���� ���� �ܾ��� �ߺ��� ���Ͽ� ���ο� �ܾ ����� �Լ�

void displayPlayer(int, int); ////��ǲ���� ���� �÷��̾��� x��ǥ,y��ǥ�� �÷��̾ ȭ�� �󿡼� �����ִ� �Լ�
void removePlayer(int, int); //��ǲ���� ���� �÷��̾��� x��ǥ,y��ǥ�� �÷��̾ ȭ�� �󿡼� ����� �Լ�
void removeBlock(int, int, int); //��ǲ���� ���� x,y ��ǥ, ������ �޾ƿͼ� ���� ����� �Լ�
char* findStage(int);//��ǲ ������ �ش��ϴ� �������� �̸��� ���ڿ��� ��ȯ���ִ� �Լ�
void stageClear(void);
void gameClear(void);
void gameOver(void);
void cleanUpInput(char*); //����� �Է����� ���� ���ڿ��� �迭���� ����� ������ ����ϴ� �Լ�
void displayProgress(int, char*, int, int); //���� ���� ��Ȳ ������ ���(����, ��������, ���� �� ����, ���)


int main()
{
	int block_start;
	int left_letter_start, right_letter_start;
	int block_xposition, block_yposition;
	int player_xposition, player_yposition;//������
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
	level = loadPage(); //1: �ʱ�, 2: �߱�, 3: ���
	block_length = 15 * level;

	if (level == 0) //escŰ�� ���� ���� ����
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
		if (block_yposition == BLOCKENDYPOS) //���� ���� �Ʒ��� �������� ��
		{
			int isInContact = 0; //���� �÷��̾ ��Ҵ��� Ȯ���ϴ� ������ ����

			for (int block_loop = 0; block_loop < level; block_loop++) {
				if (player_xposition == block_xposition + block_loop * 15) //���� ĳ���Ͱ� �浹�ߴ��� Ȯ��
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

			if (!isInContact) //��ϰ� ĳ���Ͱ� ���� �ʾҴٸ� ����
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





			//ĳ���Ͷ� ���� ���� �ʾ��� ��
			else { //���ο� ��ġ�� �� �̵�
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

				//�������� Ŭ���� ���

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

				//ĳ���� ��ġ �����·� �ʱ�ȭ �� �����̱�
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

		if (_kbhit()) //Ű���� �Է� ����
		{
			char ch;

			gotoxy(62 + place, 21);
			ch = _getch();
			if (ch == 27)
			{
				system("cls");
				printf("���� ����");
				break;
			}
			else if (strlen(input) >= 19) //�� ���ڸ� ������ �����̹Ƿ� 19���ڰ� �ִ� �Է� ���ڼ�  
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
			else if (ch == 8) //�齺���̽��� �Է��� ���
			{
				if (place > 0)
				{
					gotoxy(62 + place - 1, 21);
					printf(" ");
					gotoxy(62 + place - 1, 21);
					(place)--;
					input[place] = 0; //�ι���
				}
			}
			if (!strcmp(input, left_letter) && player_xposition > 39) { //�ܾ �ùٸ��� �Է��ߴ� && ���� ���� ���� �ʾҴ�
				place = 0;
				move(&player_xposition, &player_yposition, -15);

				left_letter = updateWord(right_letter, level);
				displayWord(LEFTWORDXPOS, WORDYPOS, left_letter);


				gotoxy(62, 21);
				printf("                   ");
				left_letter_start = clock();
			}
			else if (!strcmp(input, right_letter) && player_xposition < 99) //�ܾ �ùٸ��� �Է��ߴ� && ������ ���� ���� �ʾҴ�
			{
				place = 0;
				move(&player_xposition, &player_yposition, 15);

				right_letter = updateWord(left_letter, level);
				displayWord(RIGHTWORDXPOS, WORDYPOS, right_letter);

				gotoxy(62, 21);
				printf("                   ");
				right_letter_start = clock(); //������ �ܾ� �ð� ���ʱ�ȭ
			}

			if (place == 0) //�ܾ �Է��� �ڿ� �迭 ����
			{
				for (i = 0; i < 20; i++)
				{
					input[i] = 0; //���ڿ��� ���� Ȯ�ΰ���
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