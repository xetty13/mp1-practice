#pragma once
#include <iostream>
#include "ToDoList_Header.h"
#include <fstream>
using namespace std;

ToDoList :: ToDoList()
{
	 tasks = NULL;
	 amount_of_tasks = 0;
}
ToDoList ::ToDoList(int amount_of_tasks)
{
	this ->amount_of_tasks = amount_of_tasks;
	tasks = new Tasks*[amount_of_tasks];
}
ToDoList ::~ToDoList()
{
	for (int i = 0; i < amount_of_tasks; i++)
		delete[]tasks[i];
	delete[]tasks;
	amount_of_tasks = 0;
}
void ToDoList :: Read(const char*)
{}
void ToDoList :: Print(Date date)
{   
	cout << "Date: ";
	date.PrintDate();
	for (int i = 0; i < amount_of_tasks; i++)
		tasks[i]->Print();
}
Type1 ::Type1()
{
	description = NULL;
	date = Date();
}
Type1 ::Type1(char* description, Date date)
{
	this->description = description;
	this->date = date;
}
Type1 ::~Type1()
{
	delete[]description;
	date.~Date();
}
void Type1 :: Print()
{
	cout << "For all day: " << description << endl;
}
Type2 ::Type2()
{
	description = NULL;
	date = Date();
	duration = 0;
	time = Time();
}
Type2 ::Type2(char* description, Date date, unsigned duration, Time time)
{
	this->description = description;
	this->date = date;
	this ->duration = duration;
	this->time = time;
}
Type2 ::~Type2()
{
	delete[]description;
	date.~Date();
	duration = 0;
	time.~Time();
}
void Type2 :: Print()
{
	cout << "Not for all day: " << endl;
	time.PrintTime();
	cout <<description<<"For " << duration << "minutes";
}
Date ::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date ::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
Date ::~Date()
{
	day = 0;
	month = 0;
	year = 0;
}
bool Date ::operator == (const Date &date1)
{
	if ((day == date1.day) && (month == date1.month) && (year == date1.year))
		return true;
	else
		return false;
}
void Date ::PrintDate()
{
	cout << "Date is: "<<day<<"."<<month<<"."<<year<<endl;
}
Time ::Time()
{
	h = 0;
	m = 0;
}
Time ::Time(unsigned h, unsigned m)
{
	this->h = h;
	this->m = m;
}
Time ::~Time()
{
	h = 0;
	m = 0;
}
void Time :: PrintTime()
{
	cout<<h<<":"<<m;
}