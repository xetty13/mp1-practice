#include "Person.h"
#include "SportsmenLib.h"
void readPerson(const FILE* f, Sportsman* n)
{
    n->Name = (char*)malloc(sizeof(char) * Buffer);
    n->Surname = (char*)malloc(sizeof(char) * Buffer);
    n->Nation = ((char*)malloc(sizeof(char) * Buffer));
    n->Sport = ((char*)malloc(sizeof(char) * Buffer));
    n->Club = ((char*)malloc(sizeof(char) * Buffer));
    char* str[Buffer];
    if (fgets(str, Buffer, f) != NULL)
    {
        fscanf(f, "%s", n->Name);
        fscanf(f, "%s", n->Surname);
        read_gend(f, &n->Gend);
        read_date(f, &n->DateBirth);
        fscanf(f, "%s", n->Nation);
        fscanf(f, "%s", n->Sport);
        fscanf(f, "%s", n->Club);
        fscanf(f, "%d", &n->Record);
    }
}
void write_sport(Sportsman* n)
{
    printf("%s ", n->Name);
    printf("%s ", n->Surname);
    if (n->Gend == 0) {
        printf("Male ");
    }
    else if (n->Gend == 1) {
        printf("Female ");
    }
    if (n->DateBirth.day < 10) {
        printf("0%d.", n->DateBirth.day);
    }
    if (n->DateBirth.month < 10)
    {
        printf("0%d.", n->DateBirth.month);
    }
    else {
        printf("%d.", n->DateBirth.month);
    };
    printf("%d ", n->DateBirth.year);
    printf("%s ", n->Nation);
    printf("%s ", n->Sport);
    printf("%s ", n->Club);
    printf("%d ", n->Record);
}

