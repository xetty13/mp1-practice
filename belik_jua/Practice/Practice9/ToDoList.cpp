#include "ToDoList.h"
#include<iostream>
#include<fstream>
#include<string>
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

void ToDoList::Print(Date a)const
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

void ToDoList::Read(const char* A)
{
    ifstream fin(A);
    if (!fin.is_open())
        throw "No File";
    fin >> count;
    Tasks = new Task*[count];
    int type;
    int y, m, d;
    unsigned min, h, dur;
    char* des = new char[50];
    for (int i = 0; i < count; i++)
    {
        fin >> type;
        if (type == 1)
        {
            fin >> y >> m >> d;
            fin.getline(des, 50);
            Date date = Date(y, m, d);
            Tasks[i] = new Type1(des, date);
        }
        if (type == 2)
        {
            fin >> y >> m >> d >> h >> min >> dur;
            Date date = Date(y, m, d); 
            Time time = Time(h, min); 
            fin.getline(des, 50); 
            Tasks[i] = new Type2(des, date, time, dur);
        }
    }
    fin.close();
}
