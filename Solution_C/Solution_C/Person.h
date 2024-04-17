#pragma once
#include "Gender.h"
#include "Date.h"

typedef struct {
    char* Name;
    char* Surname;
    Gender Gend; 
    Date DateBirth;
    char* Nation;
    char* Sport;
    char* Club;
    int Record;
}Sportsman;
void readPerson(const FILE* f, Sportsman* n);
void print_record(Sportsman* n);
