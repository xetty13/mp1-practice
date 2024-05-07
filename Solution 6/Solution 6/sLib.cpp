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

void sLib::printData()
{
    for (int i = 0; i < count; i++) {
        std::cout << i + 1 << ".";
        std::cout << person[i] << std::endl;
    }
}

void sLib::printSearch(const std::string& type)
{
    int maxRecord = 0;
    Person maxRecordPerson;
    for (int i = 0; i < count; i++)
    {
        if (person[i].getSport() == type && person[i].getRecord() > maxRecord)
        {
            maxRecord = person[i].getRecord();
            maxRecordPerson = person[i];
        }
    }
    std::cout << maxRecordPerson << std::endl;
}

sLib::~sLib()
{
    if (person != nullptr)
    {
        delete[] person;
        person = nullptr;
    }
}
