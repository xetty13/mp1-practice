#include "Time.h"
#include<iostream>
using namespace std;

Time::Time()
{
    h = 0;
    m = 0;
}

Time::Time(unsigned _h, unsigned _m)
{
    h = _h;
    m = _m;
}

Time::Time(const Time& tmp)
{
    h = tmp.h;
    m = tmp.m;
}

Time::~Time()
{
    h = 0;
    m = 0;
}

void Time::Print()const
{
    cout << h << ":" << m << endl;
}

bool Time::operator== (const Time& tmp)const
{
    if ((h == tmp.h) && (m == tmp.m))
        return true;
    return false;
}

Time& Time::operator= (const Time& tmp)
{
    if (*this == tmp)
        return *this;
    h = tmp.h;
    m = tmp.m;
    return *this;
}