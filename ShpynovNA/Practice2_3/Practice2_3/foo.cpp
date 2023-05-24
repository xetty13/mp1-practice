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

lib::lib(int n) {
	emp_amount = n;
	empls = new employee[emp_amount];
}
lib::lib(const lib& l) {
	emp_amount = l.emp_amount;
	empls = new employee[emp_amount];
	for (int i = 0; i < emp_amount; i++) {
		this->empls[i] = l.empls[i];
	}
}
lib::lib(const string& filename) {
	string* strtmp = new string[50];
	ifstream file(filename);
	int n = 0;
	while ((strtmp[n] = get_string(file)) != "")
		n++;
	emp_amount = n;
	empls = new employee[emp_amount];
	for (int i = 0; i < emp_amount; i++)
		empls[i].create_data(strtmp[i]);
	file.close();
	delete[] strtmp;
}
lib::~lib() {
	delete[] this->empls;
}
employee& lib::operator[](int ind) {
	return empls[ind];
}
lib lib::output() {
	int n = 0;
	for (int i = 0; i < this->emp_amount; i++)
		if (this->empls[i].givepasport().isElderly())
			n++;
	lib new_lib(n);
	int k = 0;
	for (int i = 0; i < this->emp_amount; i++)
		if (this->empls[i].givepasport().isElderly()) {
			new_lib[k] = this->empls[i];
			k++;
		}
	return new_lib;
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
const employee& employee::operator=(const employee& e) {
	pspt = e.pspt;
	name = e.name;
	edu = e.edu;
	spec = e.spec;
	unit = e.unit;
	appnt = e.appnt;
	dateofappnt = e.dateofappnt;
	lastdate = e.lastdate;
	return *this;
}
string employee::givename() {
	return name;
}
pasport employee::givepasport() {
	return pspt;
}

const pasport& pasport::operator=(const pasport& p) {

	series = p.series;
	number = p.number;
	auth = p.auth;
	reg = p.reg;
	issue = p.issue;
	birth = p.birth;
	return *this;
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
	int a, b, c;
	this->birth.givedata(&a, &b, &c);
	if ((c < 58) ||
		((c == 58) && ((b< 4) ||
			((b == 4) && (a < 27)))))
		return true;
	else return false;
}
string pasport::givedate() {
	int a, b, c;
	string tmp = "";
	this->birth.givedata(&a, &b, &c);
	tmp.append(to_string(a));
	tmp.append(".");
	tmp.append(to_string(b));
	tmp.append(".19");
	tmp.append(to_string(c));
	return tmp;
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
void date::givedata(int* a, int* b, int* c) {
	*a = day;
	*b = month;
	*c = year;
}
const date& date::operator=(const date& d) {
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}


