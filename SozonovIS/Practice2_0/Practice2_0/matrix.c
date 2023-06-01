#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void alloc_matrix(TMatrix** matrix, int n) {
	int i;
	*matrix = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n;
	(*matrix)->x = (double**)malloc(sizeof(double*) * n);

	for (i = 0; i < n; i++) {
		(*matrix)->x[i] = (double*)malloc(sizeof(double) * n);
	}
}

void free_matrix(TMatrix** matrix) {
	int i;
	for (i = 0; i < (*matrix)->n; i++) {
		free((*matrix)->x[i]);
	}

	free((*matrix)->x);
	free(*matrix);
}

void fill_matrix(TMatrix* matrix) {
	int i, j;
	for (i = 0; i < matrix->n; i++) {
		for (j = 0; j < matrix->n; j++) {
			scanf("%lf", &(matrix->x[i][j]));
		}
	}
	printf("\n");
}

void print_matrix(TMatrix* matrix) {
	int i, j;
	for (i = 0; i < matrix->n; i++) {
		for (j = 0; j < matrix->n; j++) {
			printf("%.3lf  ", matrix->x[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

TMatrix* add_scalar(TMatrix* matrix, double c) {
	TMatrix* res;
	int i, j;

	alloc_matrix(&res, matrix->n);

	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i][j] = matrix->x[i][j] + c;
		}
	}
	return res;
}

TMatrix* multi_scalar(TMatrix* matrix, double c) {
	TMatrix* res;
	int i, j;

	alloc_matrix(&res, matrix->n);

	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i][j] = matrix->x[i][j] * c;
		}
	}
	return res;
}

TMatrix* add_matrix(TMatrix* m1, TMatrix* m2) {
	TMatrix* res;
	int i, j;

	if (m1->n != m2->n)
	{
		printf("ERROR: Incorrect vector sizes.\n");
		return NULL;
	}

	alloc_matrix(&res, m1->n);

	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i][j] = m1->x[i][j] + m2->x[i][j];
		}
	}
	return res;
}

TMatrix* multi_matrix(TMatrix* m1, TMatrix* m2) {
	TMatrix* res;
	int i, j, k;

	if (m1->n != m2->n)
	{
		printf("ERROR: Incorrect vector sizes.\n");
		return NULL;
	}

	alloc_matrix(&res, m1->n);

	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i][j] = 0;
			for (k = 0; k < res->n; k++) {
				res->x[i][j] += m1->x[i][k] * m2->x[k][j];
			}
		}
	}
	return res;
}
