#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "workers.h";
#define N 100

string get_path() {
	string path;
	do {
		cout << "Enter the file path:";
		cin >> path;
		ifstream in(path);
		if (!in.is_open()) {
			cout << "Ooops.....Something went wrong......" << endl;
		}
		else {
			in.close();
			return path;
		}
	} while (true);
}

worker::worker() {
	id=" ";
	profession = " ";
	 education = " ";
	last_job = " ";
	 rsn_dismiss = " ";
	 family_status = " ";
	contact_info = 0;
}

worker::worker(const string  id, const string  profession, const string  education, const string  last_job, const string  rsn_dismiss, const string  family_status, int  contact_info) {
	this->id = id;
	this->profession = profession;
	this->education = education;
	this->last_job = last_job;
	this->rsn_dismiss = rsn_dismiss;
	this->family_status = family_status;
	this->contact_info = contact_info;
}

int labor::amount(const string& path)
{
	fstream file;
	file.open(path);
	string line;
	int count{ 0 };
	ifstream in(path);
	while (getline(in, line))
	{
		if (line != "\0") {
			count++;
		}
	}
	in.close();
	return count;
}

labor::labor(const string& path) {
	this->n = amount(path);
	this->w = new worker[n];
	fstream file;
	file.open(path);
	int i = 0, j = 0;
	string line, s;
	ifstream in(path);
	while (getline(in, line))
	{
		if (line == "\0") {
			continue;
		}
		stringstream ss(line);
		while (getline(ss, s, ';')) {
			switch (i) {
			case 0:
				w[j].id = s;
				break;
			case 1:
				w[j].profession = s;
				break;
			case 2:
				w[j].education = s;
				break;
			case 3:
				w[j].last_job = s;
				break;
			case 4:
				w[j].rsn_dismiss = s;
				break;
			case 5:
				w[j].family_status = s;
				break;
			case 6:
				w[j].contact_info = stoi(s);
				i = -1;
				j++;
				break;
			}
			i++;
		}
	}
	in.close();
}

void labor::higher_education(const string& path) {
	float counter = 0;
	int i;
	cout << "All employees with higher education from the database:" << endl;
	for (i = 0; i < n; i++) {
		if (w[i].education != "no") {
			cout << w[i];
			counter++;
		}
	}
	cout << "Percentage of employees with higher education:" << (counter / n) * 100 << " % " << endl;
}

labor::~labor() {
	delete[] this->w;
}

ostream& operator<<(ostream& out, const worker& w)
{
	out << w.id << " " << w.education << endl;
	return out;
}
