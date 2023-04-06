#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include "workers.h";
#define N 100

string GetFilePath() {
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

int amount(string& path)
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

void adding(worker* w, string& path, int n) {
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
				w[j].contact_info = s;
				i = -1;
				j++;
				break;
			}
			i++;
		}
	}
	in.close();
}

void higher_education(worker* w, int count) {
	float counter = 0;
	int i;
	cout << "All employees with higher education from the database:" << endl;
	for (i = 0; i < count; i++) {
		if (w[i].education != "no") {
			cout << w[i];
			counter++;
		}
	}
	cout << "Percentage of employees with higher education:" << (counter / count) * 100 << " % " << endl;
}

ostream& operator<<(ostream& out, const worker& w)
{
	out << "-----------------------" << endl;
	out << "ID: " << w.id << endl;
	out << "Profession: " << w.profession << endl;
	out << "Education: " << w.education << endl;
	out << "Last Job: " << w.last_job << endl;
	out << "Reason of dismiss: " << w.rsn_dismiss << endl;
	out << "Family status: " << w.rsn_dismiss << endl;
	out << "Contact information: " << w.contact_info << endl;
	out << "-----------------------" << endl;
	return out;
}

