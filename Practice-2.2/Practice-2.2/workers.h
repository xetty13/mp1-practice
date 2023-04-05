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
	string  contact_info;
	bool operator ==(const string& otherTitle) const;
	friend ostream& operator<<(ostream& out, const worker& w);
};

string GetFilePath();
int amount(string& path);
void adding(worker* w, string& path, int n);
void higher_education(worker* w, int count);
#endif 
