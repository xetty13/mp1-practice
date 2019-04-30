#pragma once
#include "Date.h"
#include "Time.h"
#include<string>
using namespace std;

class Task
{
protected:
    string description;
    Date date;
public:
    Task();
    virtual ~Task();
    virtual Date GetDate();

    virtual void Print()const = 0;
};

class Type1 : public Task
{
public:
    Type1();
    Type1(string des, Date d);
    ~Type1();
    Date GetDate();

    void Print()const;
    Type1& operator= (const Type1& tmp);
};

class Type2 : public Task
{
private:
    Time time;
    unsigned durations;
public:
    Type2();
    Type2(string des, Date d, Time t, unsigned dur);
    ~Type2();
    Date GetDate();

    void Print()const;
    Type2& operator= (const Type2& tmp);
};
