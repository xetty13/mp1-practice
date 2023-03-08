#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "workers.h";
#define N 100

int main() {
	worker* w;
	char* buffer;
	char* fileStr;
	int charCount = counter();
	int stringCount = amount( );
	int answer;
	buffer = readFile(charCount);
	allocate(&w, stringCount);
	adding(w, buffer);
	do {
		printf("MENU:\n");
		printf("1.The entire database of employees\n");
		printf("2.All employees with higher education\n");
		printf("3.Exit\n");
		printf("Enter your choice:");
		scanf("%d", &answer);
		switch (answer) {
		case 1: database ()  ; break;
		case 2: higher_education(w, stringCount);  break;
		case 3: {memory_free (&w, stringCount); return 0; }
		}
		} while (answer != 3);
	}

