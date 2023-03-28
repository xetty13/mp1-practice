#include "card.h"

int main() {
	set <string> sections;
	string path = menu();
	int stringCount = strCount(path);
	int act = authorsCount(path, stringCount);
	cardIndex* cards = alloc(stringCount, act);

	readFile(cards, path, stringCount, act);
	sections = booksBySection(cards, stringCount, act);
	selectBook(cards, sections, stringCount, act);

	del(stringCount, cards);
	return 0;
}