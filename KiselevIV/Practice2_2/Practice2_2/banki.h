#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#include <string>
using namespace std;

struct vkladstruct {
	string vkladname;
	float rate;
	int times;
	//friend ostream& operator<<(ostream& os, const vkladstruct& our_vklad);
};
struct bankstruct {
	int count;
	string bankname;
	string banktype;
	vkladstruct* our_vklad;
	//friend ostream& operator<<(ostream& os, const bankstruct& banki);
};

struct banklib {
	bankstruct* banki;
	int count;
	banklib(const string& path);
	~banklib();
	 void search(float sum, int kMonths, string vkladType);

	friend ostream& operator << (ostream& out, const banklib& banks);
};
int strcount(string path);
string getfile();
#endif