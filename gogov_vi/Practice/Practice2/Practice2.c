#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define N 10
void main()
{
	int n, nc, bs=10, es=10, k, i=1, c, j = 1, nh, e, prov = 0, bk = 0, ko = 0, l = 0;
	int numb[N];
	int nhnumb[N];
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	do
	{
		printf("Введите длину числа с неповторяющимися числами: ");
		scanf("%d", &n);
		if ((n <= 0) || (n >= 11))
		{
			printf("Такого числа с не повторяющимися цифрами не существует\n");
		}
 	} while ((n <= 0) || (n >= 11)); // проверка длины
 	numb[0] = rand() % 10;
	while (numb[0] == 0)
	{
		numb[0] = rand() % 10;
	}
 	while(i<n)
	{
		numb[i] = rand() % 10;
		j = 0;
		for (j; j < i; j++)
		{
			if (numb[i] == numb[j])
			{
				numb[i] = rand() % 10;
				i = 1;
				break;
			}
		} // проверка на совпадение
		i++;
	} // проверка числа компьютера
	l = 0;
	while(l<n){
		es *= es;
		l++;
	}
	l = 0;
	while(l<n){
		bs *= bs;
		l++;
	}
	//es = pow((double)10, (double)n);
	//bs = pow((double)10, (double)n - 1);
	printf("Компьютер загадал %d-значное число с неповторяющимися цифрами\n", n);
	printf("Попробуйте отгадать это n-значное число: ");
	scanf("%d", &nh);
	while (bk == 0)
	{
		while (prov == 0)
		{
			while ((nh < bs) || (nh > es))
			{
				printf("Введено число неверной длины\n");
				printf("Введите число верной длины: ");
				scanf("%d", &nh);
			}
			// проверка на длину
			e = n - 1; // запись с конца
			for (l = 0; l < n; l++)
			{
				nhnumb[e] = nh % 10;
				nh = nh / 10;
				e--;
			}
			// Разбиение числа
			for (e = 0; e < n; e++)
			{
				l = e + 1;
				for (l; l < n; l++)
				{
					if (nhnumb[l] == nhnumb[e])
					{
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
			else break;
		}
		for (i = 0; i < n; i++)
		{
			e = 0;
			for (e; e < n; e++)
			{
				if (numb[i] == nhnumb[e])
				{
					ko = ko + 1;
					if (i == e)
					{
						bk = bk + 1;
					}
				}
			}
		} // быки и коровы
		printf("Количество коров: %d\n", ko);
		printf("Количество быков: %d\n", bk);
		if (bk == n)
		{
			printf("Число компьютера: ");
			for (i = 0; i < n; i++)
			{
				printf("%d", numb[i]);
			}
			printf("\n");
			printf("Молодец, ты угадал загаданное компьютером число!!!\n");
			return;
		}
		else
		{
			ko = 0;
			bk = 0;
			printf("Попробуйте еще раз: ");
			scanf("%d", &nh);
		}
	}
} // проверка вводимого числа
