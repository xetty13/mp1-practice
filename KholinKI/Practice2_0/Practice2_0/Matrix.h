#ifndef _MATRIX_H
#define _MATRIX_H


typedef struct{
	float** arr_2d;		//Declare the structure of square matrices
	int size;
}TDmatrix;  

 //Declare 3 arrays of structures

void allocate_matrix(TDmatrix** struct_p, int size); //Creating a square matrix
void free_matrix(TDmatrix** struct_p); //Releasing the memory

void fill_matrix(TDmatrix*struct_p); //filling square matrix
void print_matrix(TDmatrix*struct_p); //Output the contents of a square matrix

TDmatrix* add_matrix(TDmatrix* matr1, TDmatrix* matr2);
//Matrix addition operation: feed two pointers 
//to square matrices and a pointer to the resultant matrix
//(all from an array of structures)

TDmatrix* multi_const(TDmatrix* matr1, float c);
//Matrix multiplication operation by constant:
//give a pointer to the resulting matrix res and constant.

TDmatrix* add_const(TDmatrix* matr2, float c);
//The operation of adding a constant to a matrix : 
//feed a pointer to the resultant matrix resand a constant.

TDmatrix* multi_matrix(TDmatrix* matr1, TDmatrix* matr2);
//Matrix multiplication operation: 
//feed 3 pointers to each of the matrices in the structure array.
#endif
