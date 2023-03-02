#include <stdio.h>
#include <stdlib.h>
#include "polynom.h"

void allocate_polynom(TPolynom** polynom, int degree) {
	(*polynom) = (TPolynom*)malloc(sizeof(TPolynom) * 1);
	(*polynom)->degree = degree;
	(*polynom)->coeff = (float*)malloc(sizeof(float) * (degree + 1));
}

TPolynom* allocate_polynom_copy(TPolynom** p, TPolynom** tmp) {
	int i, tmp_dgr = 0;
	for (i = (*tmp)->degree; i >= 0; i--)
		if ((*tmp)->coeff[i] != 0) {
			tmp_dgr = i;
			break;
		}

	allocate_polynom(p, tmp_dgr);
	for (i = (*p)->degree; i >= 0; i--)
		(*p)->coeff[i] = (*tmp)->coeff[i];
	free_polynom(tmp);

	return *p;
}

void free_polynom(TPolynom** polynom) {
	free((*polynom)->coeff);
	free(*polynom);
}


void read_file(TPolynom*** p, FILE** file, int* n) {
	/*
	Чтение происходит из файла "data.txt"
	-В первой строке - количество полиномов
	-В второй строке перечисленны степени каждого полинома
	-В последующих строках перечисленны коэффициенты полиномов

	!!!Предполагается, что введенные данные верны!!!
	*/
	int i, dgr;
	*(file) = fopen("data.txt", "r");
	fscanf(*(file), "%d", n);

	*(p) = (TPolynom**)malloc(sizeof(TPolynom*) * *(n)); // массив полиномов
	for (i = 0; i < *(n); i++) {
		// Инициализация
		fscanf(*(file), "%d", &dgr);
		allocate_polynom(&((*(p))[i]), dgr);
	}
	for (i = 0; i < *(n); i++) {
		// Заполнение
		fill_polynom((*(p))[i], *(file));
	}
	fclose(*(file));
}
void fill_polynom(TPolynom* p, FILE* file) {
	int i;
	for (i = p->degree; i >= 0; i--) {
		fscanf(file, "%f", &(p->coeff[i]));
	}
}
void print_polynom(TPolynom* p) {
	int i;
	printf("%.2fx^%d ", (p->coeff[p->degree]), (p->degree));
	for (i = p->degree - 1; i >= 0; i--) {
		if (p->coeff[i] > 0)
			printf("+ %.2fx^%d ", (p->coeff[i]), i);
		else if (p->coeff[i] < 0)
			printf("- %.2fx^%d ", -(p->coeff[i]), i);
	}
	printf("\n");
}


TPolynom* plus_polynom(TPolynom* p1, TPolynom* p2) {
	TPolynom* res;
	TPolynom* tmp;
	int i, tmp_dgr = 0;
	if ((p1->degree) > (p2->degree)) {
		allocate_polynom(&tmp, p1->degree);
		for (i = p1->degree; i >= 0; i--)
			tmp->coeff[i] = p1->coeff[i];
		for (i = p2->degree; i >= 0; i--)
			tmp->coeff[i] += p2->coeff[i];
	}
	else {
		allocate_polynom(&tmp, p2->degree);
		for (i = p2->degree; i >= 0; i--)
			tmp->coeff[i] = p2->coeff[i];
		for (i = p1->degree; i >= 0; i--)
			tmp->coeff[i] += p1->coeff[i];
	}

	res = allocate_polynom_copy(&res, &tmp);
	return res;
}

TPolynom* multi_polynom(TPolynom* p1, TPolynom* p2) {
	TPolynom* mul;
	int i, j, D;
	D = (p1->degree) + (p2->degree);
	allocate_polynom(&mul, D);
	for (i = D; i >= 0; i--)
		mul->coeff[i] = 0;

	for (i = p1->degree; i >= 0; i--)
		for (j = p2->degree; j >= 0; j--)
			mul->coeff[i + j] += p1->coeff[i] * p2->coeff[j];
	return mul;
}

TPolynom* minus_polynom(TPolynom* p1, TPolynom* p2) {
	TPolynom* res;
	TPolynom* tmp;
	int i, tmp_dgr = 0;
	int M = ((p1->degree) > (p2->degree)) ? (p1->degree) : (p2->degree);
	allocate_polynom(&tmp, M);
	for (i = M; i >= 0; i--)
		tmp->coeff[i] = 0;

	for (i = p1->degree; i >= 0; i--)
		tmp->coeff[i] = p1->coeff[i];
	for (i = p2->degree; i >= 0; i--)
		tmp->coeff[i] -= p2->coeff[i];

	res = allocate_polynom_copy(&res, &tmp);
	return res;
}

TPolynom* diff_polynom(TPolynom* p) {
	TPolynom* res;
	int i;
	if (p->degree == 0) {
		allocate_polynom(&res, p->degree);
		res->coeff[0] = 0;
	}
	else {
		allocate_polynom(&res, p->degree - 1);
		for (i = p->degree - 1; i >= 0; i--) {
			res->coeff[i] = p->coeff[i + 1] * (i + 1);
		}
	}
	return res;
}


float value_polynome(TPolynom* p, float _x) {
	int i;
	float res = 0.0f, x = 1.0f;
	for (i = 0; i < p->degree; i++) {
		res += p->coeff[i] * x;
		x *= _x;
	}

	return res;
}