#include <stdio.h>
#include <malloc.h>
#include "Matrix.h"

void allocate_matrix(struct Struct_2d_matrix *struct_p, int size)
{

    int i = 0;
    (*struct_p).size = size; //Determine the size of the square matrix (the size is entered from the keyboard)
    struct_p->arr_2d = (float**)malloc(sizeof(float*) * struct_p->size);
    for (i = 0; i < struct_p->size; i++) {//Create a dynamic two-dimensional array with size size
        struct_p->arr_2d[i] = (float*)malloc(sizeof(float) * struct_p->size);
    }
}

void fill_matrix(struct Struct_2d_matrix *struct_p)
{
    printf("Fill the matrix: \n");
    int i = 0;
    int j = 0;
    for (i=0 ; i < struct_p->size; i++)
    {

        for (j = 0; j < struct_p->size; j++) {
            scanf("%f", &(struct_p->arr_2d[i][j]));//filling two-demension matrix
        }
    }
}

void print_matrix(struct Struct_2d_matrix *struct_p)
{
    printf("Two-demension matrix: \n");
    int i = 0;
    int j = 0;
    for (i=0; i < struct_p->size; i++)
    {
        printf("\n");
        for (j = 0; j < struct_p->size; j++) {
            printf("%f ", struct_p->arr_2d[i][j]);//Outputting a square matrix
        }
    }
    printf("\n");
}

void free_matrix(struct Struct_2d_matrix  *struct_p)
{
    int i = 0;
    for (i = 0; i < struct_p->size;i++) {
        free(struct_p->arr_2d[i]); //Freeing up memory from underneath the columns
    }
    free(struct_p->arr_2d); //Freeing up memory from underneath the strings
}

struct Struct_2d_matrix* add_matrix(struct Struct_2d_matrix* matr1, struct Struct_2d_matrix* matr2)
{
    struct Struct_2d_matrix* res1 = &Matrix[2];//Getting the address of structure number 2
    int i = 0, j = 0;
    if (matr1->size != matr2->size)
    {
        printf("ERROR: Vectors should have the same lenght.\n");
        exit(-100);
    }
    allocate_matrix(res1, matr1->size); //Definition of the res matrix
    for (i=0; i < res1->size; i++)
    {
        for (int j = 0; j < res1->size; j++) {
            res1->arr_2d[i][j] = matr1->arr_2d[i][j] + matr2->arr_2d[i][j];//Add matr1 and matr2 element by element
        }
    }
    return res1;
}

struct Struct_2d_matrix* multi_const(struct Struct_2d_matrix* matr1, float c)
{
    struct Struct_2d_matrix* res2 = &Matrix[2];//Getting the address of structure number 2
    int i = 0,j=0;
    allocate_matrix(res2, matr1->size); //Definition of the res matrix
    for (i = 0; i < matr1->size; i++)
    {
        for (int j = 0; j < matr1->size; j++) {
            res2->arr_2d[i][j] = matr1->arr_2d[i][j] * c;//Each element of the matrix res is multiplied by c
        }
    }
    return res2;

}
 struct Struct_2d_matrix* add_const(struct Struct_2d_matrix* matr2, float c)
 {
    struct Struct_2d_matrix* res3 = &Matrix[2];//Getting the address of structure number 2
    int i = 0, j =0;
    allocate_matrix(res3, matr2->size); //Definition of the res matrix
    for (i = 0; i < matr2->size; i++)
    {
        for (int j = 0; j < matr2->size; j++) {
            res3->arr_2d[i][j] = matr2->arr_2d[i][j] + c;//Each element of the matrix res is added by c
        }
    }
    return res3;
}

 struct Struct_2d_matrix* multi_matrix(struct Struct_2d_matrix* matr1, struct Struct_2d_matrix* matr2)
{
    int k = 0;
    int i = 0;
    int j = 0;
    struct Struct_2d_matrix* res4 = &Matrix[2];//Getting the address of structure number 2
       if (matr1->size != matr2->size)
       {
           printf("ERROR: Vectors should have the same lenght.\n");
           exit(-100);
       }
   
    allocate_matrix(res4, matr1->size);
    for (i = 0; i < res4->size; i++) {
        for (j = 0; j < res4->size; j++) {
            res4->arr_2d[i][j] = 0;
        }
    }
    for (i = 0; i < res4->size; i++)
    {
        while (k < res4->size) {//fix i-kth cell of matrix res
            for (int j = 0; j < res4->size; j++) {
                res4->arr_2d[i][k] += matr1->arr_2d[i][j] * matr2->arr_2d[j][k]; //matrix multiplication design
            }
            k++;
        }
        k = 0;
    }
    return res4;
}

