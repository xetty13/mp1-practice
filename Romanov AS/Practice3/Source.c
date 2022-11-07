#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 11
int main()
{
	int a[N], b[5] = { 0 }, c[5] = { 0 }, i, n = 0, k = 0, x, y = 0, cow = 0, bull = 0, o, p = 0, s, j;
	printf("Vvedite skolki znachnim budet ygadivaemoe chislo (ot 2 do 5)");
	do
	{
		scanf("%d", &n);
	} while ((n < 2) || (n > 5));
	for (i = 0; i < N; i++)
	{
		a[i] = k;
		k++;
	}
	srand(time(NULL));
	for (x = 0; x < n; x++)
	{
		i = rand() % 10;
		if (a[i] == 10)
		{
			while (a[i] == 10)
			{
				i -= 1;
			}
		}
		b[y] = a[i];
		for (i; i < N - 1; i++)
		{
			a[i] = a[i + 1];
		}
		y++;
	}
	do
	{
		p++;
		cow = 0;
		bull = 0;
		printf("\nVvedite vashu popitku");
		scanf("%d", &j);
		for (i = 0; i < n; i++)
		{
			c[i] = j % 10;
			j /= 10;
		}
		for (i = 0; i < n; i++)
		{
			for (o = 0; o < n; o++)
			{
				if ((c[i] == b[o]) && (i != o))
				{
					cow++;
				}
				if ((c[i] == b[o]) && (i == o))
				{
					bull++;
				}
			}
		}
		if (bull == n)
		{
			printf("Vi otgadali, kolichestvo popitok - %d", p);
			s = 1;
		}
		else
		{
			printf("Kolichestvo bikov - %d  ", bull);
			printf("Kolichestvo korov - %d  ", cow);
			s = 0;
		}
	} while (s != 1);
	return 0;
}