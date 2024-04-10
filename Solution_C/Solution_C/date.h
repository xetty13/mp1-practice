#pragma once
#include <stdlib.h>
#include <stdio.h>
#include<locale.h>
typedef struct
{
    int day;
    int month;
    int year;
}Date;

void read_date(const FILE* f, Date* d);