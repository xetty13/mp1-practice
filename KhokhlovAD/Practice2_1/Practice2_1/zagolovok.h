#ifndef _KTO_H
#define _KTO_H

typedef struct
{
	int n;
	char* name;
	char* surname;
	char* patronymic;
	char* date;
	char* carnum;
	unsigned long gibdd;
	char* phnum;
	unsigned long tehpas;
} Owners;

Owners* read_inf(int n);
void print_inf(Owners* owner, int n);

void free_inf(Owners** owner, int n);

int search_owner(Owners* owner, int n);
#endif
