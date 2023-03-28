#ifndef _CARD_H
#define _CARD_H
#include <string>
#include <set>
using namespace std;

enum availability{
	AVAILABLE,
	UNAVAILABLE
};

struct cardIndex{
	string* authors;
	string title;
	string publisher;
	string section;
	availability avb;
	float evaluation;
};

string menu();
int strCount(string path);
void del(int stringCount, cardIndex* cards);
int authorsCount(string path, int stringCount);
cardIndex* alloc(int stringCount, int authorsCount);
set <string> booksBySection(cardIndex* cards, int stringCount, int act);
void readFile(cardIndex* cards, string path, int stringCount, int authorsCount);
void selectBook(cardIndex* cards, set <string> section, int stringCount, int authorsCount);

#endif // !_CARD_H
