#ifndef _MATRIX_H
#define _MATRIX_H

typedef float таракан;
struct Struct_2d_matrix{
	float** arr_2d;		//Declare the structure of square matrices
	int size;
}Matrix[3];  //Declare 3 arrays of structures;

 //Declare 3 arrays of structures

void allocate_matrix(struct Struct_2d_matrix*struct_p, int size); //Creating a square matrix
void free_matrix(struct Struct_2d_matrix*struct_p); //Releasing the memory

void fill_matrix(struct Struct_2d_matrix*struct_p); //filling square matrix
void print_matrix(struct Struct_2d_matrix*struct_p); //Output the contents of a square matrix

void add_matrix(struct Struct_2d_matrix* matr1, struct Struct_2d_matrix* matr2, struct Struct_2d_matrix* res);
//Matrix addition operation: feed two pointers 
//to square matrices and a pointer to the resultant matrix
//(all from an array of structures)

void multi_const(struct Struct_2d_matrix* res, float c);
//Matrix multiplication operation by constant:
//give a pointer to the resulting matrix res and constant.

void add_const(struct Struct_2d_matrix* res, float c);
//The operation of adding a constant to a matrix : 
//feed a pointer to the resultant matrix resand a constant.

void multi_matrix(struct Struct_2d_matrix* matr1, struct Struct_2d_matrix* matr2, struct Struct_2d_matrix* res);
//Matrix multiplication operation: 
//feed 3 pointers to each of the matrices in the structure array.
#endif
