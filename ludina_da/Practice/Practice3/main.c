#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int n, r, k, b, a;
	int i = 0;
	char c;
	setlocale(LC_ALL, "Rus");
	printf("Выберите режим 1 или 2: ");
	scanf("%d", &n);
	srand((unsigned int)time(0));
	if (n == 1)
	{
		r = 1 + rand() % 1000;
		printf("Компьютер загадывает случайное число от 1 до 1000, попробуйте отгадать:\n");
		while (1)
		{
			i++;
			printf("Введите число: ");
			scanf("%d", &k);
			if (k < r)
			{
				printf("Загаданое число больше\n");
			}
			else if (k > r)
			{
				printf("Загаданное число меньше\n");
			}
			else
			{
				printf("Вы угадали\n");
				break;
			}
		}
		printf("Количество попыток: %d \n", i);
	}
	else if (n == 2)
	{
		printf("Загадайте число от 1 до 1000, введите его: ");
        scanf("%d", &a);
		k = 1 + rand() % 1000;
        printf("Компьютер пробует угадать: %d \n", k);
		while (1)
		{
			i++;
			printf("Загаданное число является: \n");
			scanf("%*c%c", &c);
			if (c == '<')
			{
				b = 1 + rand() % k;
				printf("%d \n", b);
			}
			else if (c == '>')
			{
				b = k + rand() % 1000;
				printf("%d \n", b);
			}
			else if (c == '=')
			{
				printf("Компьютер угадал\n");
				break;
			}

		}
		printf("Количество попыток: %d \n", i);
	}
}