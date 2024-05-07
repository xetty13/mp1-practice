#include "Date.h"
#include <iostream>
#include <fstream>

const Date& Date::operator=(const Date& d)
{
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;
    return *this;
}

std::ifstream& operator>> (std::ifstream& in, Date& d)
{
    in >> d.day;
    in >> d.month;
    in >> d.year;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Date& d)
{
    if (d.day <= 9)
    {
        out << "0" << d.day << ".";
    }
    else
        out << d.day << ".";
    if (d.month <= 9)
    {
        out << "0" << d.month << ".";
    }
    else
        out << d.month << ".";
    out << d.year << " ";
    return out;
}