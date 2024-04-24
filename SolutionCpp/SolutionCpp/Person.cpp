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
        std::cout << "Другой гендер" << std::endl;
    }
    std::cout << pers.Name << pers.Surname << pers.Gend << pers.Nation << pers.Sport << pers.Club << pers.Record;
    return in;
}