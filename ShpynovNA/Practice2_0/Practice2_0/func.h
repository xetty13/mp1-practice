#ifndef _FUNC_H
#define _FUNC_H


typedef struct
{
    int size;
    double** num;
} SMatrix;

void alloc_matrix(SMatrix** matrix, int n);
void free_matrix (SMatrix** matrix);
void create_matrix (SMatrix* matrix);
SMatrix* sum_matrix(SMatrix* m1, SMatrix* m2);
void print_matrix (SMatrix* matrix);
SMatrix* multiply_matrix(SMatrix* m1, SMatrix* m2);
SMatrix* multiply_matrix_n_scalar(SMatrix* m1, double n);
SMatrix* sum_matrix_n_scalar(SMatrix* m1, double n);

#endif // !_FUNC_H