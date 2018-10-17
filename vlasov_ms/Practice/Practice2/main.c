#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define MAX 9

/* функция проверки на повторения цифр   *
 * в числе (без массива - по-моему, это  *
 * по меньшей мере эффективно)           */
int checkReps(long int number) {
	long int cached_number;
	char current_number, comparing_number, flag = 0;
	while (number > 0) {
		flag = 0;
		current_number = number % 10;
		number /= 10;
		cached_number = number;
		while (cached_number > 0) {
			comparing_number = cached_number % 10;
			cached_number /= 10;
			if (comparing_number == current_number) {
				flag++;
				break;
			}
		}
		if (flag) break;
	}
	if (flag > 0) return 0;
	else return 1;
}

void main() {
	long int Num1 = 0, Num2 = 0, cached_Num, ord10 = 1;
	int bufs = 0, cows = 0, cNum2;
	char flag = 0, aNum1[MAX], aNum2[MAX], n, i, j;
	setlocale(LC_ALL, "Russian");
	for (i = 0; i < MAX; i++) aNum1[i] = aNum2[i] = -1;

	// приветственный экран
	do {
		system("cls");
		printf("Игра \"БЫКИ И КОРОВЫ\"\n");
		printf("Введите длину загадываемого числа (от 1 до 9): ");
		scanf("%hhd", &n);
	} while ((n < 1) || (n > 9));

	// вычисление числа без повторяющихся цифр
	srand((unsigned int)time(NULL));
	for (i = n; i > 0; i--) ord10 *= 10;
	do {
		Num1 = rand() % ((ord10 - 1) - (ord10 / 10) + 1) + (ord10 / 10);
	} while (checkReps(Num1) == 0);
	printf("Chislo: %d\n", Num1);
	printf("Отлично, я загадал %d-значное число с неповторяющимися цифрами. Теперь попробуйте угадать его.\nВведите %d-значное число: ", n, n);
	
	while (Num1 != Num2) {
		// запрашиваем число у пользователя
		scanf("%d", &Num2);
		if (Num1 == Num2) break;
		// подсчет цифр во введенном числе
		cNum2 = 0;
		cached_Num = Num2;
		while (cached_Num > 0) {
			cNum2++;
			cached_Num /= 10;
		}
		// проверка повторений, если кол-во цифр верно, иначе ошибка
		if (cNum2 == n) {
			if (checkReps(Num2) == 0) {
				printf("Цифры в вашем числе повторяются. Повторите попытку ввода: ");
				continue;
			}
		}
		else {
			printf("Вы ввели не %d-значное число. Попробуйте еще раз: ", n);
			continue;
		}
		// засунем числа в массивы
		cached_Num = Num1;
		i = 0;
		while (cached_Num > 0) {
			aNum1[i] = cached_Num % 10;
			cached_Num /= 10;
			i++;
		}
		cached_Num = Num2;
		i = 0;
		while (cached_Num > 0) {
			aNum2[i] = cached_Num % 10;
			cached_Num /= 10;
			i++;
		}
		// посчитаем коров
		for (i = 0; aNum2[i] != -1; i++) {
			for (j = 0; aNum1[j] != -1; j++) {
				if ((aNum1[j] == aNum2[i]) && (i != j)) cows++;
			}
		}
		// посчитаем быков
		for (i = 0; aNum1[i] != -1; i++) {
			if (aNum1[i] == aNum2[i]) bufs++;
		}
		// отобразим
		printf("[%d]: %d коров, %d быков. Попробуйте еще раз: ", Num2, cows, bufs);
	}

	// если вдруг число угадано
	printf("Бинго! Действительно, было загадано число %d.\n", Num1);
	return;

	

}