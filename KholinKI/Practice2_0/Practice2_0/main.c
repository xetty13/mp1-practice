#include <stdio.h>
#include <malloc.h>
#include "Matrix.h"


int main()
{
    int i = 0;
    float c = 6;
    struct Struct_2d_matrix *dynamic_matrix1;
    dynamic_matrix1 = &Matrix[0];
    struct Struct_2d_matrix* dynamic_matrix2;          //Declare three pointers to square matrices
    dynamic_matrix2 = &Matrix[1];
    struct Struct_2d_matrix* res;
    res = &Matrix[2];
    int size_2d;
    printf("Specify the dimension of the square matrix: \n");   //Determine the size of the square matrices
    scanf("%d", &size_2d);

    allocate_matrix(dynamic_matrix1, size_2d);
    fill_matrix(dynamic_matrix1);                               //Creating and filling square matrices
    allocate_matrix(dynamic_matrix2, size_2d);
    fill_matrix(dynamic_matrix2);
 //   print_matrix(dynamic_matrix1);
 //   print_matrix(dynamic_matrix2);

    res = add_matrix(dynamic_matrix1, dynamic_matrix2);
    print_matrix(res);
    free_matrix(res);

    res =multi_const(dynamic_matrix1, c);
    print_matrix(res);
    free_matrix(res);

    res =add_const(dynamic_matrix2, c);
    print_matrix(res); 
    free_matrix(res);

    res = multi_matrix(dynamic_matrix1, dynamic_matrix2);
    print_matrix(res);
    free_matrix(res);

    free_matrix(dynamic_matrix1);
    free_matrix(dynamic_matrix2);
    return 0;
}