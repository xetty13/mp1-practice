#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void allocate_matrix(Matrix** matrix, int n)
{
    (*matrix) = (Matrix*)malloc(sizeof(Matrix) * 1);
    (*matrix)->n = n;
    (*matrix)->x = (float*)malloc(sizeof(float) * n * n);
}

void fill_matrix(Matrix* matrix)
{
    int i, j;
    for (i = 0; i < matrix->n; i++)
        for (j = 0; j < matrix->n; j++)
            scanf("%f", &(matrix->x[i * matrix->n + j]));
}

void print_matrix(Matrix* matrix)
{
    int i, j;
    for (i = 0; i < matrix->n; i++)
    {
        for (j = 0; j < matrix->n; j++)
            printf("%.1f ", matrix->x[i * matrix->n + j]);

        printf("\n");
    }
}

void free_matrix(Matrix** matrix)
{
    free((*matrix)->x);
    free(*matrix);
}

Matrix* addition_matrix(Matrix* matrix1, Matrix* matrix2)
{
    Matrix* res;
    int i, j;
    if (matrix1->n != matrix2->n)
    {
        printf("ERROR: Vectors should have the same lenght.\n");
        return NULL;
    }
    allocate_matrix(&res, matrix1->n);
    for (i = 0; i < res->n; i++)
        for (j = 0; j < res->n; j++)
            res->x[i * res->n + j] = matrix1->x[i * res->n + j] + matrix2->x[i * res->n + j];

    return res;
}








}