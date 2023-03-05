#ifndef _WORKERS_H
#define _WORKERS_H
#define LINE 50

typedef struct {
	char string[LINE];
	char id[LINE];
	char profession[LINE];
	char education[LINE];
	char last_job[LINE];
	char rsn_dismis[LINE];
	char family_status[LINE];
	char contact_info[LINE];
}worker;

void database();
int amount();
int higher_education();
void percent();
#endif 
