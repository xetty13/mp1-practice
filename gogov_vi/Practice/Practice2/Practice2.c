#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int n, nc, bs, es, k, i, c, j=1, nh, e, prov, bk = 0, ko = 0, l = 0;
	int numb[10];
	int nhnumb[10];
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	do {
		printf("Введите длину числа с неповторяющимися числами: ");
		scanf("%d", &n);
		if ((n <= 0) || (n >= 11)) {
			printf("Такого числа с неповторяющимися цифрами не существует\n");
		}
	} while ((n <= 0) || (n >= 11)); // проверка длины
	for (i = 0; i < n; i++) {
		k = rand() % 10;
		numb[i] = k;
		while (numb[0] == 0) {
			k = rand() % 10;
			numb[i] = k;
		}
		// проверка на 0
		for (j; j <= i; j++) {
			for (;;) {
				if (numb[i] == numb[j - 1]) {
					k = rand() % 10;
					numb[i] = k;
					j = 1;
				}
				else break;
			}
		} // проверка на совпадение
		j = 1;
		printf("%d", numb[i]);
	} // проверка числа компьютера
	printf("\n");
	es = pow((double)10, (double)n);
	bs = pow((double)10, (double)n - 1);
	printf("Компьютер загадал %d-значное число с неповторяющимися цифрами\n", n);
	printf("Попробуйте отгадать это n-значное число: ");
	scanf("%d", &nh);

	while (1) {
		while (1) {
			int l;
			while (1) {
				if ((nh > bs) && (nh < es)) {
					break;
				}
				else {
					printf("Введено число неверной длины\n");
					printf("Введите число верной длины: ");
					scanf("%d", &nh);
				}
			}
			// проверка на длину
			e = n;
			for (l = 1; l <= n; l++) {
				nhnumb[e] = nh % 10;
				nh = nh / 10;
				e = e - 1;
			}
			// Разбиение числа
			for (e = 1; e <= n; e++) {
				l = e + 1;
				for (l; l <= n; l++) {
					if (nhnumb[l] == nhnumb[e]) {
						prov = 0;
						break;
					}
				}
				if (prov == 0) break;
			}
			// Проверка на совпадение
			if (prov == 0) {
				printf("Введено число c повторяющимися цифрами\n");
				printf("Введите новое число с неповторяющимися цифрами: ");
				scanf("%d", &nh);
				prov = 1;
			}
			else break;
		}
		for (i = 1; i <= n; i++) {
			e = 1;
			for (e = 1; e <= n; e++) {
				if (numb[i] == nhnumb[e]) {
					ko = ko + 1;
					if (i == e) {
						bk = bk + 1;
					}
				}
			}
		}
		printf("Количество коров %d\n", ko);
		printf("Количество быков %d\n", bk);
		if (bk == n) {
			printf("Молодец, ты угадал загаданное компьютером число!!!\n");
			printf("\n");
			return;
		}
		else {
			ko = 0;
			bk = 0;
			printf("Попробуйте еще раз: ");
			scanf("%d", &nh);
		}
	} // проверка вводимого числа
}
