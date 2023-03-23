#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "person.h"
using namespace std;


Person::Person()
{
	string surname = " ";
	string name = " ";
	string patronymic = " ";
	string gender = " ";
	string nation = " ";
	string date = " ";
	string height = " ";
	string weight = " ";
	string num_phone = " ";
	string postal_code = " ";
	string country = " ";
	string region = " ";
	string city = " ";
	string district = " ";
	string street = " ";
	string house = " ";
	string apartament = " ";
}

Person::Person(string surname, string name, string patronymic, string gender, string nation, string date, string height, string weight, string num_phone, string postal_code, string country, string region, string city, string district, string street, string house, string apartament)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
	this->gender = gender;
	this->nation = nation;
	this->date = date;
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

void read(Person*& p, int& n)
{
	string f;
	cout << "Enter filename or path: ";
	cin >> f;
	n = cntStruct(f);
	p = new Person[n];
	fill_data(p, n, f);
}

void fill_data(Person*& p, int n, string& f)
{
	fstream file;
	file.open(f);
	if (!file.is_open())
		throw "File open error";
	for (int i = 0; i < n; i++)
	{
		string str = "";
		int flag = 0;
		while ((getline(file, str, ';')) && (flag < 16))
		{
			if (flag == 0)
			{
				if (i != 0)
					removeFirstN(str, 1);
				p[i].surname = str;
			}
			if (flag == 1)
				p[i].name = str;
			if (flag == 2)
				p[i].patronymic = str;
			if (flag == 3)
				p[i].nation = str;
			if (flag == 4)
				p[i].gender = str;
			if (flag == 5)
				p[i].date = str;
			if (flag == 6)
				p[i].height = str;
			if (flag == 7)
				p[i].weight = str;
			if (flag == 8)
				p[i].num_phone = str;
			if (flag == 9)
				p[i].postal_code = str;
			if (flag == 10)
				p[i].ad.country = str;
			if (flag == 11)
				p[i].ad.region = str;
			if (flag == 12)
				p[i].ad.city = str;
			if (flag == 13)
				p[i].ad.district = str;
			if (flag == 14)
				p[i].ad.street = str;
			if (flag == 15)
				p[i].ad.house = str;
			flag++;
		}
		p[i].ad.apartament = str;
	}
	file.close();
}

ostream& operator<<(ostream& out, const Person& p)
{
	out << "FIO: " << p.surname << " " << p.name << " " << p.patronymic << endl;
	out << "Gender: " << p.gender << endl;
	out << "Nation: " << p.nation << endl;
	out << "Date: " << p.date << endl;
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

void Sort(Person*& p, int n)
{
	Person* tmp = new Person[1];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (p[j].surname != p[i].surname)
			{
				if (p[j].surname < p[i].surname)
				{
					*tmp = p[i];
					p[i] = p[j];
					p[j] = *tmp;
				}
			}
			else
			{
				if (p[j].name < p[i].name)
				{
					*tmp = p[i];
					p[i] = p[j];
					p[j] = *tmp;
				}
			}
		}

}

void removeFirstN(string& str, int n)
{
	str.erase(0, n);
}