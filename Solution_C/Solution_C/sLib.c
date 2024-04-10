#include "SportsmenLib.h"
void read(const char* filename, SportsmenLib* sLib)
{
    int i = 0;
    FILE* f = fopen(filename, "r");
    fscanf(f, "%d", &sLib->count);
    if (f == NULL)
    {
        printf("Îøèáêà â Read");
        abort();
    }
    if (sLib->count <= 0)
    {
        sLib->person = NULL;
    }
    sLib->person = (Sportsman*)malloc(sizeof(Sportsman) * sLib->count);
    for (i = 0; i < sLib->count; i++) {
        readPerson(f, &sLib->person[i]);
    }
    fclose(f);
}

void write(SportsmenLib* sLib)
{
    int i = 0;
    for (i = 0; i < sLib->count; i++)
    {
        printf("%d. %s ", i + 1, sLib->person[i].Name);
        printf("%s ", sLib->person[i].Surname);
        printf("%s ", sLib->person[i].Gend.gender);
        printf("%d.", sLib->person[i].DateBirth.day);
        if (sLib->person[i].DateBirth.month < 10)
        {
            printf("0%d.", sLib->person[i].DateBirth.month);
        }
        else {
            printf("%d.", sLib->person[i].DateBirth.month);
        };
        printf("%d ", sLib->person[i].DateBirth.year);
        printf("%s ", sLib->person[i].Nation);
        printf("%s ", sLib->person[i].Sport);
        printf("%s ", sLib->person[i].Club);
        printf("%d ", sLib->person[i].Record);
        printf("\n");
    }
}