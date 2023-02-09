#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "matrix.h"

int main() {
	TMatrix* matrix_d, *m1, *m2, *res;


	allocate_m(&matrix_d, 2);
	fill_matrix(matrix_d);
	print_matrix(matrix_d);
	free_matrix(&matrix_d);
	

	allocate_m(&m1, 3);
	allocate_m(&m2, 3);
	fill_matrix(m1);
	fill_matrix(m2);

	
	res = add_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	

	
	res = add_constant(m1, 2);
	print_matrix(res);
	free_matrix(&res);

	res = multi_constant(m1, 2);
	print_matrix(res);
	free_matrix(&res);
	

	res = multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);


	return 0;
}
