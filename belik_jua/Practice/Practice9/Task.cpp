#include "Task.h"
#include<iostream>

Task::Task()
{
    date = Date();
    description = "";
}

Task::~Task()
{
    date.~Date();
    description.clear();
}

Date Task::GetDate()
{
    return date;
}

Type1::Type1()
{
    date = Date();
    description = "";
}

Type1::Type1(string des, Date d)
{
    date = d;
    description = des;
}

Type1::~Type1()
{
    date.~Date();
    description.clear();
}

void Type1::Print()const
{
    cout << "All day task: " << description << endl;
}

Type1& Type1::operator= (const Type1& tmp)
{
    date = tmp.date;
    description = tmp.description;
    return *this;
}

Type2::Type2()
{
    date = Date();
    description = "";
    time = Time();
    durations = 0;
}

Type2::Type2(string des, Date d, Time t, unsigned dur)
{
    date = d; 
    description = des;
    time = t;
    durations = dur;
}

Type2::~Type2()
{
    date.~Date();
    description.clear();
    time.~Time();
    durations = 0;
}

void Type2::Print()const
{
    cout << "Task: ";
    time.Print();
    cout << description << " duration: " << durations << " min" << endl;
}

Type2& Type2::operator= (const Type2& tmp)
{
    date = tmp.date;
    description = tmp.description;
    time = tmp.time;
    durations = tmp.durations;
    return *this;
}