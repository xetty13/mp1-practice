
#ifndef _HEADER_H
#define _HEADER_H
#include <string>
#include <cstring>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Product
{
	string name;
	string unit;
	double price;
	int number;
	Date data;

};


int cntLines(const string& filename);
void allocate_sklad(Product*& p, int size);
void fill_sklad(Product*& p, int size, const string &filename);
void find_null(Product*& p, int size);
void free_sklad(Product*& p, int size);


#endif