#include <string>
#ifndef _BOOK_H
#define _BOOK_H

using namespace std;

typedef struct
{
	int Couaut;
	string* Author;
	string Name;
	string Publishing;
	string Section;
	bool Availability;
	int Score;
}TBook;

int count_books(string& str);


TBook* read(string str, TBook* book, int count);

int count_unic(TBook* book, int count);
string* create_section(TBook* book, int unic, int count);

void print_book(TBook* book, int count);

void print_section(TBook* book, int count, string word);
void print_choose_book(TBook* lib, int count, int unic, string* unic_section);


void free_mas(TBook* book, int count);

#endif _BOOK_H
