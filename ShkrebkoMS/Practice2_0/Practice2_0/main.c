#include <stdio.h>;
#include "matrix.h";
#include <stdlib.h>;

int main()
{
	TMatrix* matrix_dynamic, *m1, *m2, *res;
	alloc_matrix(&m1, 2);
	alloc_matrix(&m2, 2);
	fill_matrix(m1);
	fill_matrix(m2);
	
	res = sum_matrix(m1,m2);
	print_matrix(res);
	free_matrix(&res);
	
	res = add_const(m1, 2.33);
	print_matrix(res);
	free_matrix(&res);

	res = multi_const(m1, 2.33);
	print_matrix(res);
	free_matrix(&res);

	res = multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);




	free_matrix(&m1);
	free_matrix(&m2);


	return 0;
}