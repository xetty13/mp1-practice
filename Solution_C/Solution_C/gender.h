#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define Buffer 512
// file: 0 1
// file: MALE FEMALE
typedef enum
{
    MALE = 0,
    FEMALE = 1,
} Gender;

void read_gend(const FILE* f, Gender* g);
