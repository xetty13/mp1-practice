#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Header.h"
using namespace std;
int n;
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
	string path;
	cout << "enter path" << endl;
	cin >> path;
	ifstream infile(path);
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
		infile >> o[i];
		const char delim = '.';
		vector<string> out;
		data = o[i].date.day;
		token_size(data, delim, out);
		int j = 0;
		for (auto& data : out)
		{
			razdel[j++] = data;
		}
		int k = 0;
		o[i].date.day = razdel[k++];
		o[i].date.month = razdel[k++];
		o[i].date.year = razdel[k++];
		
	}
	infile.close();
	delete[] razdel;
	return o;
}

void print_inf(Owner* o, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << o[i];
	}
}

Owner* search_owner(Owner* o, int& n)
{
	Owner* o1 = new Owner[n];
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
				o1[flag] = o[i];
				flag++;
			}
		}
		if (flag == 0)
		{
			cout <<"incorrect number of gibdd" << endl;
		}
	}
	n = flag;
	return o1;
}

istream&::operator>>(istream& in, Owner& o)
{
	in >> o.surname >> o.name >> o.patronymic >> o.date.day >> o.carnum >> o.gibdd >> o.phnum >> o.tehpas;
	return in;
}

ostream& :: operator<<(ostream& out, const Owner& o)
{
	out << o.surname << " " << o.name << " " << o.patronymic << endl
		<< o.date.day << "." << o.date.month << "." << o.date.year << endl
		<< o.carnum << endl << o.gibdd << endl
		<< o.phnum << endl << o.tehpas << endl << endl;
	return out;
}