#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
	Matrix *matrix, *res_md;

	allocate_matrix(&matrix, 3);
	fill_matrix(matrix, 3);

	res_md = multiple_dot(matrix, 2);
	print_matrix(res_md, 3);
	free_matrix(&res_md);

	free_matrix(&matrix);

	return 0;
}