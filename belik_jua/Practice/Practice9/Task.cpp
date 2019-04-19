#include "Task.h"
#include<iostream>
using namespace std;

Task::Task()
{
    date = Date();
    description = NULL;
}

Task::Task(char* des, Date d)
{
    date = d;
    description = new char[50];
    for (int i = 0; i < 50; i++)
        description[i] = des[i];
}

Task::~Task()
{
    date.~Date();
    description = NULL;
}

void Task::Print()const
{
    cout << "All day task: " << description << endl;
}

Task& Task::operator= (const Task& tmp)
{
    date = tmp.date;
    description = new char[50];
    description = tmp.description;
    return *this;
}

Type1::Type1()
{
    date = Date();
    description = NULL;
}

Type1::Type1(char* des, Date d)
{
    date = d;
    description = new char[50];
    for (int i = 0; i < 50; i++)
        description[i] = des[i];
}

Type1::~Type1()
{
    date.~Date();
    description = NULL;
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
    description = NULL;
    time = Time();
    durations = 0;
}

Type2::Type2(char* des, Date d, Time t, unsigned dur)
{
    date = d; 
    description = new char[50];
    for (int i = 0; i < 50; i++)
        description[i] = des[i];
    time = t;
    durations = dur;
}

Type2::~Type2()
{
    date.~Date();
    description = NULL;
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