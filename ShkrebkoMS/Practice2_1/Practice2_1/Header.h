#ifndef _BOOK_H
#define _BOOK_H

#include <stdbool.h>




typedef struct
{
	int Couaut;
	char** Author;
	char Name[100];
	char Publishing[100];
	char Section[100];
	bool Availability;
	int Score;
}TBook;

void setAuthors(char* strTmp, TBook* book);

void read(FILE** file, TBook* book);
void print_book(TBook* book, int count);

void print_section(TBook* book, int count, char* word);
void free_mas(TBook* book, int count);
#endif _BOOK_H
