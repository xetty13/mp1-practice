#include <string>
#ifndef _BOOK_H
#define _BOOK_H

using namespace std;

struct TBook
{
	int Couaut;
	string* Author;
	string Name;
	string Publishing;
	string Section;
	bool Availability;
	int Score;

	TBook();
	~TBook();
	TBook& operator=(const TBook&);
};
struct TLib
{
	TBook* books;
	int count;
	int CountUnic;
	string* unic_section;


	TLib();
	TLib(const string& path);
	TLib(const TLib& lib);
	TLib& operator=(const TLib&);
	

	~TLib();

	int count_books(const string& path) const;
	int count_unic() const;
	void create_section();
	void print_unique_sections();
	TLib search_by_section(const string& section_name);
};

string get_path();
ostream& operator << (ostream& out, TBook& book);
ostream& operator << (ostream& out, TLib& lib);

#endif _BOOK_H

