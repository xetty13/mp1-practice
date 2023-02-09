#include <stdio.h>
#include "Matrix.h"

void allocate_matrix(Matrix** matr, int size)
{
    (*matr) = (Matrix*)malloc(sizeof(Matrix) * 1);
    (*matr)->size = size;
    (*matr)->arrays[N] = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        (*matr)->arrays[i] = (int*)malloc(sizeof(int) * size);
    }
}

void fill_matrix(Matrix* matr)
{
    int i = 0;
    int j = 0;
    for (i=0 ; i < matr->size; i++)
    {

        for (j = 0; j < matr->size; j++) {
            matr->arrays[i] = scanf("%d", &(matr->*(arrays[j])));
        }
    }
}

void print_matrix(Matrix* matr)
{
    int i = 0;
    int j = 0;
    for (i=0; i < matr->size; i++)
    {
        for (j = 0; j < matr->size; j++) {
            printf("%d", matr->*(arrays[j]));
        }
    }
    printf("\n");
}

void free_matrix(Matrix** matr,int size)
{
    for (int i = 0; i < size; i++) {
        free((*matr)->arrays[i]);
    }
    free(*matr);
}

Matrix* add_matrix(Matrix* matr1, Matrix* matr2)
{
    Matrix* res;
    int i = 0;
    if (matr1->size != matr1->size)
    {
        printf("ERROR: Vectors should have the same lenght.\n");
        return NULL;
    }
    allocate_matrix(&res, matr1->size);
    for (i=0; i < res->size; i++)
    {
        for (int j = 0; j < matr1->size; j++) {
            res->[i] = matr1->*(arrays[j]) + matr2->*(arrays[j]);
        }
    }
    return res;
}

 int multi_vector(Matrix* matr1, Matrix* matr2)
{
    int res = 0;
    int i = 0;
    if (matr1->size != matr2->size)
    {
        printf("ERROR: Vectors should have the same lenght.\n");
        return 0;
    }
    for (i=0; i < res->size; i++)
    {
        res+= matr1->[i] * matr2->x[i];
    }
    return res;
}


