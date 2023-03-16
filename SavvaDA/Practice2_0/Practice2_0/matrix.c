#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"


void alloc_matrix(matrix** m, int n)
{
	*m = (matrix*)malloc(1 * sizeof(matrix));
	(*m)->x = (double*)malloc(sizeof(double) * n * n);
	(*m)->n = n;
}

void free_matrix(matrix** m)
{
	free((*m)->x);
	free(*m);
}

void fill_matrix(matrix* m)
{
	int i = 0;
	for (; i < m->n * m->n; i++)
	{
		scanf("%lf", &(m->x[i]));
	}
}

void print_matrix(matrix* m)
{
	int i, j;
	for (i = 0; i < m->n; i++)
	{
		for (j = 0; j < m->n; j++)
			printf("%3.lf ", m->x[i * m->n + j]);
		printf("\n");
	}

}

matrix* add_matrix(matrix* m1, matrix* m2)
{
	if (m1->n != m2->n)
	{
		printf("ERROR: Incorrect vector sizes.\n");
		return NULL;
	}
	matrix* res;
	alloc_matrix(&res, m1->n);
	for (int i = 0; i < m1->n * m1->n; i++)
		res->x[i] = (m1->x)[i] + (m2->x)[i];
	return res;
}

matrix* add_scalar(matrix* m1, double c)
{
	matrix* res;
	alloc_matrix(&res, m1->n);
	for (int i = 0; i < m1->n * m1->n; i++)
		res->x[i] = m1->x[i] + c;
	return res;
}

matrix* multi_matrix(matrix* m1, matrix* m2)
{
	if (m1->n != m2->n)
	{
		printf("ERROR: Incorrect vector sizes.\n");
		return NULL;
	}
	matrix* res;
	alloc_matrix(&res, m1->n);
	int j, l, n = m1->n;
	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			res->x[i * n + j] = 0.0;
			for (l = 0; l < n; l++)
			{
				res->x[i * n + j] += (m1->x[i * n + l]) * (m2->x[l * n + j]);
			}
		}
	}
	return res;
}

matrix* multi_scalar(matrix* m1, double c)
{
	matrix* res;
	alloc_matrix(&res, m1->n);
	for (int i = 0; i < (m1->n) * (m1->n); i++)
		res->x[i] = m1->x[i] * c;
	return res;
}