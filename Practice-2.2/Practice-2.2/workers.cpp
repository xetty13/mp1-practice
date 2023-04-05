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
		cout << "Enter the file path..." << endl;
		cin >> path;
		ifstream in(path);
		if (!in.is_open()) {
			cout << "ERROR: Could not open file!\n";
		}
		else {
			in.close();
			return path;
		}
	} while (true);
}


int amount(string& f)
{
	fstream file;
	file.open(f);
	char* str = new char[1024];
	int count = 0;
	if (!file.is_open())
		throw "File open error";
	while (!file.eof())
	{
		file.getline(str, 1024, '\n');
		count++;
	}
	delete[]str;
	file.close();
	return count;
}

void adding(worker* w, string& path, int n) {
	int i = 0, j = 0;
	string line, s;
	ifstream in(path);
	string* buff = new string[n];
	while (getline(in, line))
	{
		if (line == "\0") {
			continue;
		}
		stringstream ss(line);
		while (getline(ss, s, ';')) {
			switch (i) {
			case 0:
				buff[j] = s;
				break;
			case 1:
				w[j].id = s;
				break;
			case 2:
				w[j].profession = s;
				break;
			case 3:
				w[j].education = s;
				break;
			case 4:
				w[j].last_job = s;
			case 5:
				w[j].rsn_dismiss = s;
			case 6:
				w[j].family_status = s;
			case 7:
				w[j].contact_info = stof(s);
				i = -1;
				j++;
				break;
			}
			i++;
		}
	}
	in.close();
	delete[] buff;
}

void higher_education(worker* w, int count) {
	float counter = 0;
	int i;
	cout << "All employees with higher education from the database:\n"<<endl;
	for (i = 0; i < count; i++) {
		if (w[i].education=="no") {
			printf("%-5s %20s\n", w[i].id, w[i].education);
			counter++;
		}
	}
	printf("Percentage of employees with higher education:%.3f%%\n ", (counter / count) * 100);
	system("pause");
	system("cls");
}

ostream& operator<<(ostream& out, const worker& w)
{
	out << "ID: " << w.id << endl;
	out << "Profession: " << w.profession << endl;
	out << "Education: " << w.education << endl;
	out << "Last Job: " << w.last_job << endl;
	out << "Reason of dismiss: " << w.rsn_dismiss << endl;
	out << "Family status: " << w.rsn_dismiss << endl;
	out << "Contact information: " << w.contact_info << endl;
	return out;
}




