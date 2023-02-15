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
		scanf("%f", &(matr->x[i]));
	}
}
void print_matrix(Matrix* matr, int n) {
	int i;
	for (i = 0; i < n * n; i++) {
		printf("%.1f ", matr->x[i]);
		if ((i + 1) % n == 0) {
			printf("\n  ");
		}
	}
	printf("\n");
}

Matrix* add_dot(Matrix* matr, float a){
	printf("\nadd dot:\n\n  ");
	Matrix* res;
	int i;
	allocate_matrix(&res, 3);
	int n = res->n;
	for (i = 0; i < n * n; i++) {
		res->x[i] = (matr->x[i]) + a;
	}
	return res;
}
Matrix* multiple_dot(Matrix* matr, float a) {
	printf("multiple dot:\n\n  ");
	Matrix* res;
	int i;
	allocate_matrix(&res, 3);
	int n = res->n;
	for (i = 0; i < n * n; i++) {
		res->x[i] = (matr->x[i]) * a;
	}
	return res;
}
Matrix* add_matrix(Matrix* matr1, Matrix* matr2) {
	printf("add matrix:\n\n  ");
	Matrix* res;
	int i, j;
	if (matr1->n != matr2->n) {
		printf("matrices must be of the same order");
		return NULL;
	}
	allocate_matrix(&res, 3);
	int n = res->n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			res->x[i * n + j] = (matr1->x[i * n + j]) + (matr2->x[i * n + j]);
		}
	}
	return res;
}
Matrix* multiple_matrix(Matrix* matr1, Matrix* matr2) {
	printf("multiple_matrix:\n\n  ");
	Matrix* res;
	int i, j, k;
	if (matr1->n != matr2->n) {
		printf("matrices must be of the same order");
		return NULL;
	}
	allocate_matrix(&res, matr1->n);
	for (k = 0; k < (res->n) * (res->n); k++) {
		res->x[k] = 0.0f;
	}
	for (k = 0; k < res->n; k++) {
		for (i = 0; i < res->n; i++) {
			for (j = 0; j < res->n; j++) {
				res->x[k * res->n + i] += matr1->x[k * res->n + j] * matr2->x[j * res->n + i];
			}
		}
	}
	return res;
}