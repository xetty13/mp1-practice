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
	int saving_month;
	int debit_month;
	int cumulative_month;

}vkladstruct;

int strcount(char* path);
bankstruct* allocbanki(int stringcount);
vkladstruct* allocvklads(int stringcount);
void workfile(bankstruct* banki,vkladstruct* vklads, char* path, int stringcount);
void choosesaving(int sumvkl, int your_month, bankstruct * banki,vkladstruct* vklads, int stringcount);
void choosedebit(int sumvkl, int your_month, bankstruct* banki,vkladstruct* vklads, int stringcount);
void choosecumulative(int sumvkl, int your_month, bankstruct* banki,vkladstruct* vklads, int stringcount);

//void choose(int sumvkl, int your_month, bankstruct* banki, vkladstruct* vklads, int stringcount);

void freebanki(bankstruct* banki);
void freevklads(vkladstruct* vklads);
#endif