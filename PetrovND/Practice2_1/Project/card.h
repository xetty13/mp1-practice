#ifndef _CARD_H
#define _CARD_H
#define LENGTH 128

typedef enum availability{
	AVAILABLE,
	UNAVAILABLE
};

typedef struct {
	char** authors;
	char title[LENGTH];
	char publisher[LENGTH];
	char section[LENGTH];
	enum availability avb;
	float evaluation;
} cardIndex;

cardIndex* alloc(int stringCount, int authorsCount);
void memoryFree(cardIndex* card, int stringCount, char** section, int authorsCount);
int strCount(char* path);
void readFile(cardIndex* cards, char* path, int stringCount, int authorsCount);
char** booksBySection(cardIndex* cards, int stringCount, int authorsCount);
void selectBook(cardIndex* card, char** section, int stringCount, int authorsCount);
int authorsCount(char* path, int stringCount);
#endif // !_CARD_H