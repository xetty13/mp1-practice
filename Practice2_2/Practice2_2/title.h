#include <iostream>
#include <fstream>
#include<string>
#include<string.h>
using namespace std;
#ifndef _TITLE_H
#define _TITLE_H

 struct Time{
	string hours;
	string minutes;
} ;
struct Opening_Hours {
	string Day;
	Time open;
	Time close;
};
typedef struct {
	string street;
	string postcode;
}Adress;
struct Shop {
	string name;
	string phone_number;
	string specialization;
	Opening_Hours* op;
	Adress adress;
	string form_of_ownership;
};
struct List {
	Shop* shop;
	int count;
};
int count_shops(const string adress);
List info(int& n, const string adress);
ostream& operator<<(ostream& os, const List& list);
istream& operator >>(istream& os, Shop& shop);
int our_quantity(Shop* shops, int records);
List correct_shop(Shop* shops, int length, int count);
void free_str(List* list, int length);
#endif
