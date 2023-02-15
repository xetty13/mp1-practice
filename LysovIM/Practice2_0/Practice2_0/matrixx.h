
#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
	int n;
	float* x;
} TMatrix;

void matrix_alloc(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);
void scan_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);
TMatrix* matrix_add_matrix(TMatrix* matrix1, TMatrix* matrix2);
TMatrix* matrix_add_constant(TMatrix* matrix, float c);
TMatrix* matrix_multi_constant(TMatrix* matrix, float c);
TMatrix* matrix_multi_matrix(TMatrix* matrix1, TMatrix* matrix2);

#endif
