#ifndef _TIME_H_ 
#define _TIME_H_ 

#include <iostream> 

class Time
{
	int h, min;
public:
	Time();
	Time(int, int);
	Time(const Time&);
	~Time();
	void Print();

	const Time& operator=(const Time&);

};

#endif
