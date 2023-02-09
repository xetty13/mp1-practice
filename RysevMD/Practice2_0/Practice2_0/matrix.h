#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct {
	int n;
	float* x;
}Matrix;

void allocate_matrix(Matrix** matr, int n);
void free_matrix(Matrix** matr);

void fill_matrix(Matrix* matr, int n);
void print_matrix(Matrix* matr, int n);

Matrix* multiple_dot(Matrix* matr, float a);
Matrix* add_matrix(Matrix* matr1, Matrix* matr2);
Matrix* multiple_matrix(Matrix* matr1, Matrix* matr2);
#endif