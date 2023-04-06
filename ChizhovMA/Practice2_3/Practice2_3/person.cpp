#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "person.h"
using namespace std;


Person::Person()
{
	surname = " ";
	name = " ";
	patronymic = " ";
	gender = " ";
	nation = " ";
	date.day = 0;
	date.month = 0;
	date.year = 0;
	height = " ";
	weight = " ";
	num_phone = " ";
	postal_code = " ";
	ad.country = " ";
	ad.region = " ";
	ad.city = " ";
	ad.district = " ";
	ad.street = " ";
	ad.house = " ";
	ad.apartament = " ";
}

Person::Person(string surname, string name, string patronymic, string gender,
	string nation, int day, int month, int year, string height,
	string weight, string num_phone, string postal_code, string country,
	string region, string city, string district, string street,
	string house, string apartament)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
	this->gender = gender;
	this->nation = nation;
	this->date.day = day;
	this->date.month = month;
	this->date.year = year;
	this->height = height;
	this->weight = weight;
	this->num_phone = num_phone;
	this->ad.country = country;
	this->ad.region = region;
	this->ad.city = city;
	this->ad.district = district;
	this->ad.street = street;
	this->ad.house = house;
	this->ad.apartament = apartament;
}

void Person::set_info(const string& p_surname, const string& p_name, const string& p_patronymic,
	const string& p_gender, const string& p_nation, const int& p_day, const int& p_month,
	const int& p_year, const string& p_height, const string& p_weight,
	const string& p_num_phone, const string& p_postal_code, const string& p_country,
	const string& p_region, const string& p_city, const string& p_district,
	const string& p_street, const string& p_house, const string& p_apartament)
{
	surname = p_surname;
	name = p_name;
	patronymic = p_patronymic;
	gender = p_gender;
	nation = p_nation;
	date.day = p_day;
	date.month = p_month;
	date.year = p_year;
	height = p_height;
	weight = p_weight;
	num_phone = p_num_phone;
	postal_code = p_postal_code;
	ad.country = p_country;
	ad.region = p_region;
	ad.city = p_city;
	ad.district = p_district;
	ad.street = p_street;
	ad.house = p_house;
	ad.apartament = p_apartament;
}

void read(Person** p, int n, string& f)
{

	fstream file;
	file.open(f);
	if (!file.is_open())
		throw "File open error";
	string surname, name, patronymic, nation, gender, height, weight,
		num_phone, postal_code, country, region, city,
		district, street, house, apartament;
	int day, month, year;
	for (int i = 0; i < n; i++)
	{
		string str = "";
		int flag = 0;
		while ((getline(file, str, ';')) && (flag < 18))
		{
			if (flag == 0)
			{
				if (i != 0)
					removeFirstN(str, 1);
				surname = str;
			}
			if (flag == 1)
				name = str;
			if (flag == 2)
				patronymic = str;
			if (flag == 3)
				gender = str;
			if (flag == 4)
				nation = str;
			if (flag == 5)
				day = stoi(str);
			if (flag == 6)
				month = stoi(str);
			if (flag == 7)
				year = stoi(str);
			if (flag == 8)
				height = str;
			if (flag == 9)
				weight = str;
			if (flag == 10)
				num_phone = str;
			if (flag == 11)
				postal_code = str;
			if (flag == 12)
				country = str;
			if (flag == 13)
				region = str;
			if (flag == 14)
				city = str;
			if (flag == 15)
				district = str;
			if (flag == 16)
				street = str;
			if (flag == 17)
				house = str;
			flag++;
		}
		apartament = str;

		p[i] = new Person();
		p[i]->set_info(surname, name, patronymic, gender, nation, day, month, year,
			height, weight, num_phone, postal_code, country, region, city, district,
			street, house, apartament);
	}
	file.close();
}

ostream& operator<<(ostream& out, const Person& p)
{
	out << "FIO: " << p.surname << " " << p.name << " " << p.patronymic << endl;
	out << "Gender: " << p.gender << endl;
	out << "Nation: " << p.nation << endl;
	out << "Date: " << p.date.day << "." << p.date.month << "." << p.date.year << endl;
	out << "Height: " << p.height << endl;
	out << "Weight: " << p.weight << endl;
	out << "Phone number: " << p.num_phone << endl;
	out << "Postal code: " << p.postal_code << endl;
	out << "Country: " << p.ad.country << endl;
	out << "Region: " << p.ad.region << endl;
	out << "Address: city: " << p.ad.city << ", ";
	out << p.ad.district << " district, ";
	out << p.ad.street << " street, ";
	out << "house number: " << p.ad.house;
	out << ", apartament: " << p.ad.apartament << endl;
	out << "<===========================================>" << endl;
	return out;
}



int cntStruct(string& f)
{
	fstream file;
	file.open(f);
	char* str = new char[1024];
	int i = 0;
	if (!file.is_open())
		throw "File open error";
	while (!file.eof())
	{
		file.getline(str, 1024, '\n');
		i++;
	}
	delete[]str;
	file.close();
	return i;
}

void Sort(Person** p, int n)
{
	Person* tmp;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (p[j]->get_surname() != p[i]->get_surname())
			{
				if (p[j]->get_surname() < p[i]->get_surname())
				{
					tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
			}
			else
			{
				if (p[j]->get_name() < p[i]->get_name())
				{
					tmp = p[i];
					p[i] = p[j];
					p[j] = tmp;
				}
			}
		}

}

void removeFirstN(string& str, int n)
{
	str.erase(0, n);
}