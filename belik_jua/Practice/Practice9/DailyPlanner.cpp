#include "DailyPlanner.h"
#include<iostream>
#include<fstream>
using namespace std;

ToDoList::ToDoList()
{
    Tasks = NULL;
    count = 0;
}

ToDoList::ToDoList(unsigned n)
{
    count = n;
    Tasks = new Task*[n];
}

ToDoList::~ToDoList()
{
    for (int i = 0; i < count; i++)
        delete[] Tasks[i];
    delete[] Tasks;
    count = 0;
}

void ToDoList::Print(Date a)
{
    a.Print();
    for (int i = 0; i < count; i++)
    {
        if (Tasks[i]->date == a)
        {
            Tasks[i]->Print();
            cout << endl;
        }
    }

}

void ToDoList::Read(const char A)
{
    ////////////////////////////////////////////
}

Task::Task()
{
    date = Date(0, 0, 0);
    description = NULL;
}

Task::Task(char* des, Date d)
{
    date = d;
    description = des;
}

Task::~Task()
{
    date.~Date();
    description = NULL;
}

Type1::Type1()
{
    date = Date(0, 0, 0);
    description = NULL;
}

Type1::Type1(char* des, Date d)
{
    date = d;
    description = des;
}

Type1::~Type1()
{
    date.~Date();
    description = NULL;
}

void Type1::Print()
{
    cout << "All day task: " << description << endl;
}

Type2::Type2()
{
    date = Date(0, 0, 0);
    description = NULL;
    time = Time(0, 0);
    durations = 0;
}

Type2::Type2(char* des, Date d, Time t, unsigned dur)
{
    date = d;
    description = des;
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

void Type2::Print()
{
    time.Print();
    cout << "Task: " << description << " duration: " << durations << endl;
}

Date::Date()
{
    y = 0;
    m = 0;
    d = 0;
}

Date::Date(int _y, int _m, int _d)
{
    y = _y;
    m = _m;
    d = _d;
}

Date::~Date()
{
    y = 0;
    m = 0;
    d = 0;
}

bool Date::operator== (Date& tmp)
{
    if ((y != tmp.y) || (m != tmp.m) || (d != tmp.d))
        return false;
    return true;
}

void Date::Print()
{
    cout << d << "." << m << "." << y << endl;
}

Time::Time()
{
    h = 0;
    m = 0;
}

Time::Time(unsigned _h, unsigned _m)
{
    h = _h;
    m = _m;
}

Time::~Time()
{
    h = 0;
    m = 0;
}

void Time::Print()
{
    cout << h << ":" << m << endl;
}