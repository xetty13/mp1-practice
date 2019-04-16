#pragma once
#include <iostream>
#include "Time.h"
#include <fstream>
using namespace std;
Time::Time()
{
	h = 0;
	m = 0;
}
Time::Time(unsigned h, unsigned m)
{
	this->h = h;
	this->m = m;
}
Time ::~Time()
{
	h = 0;
	m = 0;
}
void Time::PrintTime()
{
	cout << h << ":" << m;
}