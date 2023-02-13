#include <stdio.h>
#include "Matrix.h"


int main()
{
    int i = 0;
    Matrix* matrix_dynamic, * res, * matr1, * matr2;

    allocate_matrix(&matrix_dynamic, 2);
    fill_matrix(&matrix_dynamic);
    print_matrix(matrix_dynamic);
    free_vector(&matrix_dynamic);

    res = add_matrix(matr1, matr2);
    print_matrix(res);
    free_matrix(&res);

    res = multi_const(matr1, 2);
    print_matrix(res);
    free_matrix(&res);

    res = add_const(matr1, 2);
    print_matrix(res);
    free_matrix(&res);

    res = multi_matrix(matr1, matr2);
    print_matrix(res);
    free_matrix(&res);
    return 0;
}