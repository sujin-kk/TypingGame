#include "head.h"

char* findStage(int level)
{
	if (level == 1)
		return "Beginner";
	else if (level == 2)
		return "Intermediate";
	else
		return "Advanced";
}