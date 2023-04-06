#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"

void allocate_matrix(TMatrix** matrix, int dimension)
{
	(*matrix) = (TMatrix*) malloc(sizeof(TMatrix) * 1);
	(*matrix) -> d = dimension * dimension;
	(*matrix) -> x = (float*) malloc(sizeof(float) * dimension * dimension);
}

void build_matrix(TMatrix* matrix)
{
	int k = 0;
	for (int i = 0; i < matrix->d; i++)
		scanf("%f", &(matrix->x[i]));
}

void print_matrix(TMatrix* matrix, int dimension) 
{
	int k = 0;
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			printf("\t %f", matrix->x[k]);
			k++;
		}
		printf("\n");
	}
	printf("\n");
}

TMatrix* addition(TMatrix* matrix1, TMatrix* matrix2, int dimension)
{	
	TMatrix* result;
	if (matrix1->d != matrix2->d)
		return NULL;
	allocate_matrix(&result, (matrix1->d) / dimension);
	for (int i = 0; i < result->d; i++)
		result->x[i] = matrix1->x[i] + matrix2->x[i];

	return result;
}

TMatrix* multiplication(TMatrix* matrix1, TMatrix* matrix2, int dimension) 
{
	TMatrix* result;
	int  k = 0, i = 0, j = 0;
	if (matrix1->d != matrix2->d)
		return NULL;
	allocate_matrix(&result, (matrix1->d) / dimension);
	for (i = 0; i < dimension; i++)
	{
		for (j = 0; j < dimension; j++)
		{
			result->x[i * dimension + j] = 0;
			for (k = 0; k < dimension; k++)
			{
				result->x[i * dimension + j] += matrix1->x[i * dimension + k] * matrix2->x[k * dimension + j];
			}
		}
	}
	return result;
}

TMatrix* multiplication_const(TMatrix* matrix1, int consta, int dimension) {
	TMatrix* result;
	allocate_matrix(&result, (matrix1->d) / dimension);
	for (int i = 0; i < matrix1->d; i++)
		result->x[i] = matrix1->x[i]*consta;
	return result;
}

void free_m(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}
