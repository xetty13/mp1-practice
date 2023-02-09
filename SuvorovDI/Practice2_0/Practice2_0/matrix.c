#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void alloc_matrix(TMatrix** matrix, int n) {
	int i;
	*matrix = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n;
	(*matrix)->elems = (double**)malloc(sizeof(double*) * n);

	for (i = 0; i < n; i++) {
		(*matrix)->elems[i] = (double*)malloc(sizeof(double) * n);
	}
}

void free_matrix(TMatrix** matrix) {
	int i;
	for (i = 0; i < (*matrix)->n; i++) {
		free((*matrix)->elems[i]);
	}

	free((*matrix)->elems);
	free(*matrix);
}

void fill_matrix(TMatrix* matrix) {
	int i, j;
	for (i = 0; i < matrix->n; i++) {
		for (j = 0; j < matrix->n; j++) {
			scanf("%lf", &(matrix->elems[i][j]));
		}
	}
}

void print_matrix(TMatrix* matrix) {
	int i, j;
	for (i = 0; i < matrix->n; i++) {
		for (j = 0; j < matrix->n; j++) {
			printf("%.3lf  ", matrix->elems[i][j]);
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
			res->elems[i][j] = matrix->elems[i][j] + c;
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
			res->elems[i][j] = matrix->elems[i][j] * c;
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
			res->elems[i][j] = m1->elems[i][j] + m2->elems[i][j];
		}
	}
	return res;
}