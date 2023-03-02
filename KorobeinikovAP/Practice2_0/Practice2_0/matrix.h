#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
	int n;
	float* x;	
} TMatrix;

void allocate_m(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);


void fill_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);

TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2);
TMatrix* add_constant(TMatrix* matrix, float c);
TMatrix* multi_constant(TMatrix* matrix, float c);
TMatrix* multi_matrix(TMatrix* matrix1, TMatrix* matrix2);

#endif