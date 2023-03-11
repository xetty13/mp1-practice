#ifndef _WORKERS_H
#define _WORKERS_H

typedef struct {
	char **id;
	char  **profession;
	char  **education;
	char  **last_job;
	char  **rsn_dismiss;
	char  **family_status;
	char  **contact_info;
}worker;

void allocate(worker** w, int n);
int counter();
int amount();
char* readFile();
void adding(worker* w, char* buff);
void higher_education(worker** w);
void memory_free(worker** w);
#endif 
