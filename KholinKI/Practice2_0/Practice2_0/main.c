#include <stdio.h>
#include "Matrix.h"


int main()
{
    int i = 0;
    struct matrix;
    Matrix* matrix_dynamic, * res;
    allocate_matrix(&matrix_dynamic->arrays[1], 4);
    allocate_matrix(&matrix_dynamic->arrays[2], 4);

    fill_matrix(matrix_dynamic->arrays[1]);
    fill_matrix(matrix_dynamic->arrays[2]);

    res = add_vector(matrix_dynamic->arrays[1], matrix_dynamic->arrays[2]);
    print_matrix(res);
    free_matrix(&res);

    res = multi_const(matrix_dynamic->arrays[1], 2);
    print_matrix(res);
    free_matrix(&res);

    for (i = 0; i < matrix_dynamic->size; i++) {
        free_matrix(&matrix_dynamic[i]);
    }
    free_matrix(&matrix_dynamic);
    return 0;
}