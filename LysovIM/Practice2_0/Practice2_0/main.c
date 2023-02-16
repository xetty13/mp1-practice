
#include <stdio.h>
#include "matrixx.h"
#include <stdio.h>
int main() {
	TMatrix* matrix_dynamic, * m1, * m2, * res;


	matrix_alloc(&matrix_dynamic, 2);
	scan_matrix(matrix_dynamic);
	print_matrix(matrix_dynamic);
	free_matrix(&matrix_dynamic);

	matrix_alloc(&m1, 3);
	matrix_alloc(&m2, 3);
	scan_matrix(m1);
	printf("Your Matrix 1\n");
	print_matrix(m1);
	scan_matrix(m2);
	printf("Your Matrix 2\n");
	print_matrix(m2);

	printf("Matrix 1 + Matrix 2\n");
	res = matrix_add_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	printf("Matrix 1 * Constant(100)\n");
	res = matrix_multi_constant(m1, 100);
	print_matrix(res);
	free_matrix(&res);

	printf("Matrix 1 + Constnt(1000)\n");
	res = matrix_add_constant(m1, 1000);
	print_matrix(res);
	free_matrix(&res);

	printf("Matrix 1 * Matrix 2\n");
	res = matrix_multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	free_matrix(&m1);
	free_matrix(&m2);
	return 0;
}