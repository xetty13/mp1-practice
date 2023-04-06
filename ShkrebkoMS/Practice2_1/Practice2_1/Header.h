#ifndef _BOOK_H
#define _BOOK_H

#include <stdbool.h>
#define LONGLINE 255

#define LONTAUTHORNAME 255
#define LINE 100

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
int count_books(char* str);

void setAuthors(char* strTmp, TBook* book);
int count_unic(TBook* book, int count);
void read(char* str, TBook* book);
void print_book(TBook* book, int count);
char** create_section(TBook* book, int unic, int count);
void print_section(TBook* book, int count, char* word);
void print_choose_book(TBook* lib, int count, int unic, char** unic_section);
void free_unic(char** unic_section, int unic);
void free_mas(TBook* book, int count);
#endif _BOOK_H
