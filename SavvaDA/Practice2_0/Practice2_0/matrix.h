#pragma once


typedef struct
{
    int n;
    double* x;
} matrix;

void alloc_matrix(matrix** m, int n);
void free_matrix(matrix** m);

void fill_matrix(matrix* m);
void print_matrix(matrix* m);

matrix* add_matrix(matrix* m1, matrix* m2);
matrix* add_scalar(matrix* m, double c);

matrix* multi_matrix(matrix* m1, matrix* m2);
matrix* multi_scalar(matrix* m, double c);