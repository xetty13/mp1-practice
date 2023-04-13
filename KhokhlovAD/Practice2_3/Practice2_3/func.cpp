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
	for (int i = 0; i < n; i++)
	{
		infile >> o[i];
	}
	infile.close();
	return o;
}

void print_inf(Owner* o, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << o[i];
	}
}

Owner* search_owner(Owner* o, int& n, int& k)
{
	Owner* o1 = new Owner[n];
	int flag = 0, g;
	while (flag == 0)
	{
		cout << "input number of gibdd = ";
		cin >> g;
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			if (o[i].getGibdd() == g)
			{
				o1[flag] = o[i];
				flag++;
			}
		}
		if (flag == 0)
		{
			cout << "incorrect number of gibdd" << endl;
		}
	}
	k = flag;
	return o1;
}



istream& operator>>(istream& in, Owner& o)
{
	string day;
	in >> o.surname >> o.name >> o.patronymic >> day >> o.carnum >> o.gibdd >> o.phnum >> o.tehpas;
	const char delim = '.';
	string* razdel = new string[3];
	vector<string> out;
	token_size(day, delim, out);
	int j = 0;
	for (auto& data : out)
	{
		razdel[j++] = data;
	}
	try
	{
		int k = 0;
		o.setData(stoi(razdel[k]), stoi(razdel[k + 1]), stoi(razdel[k + 2]));
	}
	catch (const invalid_argument& e)
	{
		cout << "caught invalid argiment in date" << e.what();
	}
	delete[] razdel;
	return in;
}

ostream&  operator<<(ostream& out, const Owner& o)
{
	out << o.surname << " " << o.name << " " << o.patronymic << endl
		<< o.date.getDay() << "." << o.date.getMonth() << "." << o.date.getYear() << endl
		<< o.carnum << endl << o.gibdd << endl
		<< o.phnum << endl << o.tehpas << endl << endl;
	return out;
}