#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10
void main()
{
	int l, n, k, b, i, p;
	int  ch[N] = 0;
	int ch_mb[N] = 0;
	long int s, s1, ch_pr, a;
	
	do
	{
		printf("Vvedite kolichestvo tcifr v zagadannom chisle (do 10)\n");
		scanf("%d", n);
	} while ((n <= 0) || (n > N));
        p = 1;
	for (i = 0; i < n - 1; i++)
		for (l = p; l < n; l++)
		{
			do
			{
				srand((unsigned int)time(0));
				ch[l] = 10 / RAND_MAX * rand() + 0;
			} while (ch[i] == ch[l]);
		}
	long int ch_n = 0;
	for (i = 0; i < n; i++)
	{
		s1 = ch[i];
		ch_n = ch_n + s1 * pow(10, (n - i));
	}

	int m = 1;
	do
	{
		printf("Vvedite predpolagaemoe chislo \n");
		do
		{
			scanf("%ld", ch_pr);
			ch_pr = a;
			while (a != 0)
			{
				a = a % 10;
				m++;
			}
		} while ((ch_pr < 0) || (m > n));
		s = ch_pr;
		for (l = 0; l < n; l++)
		{
			ch_mb[l] = s % pow(10, n - i);
			s = s / pow(10, n - i);
		}

		for (i = 0; i < n; i++)
			for (l = 0; l < n; l++)
				if (ch_mb[i] == ch[l])
					if (i == l)
					{
						k++;
						b++;
					}
					else k++;
		printf("Obnaruzheno %d ", b, " bykov", " i %d ", k, " korov");
	} while (ch_n != ch_pr);
	printf("Pozdravlyaem! Vy otgadaly chislo! %d ", ch_n);
}
