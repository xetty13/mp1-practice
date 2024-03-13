#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n;
    double* x;
} TVector;

void allocate(TVector* V, int n);
void fill(TVector* V);
void print(TVector* V);
void read(const char* infilename, TVector* V1, TVector* V2);
void write(const char* outfilename, TVector* s, TVector* m, double dot);
TVector minus(TVector* V1, TVector* V2);
TVector sum(TVector* V1, TVector* V2);
double dot(TVector* V1, TVector* V2);

#endif // !VECTOR_H