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

void print(SportsmenLib* sLib)
{
    int i = 0;
    for (i = 0; i < sLib->count; i++)
    {
        printf("%d. %s ", i + 1, sLib->person[i].Name);
        printf("%s ", sLib->person[i].Surname);
        if (sLib->person[i].Gend == Male) {
            printf("Male ");
        }
        else if (sLib->person[i].Gend == Female) {
            printf("Female ");
        }
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

int search(SportsmenLib* sLib, char* vid_sporta)
{
    int max = 0;
    int idx = 0;
    int i = 0;
    for (i = 0; i < sLib->count; i++) {
        if (strcmp(sLib->person[i].Sport, vid_sporta) == 0)
        {
            if (sLib->person[i].Record > max)
            {
                idx = i;
                max = sLib->person[i].Record;
            }
        }
    }
    return idx;
}

void print_sport(SportsmenLib* sLib, char* vid_sporta)
{
    int i = 0;
    for (i = 0; i < sLib->count; i++) {
        if (strcmp(sLib->person[i].Sport, vid_sporta) == 0)
        {
            print_record(&sLib->person[i]);
            printf("\n");
        }
    }
}

void free_mem(SportsmenLib* sLib)
{
    int i = 0;
    for (i = 0; i < sLib->count; i++) {
        free(sLib->person[i].Name);
        free(sLib->person[i].Surname);
        free(sLib->person[i].Sport);
        free(sLib->person[i].Nation);
        free(sLib->person[i].Club);
    }
}
