#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>

using namespace std;

string get_string(ifstream& file) {
	string tmp;
	getline(file, tmp);
	return tmp;
}

void employee::create_data(string str)
{
	string Stmp[14];
	string delim = ";";
	size_t last = 0;
	size_t next;
	int i = 0;
	while ((next = str.find(delim, last)) != string::npos) {
		Stmp[i] = str.substr(last, next - last);
		i++;
		last = next + delim.length();
	}
	Stmp[12] = str.substr(last);
	this->pspt.create_data(Stmp);
	this->name = Stmp[0];
	this->edu = Stmp[7];
	this->spec = Stmp[8];
	this->unit = Stmp[9];
	this->appnt = Stmp[10];
	this->dateofappnt.create_data(Stmp[11]);
	this->lastdate.create_data(Stmp[12]);
}

void pasport::create_data(string* str) {
	this->series = atoi(str[1].c_str());
	this->number = atoi(str[2].c_str());
	this->auth = str[3];
	this->reg = str[6];
	this->issue.create_data(str[4]);
	this->birth.create_data(str[5]);
}
bool pasport::isElderly() {
	if ((birth.year < 58) ||
		((birth.year == 58) && ((birth.month < 4) ||
			((birth.month == 4) && (birth.day < 27)))))
		return true;
	else return false;
}

void date::create_data(string str) {
	string tmp;
	tmp = str.substr(0, 2);
	this->day = atoi(tmp.c_str());
	tmp = str.substr(3, 2);
	this->month = atoi(tmp.c_str());
	tmp = str.substr(8, 2);
	this->year = atoi(tmp.c_str());
}

void createmem(int n, string filename, employee** g_empls)
{
	ifstream file(filename);
	for (int i = 0; i < n; i++) 
		(*g_empls)[i].create_data(get_string(file));
	file.close();
}

void age_scan(int n, employee* g_empls) {
	cout << "all employees:" << endl;
	for (int i = 0; i < n; i++)
		cout << g_empls[i].name << " - " << g_empls[i].pspt.birth.day << "."
		<< g_empls[i].pspt.birth.month << ".19"
		<< g_empls[i].pspt.birth.year << endl;
	cout << endl << "elderly ones:" << endl;
	for (int i = 0; i < n; i++)
		if (g_empls[i].pspt.isElderly())
			cout << g_empls[i].name << " - " << g_empls[i].pspt.birth.day << "."
			<< g_empls[i].pspt.birth.month << ".19"
			<< g_empls[i].pspt.birth.year << endl;
}

