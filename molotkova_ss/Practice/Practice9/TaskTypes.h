#pragma once
#include "Time.h"
#include"Date.h"

class Tasks 
{
public:
	Tasks() 
	{
		description = NULL;
		date= Date(0, 0, 0);
	};
	~Tasks() 
	{
		delete[]description;
		date.~Date();
	};
	virtual void Print() = 0;
protected:
	char* description;
	Date date;
};

class Type1: public Tasks
{
public:
	Type1();
	Type1(char* description, Date date);
	~Type1();
	void Print();
};

class Type2: public Tasks
{
private:
	unsigned duration;
	Time time;
public:
	Type2();
	Type2(char* description, Date date, unsigned duration, Time time);
	~Type2();
	void Print();
};

