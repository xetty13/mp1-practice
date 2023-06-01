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

class Person
{
public:
	Person();
	string getName() const;
	string getSurname() const;
	friend ostream& operator<<(ostream& out, const Person& p);
	Person(const string& surname, const string& name, const string& middle_name, gender gender,
		const string& nation, const date& birth_date, float height, float weight,
		long long phone_number, const address& address_);
private:
	string Surname;
	string Name;
	string Middle_name;
	gender Gender;
	string Nation;
	date date_;
	float Height;
	float Weight;
	long long phone_number;
	address address_;
};

class PersonsList
{
public:
	PersonsList(const string& path);
	~PersonsList();
	void surname_sort();
	int getCount() const;
	Person* getPersons() const;	
	friend ostream& operator<<(ostream& out, const PersonsList& pl);
private:
	int person_count(const string& path) const;

	Person* persons;
	int count;
};

string getPath();
void menu(const PersonsList& ps);
#endif // !_PERSON_H
