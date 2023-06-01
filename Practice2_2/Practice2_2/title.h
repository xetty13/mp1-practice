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
	Time();
} ;
struct Opening_Hours {
	string Day;
	Time open;
	Time close;
	Opening_Hours();
	Opening_Hours& operator=(const Opening_Hours& other);
};
 struct Adress{
	string street;
	string postcode;
	Adress& operator=(const Adress& other);
};
struct Shop {
	string name;
	string phone_number;
	string specialization;
	Opening_Hours* op;
	Adress adress;
	string form_of_ownership;
	Shop();
	Shop& operator=(const Shop& other);
	friend istream& operator >>(istream& os, Shop& shop);
};
struct List {
	friend ostream& operator<<(ostream& os, const List& list);
	Shop* shop;
	int count;
	List(string adress);
	List();
	~List();
	List& correct_base(List& first);
	List& operator=(const List& other);
};

ostream& operator<<(ostream& os, const List& list);
istream& operator >>(istream& os, Shop& shop);


#endif
