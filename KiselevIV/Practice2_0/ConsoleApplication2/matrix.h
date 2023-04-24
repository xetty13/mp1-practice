#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
	int n;
	float* x;
} TMatrix;

void alloc_matrix(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);
void scan_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);
TMatrix* matrix_add_const(TMatrix* matrix, float c);
TMatrix* matrix_multiply_const(TMatrix* matrix, float c);
TMatrix* matrixes_multiply(TMatrix* matrix1, TMatrix* matrix2);
#endif