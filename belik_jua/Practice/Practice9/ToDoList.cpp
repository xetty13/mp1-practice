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
            ss = des.substr((pos2 + 1), (pos1 - pos2 - 1));
            d = atoi(ss.c_str()); 
            ss = "";

            pos2 = des.find(".", pos1 + 1); // m 12
            ss = des.substr((pos1 + 1), (pos2 - pos1 - 1));
            m = atoi(ss.c_str()); 
            ss = "";

            pos1 = des.find(" ", pos2); // y 21
            ss = des.substr((pos2 + 1), (pos1 - pos2 - 1));
            y = atoi(ss.c_str()); 
            ss = "";

            pos2 = des.find("/0", pos1); //des 12
            ss = des.substr((pos1 + 1), (pos2 - pos1 - 1));
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
            ss = des.substr((pos2 + 1), (pos1 - pos2 - 1));
            d = atoi(ss.c_str());
            ss = "";

            pos2 = des.find(".", pos1 + 1); // m 12
            ss = des.substr((pos1 + 1), (pos2 - pos1 - 1));
            m = atoi(ss.c_str());
            ss = "";

            pos1 = des.find(" ", pos2); // y 21
            ss = des.substr((pos2 + 1), (pos1 - pos2 - 1));
            y = atoi(ss.c_str());
            ss = "";

            pos1 = des.find(":");
            pos2 = des.rfind(" ", pos1); // h 21
            ss = des.substr((pos2 + 1), (pos1 - pos2 - 1));
            h = atoi(ss.c_str());
            ss = "";

            pos2 = des.find(" ", pos1); // min 12
            ss = des.substr((pos1 + 1), (pos2 - pos1 - 1));
            min = atoi(ss.c_str());
            ss = "";

            pos1 = des.find_first_of("1234567890", pos2); //dur 12
            pos2 = des.find(" ", pos1);
            ss = des.substr(pos1, (pos2 - pos1));
            dur = atoi(ss.c_str());
            ss = "";

            pos1 = des.find("/0", pos2); //des 21
            ss = des.substr((pos2 + 1), (pos1 - pos2 - 1));
            des = ss;
            ss = "";

            Date date = Date(y, m, d);
            Time time = Time(h, min);
            Tasks[i] = new Type2(des, date, time, dur);
        }
    }
    fin.close();
}
