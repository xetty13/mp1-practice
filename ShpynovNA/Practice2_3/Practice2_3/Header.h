#ifndef _HEADER_H
#define _HEADER_H

using namespace std;

typedef class dates_t {
public:
	int day;
	int month;
	int year;
} date;

typedef class employees_t {
private:
	string name;
	string edu;
	string spec;
	string unit;
	string appnt;
	dates_t dateofappnt;
	dates_t lastdate;
public:
	enum field {
		e_name,
		e_edu,
		e_spec,
		e_unit,
		e_appnt,
		e_dateofappnt,
		e_lastdate,
	};
	void create_data(ifstream& file, employees_t::field field, int n);
	void output();
} employee;

typedef class pasports_t {
private:
	int series;
	int number;
	string auth;
	string reg;
	dates_t issue;
	dates_t birth;

public:
	enum field {
		e_series,
		e_number,
		e_auth,
		e_issue,
		e_birth,
		e_reg,
	};
	bool isElderly();
	void create_data(ifstream& file, pasports_t::field field, int n);
	void output();
} pasport;

void createmem(int n, char* filename, employees_t** g_empls, pasports_t** g_pspts);

void age_scan(int n, employees_t* g_empls, pasports_t* g_pspts);


#endif //!_HEADER_H

