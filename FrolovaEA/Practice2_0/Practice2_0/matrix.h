#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
	float* x;
	int n;
}TMatrix;


void allocate_matrix(TMatrix** matrix, int n);//выделение памяти
void fill_matrix(TMatrix* matrix);//заполнение матриц
void print_matrix(TMatrix* matrix);
void free_matrix(TMatrix** matrix);
TMatrix* addition_matrix(TMatrix* matrix1, TMatrix* matrix2);
TMatrix* addition_const(TMatrix* matrix1, float c);
TMatrix* multi_const(TMatrix* matrix, float c);
TMatrix* multi_matrix(TMatrix* matrix1, TMatrix* matrix2);
#endif // !_MATRIX_H
