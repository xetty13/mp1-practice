#ifndef _PERSON_H
#define _PERSON_H
#include <string>
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
class Person
{
private:
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
public:

	Person();
	Person(string surname, string name, string patronymic, string gender, string nation, string date, string height, string weight, string num_phone, string postal_code, string country, string region, string city, string district, string street, string house, string apartament);
	friend ostream& operator<<(ostream& out, const Person& p);
	friend void read(Person*& p, int& n);
	friend void fill_data(Person*& p, int n, string& f);
	friend void Sort(Person*& p, int n);
};

int cntStruct(string& f);
void removeFirstN(string& str, int n);
#endif // !_PERSON_H
