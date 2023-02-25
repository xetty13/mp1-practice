#ifndef _WORKERS_H
#define _WORKERS_H
#define LINE 50

typedef struct {
	char id[LINE];
	char profession[LINE];
	char education[LINE];
	char last_job[LINE];
	char rsn_dismis[LINE];
	char family_status[LINE];
	char contact_info[LINE];
}worker;

int adding();
int amount();
int workers();
#endif 