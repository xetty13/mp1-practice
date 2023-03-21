#include <string>
#ifndef _PERSON_H
#define _PERSON_H
using namespace std;

struct Address
{
	string country;
	string region;
	string city;
	string district;
	string street;
	string house;
	string apartament;
};
struct Person
{
	string surname;
	string name;
	string patronymic;
	string gender;
	string nation;
	string date;
	string height;
	string weight;
	string num_phone;
	string postal_code;
	Address ad;
	void Print();
};
void read(Person*& p, int& n);
int cntStruct(fstream& f);
void fill_data(Person*& p, int n, char*& f);
void Sort(Person*& p, int n);
void removeFirstN(string& str, int n);
#endif // !_PERSON_H

