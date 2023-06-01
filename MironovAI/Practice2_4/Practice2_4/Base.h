#ifndef _BASE_H_
#define _BASE_H_
#include "Product.h"
#include <iostream>
#include <fstream>
using namespace std;


class Base {
private:
	Product product;
	int count;
public:
	Base() {
		count = 0;
	}
	friend ifstream& operator>>(ifstream& buf, Base& Date);
	friend ostream& operator<<(ostream& buf, const Base& Date);
	friend istream& operator>>(istream& buf, Base& Date);
	bool operator == (const string& str) const;
	bool operator == (const Base& base) const;
	bool operator != (const Base& base) const;
	Base& operator += (const int& ucount);
	Product get_product() const;
	int get_count() const;
	void set_count(const int ucount);
};

#endif
