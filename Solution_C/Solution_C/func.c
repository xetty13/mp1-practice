#include "struct.h"

void menu()
{
    printf("Menu:\n");
    printf("1. Print all athletes\n");
    printf("2. Search athletes by sport\n");
    printf("3. Search athletes for each sport\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void readAthlete(const char* filename, Athlete* a)
{
    int i = 0;
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("file not found");
        abort();
    }
    fgets(&a->fullName, 100, f);
    fgets(&a->gender, 100, f);
    fgets(&a->birthdate, 100, f);
    fgets(&a->nationality, 100, f);
    fgets(&a->origin, 100, f);
    fgets(&a->sport, 100, f);
    fgets(&a->club, 100, f);
    fgets(&a->personalRecord, 1000, f);

    fclose(f);
}

void printAthlete(Athlete* a)
{
    printf("Full name: %s\n", a->fullName);
    printf("Gender: %s\n", a->gender);
    printf("Birthday: %s\n", a->birthdate);
    printf("Nation: %s\n", a->nationality);
    printf("Origin: %s\n", a->origin);
    printf("Sport: %s\n", a->sport);
    printf("Club: %s\n", a->club);
    printf("Personal Record: %s\n", a->personalRecord);
    printf("--------------------------\n");
}