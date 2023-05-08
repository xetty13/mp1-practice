#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	char* vkladname;
	float rate;
	int times;
}vkladstruct;

typedef struct {
	int count;
	char* bankname;
	char* banktype;
	vkladstruct** our_vklad;
}bankstruct;

char* getfile();
int strcount(char* path);

bankstruct** allocbanki(int stringcount);

void workfile(bankstruct** banki, char* path, int stringcount);
void data_input(int* sumvkl, int* your_month, char* your_type);
void choosebest(int sumvkl, int your_month, bankstruct** banki, int stringcount, char* your_type);

void freebanki(bankstruct** banki, int stringciunt);
#endif