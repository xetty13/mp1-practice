#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#define N 10
void main()
{
	int n, x, c = 0, m = 9, f = 0;
	int i, j, k = 1, c1 = 0, b1 = 0;
	int a[N], b[N];
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(0));
	printf("Игра 'Быки и коровы'\n");
	do
	{
		printf("Выберете длинну загаданного число:");
		scanf("%d", &n);
	} while (n < 1 || n > 10);
	for (i = 0; i < n; i++)
	{
		a[i] = (m - c) / RAND_MAX * rand() + c;
		while (1)
		{
			if (a[0] = 0)
			{
				a[0] = (m - c) / RAND_MAX * rand() + c;
			}
			else
				break;
		}
		b[0] = a[0];
		for (j = 0; j < i; j++)
		{
			if (a[i] == a[j])
				f = 1;
		}
		if (f = 0)
		{
			b[k] = a[i];
			k++;
		}
	}
	while (1)
	{
		printf("Попробуйте отгадать: \n");
		scanf("%d", &x);
		for (j = 0; j < n; j++)
		{
			b[n - j] = x % 10;
			x = x % 10;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((b[i] == a[j]) && (i == j))
				{
					b1++;
				}
				if ((b[i] == a[j]) && (i != j))
				{
					c1++;
				}
			}
		}
		printf("Количесво коров: %d \n", c1);
		printf("Количесво быков: %d \n", b1);
		if ((c1 == 0) && (b1 = n))
		{
			printf("Вы угадали \n");
			break;
		}
	}
}

