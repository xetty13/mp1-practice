#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "workers.h";

int main() {
	worker* w;
	char* buffer;
	char* fileStr;
	int charCount = counter();
	int stringCount = amount();
	buffer = readFile(charCount);
	allocate(&w, stringCount);
	adding(w, buffer);
	higher_education(w, stringCount);
}
