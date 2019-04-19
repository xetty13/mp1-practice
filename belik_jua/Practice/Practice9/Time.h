#pragma once

class Time
{
private:
    unsigned h, m;
public:
    Time();
    Time(unsigned _h, unsigned _m);
    Time(const Time& tmp);
    ~Time();

    void Print()const;
    bool operator== (const Time& tmp)const;
    Time& operator= (const Time& tmp);
};