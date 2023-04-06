#ifndef _WORKERS_H
#define _WORKERS_H

typedef struct {
	char* id;
	char* profession;
	char* education;
	char* last_job;
	char* rsn_dismiss;
	char* family_status;
	int  contact_info;
}worker;

char* get_Path();
void allocate_workers(worker** w, int n);
int amount(char* path);
void adding(worker* w, char* path);
void higher_education(worker* w, int count);
void free_workers(worker** w, int number);
#endif 
