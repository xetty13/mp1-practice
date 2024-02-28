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
         for (; i < V->n; i++)
        {
            printf("%.2lf ", V->x[i]);
        }
        printf("\n");
    }
}
void read(TVector* V1, TVector* V2)
{
    int i = 0;
    FILE* f = fopen("vectorIN.txt", "r");
    if (f == NULL) {
        printf("File not found");
        abort();
    }
    fscanf(f, "%d", &V1->n);
    V1->x = (double*)malloc(sizeof(double) * V1->n);
    for (; i < V1->n; i++){
        fscanf(f, "%lf", &V1->x[i]);
    }
    fscanf(f, "%d", &V2->n);
    V2->x = (double*)malloc(sizeof(double) * V2->n);
    for (i = 0; i < V2->n; i++){
        fscanf(f, "%lf", &V2->x[i]);
    }
    fclose(f);
}
void write(TVector* s, TVector* m, double dot)
{
    int i = 0;
    FILE* f = fopen("vectorOUT.txt", "w+");
    if (f == NULL) {
        printf("File not found");
        abort();
    }
    fprintf(f, "Summa = ");
    for (; i < s->n; i++) {
        fprintf(f, "%.2lf ", s->x[i]);
    }
    fprintf(f, "\nMinus = ");
    for (i = 0; i < m->n; i++) {
        fprintf(f, "%.2lf ", m->x[i]);
    }
    fprintf(f, "\n");
    fprintf(f, "Skalyar dot: %lf", dot);
    fclose(f);
    
}