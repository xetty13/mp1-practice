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




#endif
