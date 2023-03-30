#ifndef _HEADER_H
#define _HEADER_H
#include <string>
#include <cstring>
using namespace std;

class Date;
class Product
{
private:

	string name;
	string unit;
	double price;
	int number;

public:
	Product(void);
	Product(string name, string unit, double price, int number);
//	friend void fill_sklad(Product*& p, int size, const string filename);
	friend void fill_sklad(Product*& p, int size, Date*& d, const string filename);
	friend ostream& operator <<(ostream& stream,const Product& prod);
	friend void find_NULL(Product*& p, int size,Date*&d);
	
};

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(void);
	Date(int day, int month, int year);
//	friend void fill_sklad( Date*& d, int size, const string filename);
	friend void fill_sklad(Product*& p, int size, Date*& d, const string filename);
	friend ostream& operator <<(ostream& stream, const Date& prod);
	friend void find_NULL(Product*& p, int size, Date*& d);
};

int cntLines(const string filename);
void allocate_stock(Product*& p, Date*& d, int size);



void free_stock(Product*& p, Date*& d);

//int cntLines(const string filename);
//void fill_sklad(Product*& p, Date*& d, int size, const string filename);
//void find_null(Product*& p, Date*& d, int size);



#endif