#pragma once
#include "Task.h"

class ToDoList
{
private:
    Task** Tasks;
    unsigned count;
public: 
    ToDoList();
    ToDoList(unsigned n);
    ~ToDoList();

    void Print(Date a) const;
    void Read(const char* A);
};
