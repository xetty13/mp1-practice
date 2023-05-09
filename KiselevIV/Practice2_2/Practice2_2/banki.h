#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#include <string>
using namespace std;

struct vkladstruct {
	string vkladname;
	float rate;
	int times;
};
struct bankstruct {
	int count;
	string bankname;
	string banktype;
	vkladstruct* our_vklad;
};

struct bestbank {
	bankstruct* banki;
	int sumvkl;
	int your_month;
	string your_type;
	int stringcount;//поле, ниже одноимённый параметр(он другой)
	bestbank(int stringcount);
	~bestbank();
	void workfile(string path);

	void data_input();

	void choosebest();
};

int strcount(string path);
string getfile();
#endif