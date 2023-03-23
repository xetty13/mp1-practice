#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int main() {
	int n;
	double c1=5, c2=5;
	matrix* m;
	printf("Vvedite razmer kvadratnoy matrizi\n");
	scanf("%d", &n);

	alloc_matrix(&m, n);
	fill_matrix(m);
	print_matrix(m);

	matrix* m1 = multi_scalar(m, c1);
	printf("Ymhojenie matrizi na %.3lf\n", c1);
	print_matrix(m1);
	
	matrix* m2 = add_scalar(m, c2);
	printf("Slojinie matrizi i %.3lf\n", c2);
	print_matrix(m2);
	
	matrix* m3 = multi_matrix(m1, m2);
	printf("Proizvedenie m1 i m2:\n");
	print_matrix(m3);
	
	matrix* m4 = add_matrix(m1, m2);
	if (m4)
	{
		printf("Summa m1 i m2\n");
		print_matrix(m4);
	}
	/*free_matrix(&m1);*/
	//free_matrix(&m2);
	//free_matrix(&m3);
	//free_matrix(&m4);
	//free_matrix(&m);
	return 0;
}