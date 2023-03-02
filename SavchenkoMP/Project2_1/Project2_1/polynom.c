#include <stdio.h>
#include <stdlib.h>
#include "polynom.h"

void allocate_polynom(TPolynom** polynom, int degree) {
	(*polynom) = (TPolynom*)malloc(sizeof(TPolynom) * 1);
	(*polynom)->degree = degree;
	(*polynom)->coeff = (float*)malloc(sizeof(float) * (degree + 1));
}

void free_polynom(TPolynom** polynom) {
	free((*polynom)->coeff);
	free(*polynom);
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
		if (p->coeff[i] >= 0)
			printf("+ %.2fx^%d ", (p->coeff[i]), i);
		else
			printf("- %.2fx^%d ", -(p->coeff[i]), i);
	}
	printf("\n");
}


TPolynom* plus_polynom(TPolynom* p1, TPolynom* p2) {
	TPolynom* res;
	int i;
	if ((p1->degree) > (p2->degree)) {
		allocate_polynom(&res, p1->degree);
		for (i = p1->degree; i >= 0; i--)
			res->coeff[i] = p1->coeff[i];
		for (i = p2->degree; i >= 0; i--)
			res->coeff[i] += p2->coeff[i];
	}
	else {
		allocate_polynom(&res, p2->degree);
		for (i = p2->degree; i >= 0; i--)
			res->coeff[i] = p2->coeff[i];
		for (i = p1->degree; i >= 0; i--)
			res->coeff[i] += p1->coeff[i];
	}
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
	int i;
	int M = ((p1->degree) > (p2->degree)) ? (p1->degree) : (p2->degree);
	allocate_polynom(&res, M);
	for (i = M; i >= 0; i--)
		res->coeff[i] = 0;

	for (i = p1->degree; i >= 0; i--)
		res->coeff[i] = p1->coeff[i];
	for (i = p2->degree; i >= 0; i--)
		res->coeff[i] -= p2->coeff[i];

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


float power(float x, int n) {
	int i;
	float res = 1.0f;
	for (i = 0; i < n; i++)
		res *= x;
	return res;
}

float value_polynome(TPolynom* p, float x) {
	int i;
	float res = 0.0f;
	for (i = p->degree; i >= 0; i--)
		res += p->coeff[i] * power(x, i);
	return res;
}