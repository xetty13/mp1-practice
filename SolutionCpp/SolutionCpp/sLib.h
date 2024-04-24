#pragma once
#include "Person.h"
class sLib
{
private:
    int count;
    Person* person;
public:
    sLib();
    sLib(int, const std::string& filename);
};