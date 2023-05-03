#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#include <string>
using namespace std;


struct bankstruct {

	string bankname;
	string banktype;
};

struct vkladstruct{
	float saving;
	float debit;
	float cumulative;
	int saving_month;
	int debit_month;
	int cumulative_month;

};

struct bestbank {
	bankstruct* banki;
	vkladstruct* vklads;

	bestbank(int stringcount);
	~bestbank();
	void workfile(string path, int stringcount);

	int choosesaving(int sumvkl, int your_month, int stringcount);
	int choosedebit(int sumvkl, int your_month, int stringcount);
	int choosecumulative(int sumvkl, int your_month, int stringcount);


	void chooseprint(int n);


	string bestname[3];
	string besttype[3];
	float bestsum[3];
};

int strcount(string path);
string getfile();
#endif