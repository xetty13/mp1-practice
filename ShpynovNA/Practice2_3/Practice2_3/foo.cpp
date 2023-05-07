#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>

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
void employee::output() {
	cout << this->name << " - ";
	this->pspt.output();
	cout << endl;
}
bool employee::isElderly() {
	return this->pspt.isElderly();
}

void pasport::create_data(string * str) {
	this->series = atoi(str[1].c_str());
	this->number = atoi(str[2].c_str());
	this->auth = str[3];
	this->reg = str[6];
	this->issue.create_data(str[4]);
	this->birth.create_data(str[5]);
}
bool pasport::isElderly() {
	int d, m, y;
	this->birth.give_data(&d, &m, &y);
	if ((y < 58) ||
		((y == 58) && ((m < 4) ||
			((m == 4) && (d < 27)))))
		return true;
	else return false;
}
void pasport::output() {
	int d, m, y;
	this->birth.give_data(&d, &m, &y);
	cout << d << "." << m << ".19" << y;
}

void date::give_data(int* day_dest, int* month_dest, int* year_dest) {
	*day_dest = this->day;
	*month_dest = this->month;
	*year_dest = this->year;
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
	for (int i = 0; i < n; i++) {
		g_empls[i].output();

	}
	cout << endl;
	cout << "elderly ones:" << endl;
	for (int i = 0; i < n; i++)
		if (g_empls[i].isElderly()) {
			g_empls[i].output();
		}
}