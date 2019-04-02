#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
Vector* Create(int _n)
{
    Vector *a = (Vector*)malloc(sizeof(Vector));
    a->n = _n;
    a->x = (float*)malloc(sizeof(float) * a->n);
    return a;
};
Vector* Add(Vector *a)
{
    int i;
    printf("Enter the coordinates of the vector\n");
    for (i = 0; i < a->n; i++)
    scanf("%f", &(a->x[i]));
    return a;
};
void Print(Vector *a)
{
    int i;
    for (i = 0; i < a->n; i++)
        printf("%f ", a->x[i]);
    printf("\n");
};
void Delete(Vector *a)
{
    free (a->x);
    a->n = 0;

};
Vector* Sum(Vector *a, Vector *b)
{
    int i;
    Vector *c;
    c = Create(a->n);
    if (a->n != b->n)
    {
        printf("Error: different dimension of vectors\n");
        return 0;
    }
    for (i = 0; i < a->n; i++)
        c->x[i] = a->x[i] + b->x[i];
    return c;
};
Vector* Diff(Vector *a, Vector *b)
{
    int i;
    Vector *c;
    c = Create(a->n);
    if (a->n != b->n)
    {
        printf("Error: different dimension of vectors\n");
        return 0;
    }
    for (i = 0; i < a->n; i++)
        c->x[i] = a->x[i] - b->x[i];
    return c;
};
float Scalar(Vector *a, Vector *b)
{
    int i;
    float S = 0;
    if (a->n != b->n)
    {
        printf("Error: different dimension of vectors\n");
        return 0;
    }
    for (i = 0; i < a->n; i++)
        S += a->x[i] * b->x[i];
    return S;
};
float Length(Vector*a)
{
    int i;
    float l = 0;
    for (i = 0; i < a->n; i++)
        l += (a->x[i] * a->x[i]);
    l = (float)sqrt(l);
    return l;
};
float Angle(Vector *a, Vector *b)
{
    float c, l1, l2, A;
    c = Scalar(a,b);
    l1 = Length(a);
    l2 = Length(b);
    if ((l1 == 0) || (l2 == 0))
        return 0;
    A = (float)acos(c / (l1 * l2)); 
    A = (float)(A / 3.14 * 180);
    return A;
};
