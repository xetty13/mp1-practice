#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define MAX 9

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
	long int Num1, Num2, cached_Num2;
	int bufs, cows, cNum2;
	char flag = 0, aNum1[MAX] = { 0 }, aNum2[MAX] = { 0 }, n;
	setlocale(LC_ALL, "Russian");
	do {
		system("cls");
		printf("Игра \"БЫКИ И КОРОВЫ\"\n");
		printf("Введите длину загадываемого числа (от 1 до 9): ");
		scanf("%hhd", &n);
	} while ((n < 1) || (n > 9));

	/*                           *
	 * загадывание числа сделать *
	 *                           */

	printf("Отлично, я загадал %d-значное число с неповторяющимися цифрами. Теперь попробуйте угадать его.\nВведите %d-значное число: ", n, n);
	while (1) {
		scanf("%d", &Num2);
		cNum2 = 0;
		cached_Num2 = Num2;
		while (cached_Num2 > 0) {
			cNum2++;
			cached_Num2 /= 10;
		}
		if (cNum2 == n) { // если количество цифр верно
			if (checkReps(Num2) == 1) break;
			else printf("Цифры в вашем числе повторяются. Повторите попытку ввода: ");
		}
		else 
			printf("\aВы ввели не %d-значное число. Попробуйте еще раз: ", n);
	}


	printf("hello\n");

}