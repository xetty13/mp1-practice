#pragma once
#ifndef _BANKI_H
#define _BANKI_H

typedef struct {
	
	char* bankname;
	char* banktype;
}bankstruct;

typedef struct {
	float saving;
	float debit;
	float cumulative;
	int saving_month;
	int debit_month;
	int cumulative_month;

}vkladstruct;

typedef struct {
	char* bestname;
	char* besttype;
	float bestsum;
}bestbank;

int strcount(char* path);

bankstruct** allocbanki(int stringcount);
vkladstruct* allocvklads(int stringcount);
bestbank** allocbest(int n);
void workfile(bankstruct** banki,vkladstruct* vklads, char* path, int stringcount);

void choosesaving(int sumvkl, int your_month, bankstruct ** banki,vkladstruct* vklads, bestbank** bests, int stringcount);
void choosedebit(int sumvkl, int your_month, bankstruct** banki,vkladstruct* vklads, bestbank** bests, int stringcount);
void choosecumulative(int sumvkl, int your_month, bankstruct** banki,vkladstruct* vklads, bestbank** bests, int stringcount);

//void choose(bestbank* bests);

void freebanki(bankstruct** banki, int stringciunt);
void freevklads(vkladstruct* vklads);
void freebests(bestbank** bests, int n);
#endif