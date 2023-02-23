#include <stdio.h>
#include <malloc.h>
#include "Matrix.h"

void allocate_matrix(struct Struct_2d_matrix *struct_p, int size)
{

    int i = 0;
    (*struct_p).size = size;
    struct_p->arr_2d = (float**)malloc(sizeof(float*) * struct_p->size);
    for (i = 0; i < struct_p->size; i++) {
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
            scanf("%f", &(struct_p->arr_2d[i][j]));
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
            printf("%f ", struct_p->arr_2d[i][j]);
        }
    }
    printf("\n");
}

void free_matrix(struct Struct_2d_matrix  *struct_p)
{
    int i = 0;
    for (i = 0; i < struct_p->size;i++) {
        free(struct_p->arr_2d[i]);
    }
    free(struct_p->arr_2d);
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
    allocate_matrix(res, Matrix[0].size);
    for (i=0; i < res->size; i++)
    {
        for (int j = 0; j < res->size; j++) {
            res->arr_2d[i][j] = matr1->arr_2d[i][j] + matr2->arr_2d[i][j];
        }
    }
    return res;
}

struct Matrix* multi_const(struct Struct_2d_matrix* res, float c)
{
    int i = 0;
    allocate_matrix(res, Matrix[0].size);
    fill_matrix(res);
    for (i = 0; i < res->size; i++)
    {
        for (int j = 0; j < res->size; j++) {
            res->arr_2d[i][j] = res->arr_2d[i][j] * c;
        }
    }
    return res;
}
struct Matrix* add_const(struct Struct_2d_matrix* res, float c)
{
    int i = 0;
    allocate_matrix(res, Matrix[0].size);
    fill_matrix(res);
    for (i = 0; i < res->size; i++)
    {
        for (int j = 0; j < res->size; j++) {
            res->arr_2d[i][j] = res->arr_2d[i][j] + c;
        }
    }
    return res;
}

struct Matrix* multi_matrix(struct Struct_2d_matrix* matr1, struct Struct_2d_matrix* matr2, struct Struct_2d_matrix* res)
{
    int i = 0;
    /*   if (matr1->size != matr2->size)
       {
           printf("ERROR: Vectors should have the same lenght.\n");
           return NULL;
       }
    */
    allocate_matrix(res, Matrix[0].size);
    for (i = 0; i < res->size; i++)
    {
        for (int j = 0; j < res->size; j++) {
            res->arr_2d[i][j] = matr1->arr_2d[i][j] * matr2->arr_2d[i][j];
        }
    }
    return res;
}

