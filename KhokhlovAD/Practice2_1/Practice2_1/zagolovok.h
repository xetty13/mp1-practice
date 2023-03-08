#ifndef _KTO_H
#define _KTO_H

typedef struct
{
	char* name;
	char* date;
	char* carnum;
	unsigned long gibdd;
	char* phnum;
	unsigned long tehpas;
} Owners;

void read_inf(Owners* owner, FILE* f, int n);
void print_inf(Owners* owner, int n);

void free_inf(Owners** owner, int n);

int search_owner(Owners* owner, int gibdd, int n);
#endif
