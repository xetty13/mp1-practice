#ifndef _SCHOOL_H
#define _SCHOOL_H


#include <string.h>
using namespace std;

struct TStudent {
	string FIO;
	int Class;
	string Gender;
	string Date;
	string Address;
	friend ostream& operator<<(ostream& out, const TStudent& student);
};

struct TSchool {
	TStudent* student;
	int n;
	int counting(const string& filename);
	TSchool(const string& filename);
	friend ostream& operator<<(ostream& out, const TSchool& school);
	void sorting();
	~TSchool();	
};

#endif