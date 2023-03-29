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

void allocate_workers(worker** w, int n);
string GetPath();
int amount(string path);
void adding(worker* w);
void higher_education(worker* w, int count);
void free_workers(worker** w, int number);
#endif 
