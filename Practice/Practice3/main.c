#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main()
{
	int mode, num, att = 0, inp, a = 1, b = 1000, lie = 0;
	char answ;
	srand((unsigned)time(0));
	setlocale(LC_ALL, "Rus");
	printf("Выберите режим:\n0 – компьютер загадывает,\n1 – компьютер угадывает\n");
	do
	{
		scanf("%d", &mode);
		if (mode == 0)
		{
			num = rand() % (b - a - 1) + 1 + a;
			//num = (float)(b - a - 1) / RAND_MAX * rand() + 1;
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
				inp = rand() % (b - a - 1) + 1 + a;
				printf("Число %d, оцените его (символы '>' '=' '<')\n", inp);
				do
				{
					ent:
					scanf(" %c", &answ);
					if (!((answ == '<') || (answ == '>') || (answ == '='))) printf("Неверный символ\n");
					//Контроль ввода
					if ((answ == '<') && !(num < inp) || (answ == '>') && !(num > inp) || (answ == '=') && (num != inp))
					{
						printf("Ложный ввод\n");
						lie++;
						goto ent;
						//continue;
					}
				} while (!((answ == '<') || (answ == '>') || (answ == '=')));
				switch (answ)
				{
				case '>':
					a = inp;
					att++;
					break;
				case '=':
					att++;
					break;
				case '<':
					b = inp;
					att++;
				}
			} while (answ != '=');
			printf("\nВведено верное число, совершено %d попыток\n", att);
			if (lie != 0) printf("Попыток нечестной игры: %d\n", lie);
			printf("\n");
			return;
		}
		printf("Выберите режим\n");
	} while ((mode != 0) || (mode != 1));
}