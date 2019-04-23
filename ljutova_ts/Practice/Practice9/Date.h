#ifndef _DATE_H_ 
#define _DATE_H_ 

#include <iostream> 

class Date
{
	unsigned int d, m, y;
public:
	Date();
	Date(int, int, int);
	Date(const Date&);
	~Date();
	void Print();

	bool operator==(const Date& x) const;
	const Date& operator=(const Date&);

};

#endif
