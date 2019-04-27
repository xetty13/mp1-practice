#include "ToDoList.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX_LEN 100

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
        if (Tasks[i]->GetDate() == a)
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
    char* c = new char[MAX_LEN];
    unsigned min, h, dur;
    string des, ss;
    for (int i = 0; i < count; i++)
    {
        fin >> type;
        if (type == 1)
        {
            int pos1, pos2;
            fin.getline(c, MAX_LEN);
            des = string(c);

            pos1 = des.find(".");
            pos2 = des.rfind(" ", pos1); // d 21
            for (int i = 1; i < (pos1 - pos2); i++)
                ss[i - 1] = des[pos2 + i];
            d = atoi(ss.c_str());
            ss = "";

            pos2 = des.find(".", pos1); // m 12
            for (int i = 1; i < (pos2 - pos1); i++)
                ss[i - 1] = des[pos1 + i];
            m = atoi(ss.c_str());
            ss = "";

            pos1 = des.find(" ", pos2); // y 21
            for (int i = 1; i < (pos1 - pos2); i++)
                ss[i - 1] = des[pos2 + i];
            y = atoi(ss.c_str());
            ss = "";

            pos2 = des.find("/0", pos1); //des 12
            for (int i = 1; i < (pos2 - pos1); i++)
                ss[i - 1] = des[pos1 + i];
            des = ss;
            ss = "";

            Date date = Date(y, m, d);
            Tasks[i] = new Type1(des, date);
        }
        if (type == 2)
        {
            int pos1, pos2;
            fin.getline(c, MAX_LEN);
            des = string(c);
            pos1 = des.find(".");
            pos2 = des.rfind(" ", pos1); // d 21
            for (int i = 1; i < (pos1 - pos2); i++)
                ss[i - 1] = des[pos2 + i];
            d = atoi(ss.c_str());
            ss = "";

            pos2 = des.find(".", pos1); // m 12
            for (int i = 1; i < (pos2 - pos1); i++)
                ss[i] = des[pos1 + i];
            m = atoi(ss.c_str());
            ss = "";

            pos1 = des.find(" ", pos2); // y 21
            for (int i = 1; i < (pos1 - pos2); i++)
                ss[i - 1] = des[pos2 + i];
            y = atoi(ss.c_str());
            ss = "";

            pos1 = des.find(":");
            pos2 = des.rfind(" ", pos1); // h 21
            for (int i = 1; i < (pos1 - pos2); i++)
                ss[i - 1] = des[pos2 + i];
            h = atoi(ss.c_str());
            ss = "";

            pos2 = des.find(" ", pos1); // min 12
            for (int i = 1; i < (pos2 - pos1); i++)
                ss[i - 1] = des[pos1 + i];
            min = atoi(ss.c_str());
            ss = "";

            pos1 = des.find(" ", pos2); //dur 21
            for (int i = 1; i < (pos1 - pos2); i++)
                ss[i - 1] = des[pos2 + i];
            dur = atoi(ss.c_str());
            ss = "";

            pos2 = des.find("/0", pos1); //des 12
            for (int i = 1; i < (pos2 - pos1); i++)
                ss[i - 1] = des[pos1 + i];
            des = ss;
            ss = "";

            Date date = Date(y, m, d);
            Time time = Time(h, min);
            Tasks[i] = new Type2(des, date, time, dur);
        }
    }
    fin.close();
}
