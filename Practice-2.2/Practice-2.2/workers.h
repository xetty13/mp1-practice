#ifndef _WORKERS_H
#define _WORKERS_H
#include <string>
using namespace std;

typedef struct {
	string  id;
	string  profession;
	string  education;
	string  last_job;
	string  rsn_dismiss;
	string  family_status;
	int  contact_info;
}worker;

string get_Path();
int amount(string path);
void adding(worker* w, string path, int n);
void higher_education(worker* w, int count);
#endif 
