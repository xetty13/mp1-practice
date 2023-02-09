#include "matrix.h"
#include <stdio.h>
int main()
{
	TMatrix* matrix_d, * m1, * m2, * res;

	alloc_matrix(&matrix_d, 2);
	fill_matrix(matrix_d);
	print_matrix(matrix_d);
	free_matrix(&matrix_d);

	alloc_matrix(&m1, 3);
	alloc_matrix(&m2, 3);
	fill_matrix(m1);
	fill_matrix(m2);
}
