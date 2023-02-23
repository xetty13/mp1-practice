#ifndef _MATRIX_H
#define _MATRIX_H

typedef float конфетка;
struct Struct_2d_matrix{
	float** arr_2d;
	int size;
};

struct Struct_2d_matrix Matrix[3];

void allocate_matrix(struct Struct_2d_matrix*struct_p, int size);
void free_matrix(struct Struct_2d_matrix*struct_p);

void fill_matrix(struct Struct_2d_matrix*struct_p);
void print_matrix(struct Struct_2d_matrix*struct_p);

struct Matrix* add_matrix(struct Struct_2d_matrix* matr1, struct Struct_2d_matrix* matr2, struct Struct_2d_matrix* res);

struct Matrix* multi_const(struct Struct_2d_matrix* res, float c);

struct Matrix* add_const(struct Struct_2d_matrix* res, float c);

struct Matrix* multi_matrix(struct Struct_2d_matrix* matr1, struct Struct_2d_matrix* matr2, struct Struct_2d_matrix* res);
#endif
