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
Matrix* add_matrix(Matrix* matr1, Matrix* matr2) {
	Matrix* res;
	int i;
	if (matr1->n != matr2->n) {
		printf("matrices must be of the same order");
		return NULL;
	}
	allocate_matrix(&res, 3);
	for (i = 0; i < res->n * res->n; i++) {
		res->x[i * res->n + i] = matr1->x[i * matr1->n + i] + matr2->x[i * matr2->n + i];
	}
	return res;
}
Matrix* multiple_matrix(Matrix* matr1, Matrix* matr2) {
	Matrix* res;
	int i, j, k;
	if (matr1->n != matr2->n) {
		printf("matrices must be of the same order");
		return NULL;
	}
	allocate_matrix(&res, matr1->n);
	for (i = 0; i < matr1->n; i++) {
		res->x[i * res->n + i] = 0.0f;
		for (j = 0; j < matr1->n; j++) {
			for (k = 0; k < matr2->n; k++) {
				res->x[i * res->n + j] += matr1->x[i * res->n + k] * matr2->x[k * res->n + j];
			}
		}
	}
	return res;
}