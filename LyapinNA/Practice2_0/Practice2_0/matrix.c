#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void allocate_matrix(TMatrix** matrix, int dimension)
{
	(*matrix) = (TMatrix*) malloc(sizeof(TMatrix) * 1);
	(*matrix) -> d = dimension * dimension;
	(*matrix) -> x = (int*) malloc(sizeof(int) * dimension * dimension);
}

void build_matrix(TMatrix* matrix)
{
	int k = 0;
	for (int i = 0; i < matrix->d; i++)
		scanf("%d", &(matrix->x[i]));
}

void print_matrix(TMatrix* matrix, int dimension) 
{
	int k = 0;
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			printf("\t %d", matrix->x[k]);
			k++;
		}
		printf("\n");
	}
	printf("\n");
}

TMatrix* addition(TMatrix* matrix1, TMatrix* matrix2)
{
	TMatrix* result;
	allocate_matrix(&result, matrix1->d);
	for (int i = 0; i < result->d; i++)
		result->x[i] = matrix1->x[i] + matrix2->x[i];

	return result;
}

TMatrix* multiplication(TMatrix* matrix1, TMatrix* matrix2, int dimension) 
{
	int row, column;
	TMatrix* result;
	allocate_matrix(&result, matrix1->d);
	for (int i = 0; i < matrix1->d; i++) {
		result->x[i] = 0;
		if (i >= dimension)
			column = i % dimension;
		else column = i;
		row = i / dimension;

		for (int j = 0; j < dimension; j++)
			result->x[i] += matrix1->x[j + dimension*row] * matrix2->x[column + dimension*j];
	}
	return result;
}

TMatrix* multiplication_const(TMatrix* matrix1, int consta, int dimension) {
	TMatrix* result;
	allocate_matrix(&result, matrix1->d);
	for (int i = 0; i < matrix1->d; i++)
		result->x[i] = matrix1->x[i]*consta;
	return result;
}

void free_m(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}
