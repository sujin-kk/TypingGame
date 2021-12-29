#include "head.h"

void rand_letter(char**, int);

char* updateWord(char* present_word, int level) {
	char* new_word;
	do
	{
		rand_letter(&new_word, level);
	} while (!strcmp(present_word, new_word));
	return new_word;
}
