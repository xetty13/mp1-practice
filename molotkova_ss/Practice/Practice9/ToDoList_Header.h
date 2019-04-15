#pragma once
class ToDoList
{	
private:
	Tasks** tasks; 
	int amount_of_tasks;
public:	
	ToDoList();
	ToDoList(int amount_of_tasks);
	~ToDoList();
	void Read(const char*);
	void Print(Date date);
};
class Tasks 
{
public:
	Tasks();
	~Tasks();
	char* description;
	Date date;
	virtual void Print();
};
class Type1: public Tasks
{
public:
	Type1();
	Type1(char* description, Date date);
	~Type1();
	void Print();
};
class Type2: public Tasks
{
private:
	unsigned duration;
	Time time;
public:
	Type2();
	Type2(char* description, Date date, unsigned duration, Time time);
	~Type2();
	void Print();
};
class Date
{
private:
	int day;
	int month;
	int year;
	
public:
	void PrintDate();
	Date();
	Date(int day, int month, int year);
	~Date();
	bool operator == (const Date &date1);
};
class Time
{
private:
	unsigned h;
	unsigned m;
public:
	Time();
	Time(unsigned h, unsigned m);
	~Time();
	void PrintTime();
};