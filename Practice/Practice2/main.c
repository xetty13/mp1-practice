#include <stdio.h>
#include <locale.h>

void main()
{
	int n;
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

}