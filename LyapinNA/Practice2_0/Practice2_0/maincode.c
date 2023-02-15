#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void main() {
	TMatrix matrix;
	TMatrix* m1, *m2, *result;
	printf("Enter the number of dimension with Enter\n");
	int dimension;
	do {
		scanf("\t%d", &dimension);
	} while (dimension < 1);
	//выделение памяти
	allocate_matrix(&m1, dimension);
	allocate_matrix(&m2, dimension);
	//заполнение
	printf("\nFill in the first matrix with Enter (line-by-line filling)\n");
	build_matrix(m1);
	print_matrix(m1, dimension);
	printf("\nFill in the second matrix with Enter (line-by-line filling)\n");
	build_matrix(m2); 
	print_matrix(m2, dimension);
	//складывание матриц
	printf("\n\n\nMatrix addition\n");
	result = addition(m1, m2);
	print_matrix(result, dimension);
	free_m(&result);
	//умножение матриц
	printf("\n\n\nMatrix multiplication\n");
	result = multiplication(m1, m2, dimension);
	print_matrix(result, dimension);
	free_m(&result);
	//умножение на const
	printf("\n\n\nMatrix multiplication(const * matrix)\nenter a constant\n");
	int constant;
	scanf("%d", &constant);
	result = multiplication_const(m1, constant, dimension);
	print_matrix(result, dimension);
	free_m(&result);
}