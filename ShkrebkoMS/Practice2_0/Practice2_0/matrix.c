#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>;


void alloc_matrix(TMatrix** matrix, int n)
{
	*matrix = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n;
	(*matrix)->element = (float*)malloc(sizeof(float) * n*n);
}

void fill_matrix(TMatrix* matrix)
{
	int i = 0, j = 0;

	for (; i < matrix->n; i++)
	{
		for (j = 0; j < matrix->n; j++)
		{
			scanf("%f", &(matrix->element[i * matrix->n + j]));
		}
	}
}

void print_matrix(TMatrix* matrix)
{
	int i = 0, j = 0;
	for (; i < matrix->n; i++)
	{
		for (j = 0; j < matrix->n; j++)
		{
			printf("%0.3f ", matrix->element[i * matrix->n + j]);
		}
		printf("\n");
	}
}
void free_matrix(TMatrix** matrix)
{
	free((*matrix)->element);
	free(*matrix);
}

TMatrix* sum_matrix(TMatrix* matrix1, TMatrix* matrix2)
{
	TMatrix* res;
	int i = 0, size = 0;
	if (matrix1->n != matrix2->n)
	{
		printf("ERROR: Matrix should have the same lenght.\n");
		return NULL;
	}
	alloc_matrix(&res, matrix1->n);
	size = res->n * res->n;
	for (; i < size; i++)
	{
		res->element[i] = matrix1->element[i] + matrix2->element[i];
	}
	return res;
}

TMatrix* add_const(TMatrix* matrix, float c)
{
	TMatrix* res;
	int i = 0, size = 0;
	alloc_matrix(&res, matrix->n);
	size = res->n * res->n;
	for (; i < size; i++)
	{
		res->element[i] = matrix->element[i] + c;
	}
	return res;
}

TMatrix* multi_const(TMatrix* matrix, float c)
{
	TMatrix* res;
	int i = 0;
	alloc_matrix(&res, matrix->n);
	int size = res->n * res->n;
	for (; i < size; i++)
	{
		res->element[i] = matrix->element[i] * c;
	}
	return res;
}

TMatrix* multi_matrix(TMatrix* matrix1, TMatrix* matrix2)
{
	TMatrix* res;
	alloc_matrix(&res, matrix1->n);
	int i = 0, j = 0, k = 0;
	if (matrix1->n != matrix2->n)
	{
		printf("ERROR: Matrix should have the same lenght.\n");
		return 1;
	}
	for (; i < matrix1->n; i++)
	{
		for (j = 0; j < matrix1->n; j++)
		{
			res->element[i * matrix1->n + j] = 0;
			for (k = 0; k < matrix1->n; k++)
			{
				res->element[i * matrix1->n + j] += matrix1->element[i * matrix1->n + k] * matrix2->element[k * matrix2->n + j];
			}
		}
	}
	return res;
}