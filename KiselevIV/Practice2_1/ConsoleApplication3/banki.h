#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#define maxlen 30
typedef struct {
	
	char bankname[maxlen];
	char banktype[maxlen];
}bankstruct;

typedef struct {
	float saving;
	float debit;
	float cumulative;
}vkladstruct;

int strcount(char* path);
bankstruct* allocbanki(int stringcount);
vkladstruct* allocvklads(int stringcount);
void workfile(bankstruct* banki,vkladstruct* vklads, char* path, int stringcount);
void choosesaving(int sumvkl, bankstruct * banki,vkladstruct* vklads, int stringcount);
void choosedebit(int sumvkl, bankstruct* banki,vkladstruct* vklads, int stringcount);
void choosecumulative(int sumvkl, bankstruct* banki,vkladstruct* vklads, int stringcount);
void freebanki(bankstruct* banki);
void freevklads(vkladstruct* vklads);
#endif