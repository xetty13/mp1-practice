#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

struct Dates_t {
	int day;
	int month;
	int year;
};

struct EmployeesInfo_t {
	char* name;
	char* edu;
	char* spec;
	char* unit;
	char* appnt;
	struct Dates_t dateofappnt;
	struct Dates_t lastdate;
};

struct Pasports_t{
	int series;
	int number;
	char* auth;
	char* issue;
	struct Dates_t birth;
	struct Dates_t reg;
};

void* get_target(void* base, int size, int index);

void set_data_char(void* base, int size, int index, char* value);

void set_data_int(void* base, int size, int index, int value);

void read_str(FILE* file, int n, void* target, size_t struct_size);

void read_int(FILE* file, int n, void* target, size_t struct_size);

void scanstring(char** tmpstr, FILE* file);

void set_data(char** data, const char* value);

void struct_free(struct EmployeesInfo_t* g_empls, struct Pasports_t* g_pspts);

void allocstructmem(int n, char* filename, struct EmployeesInfo_t** g_empls, struct Pasports_t** g_pspts);

void age_scan(int n, struct EmployeesInfo_t* g_empls, struct Pasports_t* g_pspts);
#endif // !_FUNCTIONS_H
