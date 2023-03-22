#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;

Owner* read_inf(int& n)
{
	ifstream infile("1.txt");
	if (!infile)
	{
		throw "file not finde";
	}
	infile >> n;
	Owner* o = new Owner[n];
	for (int i = 0; i < n; i++)
	{
		infile >> o[i].surname >> o[i].name >> o[i].patronymic >> o[i].date >> o[i].carnum >> o[i].gibdd >> o[i].phnum >> o[i].tehpas;
	}
	infile.close();
	return o;
}

void print_inf(Owner* o, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << o[i].surname << " " << o[i].name << " " << o[i].patronymic << endl << o[i].date << endl << o[i].carnum << endl << o[i].gibdd << endl << o[i].phnum << endl << o[i].tehpas << endl << endl;
	}
}

void search_owner(Owner* o, int n)
{
	int flag = 0, g;
	while (flag == 0)
	{
		cout <<"input number of gibdd = ";
		cin >> g;
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			if (o[i].gibdd == g)
			{
				flag++;
				cout << o[i].surname << " " << o[i].name << " " << o[i].patronymic << endl << o[i].date << endl << o[i].carnum << endl << o[i].gibdd << endl << o[i].phnum << endl << o[i].tehpas << endl << endl;
			}
		}
		if (flag == 0)
		{
			cout <<"incorrect number of gibdd" << endl;
		}
	}
}