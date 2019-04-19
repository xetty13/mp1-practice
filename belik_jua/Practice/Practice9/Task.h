#pragma once
#include "Date.h"
#include "Time.h"

class Task
{
public:
    char* description;
    Date date;

    Task();
    Task(char* des, Date d);
    ~Task();

    virtual void Print()const;
    virtual Task& operator= (const Task& tmp);
};

class Type1 : public Task
{
public:
    Type1();
    Type1(char* des, Date d);
    ~Type1();

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
    Type2(char* des, Date d, Time t, unsigned dur);
    ~Type2();

    void Print()const;
    Type2& operator= (const Type2& tmp);
};
