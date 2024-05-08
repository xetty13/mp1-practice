#pragma once
#include "Person.h"


class sLib {
private:
    int count;
    Person* person;
public:
    sLib();
    sLib(int, const std::string& filename);
    friend std::ostream& operator<<(std::ostream& out, const sLib* lib)
    {
        for (int i = 0; i < lib->count; i++)
        {
            out << i+1 << "." << " " << lib->person[i] << std::endl;
        }
        return out;
    };
    Person searchBest(const std::string& type) const;
    ~sLib();
};
