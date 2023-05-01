#ifndef _HEADER_H
#define _HEADER_H

using namespace std;

typedef struct dates_t {
	int day;
	int month;
	int year;
} date;

typedef struct employees_t {
	enum field {
		e_name,
		e_edu,
		e_spec,
		e_unit,
		e_appnt,
		e_dateofappnt,
		e_lastdate,
	};

	string name;
	string edu;
	string spec;
	string unit;
	string appnt;
	date dateofappnt;
	date lastdate;

	void create_data(ifstream& file, employees_t::field field, int n);


} employee;

typedef struct pasports_t {
	enum field {
		e_series,
		e_number,
		e_auth,
		e_issue,
		e_birth,
		e_reg,
	};
	int series;
	int number;
	string auth;
	string reg;
	date issue;
	date birth;


	bool isElderly();
	void create_data(ifstream& file, pasports_t::field field, int n);
}pasport;

void* get_target(void* base, int size, int index);

void set_data(void* base, int size, int index, char* value);

void set_data(void* base, int size, int index, int value);

void read_str(ifstream& file, int n, void* target, size_t struct_size);

void read_int(ifstream& file, int n, void* target, size_t struct_size);

void createmem(int n, char* filename, employee** g_empls, pasport** g_pspts);

void age_scan(int n, employee* g_empls, pasport* g_pspts);

#endif //!_HEADER_H