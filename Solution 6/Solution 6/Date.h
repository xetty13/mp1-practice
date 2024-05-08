#pragma once
#include <iostream>
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date()=default;
    Date(int d, int m, int year);
    const Date& operator=(const Date& d);
    friend std::ifstream& operator>> (std::ifstream& in, Date& d);
    friend std::ostream& operator<< (std::ostream& out, const Date& d);
};