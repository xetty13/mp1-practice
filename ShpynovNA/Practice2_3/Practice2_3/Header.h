#ifndef _HEADER_H
#define _HEADER_H

using namespace std;

class date {
private:
	int day;
	int month;
	int year;
public:
	void create_data(string str);
	void give_data(int* day_dest, int* month_dest, int* year_dest);
};

class pasport {
private:
	int series;
	int number;
	string auth;
	string reg;
	date issue;
	date birth;

public:
	bool isElderly();
	void create_data(string* str);
	void output();
};


class employee {
private:
	pasport pspt;
	string name;
	string edu;
	string spec;
	string unit;
	string appnt;
	date dateofappnt;
	date lastdate;
public:
	void create_data(string str);
	void output();
	bool isElderly();
};

void createmem(int n, string filename, employee** g_empls);

void age_scan(int n, employee* g_empls);

string get_string(ifstream& file);
#endif //!_HEADER_H

