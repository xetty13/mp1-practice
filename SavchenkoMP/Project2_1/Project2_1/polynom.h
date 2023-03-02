/*
Определить структуру для представления полинома произвольной степени (полином представляется набором коэффициентов).
Реализовать операции сложения, умножения, вычитания полиномов, а также вычисления значения полинома для заданного значения аргумента,
дифференцирования полинома.
*/
#ifndef _POLYNOM_H
#define _POLYNOM_H

typedef struct {
	float* coeff;
	int degree;
} TPolynom;

void allocate_polynom(TPolynom** polynom, int degree);
TPolynom* allocate_polynom_copy(TPolynom** p, TPolynom** tmp);
void free_polynom(TPolynom** polynom);

void read_file(TPolynom*** p, FILE** file, int* n);
void fill_polynom(TPolynom* p, FILE* file);
void print_polynom(TPolynom* p);

TPolynom* plus_polynom(TPolynom* p1, TPolynom* p2);
TPolynom* multi_polynom(TPolynom* p1, TPolynom* p2);
TPolynom* minus_polynom(TPolynom* p1, TPolynom* p2);
TPolynom* diff_polynom(TPolynom* p);

float value_polynome(TPolynom* p, float _x);


#endif // !_POLYNOM_H