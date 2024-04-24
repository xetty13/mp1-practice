#include "Date.h"
#include <iostream>
#include <fstream>

std::ifstream& operator>> (std::ifstream& in, Date& d)
{
    in >> d.day;
    in >> d.month;
    in >> d.year;
    return in;
}