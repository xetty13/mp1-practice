#ifndef _HEADER_H
#define _HEADER_H
#include <string>
#include <cstring>
using namespace std;

struct Product
{
	string name;
	string unit;
	double price;
	int number;
};

struct Date
{
	int day;
	int month;
	int year;
};

int cntLines(const string filename);
void allocate_sklad(Product*& p, Date*& d, int size);
void fill_sklad(Product*& p, Date*& d, int size, const string filename);
void find_null(Product*& p, Date*& d, int size);
void free_sklad(Product*& p, Date*& d, int size);


#endif