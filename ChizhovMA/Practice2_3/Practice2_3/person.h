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

struct Date
{
	int day;
	int month;
	int year;
};
class Person
{
private:
	string surname;
	string name;
	string patronymic;
	string gender;
	string nation;
	Date date;
	string height;
	string weight;
	string num_phone;
	string postal_code;
	Address ad;
public:

	Person();
	Person(string surname, string name, string patronymic, string gender,
		string nation, int day, int month, int year, string height,
		string weight, string num_phone, string postal_code, string country,
		string region, string city, string district, string street,
		string house, string apartament);
	void set_info(const string& p_surname, const string& p_name, const string& p_patronymic,
		const string& p_gender, const string& p_nation, const int& p_day,
		const int& p_month, const int& p_year, const string& p_height,
		const string& p_weight, const string& p_num_phone, const string& p_postal_code,
		const string& p_country, const string& p_region, const string& p_city,
		const string& p_district, const string& p_street, const string& p_house,
		const string& p_apartament);
	string get_surname()
	{
		return surname;
	}
	string get_name()
	{
		return name;
	}
	friend ostream& operator<<(ostream& out, const Person& p);
};

void read(Person** p, int n, string& f);
void Sort(Person** p, int n);
int cntStruct(string& f);
void removeFirstN(string& str, int n);
#endif // !_PERSON_H
