#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void main() {
<<<<<<< HEAD
	int n, bs, es, k, i=0, c, j=1, nh, e, prov=0, bk = 0, ko = 0, l = 0;
	long long int nc;
=======
	int n, nc, bs, es, k, i, c, j=1, nh, e, prov, bk = 0, ko = 0, l = 0;
>>>>>>> 3e4edd08dab71bc52eff79a5e4b2c7cc8e6fd5e7
	int numb[10];
	int nhnumb[10];
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	do {
<<<<<<< HEAD
		printf("Введите длину числа с неповторяющимися числами: ");
=======
		printf("Р’РІРµРґРёС‚Рµ РґР»РёРЅСѓ С‡РёСЃР»Р° СЃ РЅРµРїРѕРІС‚РѕСЂСЏСЋС‰РёРјРёСЃСЏ С‡РёСЃР»Р°РјРё: ");
>>>>>>> 3e4edd08dab71bc52eff79a5e4b2c7cc8e6fd5e7
		scanf("%d", &n);
		if ((n <= 0) || (n >= 11)) {
			printf("Такого числа с неповторяющимися цифрами не существует\n");
		}
<<<<<<< HEAD
	} while ((n <= 0) || (n >= 11)); // проверка длины
	es = pow((double)10, (double)n);
	bs = pow((double)10, (double)n - 1); // граница
	for (i; i < n; i++) {
		numb[i] = rand() % 10;
		while (numb[0] == 0) {
			numb[i] = rand() % 10;
		}
		printf("%d", numb[i]);
	} // рандом числа
	printf("\n");
	while (prov == 0) {
		l = 0;
		e = -1;
		i = 0;
		do {
			e++;
			i = e + 1;
			for (i; i < n; i++) {
				if (numb[e] == numb[i]) {
					numb[e] = rand() % 10;
					while (numb[0] == 0) {
						numb[i] = rand() % 10;
					}
					prov = 0;
					l = 1;
					break;
=======
	} while ((n <= 0) || (n >= 11)); // РїСЂРѕРІРµСЂРєР° РґР»РёРЅС‹
	for (i = 0; i < n; i++) {
		k = rand() % 10;
		numb[i] = k;
		while (numb[0] == 0) {
			k = rand() % 10;
			numb[i] = k;
		}
		// РїСЂРѕРІРµСЂРєР° РЅР° 0
		for (j; j <= i; j++) {
			for (;;) {
				if (numb[i] == numb[j - 1]) {
					k = rand() % 10;
					numb[i] = k;
					j = 1;
>>>>>>> 3e4edd08dab71bc52eff79a5e4b2c7cc8e6fd5e7
				}
			}
<<<<<<< HEAD
			if (prov == 0) break;
		} while (e < n);
		if (l != 1) prov = 1;
	}
	for (i = 0; i < n; i++) {
		printf("%d", numb[i]);
	}
	printf("\n");
	printf("Компьютер загадал %d-значное число с неповторяющимися цифрами\n", n);
	printf("Попробуйте отгадать это n-значное число: ");
	scanf("%d", &nh);
	prov = 0;
	while (bk == n) {
		while (prov == 0) {
			int l;
			while ((nh < bs) || (nh > es)) {
					printf("Введено число неверной длины\n");
					printf("Введите число верной длины: ");
					scanf("%d", &nh);
				}
			// проверка на длину
			e = n-1;
			for (l = 0; l < n; l++) {
=======
		} // РїСЂРѕРІРµСЂРєР° РЅР° СЃРѕРІРїР°РґРµРЅРёРµ
		j = 1;
		printf("%d", numb[i]);
	} // РїСЂРѕРІРµСЂРєР° С‡РёСЃР»Р° РєРѕРјРїСЊСЋС‚РµСЂР°
	printf("\n");
	es = pow((double)10, (double)n);
	bs = pow((double)10, (double)n - 1);
	printf("РљРѕРјРїСЊСЋС‚РµСЂ Р·Р°РіР°РґР°Р» %d-Р·РЅР°С‡РЅРѕРµ С‡РёСЃР»Рѕ СЃ РЅРµРїРѕРІС‚РѕСЂСЏСЋС‰РёРјРёСЃСЏ С†РёС„СЂР°РјРё\n", n);
	printf("РџРѕРїСЂРѕР±СѓР№С‚Рµ РѕС‚РіР°РґР°С‚СЊ СЌС‚Рѕ n-Р·РЅР°С‡РЅРѕРµ С‡РёСЃР»Рѕ: ");
	scanf("%d", &nh);

	while (1) {
		while (1) {
			int l;
			while (1) {
				if ((nh > bs) && (nh < es)) {
					break;
				}
				else {
					printf("Р’РІРµРґРµРЅРѕ С‡РёСЃР»Рѕ РЅРµРІРµСЂРЅРѕР№ РґР»РёРЅС‹\n");
					printf("Р’РІРµРґРёС‚Рµ С‡РёСЃР»Рѕ РІРµСЂРЅРѕР№ РґР»РёРЅС‹: ");
					scanf("%d", &nh);
				}
			}
			// РїСЂРѕРІРµСЂРєР° РЅР° РґР»РёРЅСѓ
			e = n;
			for (l = 1; l <= n; l++) {
>>>>>>> 3e4edd08dab71bc52eff79a5e4b2c7cc8e6fd5e7
				nhnumb[e] = nh % 10;
				nh = nh / 10;
				e--;
			}
<<<<<<< HEAD
			// Разбиение числа
			for (e = 0; e < n; e++) {
=======
			// Р Р°Р·Р±РёРµРЅРёРµ С‡РёСЃР»Р°
			for (e = 1; e <= n; e++) {
>>>>>>> 3e4edd08dab71bc52eff79a5e4b2c7cc8e6fd5e7
				l = e + 1;
				for (l; l < n; l++) {
					if (nhnumb[e] == nhnumb[l]) {
						prov = 1;
						break;
					}
				}
				if (prov == 1) break;
			}
			// Проверка на совпадение
			if (prov == 1) {
				printf("Введено число c повторяющимися цифрами\n");
				printf("Введите новое число с неповторяющимися цифрами: ");
				scanf("%d", &nh);
				prov = 0;
			}
		}
		// проверка числа вводимого пользователем
		for (i = 0; i < n; i++) {
			e = 1;
			for (e ; e < n; e++) {
				if (numb[i] == nhnumb[e]) {
					ko++;
					if (i == e) {
						bk++;
					}
				}
			}
<<<<<<< HEAD
		} // счет быков и коров
		printf("Количество коров %d\n", ko);
		printf("Количество быков %d\n", bk);
		if (bk == n) {
			printf("Молодец, ты угадал загаданное компьютером число!!!\n");
			printf("\n");
			return;
		} 
		// Угадал
=======
		}
		printf("РљРѕР»РёС‡РµСЃС‚РІРѕ РєРѕСЂРѕРІ %d\n", ko);
		printf("РљРѕР»РёС‡РµСЃС‚РІРѕ Р±С‹РєРѕРІ %d\n", bk);
		if (bk == n) {
			printf("РњРѕР»РѕРґРµС†, С‚С‹ СѓРіР°РґР°Р» Р·Р°РіР°РґР°РЅРЅРѕРµ РєРѕРјРїСЊСЋС‚РµСЂРѕРј С‡РёСЃР»Рѕ!!!\n");
			printf("\n");
			return;
		}
>>>>>>> 3e4edd08dab71bc52eff79a5e4b2c7cc8e6fd5e7
		else {
			ko = 0;
			bk = 0;
			printf("Попробуйте еще раз: ");
			scanf("%d", &nh);
		}
<<<<<<< HEAD
		// не угадал
	}
}
=======
	} // РїСЂРѕРІРµСЂРєР° РІРІРѕРґРёРјРѕРіРѕ С‡РёСЃР»Р°
}
>>>>>>> 3e4edd08dab71bc52eff79a5e4b2c7cc8e6fd5e7
