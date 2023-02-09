#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
	float* x;
	int n;
}Matrix;

void allocate_matrix(Matrix** matrix, int n);
void fill_matrix(Matrix* matrix);
void print_matrix(Matrix* matrix);
void free_matrix(Matrix** matrix);
Matrix* addition_matrix(Matrix* matrix1, Matrix* matrix2);




#endif // !_MATRIX_H

