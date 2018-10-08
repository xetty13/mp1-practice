#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void main()
{
	int n, a;
	setlocale(LC_ALL, "Rus");
	do
	{
		printf("Введите длину числа\n");
		scanf("%d", &n);
		if (n <= 0 || n > 10)
		{
			printf("Неверные данные\n\n");
			continue;
		}
	} while (n <= 0 || n > 10);
	n = rand() % 10;
	do { a = rand() % 10; } while (a == n);
	printf("%d %d\n", n, a);
}