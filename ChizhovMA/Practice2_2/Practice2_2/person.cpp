#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "person.h"
using namespace std;


void read(Person*& p, int& n)
{
	fstream file;
	char* f = new char[100];
	cout << "Enter filename or path: ";
	cin >> f;
	file.open(f);
	if (!file.is_open())
		throw "File open error";

	n = cntStruct(file);
	p = new Person[n];
	fill_data(p, n, f);
}

void fill_data(Person*& p, int n, char*& f)
{
	fstream file;
	file.open(f);
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

void Person::Print()
{
	cout << "FIO: " << surname << " " << name << " " << patronymic << endl;
	cout << "Gender: " << gender << endl;
	cout << "Nation: " << nation << endl;
	cout << "Date: " << date << endl;
	cout << "Height: " << height << endl;
	cout << "Weight: " << weight << endl;
	cout << "Phone number: " << num_phone << endl;
	cout << "Postal code: " << postal_code << endl;
	cout << "Country: " << ad.country << endl;
	cout << "Region: " << ad.region << endl;
	cout << "Address: city: " << ad.city << ", ";
	cout << ad.district << " district, ";
	cout << ad.street << " street, ";
	cout << "house number: " << ad.house;
	cout << ", apartament: " << ad.apartament << endl;
	cout << "<===========================================>" << endl;
}


int cntStruct(fstream& f)
{
	char* str = new char[1024];
	int i = 0;
	//ifstream f(file);
	while (!f.eof())
	{
		f.getline(str, 1024, '\n');
		i++;
	}
	delete[]str;
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