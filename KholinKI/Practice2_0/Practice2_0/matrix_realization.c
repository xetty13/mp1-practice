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

struct Matrix* add_matrix(struct Struct_2d_matrix* matr1, struct Struct_2d_matrix* matr2,struct Struct_2d_matrix* res)
{
    int i = 0;
 /*   if (matr1->size != matr2->size)
    {
        printf("ERROR: Vectors should have the same lenght.\n");
        return NULL;
    }
 */
    allocate_matrix(res, Matrix[0].size); //Definition of the res matrix
    for (i=0; i < res->size; i++)
    {
        for (int j = 0; j < res->size; j++) {
            res->arr_2d[i][j] = matr1->arr_2d[i][j] + matr2->arr_2d[i][j];//Add matr1 and matr2 element by element
        }
    }
    return res;
}

struct Matrix* multi_const(struct Struct_2d_matrix* res, float c)
{
    int i = 0;
    allocate_matrix(res, Matrix[0].size); //Definition of the res matrix
    fill_matrix(res);
    for (i = 0; i < res->size; i++)
    {
        for (int j = 0; j < res->size; j++) {
            res->arr_2d[i][j] = res->arr_2d[i][j] * c;//Each element of the matrix res is multiplied by c
        }
    }
    return res;
}
struct Matrix* add_const(struct Struct_2d_matrix* res, float c)
{
    int i = 0;
    allocate_matrix(res, Matrix[0].size);//Definition of the res matrix
    fill_matrix(res);
    for (i = 0; i < res->size; i++)
    {
        for (int j = 0; j < res->size; j++) {
            res->arr_2d[i][j] = res->arr_2d[i][j] + c;//Each element of the matrix res is added by c
        }
    }
    return res;
}

struct Matrix* multi_matrix(struct Struct_2d_matrix* matr1, struct Struct_2d_matrix* matr2, struct Struct_2d_matrix* res)
{
    int k = 0;
    int i = 0;
    int j = 0;
    /*   if (matr1->size != matr2->size)
       {
           printf("ERROR: Vectors should have the same lenght.\n");
           return NULL;
       }
    */
    allocate_matrix(res, Matrix[0].size);
    for (i = 0; i < res->size; i++) {
        for ( j = 0; j < res->size; j++) {
            res->arr_2d[i][j] = 0;
        }
    }
    for (i = 0; i < res->size; i++)
    {
        while (k < res->size) {//fix i-kth cell of matrix res
            for (int j = 0; j < res->size; j++) {
                res->arr_2d[i][k] += matr1->arr_2d[i][j] * matr2->arr_2d[j][k]; //matrix multiplication design
            }
            k++;
        }
        k = 0;
    }
    return res;
}

