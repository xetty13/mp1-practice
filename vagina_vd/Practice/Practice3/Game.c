#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
void main()
{
	int n, cows = 0, bulls = 0, i, f, j, m = 0;
	int  ch[N] = { 0 };
	int ch_mb[N] = { 0 };
	long long ch_predp, ch_nast = 0, predp, a;

	do
	{
		printf("Vvedite kolichestvo tcifr v zagadannom chisle (do 10)\n"); //ввод кол-ва цифр числа и проверка 
		scanf("%d", &n);
	} while (n <= 0 || n > N);


	srand((unsigned int)time(0));
	f = 0; 
	ch[0] = rand() % 9+1;
	
		for (i = 1; i < n; i++)
		{
			if (f == 1)
			{
				i--;
				j--;
			}
			ch[i] = rand() % 9;
			f = 0;
			for (j = 1; j < n; j++)
				if (ch[i - 1] == ch[j])
					f = 1;
		}



	for (i = 0; i < n; i++)
		printf("%d", ch[i]);
	
	i = 1;
	ch_nast = ch[0];
	while (i < n) // перевод числа, введенного комп., из массива в переменную 
	{
		
		ch_nast = ch_nast * 10 + ch[i];
		i++;
	}
	printf("\n");
	printf("%lld\n", ch_nast);
	do
	{
		printf("Vvedite predpolagaemoe chislo (naturalnoe i pervaya tsifra ne 0)\n"); //ввод числа игроком и преобразование его в массив
		f = 0;                                      //с проверкой на 1й "0" 
		do
		{
			scanf("%lld", &ch_predp);
			a = ch_predp;
			while (m != n)                      // проверка на кол-во введенных цифр
			{
				a = a % 10;
				m++;
			}
			predp = ch_predp;
			for (i = n - 1; i = 0; i--)
			{
				ch_mb[i] = predp % 10;
				predp /= 10;
				if (ch_mb[0] == 0) f = 1;
			}

			for (i = 0; i < n; i++)
				for (j = i + 1; j < n - 1; j++)
					if (ch_mb[i] == ch_mb[j])
						f = 1;
		} while (f == 0 || ch_predp < 0 || m > n);



		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (ch_mb[i] == ch[j])
					if (i == j)
					{
						cows++;
						bulls++;
					}
					else cows++;
		printf("Korovy = %d\n", cows);
		printf("Byki = %d\n", bulls);
	} while (ch_nast != ch_predp);
	printf("Pozdravlyaem! Vy otgadaly chislo! %lld ", ch_nast);
}
