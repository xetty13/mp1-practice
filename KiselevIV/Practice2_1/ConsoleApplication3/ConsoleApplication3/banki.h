#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#define maxlen 30
typedef struct {
	
	char bankname[maxlen];
	char banktype[maxlen];
	float saving;
	float debit;
	float cumulative;
}bankstruct;


int strcount(char* path);
bankstruct* alloc(int stringcount);
void workfile(bankstruct* banki, char* path, int stringcount);
void choosesaving(int sumvkl, bankstruct * banki, int stringcount);
void choosedebit(int sumvkl, bankstruct* banki, int stringcount);
void choosecumulative(int sumvkl, bankstruct* banki, int stringcount);
void freebanki(bankstruct* banki);
#endif