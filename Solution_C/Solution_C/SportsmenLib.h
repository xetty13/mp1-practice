#pragma once
#include "person.h"
#include <string.h>

typedef struct
{
    Sportsman *person;
    int count;
} SportsmenLib;

void read(const char* filename, SportsmenLib* sLib);
int search(SportsmenLib* sLib, char* vid_sporta);
void print(SportsmenLib* sLib);
void print_sport(SportsmenLib* sLib, char* vid_sporta);
void free_mem(SportsmenLib* sLib);