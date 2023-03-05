#ifndef _WORKERS_H
#define _WORKERS_H

typedef struct {
	char *id;
	char *profession;
	char *education;
	char *last_job;
	char *rsn_dismis;
	char *family_status;
	char *contact_info;
}worker;

void database();
void allocate(worker** w);
void free(worker** w);
void percent();
int amount();
int higher_education();
#endif 
