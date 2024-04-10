#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define Buffer 512
typedef struct
{
    char* gender;
}Gender;

void read_gend(const FILE* f, Gender* g);
