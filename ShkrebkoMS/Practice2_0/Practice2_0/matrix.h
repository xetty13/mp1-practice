#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
	int n;
	float* element;
}TMatrix;
void alloc_matrix(TMatrix** matrix, int n);
void fill_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);
void free_matrix(TMatrix** matrix);
TMatrix*sum_matrix(TMatrix* matrix1, TMatrix* matrix2);
TMatrix* add_const(TMatrix* matrix, float c);
TMatrix* multi_const(TMatrix* matrix, float c);
TMatrix* multi_matrix(TMatrix* matrix1, TMatrix* matrix2);


#endif _MATRIX_H
