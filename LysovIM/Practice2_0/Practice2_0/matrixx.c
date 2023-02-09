#include "matrixx.h"
#include <stdio.h>


void alloc_matrix(TMatrix** matrix, int n)
{
	(*matrix) = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n;

	(*matrix)->x = (float*)malloc(sizeof(float) * n * n);

}

void scan_matrix(TMatrix* matrix)
{
	int i;
	int j;
	for (i = 0; i < matrix->n; i++) {
		for (j = 0; j < matrix->n; j++) {
			scanf("%f", &(matrix->x[matrix->n * i + j]));
		}
	}
}


void print_matrix(TMatrix* matrix)
{
	int i = 0;
	int j;
	for (; i < matrix->n; i++) {
		for (j = 0; j < matrix->n; j++) {
			printf("%.3f ", (matrix->x[matrix->n * i + j]));
		}
		printf("\n");
	}
	printf("\n");
}

void free_matrix(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}
TMatrix* manrix_add_constant(TMatrix* matrix, float c) {
	TMatrix* res;
	int i = 0;
	allocate_m(&res, matrix->n);
	for (; i < res->n * res->n; i++)
	{
		res->x[i] = matrix->x[i] + c;
	}
	return res;
}