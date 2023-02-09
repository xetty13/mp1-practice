#ifndef _VECTOR_H
#define _VECTOR_H

typedef struct
{
    int n;
    double* x;
} TVector;

void alloc_vector(TVector** vector, int n);
void free_vector(TVector** vector);

void fill_vector(TVector* vector);
void print_vector(TVector* vector);

TVector* add_vector(TVector* v1, TVector* v2);
TVector* add_scalar(TVector* vector, double c);

double multi_vector(TVector* v1, TVector* v2);
TVector* multi_scalar(TVector* vector, double c);

#endif // !_VECTOR_H

