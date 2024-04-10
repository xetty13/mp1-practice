#pragma once
#include "Gender.h"
#include "Date.h"

typedef struct {
    char* Name;
    char* Surname;
    Gender Gend; // 0 or 1 (Gend = atoi(str))
                 // MALE or FEMALE (strcmp("MALE", str) == 0 -> Gend = 0)
    Date DateBirth;
    char* Nation;
    char* Sport;
    char* Club;
    int Record;
}Sportsman;
void readPerson(const FILE* f, Sportsman* n);
void write_sport(Sportsman* n);
void free_mem(Sportsman* n);