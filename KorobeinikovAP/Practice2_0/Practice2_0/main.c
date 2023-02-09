#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "matrix.h"

int main() {
	TMatrix* matrix_d, *m1, *m2;



	allocate_m(&matrix_d, 2);
	fill_matrix(matrix_d);
	print_matrix(matrix_d);
	free_matrix(&matrix_d);
	
	allocate_m(&m1, 2);
	allocate_m(&m2, 2);
	fill_matrix(m2);
	fill_matrix(m1);




	return 0;
}
