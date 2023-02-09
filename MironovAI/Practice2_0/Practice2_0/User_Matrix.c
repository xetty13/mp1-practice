#include <stdio.h>
#include "HUser_Matrix.h"
#include <stdlib.h>

void allocate_matrix(CMatrix** data, int new_size)
{  
    
    (*data) = (CMatrix*)malloc(sizeof(CMatrix));
    (*data)->size = new_size;

    (*data)->matrix = (float**)malloc(sizeof(float*) * new_size);
    for (int i = 0; i < new_size; i++) {
        (*data)->matrix[i] = (float*)malloc(sizeof(float) * new_size);
    }
}

void fill_matrix(CMatrix* data)
{
    int n = data->size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Input a number from %d column and %d row ", i+1, j+1);
            scanf("%f", &data->matrix[i][j]);
        }
    }
}

void mprint(CMatrix* data)
{
    printf("\n");
    int n = data->size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f   ", data->matrix[i][j]);
        }
        printf("\n");
    }
   
}

void free_matrix(CMatrix** data)
{
    int size = (*data)->size;
   
    for (int i = 0; i < size; i++) {
        free((*data)->matrix[i]);
    }
    free((*data)->matrix);
}

CMatrix* add_const(CMatrix* data, float c)
{
    CMatrix* res;
    int i = 0;
    int k = data->size;
    allocate_matrix(&res, k);
    for (; i < k; i++)
    {
        for (int j = 0; j < k; j++) {
            res->matrix[i][j] = data->matrix[i][j] + c;

        }
    }

    return res;
}

CMatrix* multi_const(CMatrix* data, float c)
{
    CMatrix* res;
    int i = 0;
    int k = data->size;
    allocate_matrix(&res, k);
    for (; i < k; i++)
    {
        for (int j = 0; j < k; j++) {
            res->matrix[i][j] = data->matrix[i][j] * c;
        }
    }
    return res;
}



CMatrix *add_matrix(CMatrix *matrix1, CMatrix *matrix2) {
    CMatrix* res;
    int i = 0;
    int k1 =  matrix1->size, k2 = matrix2->size;
    if (k1 != k2)
    {
        printf("ERROR: Vectors should have the same lenght.\n");
        return NULL;
    }
    
    allocate_matrix(&res, k1);
    for (; i < k1; i++)
    {
        for (int j = 0; j < k2; j++) {
            res->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
        }
    }
    return res;
}



CMatrix* multi_matrix(CMatrix* matrix1, CMatrix* matrix2)
{
    CMatrix* res;
    int i = 0;
    int k1 = matrix1->size, k2 = matrix2->size;
    if (k1 != k2)
    {
        printf("ERROR: Vectors should have the same lenght.\n");
        return NULL;
    }

    allocate_matrix(&res, k1);

    for (; i < k1; i++)
        for (int j = 0; j < k1; j++)
        {
            res->matrix[i][j] = 0;
            for (int k = 0; k < k1; k++)
                res->matrix[i][j] += matrix1->matrix[i][k] * matrix2->matrix[k][j];
        }


    return res;
}


