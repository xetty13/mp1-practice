#ifndef _WORKERS_H
#define _WORKERS_H
#include <string>
using namespace std;

struct worker {
	string  id;
	string  profession;
	string  education;
	string  last_job;
	string  rsn_dismiss;
	string  family_status;
	int  contact_info;
	friend ostream& operator<<(ostream& out, const worker& w);
};

struct labor {
	worker* w;
	int n;
	int amount(const string& path);
	labor(const string& path);
	void higher_education(const string& path);
	~labor();
};

string get_path();
#endif 
