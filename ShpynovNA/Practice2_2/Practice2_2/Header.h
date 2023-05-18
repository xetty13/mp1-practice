#ifndef _HEADER_H
#define _HEADER_H

using namespace std;

struct date {
	int day;
	int month;
	int year;

	void create_data(string str);
	const date& operator= (const date& e);
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
	const pasport& operator= (const pasport& e);
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
	const employee& operator= (const employee& e);
};

struct lib {
	int emp_amount;
	employee* empls;

	lib(int n);
	lib(const lib& l);
	~lib();

	employee& operator[](int ind);
	friend ostream& operator<<(ostream& out, const lib& l) {
		for (int i = 0; i < l.emp_amount; i++)
			out << l.empls[i].name << " - " << l.empls[i].pspt.birth.day << "." << l.empls[i].pspt.birth.month << ".19" << l.empls[i].pspt.birth.year << endl;
		return out;
	}

	lib output();
	void createmem(string str);
};

string get_string(ifstream& file);

#endif //!_HEADER_H