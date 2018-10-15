#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void main()
{
	int n, i = 0, q, w, c = 0, r, rt1 = 0, rt2 = 0, rr, cow = 0, bull = 0, c1 = 0, c2 = 0;
	long long in, nt;
	setlocale(LC_ALL, "Rus");
	int rnd[N] = { 0 }, ain[N] = { 0 };
	srand((unsigned)time(0));
	//Ввод длины числа
	do
	{
		printf("Введите длину числа от 2 до 10\n");
		scanf("%d", &n);
		if (n <= 1 || n > 10)
		{
			printf("Повторите ввод\n\n");
			continue;
		}
	} while (n <= 1 || n > 10);
	//Ввод первого числа пользователя
	nt = (long long)pow(10, n);
	do {
		do
		{
			printf("Введите %i-значное число с различными цифарами\n", n);
			scanf("%lli", &in);
			if ((in < nt * 0.1) || (in > nt))
			{
				printf("Повторите ввод\n\n");
				continue;
			}
		} while ((in < nt * 0.1) || (in > nt));
		for (i = 0; i < n; i++)
		{
			ain[i] = in - (int)(in * 0.1) * 10;
			in /= 10;
		}
		for (q = 0; q < n; q++)
		{
			for (w = q + 1; w <= n; w++)
			{
				if (ain[q] == ain[w])
				{
					printf("Повторите ввод\n\n");
					c++;
				}
			}
		}
	} while (c != 0);
	//Генерация псевдослучайного числа
	for (r = 0; r < n; r++)
	{
		rnd[r] = ain[r];
	}
	for (r = 0; r < n; r++)
	{
		rr = rand() % n;
		rt1 = rnd[r];
		rt2 = rnd[rr];
		rnd[r] = rt2;
		rnd[rr] = rt1;
	}
	if (rnd[0] == 0)
	{
		rr = rand() % n;
		rt1 = rnd[0];
		rt2 = rnd[rr];
		rnd[0] = rt2;
		rnd[rr] = rt1;
	}
	for (r = 0; r < n; r++)
	{
		if ((rnd[r] * 0.5) * 2 == rnd[r]) rnd[r] = rnd[r] * 2 + 7;
		else rnd[r] = rnd[r] * 2 + 4;
		rnd[r] = rnd[r] % 10 - 1;
	}
	//Сравнение
	do
	{
		cow = 0;
		bull = 0;
		i = 0;
		q = 0;
		w = 0;
		c = 0;
		for (c1 = 0; c1 < n; c1++)
		{
			for (c2 = 0; c2 < n; c2++)
			{
				if (rnd[c1] == ain[c2] && c1 == c2) bull++;
				if (rnd[c1] == ain[c2] && c1 != c2) cow++;
			}
		}
		if (bull != n)
		{
			printf("%d коров(ы), %d быка(ов)\n", cow, bull);
			do {
				do
				{
					printf("Введите новое %i-значное число с различными цифарами\n", n);
					scanf("%d", &in);
					if ((in < nt * 0.1) || (in > nt))
					{
						printf("Повторите ввод\n\n");
						continue;
					}
				} while ((in < nt * 0.1) || (in > nt));
				for (i = 0; i < n; i++)
				{
					ain[i] = in - (int)(in * 0.1) * 10;
					in /= 10;
				}
				for (q = 0; q < n; q++)
				{
					for (w = q + 1; w <= n; w++)
					{
						if (ain[q] == ain[w])
						{
							printf("Повторите ввод\n\n");
							c++;
						}
					}
				}
			} while (c != 0);
		}
	} while (bull != n);
	printf("Все быки найдены\n");
}
