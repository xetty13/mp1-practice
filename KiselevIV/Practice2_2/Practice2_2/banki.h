#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#include <string>
using namespace std;

struct vkladstruct {
	string vkladname;
	float rate;
	int times;
	friend ostream& operator<<(ostream& os, const vkladstruct& our_vklad);
};
struct bankstruct {
	int count;
	string bankname;
	string banktype;
	vkladstruct* our_vklad;
	friend ostream& operator<<(ostream& os, const bankstruct& banki);
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