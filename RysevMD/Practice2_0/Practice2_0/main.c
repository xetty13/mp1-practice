#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
	Matrix *res, *m1, *m2, *res_dt;

	allocate_matrix(&m1, 3);
	fill_matrix(m1, 3);

	allocate_matrix(&m2, 3);
	fill_matrix(m2, 3);
	
	res_dt = add_dot(m1, 5.0f);
	print_matrix(res_dt, 3);
	free_matrix(&res_dt);

	res_dt = multiple_dot(m1, 2.0f);
	print_matrix(res_dt, 3);
	free_matrix(&res_dt);

	res = add_matrix(m1, m2);
	print_matrix(res, 3);
	free_matrix(&res);

	res = multiple_matrix(m1, m2);
	print_matrix(res, 3);
	free_matrix(&res);

	free_matrix(&m1);
	free_matrix(&m2);

	return 0;
}