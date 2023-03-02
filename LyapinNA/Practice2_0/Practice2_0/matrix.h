#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float* x;
	int d;
} TMatrix;

void allocate_matrix(TMatrix** matrix, int d); 
void build_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix, int dimension);
TMatrix* addition(TMatrix* matrix1, TMatrix* matrix2, int dimension);
TMatrix* multiplication(TMatrix* matrix1, TMatrix* matrix2, int dimension);
TMatrix* multiplication_const(TMatrix* matrix1, int consta, int dimension);
void free_m(TMatrix** matrix);