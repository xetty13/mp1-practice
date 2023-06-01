#include "Base.h"
#include "Product.h"
#include <iostream>
#include <fstream>
using namespace std;


//Base
ifstream& operator>>(ifstream& buf, Base& Date) {

	buf >> Date.product >> Date.count;
	return buf;
}
istream& operator>>(istream& buf, Base& Date) {
	buf >> Date.product >> Date.count;
	return buf;
}
ostream& operator<<(ostream& buf, const Base& Date) {
	buf << Date.product << Date.count << endl;
	return buf;
}
bool Base::operator == (const string& str) const
{
	return product == str;
}
bool Base::operator == (const Base& base) const
{
	return product == base.product;
}
bool Base::operator != (const Base& base) const
{
	return !(*this == base);
}
Base& Base::operator+=(const int& ucount)
{
	if (ucount)
	{
		count += ucount;
	}
	return *this;
}


Product Base::get_product() const
{
	return product;
}
int Base::get_count() const
{
	return count;
}
void Base::set_count(const int ucount)
{
	count = ucount;
}


