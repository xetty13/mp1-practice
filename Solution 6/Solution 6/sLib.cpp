#include "sLib.h"

sLib::sLib()
{
    this->count = 0;
    this->person = nullptr;
}

sLib::sLib(int count, const std::string& filename)
{
    this->count = count;
    this->person = new Person[count];
    std::ifstream in;
    in.open(filename);
    for (int i = 0; i < count; i++)
    {
        in >> this->person[i];
    }
    in.close();
}

Person sLib::searchBest(const std::string& type) const
{
    Person* maxPerson = nullptr;
    int maxRecord = 0;
    for (int i = 0; i < count; i++)
    {
        if (person[i].getSport() == type && person[i].getRecord() > maxRecord)
        {
            maxRecord = person[i].getRecord();
            maxPerson = &person[i];
        }
    }
    if (maxPerson)
    {
        return *maxPerson;
    }
    else {
        throw "Ќет, спортсмена заданного вида спорта!!";
    }
}

sLib::~sLib()
{
    if (person != nullptr)
    {
        delete[] person;
        person = nullptr;
    }
}
