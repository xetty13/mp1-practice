#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Header.h"
using namespace std;
void token_size(string const& str, const char delim, vector<string>& out) 
{
	stringstream ss(str);
	string s;
	while (getline(ss, s, delim))
	{
		out.push_back(s);
	}
}

Owner* read_inf(int& n)
{
	
	ifstream infile("1.txt");
	if (!infile)
	{
		throw "file not finde";
	}
	infile >> n;
	Owner* o = new Owner[n];
	string data;
	string* razdel = new string[3];
	for (int i = 0; i < n; i++)
	{
		infile >> o[i].surname >> o[i].name >> o[i].patronymic >> data >> o[i].carnum >> o[i].gibdd >> o[i].phnum >> o[i].tehpas;
		const char delim = '.';
		vector<string> out;
		token_size(data, delim, out);
		int j = 0;
		for (auto& data : out)
		{
			razdel[j++] = data;
		}
		try
		{
			int k = 0;
			o[i].date.day = stoi(razdel[k++]);
			o[i].date.month = stoi(razdel[k++]);
			o[i].date.year = stoi(razdel[k++]);
		}
		catch (invalid_argument e)
		{
			cout << "caught invalid argiment in date";
		}
	}
	infile.close();
	delete[] razdel;
	return o;
}

void print_inf(Owner* o, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << o[i].surname << " " << o[i].name << " " << o[i].patronymic << endl
			<< o[i].date.day << "." << o[i].date.month << "." << o[i].date.year << endl 
			<< o[i].carnum << endl << o[i].gibdd << endl 
			<< o[i].phnum << endl << o[i].tehpas << endl << endl;
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
				cout << o[i].surname << " " << o[i].name << " " << o[i].patronymic << endl
					<< o[i].date.day << "." << o[i].date.month << "." << o[i].date.year << endl
					<< o[i].carnum << endl << o[i].gibdd << endl
					<< o[i].phnum << endl << o[i].tehpas << endl << endl;
			}
		}
		if (flag == 0)
		{
			cout <<"incorrect number of gibdd" << endl;
		}
	}
}