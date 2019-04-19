#pragma once

class Date
{
private:
    int y, m, d;
public:
    Date();
    Date(int _y, int _m, int _d);
    Date(const Date& tmp);
    ~Date();

    bool operator== (const Date& tmp) const;
    void Print()const;
    Date& operator= (const Date& tmp);
};