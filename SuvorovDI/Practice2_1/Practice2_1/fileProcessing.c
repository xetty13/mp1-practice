#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "fileProcessing.h"

int find_num_univ(char fname[])
{
    char line[MAX_LINE_LEN];
    int c = 0;

    FILE* fp;
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("No such file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, fp) != NULL)
    {
        c++;
    }
    fclose(fp);

    return c;
}

University_t* fill_univ(char fname[], int c)
{
    char line[1000];
    int i = 0;
    University_t* uns = (University_t*)malloc(sizeof(University_t) * c);

    FILE* fp;
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("No such file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, fp) != NULL)
    {
        int iter;
        strcpy(uns[i].name, strtok(line, ";"));
        uns[i].n_spec = atoi(strtok(NULL, ";"));
        uns[i].specs = (Spec_t*)malloc(sizeof(Spec_t) * uns[i].n_spec);

        for (iter = 0; iter < uns[i].n_spec; iter++)
        {
            int j;
            strcpy(uns[i].specs[iter].name, strtok(NULL, ";"));
            uns[i].specs[iter].n_form = atoi(strtok(NULL, ";"));

            uns[i].specs[iter].forms = (EducationalForm*)malloc(uns[i].specs[iter].n_form * sizeof(EducationalForm));
            uns[i].specs[iter].costs = (int*)malloc(uns[i].specs[iter].n_form * sizeof(int));
            uns[i].specs[iter].examScores = (int*)malloc(uns[i].specs[iter].n_form * sizeof(int));

            for (j = 0; j < uns[i].specs[iter].n_form; j++)
            {
                char type_form[MAX_NAME];
                strcpy(type_form, strtok(NULL, ";"));
                if (!strcmp(type_form, "дневна€"))
                {
                    uns[i].specs[iter].forms[j] = DNEV;
                    uns[i].specs[iter].examScores[j] = atoi(strtok(NULL, ";"));
                    uns[i].specs[iter].costs[j] = atoi(strtok(NULL, ";"));
                }
                if (!strcmp(type_form, "вечерн€€"))
                {
                    uns[i].specs[iter].forms[j] = VECHER;
                    uns[i].specs[iter].examScores[j] = atoi(strtok(NULL, ";"));
                    uns[i].specs[iter].costs[j] = atoi(strtok(NULL, ";"));
                }
                if (!strcmp(type_form, "заочна€"))
                {
                    uns[i].specs[iter].forms[j] = ZAOCH;
                    uns[i].specs[iter].examScores[j] = atoi(strtok(NULL, ";"));
                    uns[i].specs[iter].costs[j] = atoi(strtok(NULL, ";"));
                }

            }
        }

        i++;
    }

    return uns;

    fclose(fp);
}

void free_memory(University_t* uns, int c)
{
    int i, j;
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < uns[i].n_spec; j++)
        {
            free(uns[i].specs[j].forms);
            free(uns[i].specs[j].examScores);
            free(uns[i].specs[j].costs);
        }
        free(uns[i].specs);
    }
    free(uns);
}