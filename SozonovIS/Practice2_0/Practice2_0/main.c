#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int main() 
{
    TMatrix* m1, * m2, * res;

    alloc_matrix(&m1, 3);
    alloc_matrix(&m2, 3);

    fill_matrix(m1);
    fill_matrix(m2);

    print_matrix(m1);
    print_matrix(m2);

    res = add_scalar(m1, 1);
    print_matrix(res);
    free_matrix(&res);

    res = multi_scalar(m1, 10);
    print_matrix(res);
    free_matrix(&res);

    res = add_matrix(m1, m2);
    print_matrix(res);
    free_matrix(&res);

    res = multi_matrix(m1, m2);
    print_matrix(res);
    free_matrix(&res);

    return 0;
}