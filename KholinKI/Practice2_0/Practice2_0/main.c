#include <stdio.h>
#include <malloc.h>
#include "Matrix.h"


int main(int argc, char *argv[])
{
    int i = 0;
    float c = 6;
    TDmatrix Matrix;
    TDmatrix*dynamic_matrix1;
    TDmatrix* dynamic_matrix2;          //Declare three pointers to square matrices
    TDmatrix* res;
    int size_2d;
    printf("Specify the dimension of the square matrix: \n");   //Determine the size of the square matrices
    scanf("%d", &size_2d);

    allocate_matrix(&dynamic_matrix1, size_2d);
    fill_matrix(dynamic_matrix1);                               //Creating and filling square matrices
    allocate_matrix(&dynamic_matrix2, size_2d);
    fill_matrix(dynamic_matrix2);
 //   print_matrix(dynamic_matrix1);
 //   print_matrix(dynamic_matrix2);

    res = add_matrix(dynamic_matrix1, dynamic_matrix2);//returned address matrix res1
    print_matrix(res);
    free_matrix(&res);

    res =multi_const(dynamic_matrix1, c);//returned address matrix res2
    print_matrix(res);
    free_matrix(&res);//structure number 3 is free

    res =add_const(dynamic_matrix2, c);//returned address matrix res3
    print_matrix(res); 
    free_matrix(&res);

    res = multi_matrix(dynamic_matrix1, dynamic_matrix2);//returned address matrix res4
    print_matrix(res);
    free_matrix(&res);

    free_matrix(&dynamic_matrix1);
    free_matrix(&dynamic_matrix2);
    return 0;
}