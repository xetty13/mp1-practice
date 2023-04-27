// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"


int main()
{
	TMatrix* matrix_d, *m1, *m2, *res, *size;

	size_matrix(& size);
	alloc_matrix(&matrix_d,size);//vyvod
	scan_matrix(matrix_d);
	print_matrix(matrix_d);
	free_matrix(&matrix_d);

	alloc_matrix(&m1, size);//scan m1,m2
	alloc_matrix(&m2, size);
	scan_matrix(m1);
	scan_matrix(m2);

	res = matrix_add_const(m1, 2);//add 
	print_matrix(res);
	free_matrix(&res);
	
	res = matrix_multiply_const(m1, 2);//multiply c.
	print_matrix(res);
	free_matrix(&res);
	
	res = matrixes_multiply(m1, m2);//multiply m.
	print_matrix(res);
	free_matrix(&res);

	free(&m1);
	free(&m2);



	return 0;
}
