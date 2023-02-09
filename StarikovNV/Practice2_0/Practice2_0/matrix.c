#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void alloc_matrix(TMatrix** matrix, int n)
{
	(*matrix) = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n;
	(*matrix)->x = (float*)malloc(sizeof(float) * n * n);
}

void free_matrix(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}

void fill_matrix(TMatrix* matrix)
{
	int i, j;
	for (i = 0; i < matrix->n; i++) 
	{
		for (j = 0; j < matrix->n; j++) 
		{
			scanf("%f", &(matrix->x[matrix->n * i + j]));
		}
	}
}

void print_matrix(TMatrix* matrix)
{
	int i = 0, j;
	for (; i < matrix->n; i++) 
	{
		for (j = 0; j < matrix->n; j++) 
		{
			printf("%.3f ", (matrix->x[matrix->n * i + j]));
		}
		printf("\n");
	}
	printf("\n");
}

