#include "Date.h"
#include<iostream>
using namespace std;

Date::Date()
{
    y = 0;
    m = 0;
    d = 0;
}

Date::Date(int _y, int _m, int _d)
{
    y = _y;
    m = _m;
    d = _d;
}

Date::Date(const Date& tmp)
{
    y = tmp.y;
    m = tmp.m;
    d = tmp.d;
}

Date::~Date()
{
    y = 0;
    m = 0;
    d = 0;
}

bool Date::operator== (const Date& tmp)const
{
    if ((y != tmp.y) || (m != tmp.m) || (d != tmp.d))
        return false;
    return true;
}

void Date::Print()const
{
    cout << d << "." << m << "." << y << endl;
}

Date& Date::operator= (const Date& tmp)
{
    if (*this == tmp)
        return *this;
    y = tmp.y;
    m = tmp.m;
    d = tmp.d;
    return *this;
}