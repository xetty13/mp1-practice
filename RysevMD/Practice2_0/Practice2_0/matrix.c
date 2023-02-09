#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void allocate_matrix(Matrix** matr, int n) {
	(*matr) = (Matrix*)malloc(sizeof(Matrix) * 1);
	(*matr)->n = n;
	(*matr)->x = (float*)malloc(sizeof(float) * (n * n));
}
void free_matrix(Matrix** matr) {
	free((*matr)->x);
	free(*matr);
}

void fill_matrix(Matrix* matr, int n) {
	int i;
	for (i = 0; i < n * n; i++) {
		scanf("%f", &(matr->x[i * n + i]));
	}
}
void print_matrix(Matrix* matr, int n) {
	int i;
	for (i = 0; i < n * n; i++) {
		printf("%.1f ", matr->x[i * n + i]);
		if ((i + 1) % n == 0) {
			printf("\n");
		}
	}
}

Matrix* multiple_dot(Matrix* matr, float a) {
	Matrix* res;
	int i;
	allocate_matrix(&res, 3);
	for (i = 0; i < (res->n * res->n); i++) {
		res->x[i * res->n + i] = matr->x[i * matr->n + i] * a;
	}
	return res;
}