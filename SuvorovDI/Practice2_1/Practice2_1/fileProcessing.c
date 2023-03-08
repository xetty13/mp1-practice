#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "fileProcessing.h"

int find_num_univ(FILE* fp)
{
    char line[1000];
    int c = 0;
    while (fgets(line, 1000, fp) != NULL)
    {
        c++;
    }
    return c;
}

void alloc_univ(FILE* fp, University_t** uns)
{
    char line[1000];
    int i = 0;

    while (fgets(line, 1000, fp) != NULL)
    {
        int iter;
        strcpy((*uns)[i].name, strtok(line, ";"));
        (*uns)[i].n_spec = atoi(strtok(NULL, ";"));
        (*uns)[i].specs = (Spec_t*)malloc(sizeof(Spec_t) * (*uns)[i].n_spec);

        for (iter = 0; iter < (*uns)[i].n_spec; iter++)
        {
            int j;
            strcpy((*uns)[i].specs[iter].name, strtok(NULL, ";"));
            (*uns)[i].specs[iter].n_form = atoi(strtok(NULL, ";"));

            // default values of all types of educational forms
            int t;
            for (t = 0; t < 3; t++)
            {
                (*uns)[i].specs[iter].form_info[t][0] = -1;
                (*uns)[i].specs[iter].form_info[t][1] = -1;
            }

            for (j = 0; j < (*uns)[i].specs[iter].n_form; j++)
            {
                char type_form[MAX_NAME];
                strcpy(type_form, strtok(NULL, ";"));
                if (!strcmp(type_form, "дневна€"))
                {
                    (*uns)[i].specs[iter].form_info[0][0] = atoi(strtok(NULL, ";"));
                    (*uns)[i].specs[iter].form_info[0][1] = atoi(strtok(NULL, ";"));
                }
                if (!strcmp(type_form, "вечерн€€"))
                {
                    (*uns)[i].specs[iter].form_info[1][0] = atoi(strtok(NULL, ";"));
                    (*uns)[i].specs[iter].form_info[1][1] = atoi(strtok(NULL, ";"));
                }
                if (!strcmp(type_form, "заочна€"))
                {
                    (*uns)[i].specs[iter].form_info[2][0] = atoi(strtok(NULL, ";"));
                    (*uns)[i].specs[iter].form_info[2][1] = atoi(strtok(NULL, ";"));
                }

            }
        }

        i++;
    }
}

void print_all_info(University_t** uns, int c)
{
    int i;
    for (i = 0; i < c; i++)
    {
        int j;
        printf("%s  %d::: \n", (*uns)[i].name, (*uns)[i].n_spec);

        for (j = 0; j < (*uns)[i].n_spec; j++)
        {
            int z;
            printf("   %s  %d:: \n", (*uns)[i].specs[j].name, (*uns)[i].specs[j].n_form);

            for (z = 0; z < 3; z++)
            {
                printf("      %d %d\n", (*uns)[i].specs[j].form_info[z][0], (*uns)[i].specs[j].form_info[z][1]);
            }
        }
    }
}

void free_memory(University_t** uns, int c)
{
    int i;
    for (i = 0; i < c; i++)
    {
        free((*uns)[i].specs);
    }
    free((*uns));
}