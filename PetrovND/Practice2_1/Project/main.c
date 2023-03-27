#include "card.h"

int main() {
	int sectionCount;
	char** section;
	char* path = menu();
	int stringCount = strCount(path);
	int act = authorsCount(path, stringCount);
	cardIndex* cards = alloc(stringCount, act);

	readFile(cards, path, stringCount, act);
	section = booksBySection(cards, stringCount, act, &sectionCount);
	selectBook(cards, section, stringCount, act, sectionCount);

	memoryFree(cards, stringCount, section, act, sectionCount, path);
	return 0;
}
//C:\\Users\\nikit\\Desktop\\12.txt