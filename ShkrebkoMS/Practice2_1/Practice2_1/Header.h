#ifndef _BOOK_H
#define _BOOK_H

typedef struct
{
	char Author[100];
	char Name[100];
	char Publishing[100];
	char Section[100];
	char Availability[100];
	char Score[100];


}TBook;
int read(FILE** file);
void print_book(TBook* book, int count);

void print_section(TBook* book, int count);
void print_section(TBook* book, int count, char* word);
#endif _BOOK_H
