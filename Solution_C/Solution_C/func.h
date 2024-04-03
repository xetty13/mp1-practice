#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"
#include "gender.h"
#define Buffer 128

typedef struct{
    char* Name;
    char* Surname;
    Gender Gend;
    Date DateBirth;
    char* Nation;
    char* Sport;
    char* Club;
    int Record;
}Sportsman;

typedef struct
{
    Sportsman *person;
    int count;
} SportsmenLib;

void read(const char* filename, SportsmenLib* slib);
void write(SportsmenLib* sLib);
void menu();