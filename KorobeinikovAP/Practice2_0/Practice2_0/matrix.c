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
	int i = 0, j;
	for (; i < matrix->n; i++){
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
