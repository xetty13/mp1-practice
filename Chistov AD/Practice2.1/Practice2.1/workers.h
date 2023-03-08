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

void allocate(worker** w);
void database();
void allocate(worker** w);
void memory_free(worker** w);
int amount();
void higher_education();
#endif 
