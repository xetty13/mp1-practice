#define _STRUCT_H_
#include <stdio.h>
#include <stdlib.h>

double dot(TVector* V1, TVector* V2)
{
    int i = 0;
    double result = 0.0;
    for (; i < V1->n; i++) {
        result += V1->x[i] * V2->x[i];
    }
    return result;
}
