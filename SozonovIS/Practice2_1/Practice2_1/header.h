#ifndef _SCHOOL_H
#define _SCHOOL_H

typedef struct{
	char* FIO;
	int Class;
	char* Gender;
	char* Date;
	char* Address;
} TSchool;

void allocation(TSchool** school, int n);
void release(TSchool** school, int n);

int counting();
void read_file(TSchool* school);
void print_file(TSchool* school, int n);

void sorting(TSchool* school, int n);

#endif