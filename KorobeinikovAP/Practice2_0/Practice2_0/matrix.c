#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "matrix.h"

void allocate_m(TMatrix** matrix, int n)
{
	(*matrix) = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n;

	(*matrix)->x = (float*)malloc(sizeof(float) * n*n);

}

void fill_matrix(TMatrix* matrix)
{
	int i,j;
	for (i = 0; i < matrix->n; i++){
		for (j = 0; j < matrix->n; j++) {
			scanf("%f", &(matrix->x[matrix->n*i+j]));
		}
	}
}


void print_matrix(TMatrix* matrix)
{
	int i = 0, j;
	for (; i < matrix->n; i++) {
		for (j = 0; j < matrix->n; j++) {
			printf("%.3f ", (matrix->x[matrix->n*i + j]));
		}
		printf ("\n");
	}
	printf ("\n");
}

void free_matrix(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}



TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2) {
	TMatrix* res;
	int i = 0;
	if (matrix1->n != matrix2->n)
	{
		printf("ERROR: Vectors should have the same lenght.\n");
		return NULL;
	}
	allocate_m(&res, matrix1->n);
	for (; i < res->n*res->n; i++)
	{
		res->x[i] = matrix1->x[i] + matrix2->x[i];
	}
	return res;
}

TMatrix* add_constant(TMatrix* matrix, float c) {
	TMatrix* res;
	int i = 0;
	allocate_m(&res, matrix->n);
	for (; i < res->n*res->n; i++)
	{
		res->x[i] = matrix->x[i] + c;
	}
	return res;
}

TMatrix* multi_constant(TMatrix* matrix, float c) {
	TMatrix* res;
	int i = 0;
	allocate_m(&res, matrix->n);
	for (; i < res->n*res->n; i++)
	{
		res->x[i] = matrix->x[i] * c;
	}
	return res;
}

TMatrix* multi_matrix(TMatrix* matrix, TMatrix* matrix2) {
	TMatrix* res;
	int i,j,k;
	allocate_m(&res, matrix->n);
	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i*res->n + j] = 0;
			for (k = 0; k < res->n; k++)
			   res->x[i* res->n + j] += matrix->x[i*res->n+k]*matrix2->x[k*res->n+j];
		}
	}
	return res;
}
