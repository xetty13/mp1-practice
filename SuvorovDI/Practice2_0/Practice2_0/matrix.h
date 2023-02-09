#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
    int n;
    double** elems;
} TMatrix;

void alloc_matrix(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);

void fill_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);

TMatrix* add_scalar(TMatrix* matrix, double c);
TMatrix* multi_scalar(TMatrix* matrix, double c);

TMatrix* add_matrix(TMatrix* v1, TMatrix* v2);

#endif