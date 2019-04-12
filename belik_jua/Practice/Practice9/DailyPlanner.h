#pragma once

class ToDoList
{
private:
    Task** Tasks;
    unsigned count;
public: 
    ToDoList();
    ToDoList(unsigned n);
    ~ToDoList();

    void Print(Date a);
    void Read(const char A);
};

class Task
{
public:
    char* description;
    Date date;

    Task();
    Task(char* des, Date d);
    ~Task();

    virtual void Print();
};

class Type1: public Task
{
public:
    Type1();
    Type1(char* des, Date d);
    ~Type1();

    void Print();
};

class Type2: public Task
{
private:
    Time time;
    unsigned durations;
public:
    Type2();
    Type2(char* des, Date d, Time t, unsigned dur);
    ~Type2();

    void Print();
};

class Date
{
private:
    int y, m, d;
public:
    Date();
    Date(int _y, int _m, int _d);
    ~Date();

    bool operator== (Date& tmp);
    void Print();
};

class Time
{
private:
    unsigned h, m;
public:
    Time();
    Time(unsigned _h, unsigned _m);
    ~Time();

    void Print();
};