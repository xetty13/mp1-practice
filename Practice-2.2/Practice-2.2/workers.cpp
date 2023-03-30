#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include "workers.h";
#define N 100

string get_Path() {
	string path;
	do {
		cout << "Enter the file path:";
		cin >> path;
		ifstream in(path);
		if (!in.is_open()) {
			cout << "Ooops.....Something went wrong......\n";
		}
		else {
			in.close();
			return path;
		}
	} while (true);
	}

int amount(string path) {
	int count{ 0 };
	string line;
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

void adding(worker* w, string path, int n) {
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
	printf("All employees with higher education from the database:\n");
	for (i = 0; i < count; i++) {
		if (strcmp(w[i].education, "no") != 0) {
			printf("%-5s %20s\n", w[i].id, w[i].education);
			counter++;
		}
	}
	printf("Percentage of employees with higher education:%.3f%%\n ", (counter / count) * 100);
	system("pause");
	system("cls");
}

