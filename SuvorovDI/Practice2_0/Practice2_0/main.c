#include <stdio.h>
#include "matrix.h"

int main() {
	TMatrix* m1, *m2, *res;

	// Creating matrices
	alloc_matrix(&m1, 3);
	alloc_matrix(&m2, 3); 

	// Filling in the matrices
	fill_matrix(m1);
	fill_matrix(m2);

	// Output of matrices
	print_matrix(m1);
	print_matrix(m2);

	// 1. Adding a scalar to the matrix
	res = add_scalar(m1, 3);
	print_matrix(res);
	free_matrix(&res);

	// 2. Multiplication a matrix by a scalar
	res = multi_scalar(m1, 3);
	print_matrix(res);
	free_matrix(&res);

	// 3. Adding a matrix to another matrix
	res = add_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	// 4. Multiplication a matrix to another matrix
	res = multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	return 0;
}