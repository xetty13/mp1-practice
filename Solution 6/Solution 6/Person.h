#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "Gender.h"

class Person
{
private:
    std::string Name;
    std::string Surname;
    Gender Gend;
    Date DateBirth;
    std::string Nation;
    std::string Sport;
    std::string Club;
    int Record;
public:
    friend std::ifstream& operator>> (std::ifstream& in, Person& pers);
    friend std::ostream& operator<< (std::ostream& out, const Person& pers);
    int getRecord() const;
    std::string getSport() const;
};

