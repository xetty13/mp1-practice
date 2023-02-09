#include "func.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    SMatrix* matrix1, *matrix2, *resMatrix;
    int size;
    double scalar;
    scanf("%d", &size);
    scanf("%lf", &scalar);
    alloc_matrix(&matrix1, size);
    alloc_matrix(&matrix2, size);
    create_matrix (matrix1);
    create_matrix (matrix2);
    resMatrix = sum_matrix(matrix1, matrix2);
    print_matrix(resMatrix);
    free_matrix(&resMatrix);
    resMatrix = multiply_matrix(matrix1, matrix2);
    print_matrix(resMatrix);
    free_matrix(&resMatrix);
    resMatrix = sum_matrix_n_scalar(matrix1, scalar);
    print_matrix(resMatrix);
    free_matrix(&resMatrix);
        resMatrix = multiply_matrix_n_scalar(matrix1, scalar);
    print_matrix(resMatrix);
    free_matrix(&resMatrix);
    free_matrix(&matrix1);
    free_matrix(&matrix2);
}