#include <stdio.h>
#include <stdlib.h>;
#include "matrix.h"

int main() {
	int i, j;
	TMatrix matrix;
	TMatrix* matrix_dynamic, * m1, * m2, * res;

	/*
	matrix.n = 2;
	matrix.x = (float*)malloc(sizeof(float) * matrix.n * matrix.n);
	for (i = 0; i < matrix.n; i++) {
		for (j = 0; j < matrix.n; j++) {
			scanf("%f", &(matrix.x[i * matrix.n + j]));
		}
	}
	for (i = 0; i < matrix.n; i++) {
		for (j = 0; j < matrix.n; j++) {
			printf("%.3f ", matrix.x[i * matrix.n + j]);
		}
		printf("\n");
	}
	free(matrix.x);
	*/

	/*
	allocate_matrix(&matrix_dynamic, 3);
	fill_matrix(matrix_dynamic);
	print_matrix(matrix_dynamic);
	free_matrix(&matrix_dynamic);
	*/

	int		  n = 3;
	float	add = 5.5f;
	float multi = 2.0f;

	allocate_matrix(&m1, n);
	allocate_matrix(&m2, n);
	fill_matrix(m1); // 1 2 3 4 5 6 7 8 9
	fill_matrix(m2); // 9 8 7 6 5 4 3 2 1
	print_matrix(m1);
	print_matrix(m2);

	printf("add_matrix:\n");
	res = add_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	printf("add_const:\n");
	res = add_const(m1, add);
	print_matrix(res);
	free_matrix(&res);

	printf("multi_matrix:\n");
	res = multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	printf("multi_const:\n");
	res = multi_const(m1, multi);
	print_matrix(res);
	free_matrix(&res);

	free_matrix(&m1);
	free_matrix(&m2);


	return 0;
}