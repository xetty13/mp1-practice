#define _STRUCT_H_
#include <stdio.h>
#include <stdlib.h>

TVector sum(TVector* V1, TVector* V2)
{
    TVector res;
    int i = 0;
    if (V1->n != V2->n)
    {
        printf("V1->n != V2->n");
        res.x = NULL;
        res.n = 0;
        return res;
    }
    allocate(&res, V1->n);
    for (; i < res.n; i++) {
        res.x[i] = V1->x[i] + V2->x[i];
    }
    return res;
}