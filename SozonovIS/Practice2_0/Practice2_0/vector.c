#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void alloc_vector(TVector** vector, int n)
{
    *vector = (TVector*)malloc(sizeof(TVector) * 1);
    (*vector)->n = n;
    (*vector)->x = (double*)malloc(sizeof(double) * n);
}

void free_vector(TVector** vector)
{
    free((*vector)->x);
    free(*vector);
}

void fill_vector(TVector* vector)
{
    int i = 0;
    for (; i < vector->n; i++)
    {
        scanf("%lf", &(vector->x[i]));
    }
}

void print_vector(TVector* vector)
{
    int i = 0;
    for (; i < vector->n; i++)
    {
        printf("%.3lf ", vector->x[i]);
    }
    printf("\n");
}

TVector* add_vector(TVector* v1, TVector* v2)
{
    TVector* res;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("ERROR: Incorrect vector sizes.\n");
        return NULL;
    }
    alloc_vector(&res, v1->n);
    for (; i < res->n; i++)
    {
        res->x[i] = v1->x[i] + v2->x[i];
    }
    return res;
}

TVector* add_scalar(TVector* vector, double c)
{
    TVector* res;
    int i = 0;
    alloc_vector(&res, vector->n);
    for (; i < res->n; i++)
    {
        res->x[i] = vector->x[i] + c;
    }
    return res;
}

double multi_vector(TVector* v1, TVector* v2)
{
    double res = 0.0;
    int i = 0;
    if (v1->n != v2->n)
    {
        printf("ERROR: Incorrect vector sizes.\n");
        return 0.0;
    }
    for (; i < v1->n; i++)
    {
        res += v1->x[i] * v2->x[i];
    }
    return res;
}

TVector* multi_scalar(TVector* vector, double c)
{
    TVector* res;
    int i = 0;
    alloc_vector(&res, vector->n);
    for (; i < res->n; i++)
    {
        res->x[i] = vector->x[i] * c;
    }
    return res;
}
