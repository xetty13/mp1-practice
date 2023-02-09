#include <stdio.h>
#include "matrix.h"


int main()
{
    int i = 0;
    TMatrix matrix;
    TMatrix* matrix_dynamic, * v1, * v2, * res;
    float res_dotprod;
    allocate_matrix(&v1, 4);
    allocate_matrix(&v2, 4);
    fill_matrix(v1);
    fill_matrix(v2);

    res = add_matrix(v1, v2);
    print_matrix(res);
    free_matrix(&res);

    res = add_const(v1, 5.5f);
    print_matrix(res);
    free_matrix(&res);

    res_dotprod = multi_matrix(v1, v2);
    printf("%f\n", res_dotprod);

    res = multi_const(v1, 2.0f);
    print_matrix(res);
    free_matrix(&res);

    free_matrix(&v1);
    free_matrix(&v2);
    return 0;
}
