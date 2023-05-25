#ifndef _PERSON_H
#define _PERSON_H
#include <string>
using namespace std;

enum gender
{
	male,
	female
};

struct address
{
	int postal_code;
	string Country;
	string Region;
	string City;
	string Area;
	string Street;
	int House;
	int Apart;
};

struct date
{
	int day;
	int mounth;
	int year;
};

struct person
{
	string Surname;
	string Name;
	string Middle_name;
	gender Gender;
	string Nation;
	date date;
	float Height;
	float Weight;
	long long phone_number;
	address address;
	friend ostream& operator<<(ostream& out, const person& p);
};

struct persons_list
{
	person* persons;
	int count;
	persons_list(const string& path);
	~persons_list();
	int person_count(const string& path);
	void surname_sort();
	friend ostream& operator<<(ostream& out, const persons_list& pl);
};

string getPath();
void menu(const persons_list& ps);

#endif // !_PERSON_H
#pragma once
