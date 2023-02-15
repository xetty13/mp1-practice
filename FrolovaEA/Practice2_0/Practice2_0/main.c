#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
	int i, j;
	TMatrix* m1, * m2, * res;

	allocate_matrix(&m1, 2);
	allocate_matrix(&m2, 2);

	fill_matrix(m1);
	fill_matrix(m2);
	/*
	res = addition_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	free_matrix(&m1);
	*/

	/*
	res = addition_const(m1, 5.2f);
	print_matrix(res);
	free_matrix(&res);
	free_matrix(&m1);

	res = multi_const(m1, 3.4f);
	print_matrix(res);
	free_matrix(&res);
	free_matrix(&m1);
	*/

	res = multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	free_matrix(&m1);
	free_matrix(&m2);

	return 0;
}