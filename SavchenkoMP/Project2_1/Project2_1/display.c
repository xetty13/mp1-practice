#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "display.h"
#include "polynom.h"

void choose() {
	printf("1. Сложить полиномы.\n");
	printf("2. Вычесть из одного полинома второй полином.\n");
	printf("3. Умножение полиномов.\n");
	printf("4. Вычислить значение по заданному аргументу.\n");
	printf("5. Найти производную полинома.\n");
	printf("0. Выход\n\n");
}

void answer(int* ans) {
	do {
		scanf("%d", ans);
	} while (*ans > 5 || *ans < 0);
}

void retry(int* ans) {
	printf("\nПродолжить? (1/0)\n");
	answer(ans);
}


void print_p(TPolynom** p, int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("f%d = ", i);
		print_polynom(p[i]);
	}
	printf("\n");
}

void print_2p(TPolynom* p1, TPolynom* p2, int* ind) {
	printf("f%d = ", ind[0]);
	print_polynom(p1);
	printf("f%d = ", ind[1]);
	print_polynom(p2);
	printf("\n");
}

void index(int* ind, int n) {
	printf("Выберите 2 полинома:\n");
	printf("Полином 1: ");
	do {
		scanf("%d", &ind[0]);
	} while (ind[0] < 0 || ind[0] >= n);

	printf("Полином 2: ");
	do {
		scanf("%d", &ind[1]);
	} while (ind[1] < 0 || ind[1] >= n);
	printf("\n");
}