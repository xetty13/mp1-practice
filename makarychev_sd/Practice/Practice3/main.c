#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	int n, chislo;
	unsigned int m;
	printf("Выберите 1 или 2 режим");
	scanf("%d", &n);
		if (n==2)
		{
			printf("Загадайте число от 1 до 1000");
			do 
			{ 
				scanf("%d", &m);
			}
			while ((m<1)||(m>1000));
			chislo = 1 + rand() %1000;
			printf("chislo");
		}
}

			

