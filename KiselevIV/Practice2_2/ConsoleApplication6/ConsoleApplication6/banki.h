#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#include <string>
using namespace std;


typedef struct {

	string bankname;
	string banktype;
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
	string bestname;
	string besttype;
	float bestsum;
}bestbank;

int strcount(string path);

bankstruct* allocbanki(int stringcount);
vkladstruct* allocvklads(int stringcount);
bestbank* allocbest(int n);
void workfile(bankstruct* banki, vkladstruct* vklads, string path, int stringcount);

int choosesaving(int sumvkl, int your_month, bankstruct* banki, vkladstruct* vklads, bestbank* bests, int stringcount);
int choosedebit(int sumvkl, int your_month, bankstruct* banki, vkladstruct* vklads, bestbank* bests, int stringcount);
int choosecumulative(int sumvkl, int your_month, bankstruct* banki, vkladstruct* vklads, bestbank* bests, int stringcount);


void chooseprint(bestbank* bests, int n);

void freebanki(bankstruct* banki, int stringciunt);
void freevklads(vkladstruct* vklads);
void freebests(bestbank* bests, int n);
#endif