#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#include <string>
using namespace std;

struct vkladstruct {
	string vkladname;
	float rate;
	int times;
	bool operator==(const string& vkladType) const;
	bool operator!=(const string& vkladType) const;
	friend ostream& operator<<(ostream& os, const vkladstruct& our_vklad);
};
struct bankstruct {
	int count;
	string bankname;
	string banktype;
	bool smotr;
	vkladstruct* our_vklad;
	friend ostream& operator<<(ostream& os, const bankstruct& banki);
};

struct banklib {
	bankstruct* banki;
	int count;
	string vkladType;
	banklib() {}
	banklib(const string& path);
	~banklib();
	banklib& search(float sum, int kMonths, string vkladType);
	banklib(const banklib& banks);
	//banklib& operator=(const banklib& banks);//опер. присваивания
	friend ostream& operator << (ostream& out, const banklib& banks);
};
string getfile();
#endif