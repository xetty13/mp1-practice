#pragma once
#include "person.h"
#include <string.h>

typedef struct
{
    Sportsman *person;
    int count;
} SportsmenLib;

void read(const char* filename, SportsmenLib* sLib);
void write(SportsmenLib* sLib);
void menu();