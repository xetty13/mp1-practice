#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
	int i,j,n;
	Matrix *matrix_dynamic, *m1,*m2,*res;
	
	allocate_matrix(&matrix_dynamic, 2);
	fill_matrix(matrix_dynamic);
	print_matrix(matrix_dynamic);
	free_matrix(&matrix_dynamic);
	
	allocate_matrix(&m1, 2);
	allocate_matrix(&m2, 2);

	fill_matrix(m1);
	fill_matrix(m2);
	printf("\n");

	res = addition_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	printf("\n");

	res = addition_const(m1, 5.2f);
	print_matrix(res);
	free_matrix(&res);
	printf("\n");

	res = multi_const(m1, 3.4f);
	print_matrix(res);
	free_matrix(&res);
	printf("\n");

	res = multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);
	free_matrix(&m1);
	free_matrix(&m2);
	return 0;
}