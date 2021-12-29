#include "head.h"
#define WORDSCOUNT 40

/*
추가적으로 필요한 함수의 입력값: 쉬움, 중간, 어려움 모드를 구별해줄 수 있는 인자가 필요하다.
ex)쉬움/중간/어려움 각각 1,2,3 전달
tip: GUI에서 쉬움,중간,어려움 모드를 입력받을 때 각각 1, 2, 3을 문자열로 입력하므로 이를 인자로 받아온다고 가정하고 조건문을 작성하였다.
*/

void rand_letter(char** letter, int level) //원래 코드: char* letter[20] 그러나 여러개의 문자열을 letter에 저장할 필요가 없기에 배열로 사용할 필요가 없다.
{
	srand(time(0)); //단어 랜덤으로 생성시에 필요한 함수

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

	*letter = random; //strcpy(letter, random); 대신에 작성, 간접참조이므로 a = random과 똑같은 의미이다.
}
