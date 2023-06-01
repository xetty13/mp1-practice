#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <windows.h>
#include "Header.h"

using namespace std;

int TSchool::counting(const string& filename) {
	ifstream file(filename);
	int n = 0;
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			n++;
		}
	}
	else {
		cout << "Не удалось открыть файл" << endl;
	}
	file.close();
	return n;
}

TSchool::TSchool(const string& filename) {
	this->n = counting(filename);
	this->student = new TStudent[n];
	ifstream file(filename);
	int i, j = 0;
	string line, str;
	if (file.is_open()) {
		while (getline(file, line)) {
			istringstream iss(line);
			i = 0;
			while (getline(iss, str, ';')) {
				switch (i) {
				case 0:
					student[j].FIO = str;
					break;
				case 1:
					student[j].Class = stoi(str);
					break;
				case 2:
					student[j].Gender = str;
					break;
				case 3:
					student[j].Date = str;
					break;
				case 4:
					student[j].Address = str;
					break;
				}
				i++;
			}
			j++;
		}
	}
	else {
		cout << "Не удалось открыть файл" << endl;
	}
	file.close();
}

ostream& operator<<(ostream& out, const TStudent& student)
{
	out << student.FIO << "    " << student.Class << "    " << student.Gender << "    " << student.Date << "    " << student.Address << endl;
	return out;
}

ostream& operator<<(ostream& out, const TSchool& school) {
	cout << "ФИО" << "                          " << 
		    "Класс" << "       " << "Пол" << "        " << 
		    "Дата рождения" << "       " << 
		    "Домашний адрес\n" << endl;
	for (int i = 0; i < school.n; i++) {
		out << school.student[i];
	}
	return out;
}


void TSchool::sorting() {
	int i = 0, j, k = 1;
	TStudent tmp;
	for (; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (student[i].Class > student[j].Class) {
				tmp = student[i];
				student[i] = student[j];
				student[j] = tmp;
			}
		}
	}
	i = 0;
	while (i < n) {
		while (student[i].Class == k) {
			j = i + 1;
			while (student[j].Class == k) {
				if (student[i].FIO > student[j].FIO) {
					tmp = student[i];
					student[i] = student[j];
					student[j] = tmp;
				}
				j++;
			}
			i++;
		}
		k++;
	}
}

TSchool::~TSchool() {
	delete[] this->student;
}