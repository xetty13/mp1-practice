#include "Person.h"

std::ifstream& operator>> (std::ifstream& in, Person& pers)
{
    std::string GenderStr;
    in >> pers.Name >> pers.Surname >> GenderStr;
    in >> pers.DateBirth >> pers.Nation >> pers.Sport >> pers.Club >> pers.Record;

    if (GenderStr == "Male")
    {
        pers.Gend = Gender::Male;
    }
    else if (GenderStr == "Female")
    {
        pers.Gend = Gender::Female;
    }
    else
    {
        std::cout << "Other" << std::endl;
    }
    return in;
}

std::ostream& operator<< (std::ostream& out, const Person& pers) {
    out << pers.Name << " ";
    out << pers.Surname << " ";
    out << (pers.Gend == Male ? "Male" : "Female") << " ";
    out << pers.DateBirth << " ";
    out << pers.Nation << " ";
    out << pers.Sport << " ";
    out << pers.Club << " ";
    out << pers.Record;

    return out;
}

int Person::getRecord() const
{
    return Record;
}

std::string Person::getSport() const
{
    return Sport;
}
