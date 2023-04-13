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

class Product
{
private:

	string name;
	string unit;
	double price;
	int number;
	Date data;

public:
	Product(void);
	Product(string name, string unit, double price, int number,int day,int month,int year);
//	friend void fill_sklad(Product*& p, int size, const string filename);
	friend ostream& operator <<(ostream& stream,const Product& p);
	friend void find_NULL(Product*& p, int size);
	void SetRes( string _name, string _unit, double _price, int _number, int _day, int _month, int _year);
};

void fill_sklad(Product*& p, int size, const string filename);
int cntLines(const string filename);
void allocate_stock(Product*& p, int size);



void free_stock(Product*& p);

//int cntLines(const string filename);
//void fill_sklad(Product*& p, Date*& d, int size, const string filename);
//void find_null(Product*& p, Date*& d, int size);



#endif