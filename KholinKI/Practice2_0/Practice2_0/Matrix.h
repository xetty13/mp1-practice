#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct {
	float* arr;
	int size;
}Matrix;

void allocate_matrix(Matrix** matr, int size);
void free_matrix(Matrix** matrix);

void fill_Matrix(Matrix* matrix);
void print_Matrix(Matrix* matrix);

Matrix* add_matrix(Matrix* matr1, Matrix* matr2);
Matrix* multi_matrix(Matrix* matr1, Matrix* matr2);
Matrix* multi_const(Matrix* matr, float c);
Matrix* multi_const(Matrix* matr, float c);
#endif
