#include <stdlib.h>
#include <stdio.h>
#include "func.h"

void alloc_matrix(SMatrix** matrix, int n)
{
    *matrix = (SMatrix*)malloc(sizeof(SMatrix) * 1);
    (*matrix)->size = n;
    (*matrix)->num = (double**)malloc(sizeof(double*) * n);
    for (int i = 0; i < n; i++) {
        (*matrix)->num[i] = (double*)malloc(sizeof(double) * n);
    }
}
void free_matrix (SMatrix** matrix)
{
    for (int i = 0; i < (*matrix)->size; i++) {
        free((*matrix)->num[i]);
    }
    free((*matrix)->num);
    free(*matrix);
}
void create_matrix (SMatrix* matrix)
{
    for (int i = 0; i < matrix->size; i++){
        for (int j = 0; j < matrix->size; j++) {
            scanf("%lf", &(matrix->num[i][j]));
        }
    }
}
SMatrix* sum_matrix(SMatrix* m1, SMatrix* m2)
{
    SMatrix* res;
    alloc_matrix (&res, m1->size);
    for (int i = 0; i < m1->size; i++){
        for (int j = 0; j < m1->size; j++){
            res->num[i][j] = m1->num[i][j] + m2->num[i][j];
        }
    }
    return res;
}
void print_matrix (SMatrix* matrix)
{
    for (int i = 0; i < matrix->size; i++){
        for (int j = 0; j < matrix->size; j++){
            printf("%.2lf ", matrix->num[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
SMatrix* multiply_matrix(SMatrix* m1, SMatrix* m2)
{
    SMatrix* res;
    alloc_matrix (&res, m1->size);
    for(int i = 0; i < m1->size; i++)
    {
        for(int j = 0; j < m1->size; j++)
        {
            res->num[i][j] = 0;
            for(int g = 0; g < m1->size; g++)
            {
                res->num[i][j] += m1->num[i][g] * m2->num[g][j];
            }
        }
    }
    return res;
}
SMatrix* multiply_matrix_n_scalar(SMatrix* m1, double n)
{
    SMatrix* res;
    alloc_matrix (&res, m1->size);
    for(int i = 0; i < m1->size; i++)
    {
        for(int j = 0; j < m1->size; j++)
        {
            res->num[i][j] = m1->num[i][j] * n;
        }
    }
    return res;
}
SMatrix* sum_matrix_n_scalar(SMatrix* m1, double n)
{
    SMatrix* res;
    alloc_matrix (&res, m1->size);
    for(int i = 0; i < m1->size; i++)
    {
        for(int j = 0; j < m1->size; j++)
        {
            res->num[i][j] = m1->num[i][j] + n;
        }
    }
    return res;
}

