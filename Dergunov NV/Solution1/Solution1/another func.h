#define _STRUCT_H_
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "struct.h"

void allocate(TVector* V, int n)
{
    V->n = n;
    V->x = (double*)malloc(sizeof(double) * n);
}

void fill(TVector* V)
{
    int i = 0;
    setlocale(LC_ALL, "Ru");
    printf("Заполните вектор: ");
    for (; i < V->n; i++)
    {
        scanf("%lf", &(V->x[i]));
    }
}

void print(TVector* V)
{
    int i = 0;
    setlocale(LC_ALL, "Ru");
    if (V->x != NULL) {
        printf("Вектор: ");
        for (; i < V->n; i++)
        {
            printf("%.2lf ", V->x[i]);
        }
        printf("\n");
    }
}

