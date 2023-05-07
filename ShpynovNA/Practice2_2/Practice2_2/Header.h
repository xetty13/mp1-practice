#ifndef _HEADER_H
#define _HEADER_H

using namespace std;

struct date {
	int day;
	int month;
	int year;

	void create_data(string str);
};

struct pasport {
	int series;
	int number;
	string auth;
	string reg;
	date issue;
	date birth;


	bool isElderly();
	void create_data(string* str);
};

struct employee {
	pasport pspt;
	string name;
	string edu;
	string spec;
	string unit;
	string appnt;
	date dateofappnt;
	date lastdate;

	void create_data(string str);


};

void createmem(int n, string filename, employee** g_empls);

void age_scan(int n, employee* g_empls);

string get_string(ifstream& file);

#endif //!_HEADER_H