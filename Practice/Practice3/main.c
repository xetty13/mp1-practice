#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main()
{
	int mode, num, att = 0, inp, a = 1, b = 1000;
	char answ;
	srand((unsigned)time(0));
	setlocale(LC_ALL, "Rus");
	printf("Выберите режим:\n0 – компьютер загадывает,\n1 – компьютер угадывает\n");
	do
	{
		scanf("%d", &mode);
		if (mode == 0)
		{
			num = (float)998 / RAND_MAX * rand() + 1;
			do
			{
				do
				{
					printf("Введите число от 1 до 999\n");
					scanf("%d", &inp);
					if ((inp < 1) || (inp > 999)) printf("Число вне допустимых пределов\n");
				} while ((inp < 1) || (inp > 999));
				if (inp > num)
				{
					printf("Слишком большое\n");
					att++;
				}
				if (inp < num)
				{
					printf("Слишком маленькое\n");
					att++;
				}
			} while (inp != num);
			printf("Введено верное число, совершено %d попыток\n", ++att);
			return;
		}
		if (mode == 1)
		{
			do
			{
				printf("Введите число от 1 до 999\n");
				scanf("%d", &num);
				if ((num < 1) || (num > 999)) printf("Число вне допустимых пределов\n");
			} while ((num < 1) || (num > 999));
			do
			{
				inp = (float)(b - a) / RAND_MAX * rand() + 1;
				printf("Число %d, оцените его (символы '>' '=' '<')\n", inp);
				do
				{
					scanf("%c", &answ);
					if ((answ != '<') || (answ != '>') || (answ != '=')) printf("Неверный символ");
				} while ((answ != '<') || (answ != '>') || (answ != '='));
				switch (answ)
				{
				case '>': 
					b = inp;
					att++;
					break;
				case '=': 
					att++;
					break;
				case '<':
					a = inp;
					att++;
				}
			} while (answ != '=');			
			printf("Введено верное число, совершено %d попыток\n", att);
			return;
		}
		printf("Выберите режим\n");
	} while ((mode != 0) || (mode != 1));
}