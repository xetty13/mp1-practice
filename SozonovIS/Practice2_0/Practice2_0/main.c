#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int main()
{
    int i = 0;
    TVector vector;
    TVector* vector_dynamic, * v1, * v2, * res;
    double dot_product;

    /*
    vector.n = 4;
    vector.x = (double*)malloc(sizeof(double) * vector.n);
    for (; i < vector.n; i++)
    {
        scanf("%lf", &(vector.x[i]));
    }
    for (i = 0; i < vector.n; i++)
    {
        printf("%.3lf ", vector.x[i]);
    }
    printf("\n");
    free(vector.x);
    */

    /*
    alloc_vector(&vector_dynamic, 4);
    fill_vector(vector_dynamic);
    print_vector(vector_dynamic);
    free_vector(&vector_dynamic);
    */

    alloc_vector(&v1, 4);
    alloc_vector(&v2, 4);
    fill_vector(v1);
    fill_vector(v2);

    res = add_vector(v1, v2);
    print_vector(res);
    free_vector(&res);

    res = add_scalar(v1, 2.5);
    print_vector(res);
    free_vector(&res);

    dot_product = multi_vector(v1, v2);
    printf("%.3lf\n", dot_product);

    res = multi_scalar(v1, 2.0);
    print_vector(res);
    free_vector(&res);

    free_vector(&v1);
    free_vector(&v2);
    return 0;
}