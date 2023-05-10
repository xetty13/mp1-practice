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
int count_shops(const string adress);
Shop* info(int& n, const string adress);
ostream& operator<<(ostream& os, const Shop& shop);
int our_quantity(Shop* shops, int records);
Shop* correct_shop(Shop* shops, int length, int count);
void free_str(Shop* shop, int length);
#endif
