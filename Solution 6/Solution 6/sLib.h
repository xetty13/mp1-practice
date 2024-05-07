#pragma once
#include "Person.h"


class sLib {
private:
    int count;
    Person* person;
public:
    sLib();
    sLib(int, const std::string& filename);
    void printData();
    void printSearch(const std::string& type);
    ~sLib();
};
