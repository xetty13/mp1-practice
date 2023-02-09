#define _CRT_SECURE_NO_WARNINGS
#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
	int n;
	float* x;	
} TMatrix;

void allocate_m(TMatrix** matrix, int n);
void fill_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);
void free_matrix(TMatrix** matrix);



#endif