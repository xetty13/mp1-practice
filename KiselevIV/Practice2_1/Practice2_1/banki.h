#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	float saving;
	float debit;
	float cumulative;
	int saving_month;
	int debit_month;
	int cumulative_month;

}vkladstruct;

typedef struct {
	
	char* bankname;
	char* banktype;
	vkladstruct* our_vklad;
}bankstruct;


char* getfile();
int strcount(char* path);

bankstruct** allocbanki(int stringcount);
void workfile(bankstruct** banki,char* path, int stringcount);

void data_input(int* sumvkl, int* your_month, char* your_type);
void chooseall(int sumvkl, int your_month, bankstruct** banki,int stringcount, char* your_type);

void choosesaving(int sumvkl, int your_month, bankstruct** banki,int stringcount);
void choosedebit(int sumvkl, int your_month, bankstruct** banki,int stringcount);
void choosecumulative(int sumvkl, int your_month, bankstruct** banki,int stringcount);

void freebanki(bankstruct** banki, int stringciunt);
#endif