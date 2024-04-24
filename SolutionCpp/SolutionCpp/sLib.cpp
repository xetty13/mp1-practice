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

