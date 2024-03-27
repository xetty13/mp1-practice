#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char fullName[100];
    char gender[10];
    char birthdate[10];
    char nationality[100];
    char origin[100];
    char sport[100];
    char club[100];
    float personalRecord;
}Athlete;

void readAthlete(const char* filename, Athlete* a);
void printAthlete(Athlete* a);

