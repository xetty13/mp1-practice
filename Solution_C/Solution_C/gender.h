#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define Buffer 512
#include "Person.h"

typedef enum
{
    Male = 0,
    Female = 1,
} Gender;
void read_gend(const FILE* f, Gender* g);
