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

string get_path();
int amount(string& path);
void adding(worker* w, string& path, int n);
void higher_education(worker* w, int count);
#endif 
