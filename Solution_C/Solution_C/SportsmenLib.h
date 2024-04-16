#pragma once
#include "person.h"
#include <string.h>

typedef struct
{
    Sportsman *person;
    int count;
} SportsmenLib;

void read(const char* filename, SportsmenLib* sLib);
int sort(SportsmenLib* sLib, char* vid_sporta);
void write(SportsmenLib* sLib);
void without_sort(SportsmenLib* sLib, char* vid_sporta);
void free_mem(SportsmenLib* sLib);