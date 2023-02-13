#include <stdio.h>
#include "Matrix.h"

void allocate_matrix(Matrix** matr, int size)
{
    (*matr) = (Matrix*)malloc(sizeof(Matrix) * 1);
    (*matr)->size = size;
    (*matr)->arr = (float*)malloc(sizeof(float*) * size*size);
}

void fill_matrix(Matrix* matr)
{
    int i = 0;
    int j = 0;
    for (i=0 ; i < matr->size; i++)
    {

        for (j = 0; j < matr->size; j++) {
            scanf("%f", &(matr->arr[matr->size * i + j]));
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
            printf("%f ", (matr->arr[matr->size * i + j]));
        }
    }
    printf("\n");
}

void free_matrix(Matrix** matr,int size)
{
    free((*matrix)->arr);
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
    for (i=0; i < res->size*res->size; i++)
    {
        for (int j = 0; j < matr1->size; j++) {
            res->arr[i] = matr1->arr[i] + matr2->arr[i]
        }
    }
    return res;
}

 int multi_const(Matrix* matr1, float c)
{
    int i = 0;
    allocate_matrix(&res, matr->size);
    if (matr1->size != matr2->size)
    {
        printf("ERROR: Vectors should have the same lenght.\n");
        return 0;
    }
    for (i=0; i < res->size; i++)
    {
        res->arr[i] = matr->arr[i] * c;
    }
    return res;
}
 Matrix* multi_matrix(Matrix* matr1, Matrix* matr2) {
     Matrix* res;
     int i, j, q;
     allocate_m(&res, matr->size);
     for (i = 0; i < res->size; i++) {
         for (j = 0; j < res->size; j++) {
             res->arr[i * res->size + j] = 0;
             for (q = 0; q < res->size; q++)
                 res->arr[i * res->size + j] += matr1->arr[i * res->size + q] * matr2->x[q * res->size + j];
         }
     }
     return res;
 }


