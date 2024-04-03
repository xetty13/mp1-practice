#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 128
typedef struct{
    char* Name[LEN];
    char* Surname[LEN];
    char* Gender[LEN];
    char* DateOfBirth[LEN];
    char* Nation[LEN];
    char* Sport[LEN];
    char* Club[LEN];
    int Record;
}info;

void read(const FILE* f, info* n);
void write(info* n);
