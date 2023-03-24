#ifndef _WORKERS_H
#define _WORKERS_H

typedef struct {
	char *id;
	char  *profession;
	char  *education;
	char  *last_job;
	char  *rsn_dismiss;
	char  *family_status;
	char  *contact_info;
}worker;

void allocate_workers(worker** w, int n);
int amount();
void adding(worker* w);
void higher_education(worker* w, int count);
void free_workers(worker** w, int number);
#endif 
