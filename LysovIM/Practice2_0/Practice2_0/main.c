#include "matrixx.h"
#include <stdio.h>
int main() {
	TMatrix* matrix_d, * m1, * m2, * res;


	alloc_matrix(&matrix_d, 2);
	scan_matrix(matrix_d);
	print_matrix(matrix_d);
	free_matrix(&matrix_d);

	alloc_matrix(&m1, 3);
	alloc_matrix(&m2, 3);
	scan_matrix(m1);
	scan_matrix(m2);

	res = matrix_add_constant(m1, 2);
	print_matrix(res);
	free_matrix(&res);







	return 0;
}