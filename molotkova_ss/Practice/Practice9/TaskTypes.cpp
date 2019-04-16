#pragma once
#include <iostream>
#include "TaskTypes.h"
#include"Date.h"
#include"Time.h"
#include <fstream>
using namespace std;


Type1 ::Type1()
{
	description = NULL;
	date = Date();
}
Type1 ::Type1(char* description, Date date)
{
	this->description = description;
	this->date = date;
}
Type1 ::~Type1()
{
	delete[]description;
	date.~Date();
}
void Type1 :: Print()
{
	cout << "For all day: " << description << endl;
}
Type2 ::Type2()
{
	description = NULL;
	date = Date();
	duration = 0;
	time = Time();
}
Type2 ::Type2(char* description, Date date, unsigned duration, Time time)
{
	this->description = description;
	this->date = date;
	this ->duration = duration;
	this->time = time;
}
Type2 ::~Type2()
{
	delete[]description;
	date.~Date();
	duration = 0;
	time.~Time();
}
void Type2 :: Print()
{
	cout << "Not for all day: " << endl;
	time.PrintTime();
	cout <<description<<"For " << duration << "minutes";
}
