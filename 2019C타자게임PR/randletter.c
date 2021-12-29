#include "head.h"
#define WORDSCOUNT 40

/*
�߰������� �ʿ��� �Լ��� �Է°�: ����, �߰�, ����� ��带 �������� �� �ִ� ���ڰ� �ʿ��ϴ�.
ex)����/�߰�/����� ���� 1,2,3 ����
tip: GUI���� ����,�߰�,����� ��带 �Է¹��� �� ���� 1, 2, 3�� ���ڿ��� �Է��ϹǷ� �̸� ���ڷ� �޾ƿ´ٰ� �����ϰ� ���ǹ��� �ۼ��Ͽ���.
*/

void rand_letter(char** letter, int level) //���� �ڵ�: char* letter[20] �׷��� �������� ���ڿ��� letter�� ������ �ʿ䰡 ���⿡ �迭�� ����� �ʿ䰡 ����.
{
	srand(time(0)); //�ܾ� �������� �����ÿ� �ʿ��� �Լ�

	char* random = "";
	char* wordList[3][WORDSCOUNT] = {
	{ "air", "able", "about", "above", "act", "add", "all", "any", "area", "arm", "bar", "base", "best", "bed", "box", "boy", "bill", "bring", "call", "can", "come", "city", "day", "cost", "cut", "dark", "deep", "die", "dog", "eat", "easy", "ever", "fail", "fast", "few", "feel", "fact", "fire", "full", "food" },
	{ "accept", "alone", "always", "among", "attack", "allply", "argue", "around", "arrive", "another", "become", "begin", "between", "beyond", "camera", "blood", "cancer", "capital", "black", "better", "child", "color", "crime", "court", "detail", "design", "dinner", "drive", "during", "dream", "degree", "entire", "event", "expert", "family", "father", "forward", "future", "figure", "friend" },
	{ "according", "agreement", "administration", "approach", "audience", "authority", "beautiful", "because", "between", "behavior", "believe", "business", "candidate", "building", "challenge", "character", "economic", "collection", "commercial", "community", "condition", "conference", "daughter", "customer", "democratic", "determine", "development", "discussion", "direction", "education", "employee", "enough", "environment", "especially", "establish", "everything", "financial", "government", "generation", "international" }
	};
	int randIndex = rand() % WORDSCOUNT;

	if (level == 1)
		random = wordList[0][randIndex];
	else if (level == 2)
		random = wordList[1][randIndex];
	else
		random = wordList[2][randIndex];

	*letter = random; //strcpy(letter, random); ��ſ� �ۼ�, ���������̹Ƿ� a = random�� �Ȱ��� �ǹ��̴�.
}
