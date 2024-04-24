#pragma once
#include <iostream>
class Date
{
private:
    int day;
    int month;
    int year;
public:
    friend std::ifstream& operator>> (std::ifstream& in, Date& d);
};