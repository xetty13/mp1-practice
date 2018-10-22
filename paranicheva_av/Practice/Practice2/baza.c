<<<<<<< HEAD
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
void main()
{
	int b[10], a[10];
	int n, i, j, x, bull = 0, cow = 0, k, m;
	srand((unsigned)time(0));
	printf("Igra Byki i Korovy \n");
	do
	{
		printf("Vyberete dlinu zagadyvaemogo chisla ");
		scanf("%d", &n);
	} while ((n < 1) || (n > 10));
	for (i = 0; i < n; i++)
	{
		do
		{
			k = 0;
			if (i == 0)
				m = 9.0 / RAND_MAX * rand() + 1;
			else
				m = 10.0 / RAND_MAX * rand();
			for (j = 0; j < i; j++)
			{
				if (m == b[j])
					k++;
			}
		} while (k != 0);
		b[i] = m;
	}
	do
	{
		bull = 0;
		cow = 0;
		do
		{
			printf("Vvedite predpolagaemoe chislo \n");
			scanf("%d", &x);
			k = 0;
			for (i = (n - 1); i >= 0; i--)
			{
				m = x % 10;
				x /= 10;
				a[i] = m;
				for (j = (i + 1); j < n; j++)
				{
					if (m == a[j])
						k++;
				}
			}
		} while (k != 0);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((b[i] == a[j]) && (i == j))
					bull++; 
				if ((b[i] == a[j]) && (i != j))
					cow++;
			}
		}
		printf("bull = %d, cow = %d \n", bull, cow);
	} while (bull != n);
=======
#include <stdio.h>
void main()
{
	int n, 
		do
			{printf("Vvedite n");
	scanf ("%d", &n)
		while 

>>>>>>> 7a2ae15abbb03ccd1f9ab2c0eebc40970e532f0d
}