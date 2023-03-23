#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"

int main() {
	char** section;
	char* path = "C:\\Users\\nikit\\Desktop\\lib.txt";
	int stringCount = strCount(path);
	int act = authorsCount(path, stringCount);
	cardIndex* cards = alloc(stringCount, act);

	readFile(cards, path, stringCount, act);
	section = booksBySection(cards, stringCount, act);
	selectBook(cards, section, stringCount, act);

	memoryFree(cards, stringCount, section, act);
	return 0;
}
