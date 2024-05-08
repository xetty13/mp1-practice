#include "Date.h"
#include <iostream>
#include <fstream>

Date::Date(int day, int month, int year)
{
    if (year > 2024)
        throw "Некорректный год рождения!";
    if (month > 12 || month <= 0)
        throw "Некорректный месяц";
    if (day <= 0 || ((day > 31) || ((day > 30) && (month == 4 || month == 6 || month == 9 || month == 11))))
        throw "Некорректная связка числа и месяца";
    if (year % 400 == 0 ||
        ((year % 4 == 0) && (year % 100 != 0))) {
        if (month == 2 && day > 30) {
            throw "Некорректный февраль!";
        }
    }

    this->day = day;
    this->month = month;
    this->year = year;
}

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