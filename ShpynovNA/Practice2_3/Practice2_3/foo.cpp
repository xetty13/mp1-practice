#include <iostream>
#include "Header.h"
#include <string>
#include <fstream>

void employee::create_data(ifstream& file, employee::field field, int n)
{
	string* str = new string[n];
	for (int i = 0; i < n; i++)
		getline(file, str[i], ';');
	switch (field) {
	case employee::field::e_name:
		for (int i = 0; i < n; i++)
			this[i].name = str[i];
		break;
	case employee::field::e_edu:
		for (int i = 0; i < n; i++)
			this[i].edu = str[i];
		break;
	case employee::field::e_spec:
		for (int i = 0; i < n; i++)
			this[i].spec = str[i];
		break;
	case employee::field::e_unit:
		for (int i = 0; i < n; i++)
			this[i].unit = str[i];
		break;
	case employee::field::e_appnt:
		for (int i = 0; i < n; i++)
			this[i].appnt = str[i];
		break;
	case employee::field::e_dateofappnt:
		for (int i = 0; i < n; i++) {
			char tmp[12];
			strncpy(tmp, str[i].c_str(), 11);
			char day[2] = { tmp[0], tmp[1] };
			char month[2] = { tmp[3], tmp[4] };
			char year[2] = { tmp[8], tmp[9] };
			this[i].dateofappnt.day = atoi(day);
			this[i].dateofappnt.month = atoi(month);
			this[i].dateofappnt.year = atoi(year);
		}
		break;
	case employee::field::e_lastdate:
		for (int i = 0; i < n; i++) {
			char tmp[12];
			strncpy(tmp, str[i].c_str(), 11);
			char day[2] = { tmp[0], tmp[1] };
			char month[2] = { tmp[3], tmp[4] };
			char year[2] = { tmp[8], tmp[9] };
			this[i].lastdate.day = atoi(day);
			this[i].lastdate.month = atoi(month);
			this[i].lastdate.year = atoi(year);
		}
		break;
	};
	delete[] str;
}
void employee::output() {
	cout << this->name;
}

void pasport::create_data(ifstream& file, pasport::field field, int n) {
	string* str = new string[n];
	for (int i = 0; i < n; i++)
		getline(file, str[i], ';');
	switch (field) {
	case pasport::field::e_series:
		for (int i = 0; i < n; i++)
			this[i].series = atoi(str[i].c_str());
		break;
	case pasport::field::e_number:
		for (int i = 0; i < n; i++)
			this[i].number = atoi(str[i].c_str());
		break;
	case pasport::field::e_auth:
		for (int i = 0; i < n; i++)
			this[i].auth = str[i];
		break;
	case pasport::field::e_issue:
		for (int i = 0; i < n; i++) {
			char tmp[12];
			strncpy(tmp, str[i].c_str(), 12);
			char day[2] = { tmp[0], tmp[1] };
			char month[2] = { tmp[3], tmp[4] };
			char year[2] = { tmp[8], tmp[9] };
			this[i].issue.day = atoi(day);
			this[i].issue.month = atoi(month);
			this[i].issue.year = atoi(year);
		}
		break;
	case pasport::field::e_birth:
		for (int i = 0; i < n; i++) {
			char tmp[12];
			strncpy(tmp, str[i].c_str(), 12);
			char day[2] = { tmp[0], tmp[1] };
			char month[2] = { tmp[3], tmp[4] };
			char year[2] = { tmp[8], tmp[9] };
			this[i].birth.day = atoi(day);
			this[i].birth.month = atoi(month);
			this[i].birth.year = atoi(year);
		}
		break;
	case pasport::field::e_reg:
		for (int i = 0; i < n; i++)
			this[i].reg = str[i];
		break;
	};
	delete[] str;
}
bool pasport::isElderly() {
	if ((this->birth.year < 58) ||
		((this->birth.year == 58) && ((this->birth.month < 4) ||
			((this->birth.month == 4) && (this->birth.day < 27)))))
		return true;
	else return false;
}
void pasport::output() {
	cout << this->birth.day << "." << this->birth.month << ".19" << this->birth.year;
}

void createmem(int n, char* filename, employee** g_empls, pasport** g_pspts)
{
	ifstream file(filename);
	if (!file.is_open())
		exit(ENFILE);
	(*g_empls)->create_data(file, employee::field::e_name, n);
	(*g_pspts)->create_data(file, pasport::field::e_series, n);
	(*g_pspts)->create_data(file, pasport::field::e_number, n);
	(*g_pspts)->create_data(file, pasport::field::e_auth, n);
	(*g_pspts)->create_data(file, pasport::field::e_issue, n);
	(*g_pspts)->create_data(file, pasport::field::e_birth, n);
	(*g_pspts)->create_data(file, pasport::field::e_reg, n);
	(*g_empls)->create_data(file, employee::field::e_edu, n);
	(*g_empls)->create_data(file, employee::field::e_spec, n);
	(*g_empls)->create_data(file, employee::field::e_unit, n);
	(*g_empls)->create_data(file, employee::field::e_appnt, n);
	(*g_empls)->create_data(file, employee::field::e_dateofappnt, n);
	(*g_empls)->create_data(file, employee::field::e_lastdate, n);
	file.close();
}
void age_scan(int n, employee* g_empls, pasport* g_pspts) {
	cout << "all employees:" << endl;
	for (int i = 0; i < n; i++) {
		g_empls[i].output();
		cout << " - ";
		g_pspts[i].output();
		cout << endl;
	}
	cout << endl;
	cout << "elderly ones:" << endl;
	for (int i = 0; i < n; i++)
		if (g_pspts[i].isElderly()) {
			g_empls[i].output();
			cout << " - ";
			g_pspts[i].output();
			cout << endl;
		}
}