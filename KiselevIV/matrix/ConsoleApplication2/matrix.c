#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

void alloc_matrix(TMatrix** matrix, int n)
{
	(*matrix) = (TMatrix*)malloc(sizeof(TMatrix));
	(*matrix)->n = n;//обр. к полю n

	(*matrix)->x = (float*)malloc(sizeof(float) * n * n);

}

void size_matrix(int size) {
	
	printf("VVedite rasmer matrix");
	scanf("%d", size);
}
void scan_matrix(TMatrix* matrix)
{

	for (int i = 0; i < matrix->n; i++){
		for (int j = 0; j < matrix->n; j++){
			scanf("%f", &(matrix->x[matrix->n * i + j]));
		}
	}
}


void print_matrix(TMatrix* matrix)
{

	for (int i=0; i < matrix->n; i++){
		for (int j = 0; j < matrix->n; j++){
			printf("%f ", (matrix->x[matrix->n * i + j]));
		}
		printf("\n");
	}
	printf("\n");
}

void free_matrix(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}
TMatrix* matrix_add_const(TMatrix* matrix, float c)
{ //const
	TMatrix* res;
	
	alloc_matrix(&res, matrix->n);
	for (int i = 0; i < res->n * res->n; i++){
		res->x[i] = matrix->x[i] + c;
	}
	return res;
}

TMatrix* matrix_multiply_const(TMatrix* matrix, float c) 
{ //const
	TMatrix* res;

	alloc_matrix(&res, matrix->n);
	for (int i = 0; i < res->n * res->n; i++){
		res->x[i] = matrix->x[i] * c;
	}
	return res;
}

TMatrix* matrixes_multiply(TMatrix* matrix1, TMatrix* matrix2)
{//matrix
	TMatrix* res;

	alloc_matrix(&res, matrix1->n);
	/*
	for (int i = 0; i < res->n * res->n; i++){
		for (int j = 0; j < res->n*res->n; j++) {

		}

		res->x[i] = matrix1->x[i] * matrix2->x[i];
	}
	*/
	if (matrix1->n != matrix2->n){
		printf("ERROR: Incorrect matrix sizes.\n");
		res->n = 0;
	}
	else{
		for (int i = 0; i < res->n; ++i){
			for (int j = 0; j < res->n; ++j){
				res->x[ res->n * i + j] = 0;
				for (int k = 0; k < res->n; ++k)
					res->x[res->n * i + j] += matrix1->x[i*res->n + k] * matrix2->x[k*res->n + j];
			}
		}
	}

	return res;
}