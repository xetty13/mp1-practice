#ifndef _MATRIX_H
#define _MATRIX_H
#define N 2

typedef struct {
	int* arrays[N];
	int size;
}Matrix;
#endif

void allocate_matrix(Matrix** matr, int size);
void free_matrix(Matrix** vector);

void fill_Matrix(Matrix* matrix);
void print_Matrix(Matrix* matrix);

Matrix* add_vector(Matrix* matr1, Matrix* matr2);
int multi_matrix(Matrix* matr1, Matrix* matr2);
Matrix* multi_const(Matrix* matr, int c);
